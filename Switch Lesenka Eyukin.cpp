// Switch Lesenka Eyukin
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "---Программа расчета скидки!---" << endl;

    double summa = 0.0;
    cout << "Введите сумму покупки: ";
    cin >> summa;
    //switch работает только с готовым целым значением,
    //а определение, является ли сумма корректной(summa <= 0), — это условие
    //любое сравнение(> , < , >= , <= ) — это условие
    if (summa <= 0)
    {
        cout << "Некорректная сумма!" << endl;
        cout << "Для выхода из программы нажмите любую клавишу..." << endl;
        system("pause > NUL");
        return 0;
     }
 // Определяем уровень скидки: 0..5 через тернарные операторы
    //int level =
      //  (summa >= 5000) ? 0 :
       // (summa >= 4000) ? 1 :
       // (summa >= 3000) ? 2 :
       // (summa >= 2000) ? 3 :
       // (summa >= 1000) ? 4 :
       // 5;
    int level=0;  
    if (summa >= 5000) level = 0;
    else if (summa >= 4000) level = 1;
    else if (summa >= 3000) level = 2;
    else if (summa >= 2000) level = 3;
    else if (summa >= 1000) level = 4;
    else level = 5; 
    switch (level)
    {
    case 0:
        cout << "Ваша скидка 25%, это максимальная скидка! К оплате: "
            << summa * 0.75 << " руб." << endl;
        break;
    case 1:
        cout << "Ваша скидка 20%, до скидки в 25% не хватает "
         << 5000.0 - summa << " руб. К оплате: " << summa * 0.8 << " руб." << endl;
        break;
    case 2:
        cout << "Ваша скидка 15%, до скидки в 20% не хватает "
        << 4000.0 - summa << " руб. К оплате: " << summa * 0.85 << " руб." << endl;
        break;
    case 3:
        cout << "Ваша скидка 10%, до скидки в 15% не хватает "
        << 3000.0 - summa << " руб. К оплате: " << summa * 0.9 << " руб." << endl;
        break;
    case 4:
        cout << "Ваша скидка 5%, до скидки в 10% не хватает "
        << 2000.0 - summa << " руб. К оплате: " << summa * 0.95 << " руб." << endl;
        break;
    case 5:
        cout << "Ваша скидка 0%, до скидки в 5% не хватает "
        << 1000.0 - summa << " руб. К оплате: " << summa << " руб." << endl;
        break;
    }

    cout << "Для выхода из программы нажмите любую клавишу..." << endl;
    system("pause > NUL");
}
