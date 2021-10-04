#include <iostream>
#include <locale>
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";
}
