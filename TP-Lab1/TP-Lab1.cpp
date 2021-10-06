#include <iostream>
#include <locale>
#include <fstream>
#include "Keeper.h"
#include "VUZ.h"
#include "Student.h"
#include "Teacher.h"
#include "Administration.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
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
    else if (in.peek() == EOF or in.peek() <1) {
        cout << "Файл пуст или данные испорчены\n";
        base = new Keeper();
    }
    else {
        base = new Keeper(in);
    }
}
