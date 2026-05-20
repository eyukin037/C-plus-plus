//SeaBattle2.0 Eyukin.cpp 
//Игра "Морской бой"(поле 10х10, 10 штук кораблей). Обязательно: Расстановка кораблей случайным образом, корабли не должны соприкасаться и
//обозначения попаданий(ранил/потопил или мимо)
//Необходимо  использовать функции, работу с массивами и таблицами, а для оформления псевдографику.
//План реализации игры "Морской бой" (содержит по 4 одноклеточных катера (S), 3 двухклеточных эсминца (SS), 2 трехклеточных крейсера (SSS) и 
//1 четырехклеточному линкору (SSSS) для игрока и компьютера) :
//1.Пользовательский интерфейс (консольный вывод, псевдографика, цветовое оформление)
//2.Создание игровых полей(инициализация массивов 10х10 для игрока (обязательно) и компьютера (по желанию))
//3.Реализация случайной расстановки кораблей(с проверкой на корректность размещения)
//4.Проверка, чтобы корабли не соприкасались(включая диагонали)
//5.Псевдографическое отображение поля(корабли, попадания, промахи)
//6.Реализация механизма выстрелов(ввод координат, проверка попадания)
//7.Определение результата выстрела(мимо / ранил / потопил)
//8.Реализация хода игрока(повтор при попадании, завершение при промахе) - обязательно
//9.Реализация хода компьютера(случайный выбор координат, исключение повторов) - по желанию
//10.Обновление игрового поля после каждого хода
//11.Если игрок попадает в корабль (ранит или топит его), он получает право сделать ещё один ход, пока не промахнётся.
//Если ПК попадает в корабль, он продолжает ходить, пока не промахнётся.
//12.Отмечаем клетки вокруг корабля, который потоплен промахами.
//13.Возможность повторной игры (реванш)
//14.Завершение игры(вывод результата)
//0 — пустое поле.
//1 — целая палуба корабля.
//2 — попадание(подбитая палуба).
//-1 — промах.
//-2 — зона вокруг потопленного корабля.
//"Морской бой" — это игра против активного противника (человека или компьютера), а не "расстрел поля" без сопротивления.
//Одиночный режим — это упрощенная версия, которая не соответствует классическим правилам.
#include <iostream>
#include <Windows.h> // Для работы с цветами консоли и заголовком окна
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
const int size_battlefield = 10; // Размер игрового поля 10x10 (глобальная константа)
// Дескриптор консоли для изменения цвета текста
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// Глобальная строка с буквами для координат
const char COLS[] = "АБВГДЕЖЗИК";
// --- Память ПК для "умного" хода ---
int targetsX[100]; // Массив X координат возможных целей для ПК
int targetsY[100]; // Массив Y координат возможных целей для ПК
int targetCount = 0; // Количество текущих целей в памяти ПК
bool isHunting = false; // Флаг режима охоты после попадания (true — ПК продолжает стрелять вокруг попадания)
// Функция установки цвета текста в консоли
void SetColor(int color) {
    SetConsoleTextAttribute(h, color);
}
// Сброс цвета текста на белый
void ResetColor() {
    SetColor(7);
}
// Установка случайного цвета текста
void SetRandomColor() {
    SetColor(1 + rand() % 15);
}
// ---Логика расстановки кораблей---
// Функция PlaceCan проверяет не только саму позицию корабля, но и «ореол» вокруг него (9 клеток вокруг каждой палубы), что гарантирует 
// отсутствие соприкосновений даже по диагонали.
// Проверка, можно ли разместить корабль длины len в позиции x,y
bool PlaceCan(int battlefield[size_battlefield][size_battlefield], int x, int y, int len, bool horizontal) {
    //// Внешний цикл: перебираем каждую палубу будущего корабля (от 0 до len-1)
    for (int i = 0; i < len; i++) { // Цикл по каждой клетке корабля
        // Вычисляем координаты текущей проверяемой палубы 'nx' и 'ny'
        // Если horizontal == true, меняется только столбец (y + i), если false — только строка (x + i)
        int nx = x + (horizontal ? 0 : i); // X координата текущей клетки корабля
        int ny = y + (horizontal ? i : 0); // Y координата текущей клетки корабля
        // Проверка соседних клеток по X и Y (включая диагонали)
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int cx = nx + dx;
                int cy = ny + dy;
                // Проверка: находится ли вычисленная клетка внутри границ поля 10x10
                if (cx >= 0 && cx < size_battlefield && cy >= 0 && cy < size_battlefield) { // Если в пределах поля
                    if (battlefield[cx][cy] != 0) return false; // Если клетка занята или рядом, корабль нельзя ставить
                }
            }
        }
    }
    return true; // Разместить корабль можно
}
// Функция ShipPlace размещает один корабль длиной len
void ShipPlace(int battlefield[size_battlefield][size_battlefield], int len) {
    while (true) { // Пока корабль не будет корректно поставлен
        int x = rand() % size_battlefield;        // Случайная координата X
        int y = rand() % size_battlefield;        // Случайная координата Y
        bool horizontal = rand() % 2;       // Случайная ориентация: горизонтальная/вертикальная
        // Проверка выхода за границы поля
        if (horizontal && y + len > size_battlefield) continue;
        if (!horizontal && x + len > size_battlefield) continue;
        if (!PlaceCan(battlefield, x, y, len, horizontal)) continue; // Проверка соседних клеток
        // Размещение корабля в массиве поля
        for (int i = 0; i < len; i++) {
            if (horizontal) battlefield[x][y + i] = 1; // Горизонтальный корабль
            else battlefield[x + i][y] = 1;            // Вертикальный корабль
        }
        break; // Корабль успешно поставлен
    }
}
// Функция AllShipsPlace (Координатор расстановки флота) размещает все корабли на поле боя. Расстановка идет от больших кораблей к меньшим.
void AllShipsPlace(int battlefield[size_battlefield][size_battlefield]) {
    ShipPlace(battlefield, 4);        //один Линкор (4 клетки)
    for (int i = 0; i < 2; i++) ShipPlace(battlefield, 3); //два Крейсера (3 клетки)
    for (int i = 0; i < 3; i++) ShipPlace(battlefield, 2); //три Эсминца (2 клетки)
    for (int i = 0; i < 4; i++) ShipPlace(battlefield, 1); //четыре Катера (1 клетка)
}
// ---Проверка состояния корабля---
// Функция isKilled осуществляет проверку целостности корабля
// Проверка, убит ли корабль после попадания в клетку x,y
bool isKilled(int battlefield[size_battlefield][size_battlefield], int x, int y) {
    // Массивы направлений dx и dy  для проверки соседних клеток (вверх, вниз, вправо, влево)  
    int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
    for (int i = 0; i < 4; i++) { // Цикл по 4 направлениям
        int nx = x + dx[i], ny = y + dy[i]; // Вычисляем координаты соседней клетки nx и ny
        // Проверка выхода за границы поля
        if (nx < 0 || nx >= size_battlefield || ny < 0 || ny >= size_battlefield) continue;
        // Цикл для проверки всех клеток корабля в текущем направлении
        while (nx >= 0 && nx < size_battlefield && ny >= 0 && ny < size_battlefield &&
            (battlefield[nx][ny] == 1 || battlefield[nx][ny] == 2)) {
            if (battlefield[nx][ny] == 1) return false; // Если найдена живая часть корабля, корабль не потоплен

            // Переходим к следующей клетке в текущем направлении для nx и ny
            nx += dx[i];
            ny += dy[i];
            // Проверка выхода за границы поля внутри цикла
            if (nx < 0 || nx >= size_battlefield || ny < 0 || ny >= size_battlefield) break;
        }
    }
    return true; // Корабль потоплен
}
// ---Псевдографика поля битвы---
// Функция printbattlefields выводит два поля битвы: игрока и компьютера, с цветами и символами
// cbattlefield — поле компьютера
// pbattlefield — поле игрока
// showEnemyShips — показывать ли корабли компьютера (false)
// showPlayerShips — показывать ли корабли игрока (true)
void printbattlefields(int cbattlefield[size_battlefield][size_battlefield], int pbattlefield[size_battlefield][size_battlefield], bool showEnemyShips, bool showPlayerShips) {
    // Вывод заголовков полей
    cout << "\n          "; // отступ слева для выравнивания
    SetColor(12);
    cout << "\tПоле противника (компьютер)";
    ResetColor();
    cout << "                      ";// расстояние между полями
    SetColor(10);
    cout << "\tВаше поле (игрок)";
    ResetColor();
    cout << "\n";
    // Верхние границы и буквы столбцов
    SetColor(8);
    cout << "    +---+";
    for (int j = 0; j < size_battlefield; j++) cout << "---+";// рисуем верхнюю границу для поля компьютера
    cout << "      +---+";
    for (int j = 0; j < size_battlefield; j++) cout << "---+"; // верхняя граница поля игрока
    // Строка с буквами (координаты по горизонтали)
    cout << "\n    |   |";
    for (int j = 0; j < size_battlefield; j++) {
        SetColor(3);
        cout << " " << COLS[j] << " "; // Буквы для компьютера
        SetColor(8);
        cout << "|";
    }
    cout << "      |   |";
    for (int j = 0; j < size_battlefield; j++) {
        SetColor(11);
        cout << " " << COLS[j] << " "; // Буквы для игрока
        SetColor(8);
        cout << "|";
    }
    // Нижняя граница заголовка
    cout << "\n    +---+";
    for (int j = 0; j < size_battlefield; j++) cout << "---+";
    cout << "      +---+";
    for (int j = 0; j < size_battlefield; j++) cout << "---+";
    cout << "\n";
    // Отрисовка строк поля
    for (int i = 0; i < size_battlefield; i++) { // Цикл по строкам
// --- Левое поле (компьютер) ---
        SetColor(8);
        cout << "    |";
        SetColor(3);
        cout << setw(2) << i + 1 << " "; //номер строки
        SetColor(8);
        cout << "|";
        for (int j = 0; j < size_battlefield; j++) {
            cout << " ";
            if (cbattlefield[i][j] == 2) {
                SetColor(12);
                cout << "X";  //попал
            }
            else if (cbattlefield[i][j] == -1) {
                SetColor(1);
                cout << "o"; //мимо
            }
            else if (cbattlefield[i][j] == -2) {
                SetColor(8);
                cout << "o"; // зона вокруг убитого корабля
            }
            else if (cbattlefield[i][j] == 1 && showEnemyShips) {
                SetColor(13);
                cout << "S"; //корабли ПК
            }
            else cout << " "; //пустая клетка
            SetColor(8);
            cout << " |"; //граница клетки
        }
        cout << "      "; //отступ между полями
        // --- Правое поле (игрок) ---
        SetColor(8);
        cout << "|";
        SetColor(11);
        cout << setw(2) << i + 1 << " "; //номер строки
        SetColor(8);
        cout << "|";
        for (int j = 0; j < size_battlefield; j++) {
            cout << " ";
            if (pbattlefield[i][j] == 2) {
                SetColor(4);
                cout << "X"; //попал
            }
            else if (pbattlefield[i][j] == -1) {
                SetColor(9);
                cout << "o"; //мимо
            }
            else if (pbattlefield[i][j] == -2) {
                SetColor(8);
                cout << "o";// зона вокруг убитого корабля
            }
            else if (pbattlefield[i][j] == 1 && showPlayerShips) {
                SetColor(10);
                cout << "S"; //корабли игрока
            }
            else cout << " ";
            SetColor(8);
            cout << " |";
        }
        // Нижняя граница строки
        cout << "\n    +---+";
        for (int j = 0; j < size_battlefield; j++) cout << "---+";
        cout << "      +---+";
        for (int j = 0; j < size_battlefield; j++) cout << "---+";
        cout << "\n";
    }
    ResetColor();
}
// Функция targetExists проверяет, существует ли цель в списке ПК
bool targetExists(int x, int y) { // Проходим циклом по всем координатам, которые уже лежат в очереди на обстрел
    for (int i = 0; i < targetCount; i++) // Цикл по всем текущим целям ПК
        if (targetsX[i] == x && targetsY[i] == y) return true; // Подтверждаем: такая цель уже существует
    return false; // Если прошли весь цикл и совпадений не нашли — цель новая
}
// Функция addTarget добавляет соседние клетки в список целей ПК.Она выполняет роль "фильтра", не позволяя добавлять координаты за пределами 
//поля (например, отрицательные) или клетки, в которые уже стреляли.
void addTarget(int x, int y, int battlefield[size_battlefield][size_battlefield]) {
    if (targetCount >= 100) return; // защита от переполнения массива целей
    if (x >= 0 && x < size_battlefield && y >= 0 && y < size_battlefield && battlefield[x][y] != 2 && battlefield[x][y] != -1 && battlefield[x][y] != -2 && !targetExists(x, y)) {
        //Проверка границ: x и y должны быть в диапазоне от 0 до 9 (внутри поля) if (x >= 0 && x < size_battlefield && y >= 0 && y < size_battlefield &&
        //Проверка на попадание: в этой клетке еще не должно быть отметки "ранил" (2) battlefield[x][y] != 2 &&
        //Проверка на промах: в этой клетке еще не должно быть отметки "мимо" (-1) battlefield[x][y] != -1 &&
        //Проверка на уникальность: вызываем targetExists, чтобы не добавить одну и ту же цель дважды !targetExists(x, y)) {
        // Если все проверки пройдены — записываем координаты в "память"
        targetsX[targetCount] = x; // Сохраняем строку
        targetsY[targetCount] = y; // Сохраняем столбец
        targetCount++; // Увеличиваем счетчик целей
    }
}
// Функция markSurroundings помечает клетки вокруг потопленного корабля
// Используется значение -2 (запрещённая зона вокруг корабля)
void markSurroundings(int battlefield[size_battlefield][size_battlefield], int x, int y) {
    int nx, ny;
    // --- Горизонтальный корабль ---
    nx = x; // фиксируем строку (горизонтальный корабль лежит по столбцам)
    ny = y; // начинаем с точки попадания
    // Идём влево, чтобы найти начало корабля
    // Пока встречаем клетки корабля (1 или 2), продолжаем движение
    while (ny >= 0 && (battlefield[nx][ny] == 2 || battlefield[nx][ny] == 1)) ny--;
    ny++; // возвращаемся на первую клетку корабля
    // Идём враво по всем палубам корабля
    while (ny < size_battlefield && (battlefield[nx][ny] == 2 || battlefield[nx][ny] == 1)) {
        // Обходим все соседние клетки вокруг текущей палубы (включая диагонали)
        for (int dx1 = -1; dx1 <= 1; dx1++)
            for (int dy1 = -1; dy1 <= 1; dy1++) {
                int cx = nx + dx1; // соседняя строка
                int cy = ny + dy1; // соседний столбец
                // Проверяем, что не вышли за границы поля
                if (cx >= 0 && cx < size_battlefield && cy >= 0 && cy < size_battlefield)
                    // Если клетка пустая — помечаем её как "зона вокруг корабля"
                    if (battlefield[cx][cy] == 0)
                        battlefield[cx][cy] = -2;
            }
        ny++; // переходим к следующей палубе вправо
    }
    // --- Вертикальный корабль ---
    nx = x; // начинаем с точки попадания
    ny = y; // фиксируем столбец (вертикальный корабль идёт по строкам)
    // Идём ВВЕРХ, чтобы найти начало корабля
    while (nx >= 0 && (battlefield[nx][ny] == 2 || battlefield[nx][ny] == 1)) nx--;
    nx++; // возвращаемся на первую палубу корабля
    // Идём ВНИЗ по всем палубам корабля
    while (nx < size_battlefield && (battlefield[nx][ny] == 2 || battlefield[nx][ny] == 1)) {
        // Обходим все соседние клетки вокруг текущей палубы
        for (int dx1 = -1; dx1 <= 1; dx1++)
            for (int dy1 = -1; dy1 <= 1; dy1++) {
                int cx = nx + dx1; // соседняя строка
                int cy = ny + dy1; // соседний столбец
                // Проверка границ поля
                if (cx >= 0 && cx < size_battlefield && cy >= 0 && cy < size_battlefield)
                    // Помечаем только пустые клетки
                    if (battlefield[cx][cy] == 0)
                        battlefield[cx][cy] = -2; // зона вокруг корабля
            }
        nx++; // следующая палуба вниз
    }
}
// --- Ход компьютера---
// Функция computerTurn рекурсивна и реализует интеллектуальный алгоритм поведения противника (ИИ). 
// В отличие от простого случайного выбора координат, данный компьютер умеет «добивать» раненые корабли, используя логику поиска.
// Возвращает true, если компьютер попал и может стрелять снова
bool computerTurn(int battlefield[size_battlefield][size_battlefield], int& pCells) {
    int x, y; // Координаты выстрела (переменные x и y)
    if (isHunting && targetCount > 0) { // Режим охоты после попадания
        targetCount--; //уменьшаем счетчик, тем самым «забирая» координату из списка.Это работает по принципу LIFO(Last In, First Out — последним пришел, первым ушел)
        x = targetsX[targetCount];// Присваиваем переменной x значение из массива целей по текущему индексу из стека
        y = targetsY[targetCount];// Присваиваем переменной y значение из массива целей по текущему индексу
        if (battlefield[x][y] == 2 || battlefield[x][y] == -1 || battlefield[x][y] == -2) return computerTurn(battlefield, pCells);// Рекурсивный самовызов, если в эту точку уже стреляли (защита от повторов) 
    }
    else // ---Режим поиска---
    { // Случайный выстрел
        do
        { //генерация случайных координат x и y
            x = rand() % size_battlefield;
            y = rand() % size_battlefield;
        } while (battlefield[x][y] == 2 || battlefield[x][y] == -1 || battlefield[x][y] == -2); //защита от повторных выстрелов
        //Условие: Цикл заставляет компьютер перевыбирать x и y, если в выбранной клетке уже стоит -1 (промах) или 2 (попадание).
        //Без этой проверки компьютер мог бы стрелять в одно и то же место несколько раз подряд, тратя свои ходы впустую.
    }
    // Проверка попадания
    if (battlefield[x][y] == 1) { // Если попал в палубу
        battlefield[x][y] = 2; pCells--; // Ранил
        if (isKilled(battlefield, x, y)) { // Если корабль потоплен — выключаем режим охоты
           //Сброс режима «Охоты»
            isHunting = false; //Сообщает компьютеру, что текущая цель полностью уничтожена.
            targetCount = 0; //очистка «памяти». Если компьютер подбил двухпалубный корабль, в списке целей могли остаться лишние клетки
            //(например, если он сначала ударил по одной палубе, добавил 4 цели, а вторым ходом сразу добил вторую). Чтобы в следующий раз 
            //компьютер не стрелял по пустому месту вокруг уже потопленного корабля, полностью обнуляем список запланированных ходов.
            markSurroundings(battlefield, x, y); // Помечаем область вокруг корабля как запрещенную
            //Это нужно для того, чтобы игрок или ИИ не стреляли по соседним клеткам, так как согласно правилам «Морского боя» корабли не соприкасаются.
            SetRandomColor();
            cout << "Компьютер: Потопил корабль в " << COLS[y] << x + 1 << "!\n";
            ResetColor();
        }
        else { //Если только ранил — активируем режим охоты и добавляем 4 соседние клетки в список целей
            isHunting = true; //Активация режима «Охоты»
            addTarget(x + 1, y, battlefield); // Снизу
            addTarget(x - 1, y, battlefield); // Сверху
            addTarget(x, y + 1, battlefield); // Справа
            addTarget(x, y - 1, battlefield); // Слева
            SetRandomColor();
            cout << "Компьютер: Ранил корабль в " << COLS[y] << x + 1 << "!\n";
            ResetColor();
        }
        Sleep(1500);
        return true;  // Компьютер стреляет снова (используется право на повторный ход)!
    }
    else { // Промах
        battlefield[x][y] = -1; // Фиксируем промах в массиве, чтобы не стрелять сюда повторно и отобразить "o"
        SetRandomColor();
        cout << "Компьютер: Мимо в " << COLS[y] << x + 1 << "!\n";
        ResetColor();
        Sleep(1000);
        return false; // Ход передаётся игроку
    }
}
int main() {
    system("chcp 1251>NUL"); // Установка кодировки консоли 
    srand((unsigned int)time(nullptr)); // Инициализация генератора случайных чисел
    SetConsoleTitleA("Морской Бой: Игрок против компьютера"); // Заголовок окна
    char playAgain;
    do {
        system("cls");
        targetCount = 0;
        isHunting = false;
        // Массивы поля игрока и компьютера
        // 0 — пустая клетка, 1 — корабль, 2 — попадание, -1 — промах
        int pbattlefield[size_battlefield][size_battlefield] = { 0 };
        int cbattlefield[size_battlefield][size_battlefield] = { 0 };

        AllShipsPlace(pbattlefield); // Расстановка кораблей игрока
        AllShipsPlace(cbattlefield); // Расстановка кораблей компьютера

        int pCells = 20, cCells = 20; // Количество живых клеток кораблей для игрока и компьютера
        bool pTurn = true;             // Флаг чей ход: true = игрок, false = компьютер

        // --- Главный цикл игры ---
        while (pCells > 0 && cCells > 0) {
            system("cls"); // Очистка консоли
            printbattlefields(cbattlefield, pbattlefield, false, true); // Вывод полей

            if (pTurn) { // Ход игрока
                SetColor(14);
                cout << "\n--- Ваш ход ---\n";
                ResetColor();

                // Координаты выстрела игрока
                char colChar;
                int rowNum;
                SetRandomColor();
                cout << "Введите координаты, например А1: ";
                ResetColor();

                if (!(cin >> colChar >> rowNum)) {
                    cin.clear();
                    cin.ignore(LLONG_MAX, '\n');
                    continue;
                }

                // Переводим введенную букву в индекс колонки (y)
                int y = -1;
                // Поддерживаем русские и английские буквы (большие и маленькие) для защиты от ошибок раскладки
                char validCols[] = "АБВГДЕЖЗИКабвгдежзикABCDEFGHIJabcdefghij";
                for (int i = 0; i < 40; i++) {
                    if (colChar == validCols[i]) {
                        y = i % 10;
                        break;
                    }
                }
                // Переводим введенную цифру в индекс строки (x)
                int x = rowNum - 1;
                if (x < 0 || x >= size_battlefield || y < 0 || y >= size_battlefield) { // Проверка границ
                    SetColor(12);
                    cout << "Ошибка: Неверные координаты! Вводите от А до К и от 1 до 10.";
                    ResetColor();
                    Sleep(750);
                    continue;
                }
                if (cbattlefield[x][y] == 2 || cbattlefield[x][y] == -1) { // Проверка повторного выстрела
                    SetColor(13);
                    cout << "Вы сюда уже стреляли! Попробуйте другие координаты.";
                    ResetColor();
                    Sleep(2000);
                    continue;
                }
                if (cbattlefield[x][y] == -2) {
                    SetColor(12);
                    cout << "Зона вокруг потопленного корабля!";
                    ResetColor();
                    Sleep(1500);
                    continue;
                }
                if (cbattlefield[x][y] == 1) { // Попадание
                    cbattlefield[x][y] = 2; cCells--;
                    bool killed = isKilled(cbattlefield, x, y); //Проверяем, уничтожен ли корабль после попадания в клетку(x, y).
                    if (killed) {
                        markSurroundings(cbattlefield, x, y);// помечает все клетки вокруг потопленного корабля как зону вокруг потопленного корабля (-2), включая диагонали для игрока
                    }
                    SetColor(10);
                    cout << (killed ? "Потопил!" : "Ранил!"); // Используется для краткой записи условного вывода результата попадания.
                    ResetColor();
                    Sleep(1200);
                    // Ход не передаётся компьютеру — игрок стреляет снова!
                }
                else { // Промах
                    cbattlefield[x][y] = -1;
                    SetRandomColor();
                    cout << "Мимо!";
                    ResetColor();
                    pTurn = false; // Ход передаётся компьютеру
                    Sleep(3000);
                }
            }
            else { // Ход компьютера
                SetColor(11);
                cout << "\n--- Ход компьютера ---\n";
                ResetColor();
                if (!computerTurn(pbattlefield, pCells)) pTurn = true; // Если промах — ход игрока
            }
        }
        // --- Конец игры ---
        system("cls");
        if (cCells == 0) {
            SetRandomColor();
            cout << "\nПобеда! Вы потопили все корабли противника!\n";
            ResetColor();
        }
        else {
            SetRandomColor();
            cout << "\nПоражение! Все ваши корабли потоплены!\n";
            ResetColor();
        }
        Sleep(1500);
        SetRandomColor();
        cout << "\nСыграем ещё? (y/n) ";
        ResetColor();
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    if (playAgain == 'n' || playAgain == 'N') {
        SetRandomColor();
        cout << "Для выхода из программы нажмите любую клавишу...";
        ResetColor();
        system("pause > NUL");
    }
}
