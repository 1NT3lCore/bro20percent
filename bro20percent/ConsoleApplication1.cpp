#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int cnt = 0;
    int* A = new int[10];
    int* ptrA = A;

    for (int i = 0; i < 10; ++i) {
        *ptrA = rand() % 100;
        ptrA++;
    }

    int sum = 0;
    int count = 0;
    ptrA = A;
    for (int i = 0; i < 10; i++) {
        if (*ptrA > 0 && *ptrA % 5 == 0) {
            sum += *ptrA;
            ++count;
        }
        ptrA++;
    }

    std::cout << "Сгенерированный массив из 10 элементов: ";
    ptrA = A;
    for (int i = 0; i < 10; ++i) {
        std::cout << *ptrA << " ";
        ptrA++;
    }

    std::cout << "Сумма положительных элементов кратных 5: " << sum << std::endl;
    std::cout << "Количество таких элементов: " << count << std::endl;
    return 0;
}