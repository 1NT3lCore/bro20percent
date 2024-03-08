#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int cnt = 0;
    int* A = new int[10];
    for (int i = 0; i < 10; ++i) {
        A[i] = rand() % 100;
    }
    int* ptrA = A;

    int sum = 0;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (*(ptrA + i) > 0 && *(ptrA + i) % 5 == 0) {
            sum += *(ptrA + i);
            ++count;
        }
    }

    std::cout << "Сгенерированный массив из 10 элементов: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << *(ptrA + i) << " ";
    }

    std::cout << "Сумма положительных элементов кратных 5: " << sum << std::endl;
    std::cout << "Количество таких элементов: " << count << std::endl;
    return 0;
}