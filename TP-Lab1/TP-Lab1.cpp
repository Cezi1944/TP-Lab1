#include <iostream>
#include <locale>
#include <fstream>
#include <windows.h>
#include "Keeper.h"
#include "VUZ.h"
#include "Student.h"
#include "Teacher.h"
#include "Administration.h"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Hello World!\n";
    ifstream in;
    ofstream out;
    Keeper* base = NULL;
    int i = 0;
    in.open("D:\\учёба\\Третий курс\\TP\\TP Lab1\\TP-Lab1\\Save.txt");
    if (!in)
    {
        printf("Не удалось открыть файл");
        system("pause");
        return 0;
    }
    base = new Keeper();
    base->loadData(in);
    in.close();
    int choise = -1;
    do {
        system("cls");
        base->printData();
        cout << "1.Загрузка данных из файла\n2.Сохранение данных\n3.Изменить данные\n4.Добавить данные\n5.Удалить данные\n0.Выход";
        cout << endl << "Выберите действие: ";
        while (!(cin >> choise) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Неверный ввод!" << endl;
        }
        switch (choise)
        {
        case 1:
            in.open("D:\\учёба\\Третий курс\\TP\\TP Lab1\\TP-Lab1\\Save.txt");
            if (!in)
            {
                printf("Не удалось открыть файл");
                system("pause");
                return 0;
            }
            try {
                base->loadData(in);
            }
            catch (string ex) {
                cout << "ОШИБКА!!!" << endl << ex << endl;
            }
            in.close();
            break;
        case 2:
            out.open("D:\\учёба\\Третий курс\\TP\\TP Lab1\\TP-Lab1\\Save.txt");
            if (!out)
            {
                printf("Не удалось открыть файл");
                system("pause");
                return 0;
            }
            base->saveData(out);
            out.close();
            break;
        case 3:
            base->changeData();
            break;
        case 4:
            try {
                base->addData();
            }
            catch (string ex){
                cout << "ОШИБКА!!!" << endl << ex << endl;
            }
            break;
        case 5:
            base->destroyData();
            break;
        case 0:
            cout << endl << "Завершение работы.";
            break;
        default:
            break;
        }
    } while (choise != 0);
    delete base;
}
