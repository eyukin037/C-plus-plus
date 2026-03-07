// Dice 4.0 Eyukin
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
int main()
{
    system("chcp 1251 > NUL");
    //аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    //заголовок программы на рамке окна консоли
    SetConsoleTitleA("---Корсары. Игра в кости!---");
    //заголовок программы на экране консоли
    cout << "---Корсары. Игра в кости!---" << endl;
    //Объявлем переменные: баланс, ставка, броски компьютера и игрока, значения выпавшие на кубиках, ходы, цвета кубиков
    int cash = 0, bet = 0, strike_pc = 0, strike_player = 0, strike_dice_1 = 0, strike_dice_2 = 0, moves = 0, diceColor1 = 0, diceColor2 = 0;
    HANDLE h{}; //"переменная" для хранения дескриптора окна консоли нашей программы
    h = GetStdHandle(STD_OUTPUT_HANDLE);  //получаем информацию об окне консоли про отображаемые в ней данные
    //Цвета по умолчанию, Фон - 0 Черный, Текст 7 - Светло-Серый 
    //цикл проверки пользовательского ввода cash
    do
    {
        ////I Вариант
//cout << "Выворачивай карманы! ";  
//SetConsoleTextAttribute(h, 0x06);   
//cin >> cash;
//SetConsoleTextAttribute(h, 0x07);
//II Вариант
        cout << "Выворачивай карманы! \033[33m";
        cin >> cash;
        cout << "\033[0m";

        if (cash < 0)cout << "Кошелек прохудился?" << endl;
        //При вводе символов вместо числа программа завершает работу
        cin.ignore(LLONG_MAX, '\n');   //для удаления из буфера дробной части при вводе дробного числа 
    } while (cash < 0);
    //условие выхода из игры, то есть условие не входа в цикл повторной игры 
    if (cash == 0)cout << "Не хочешь играть? Тогда прощай!" << endl;
    //цикл повторной игры
    while (cash > 0) //while (cash != 0)
    {
        system("cls"); //очистка экрана консоли перед новым раундом
        //bet=0; strike_dice = 0; //пока не требуется
        strike_pc = 0; strike_player = 0; //для надежности
        cout << "---Деньги на бочку!---" << endl;
        cout << "У тебя в карманах: \033[33m" << cash << "\033[0m пиастров!" << endl;
        //цикл проверки пользовательского ввода ставки bet
        do
        {
            cout << "Сколько ставишь? \033[34m"; cin >> bet;
            SetConsoleTextAttribute(h, 0x07);
            if (bet > cash)cout << "А денег-то хватает?" << endl;
            if (bet < 0)cout << "Денег нет? Корабль поставишь?" << endl;
            cin.ignore(LLONG_MAX, '\n');   //для удаления из буфера дробной части при вводе дробного числа 
        } while (bet<0 || bet>cash);
        //условие выхода из игры
        if (bet == 0)
        {
            cout << "Ну ты и слабак! Проваливай!" << endl;
            break; //выход из цикла повторной игры while(cash>0)
        }
        //если ставка корректная и можно играть
        //цикл из бросков двух кубиков
        SetConsoleTextAttribute(h, 8); // серый
        cout << "\n--------------------------------\n\n";
        SetConsoleTextAttribute(h, 7);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN); // жёлтый
        cout << "          Ход #" << moves + 1 << endl;
        SetConsoleTextAttribute(h, 0x07);
        for (int i = 1; i <= 2; i++) //i==1 - бросок Пирата(Компьютера), i==2 - бросок Корсара(Игрока)
        {
            strike_dice_1 = 1 + rand() % 6; //делаем бросок первого кубика
            strike_dice_2 = 1 + rand() % 6; //делаем бросок второго кубика
            if (i == 1)
            {
                strike_pc = strike_dice_1 + strike_dice_2;
                cout << "\nУ \033[4;35mПирата (Компьютера)\033[0m выпало: \n";
                //SetConsoleTextAttribute(h, 0x04); //раскрашиваем кубик Пирата в красный цвет
                //SetConsoleTextAttribute(h, FOREGROUND_RED); //аналогично
                //cout << " У Пирата (Компьютера) выпало: ";
            }
            else
            {
                strike_player = strike_dice_1 + strike_dice_2;
                cout << "\nУ \033[4;34mКорсара (Игрока)\033[0m выпало: \n";
                //SetConsoleTextAttribute(h, 0x02); //раскрашиваем кубик Корсара в зеленый цвет
                //SetConsoleTextAttribute(h, FOREGROUND_GREEN); //аналогично

               // cout << " У Корсара (Игрока) выпало: ";
            }
            // случайный читаемый цвет для кубиков
            do {diceColor1 = rand() % 15 + 1; } while (diceColor1 == 1 || diceColor1 == 8);
            do {diceColor2 = rand() % 15 + 1;} while (diceColor2 == 1 || diceColor2 == 8 || diceColor2 == diceColor1);
            //не важно чей бросок, кубик рисуется одинаково
            switch (strike_dice_1) {
            case 1:
                switch (strike_dice_2)
                {
                case 1:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _ _|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _ _|\n";
                    SetConsoleTextAttribute(h, 7); // вернуть стандартный цвет
                    break;
                case 2:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _ _|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";

                    SetConsoleTextAttribute(h, 7);
                    break;
                case 3:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _ _|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";

                    SetConsoleTextAttribute(h, 7);
                    break;

                case 4:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _ _|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";

                    SetConsoleTextAttribute(h, 7);
                    break;
                case 5:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _ _|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";

                    SetConsoleTextAttribute(h, 7);
                    break;
                case 6:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _ _|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";

                    SetConsoleTextAttribute(h, 7);
                    break;
                }
                break;
            case 2:
                switch (strike_dice_2)
                {
                case 1:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _ _|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 2:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 3:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 4:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 5:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 6:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;
                }
                break;

            case 3:
                switch (strike_dice_2)
                {
                case 1:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _ _|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 2:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 3:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 4:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 5:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 6:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| *   |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_ _*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;
                }
                break;
            case 4:
                switch (strike_dice_2)
                {
                case 1:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _ _|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 2:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 3:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 4:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 5:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 6:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|     |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;
                }
                break;

            case 5:
                switch (strike_dice_2)
                {
                case 1:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _ _|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 2:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 3:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 4:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 5:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 6:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|  *  |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;
                }
                break;

            case 6:
                switch (strike_dice_2)
                {
                case 1:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _ _|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 2:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 3:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | *   |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_ _*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 4:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |     |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 5:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |  *  |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;

                case 6:
                    SetConsoleTextAttribute(h, diceColor1);
                    cout << " _ _ _";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << "   _ _ _\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "| * * |";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " | * * |\n";

                    SetConsoleTextAttribute(h, diceColor1);
                    cout << "|_*_*_|";
                    SetConsoleTextAttribute(h, diceColor2);
                    cout << " |_*_*_|\n";
                    SetConsoleTextAttribute(h, 7);
                    break;
                }
                break;
            }

            //возвращаем цвет текста обратно на светло-серый(Белый)
            SetConsoleTextAttribute(h, 0x07);
            //если после бросков Пирата(Компьютера) и Корсара(Игрока) ничья
            if (i == 2 && strike_pc == strike_player) //i==4 - после бросков обоих участников игры  
            {
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                cout << "\nНичья! Нужно перебросить!" << endl;
                SetConsoleTextAttribute(h, 0x07);
                Sleep(50); //задержка работы программы перед повторными бросками
                strike_pc = 0;
                strike_player = 0; //для надежности
                //устанавливаем значение счетчика на значение перед броском Пирата(Компьютера)
                //учитывая что сработает i++
                i = 0;
            }
        }
        //определение победителя
        moves++;
        if (strike_pc > strike_player) //условие победы Пирата(Компьютера)
        {
            cout << "\nТебе не везет! Ха-Ха-Ха!!!" << endl;
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Пират (Компьютер) выиграл!" << endl;
            SetConsoleTextAttribute(h, 0x07);
            cash -= bet; //cash=cash-bet; //вычитаем ставку из баланса
            cout << "У тебя осталось: \033[33m" << cash << "\033[0m пиаcтров!" << endl;
            if (cash == 0) //если денег не осталось
            {
                cout << "Мы кредитов не выдаем! Прощай!" << endl;
                break; //выход из цикла повторной игры while(cash>0)
            }
        }
        else //иначе победа Корсара(Игрока)
        {
            cout << "\nАгрх! Тебе просто повезло!" << endl;
            SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "Корсар (Игрок) выиграл!" << endl;
            SetConsoleTextAttribute(h, 0x07);
            cash += bet; //cash=cash+bet; //прибавляем ставку к балансу
            cout << "У тебя теперь: \033[33m" << cash << "\033[0m пиаcтров!" << endl;
        }

    */? "\nТебе не везет! Ха-Ха-Ха!!!\n"
    : "\nАгрх! Тебе просто повезло!\n");

