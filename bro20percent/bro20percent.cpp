#include <iostream>
#include <ctime>
#include <cstdlib>

void printArray(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << *arr << " ";
        arr++;
    }
    std::cout << std::endl;
}

void randomizeArray(float* arr, int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        *arr = (rand() % 201 - 100) / 10.0;
        arr++;
    }
}

bool isEqual(float a, float b, float epsilon) {
    return std::abs(a - b) < epsilon;
}

    int countLessThanC(float* arr, int n, float c) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (*arr < c) {
                count++;
            }
            arr++;
        }
        return count;
    }

    float* findLastNegative(float* arr, int n) {
        float* lastNegative = nullptr;
        for (int i = 0; i < n; i++) {
            if (*arr < 0) {
                lastNegative = arr;
            }
            arr++;
        }
        return lastNegative;
    }


    float sumOfWholePartsAfterLastNegative(float* arr, int n) {
        float* lastNeg = findLastNegative(arr, n);
        float* tempPtr = lastNeg;
        float sum = 0;

        if (lastNeg != nullptr) {
            sum -= static_cast<int>(*tempPtr);
            for (int i = 0; i < (n - (lastNeg - arr)); i++) {
                sum += static_cast<int>(*tempPtr);
                tempPtr++;
            }
        }

        return sum;
    }

    int main() {
        srand(time(nullptr));
        int n;
        std::cout << "Enter the number of elements in the array: ";
        std::cin >> n;

        float* arr = new float[n];
        float* ptr = arr;
        randomizeArray(arr, n);
        std::cout << "Generated array:" << std::endl;
        printArray(arr, n);


        float c;
        std::cout << "Enter the value of C: ";
        std::cin >> c;
        int count = countLessThanC(arr, n, c);
        std::cout << "Number of elements less than " << c << ": " << count << std::endl;


        float sumAfterNegative = sumOfWholePartsAfterLastNegative(arr, n);


        std::cout << "Sum of integer parts after the last negative number: " << sumAfterNegative << std::endl;


        delete[] arr;

        return 0;
    }