SetConsoleTextAttribute(
    h,
    (strike_pc > strike_player)
        ? (FOREGROUND_RED | FOREGROUND_INTENSITY)
        : (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
);

cout << ((strike_pc > strike_player)
    ? "Пират (Компьютер) выиграл!\n"
    : "Корсар (Игрок) выиграл!\n");

SetConsoleTextAttribute(h, 0x07);

// изменение баланса
cash += (strike_pc > strike_player) ? -bet : bet;

// вывод баланса
cout << ((strike_pc > strike_player)
    ? "У тебя осталось: "
    : "У тебя теперь: ")
    << "\033[33m" << cash << "\033[0m пиаcтров!" << endl;
 if (cash == 0) //если денег не осталось
            {
                cout << "Мы кредитов не выдаем! Прощай!" << endl;
                break; //выход из цикла повторной игры while(cash>0)
            }
/*
        cout << "Хочешь сыграть ещё? Жми любую клавишу!" << endl;
        system("pause > NUL"); //запрос нажатия любой клавиши для продолжения игры
    }
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Игра окончена!" << endl;
    SetConsoleTextAttribute(h, 0x07);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "Всего совершено ходов: " << moves << endl;
    SetConsoleTextAttribute(h, 0x07);
    Sleep(1500); //задержка работы программы в 1500 миллисекунд
}