#include <iostream>
#include <iomanip>
#include <random>

void randomnum(int a[], int size) {
    const int MIN_VALUE = -100;
    const int MAX_VALUE = 100;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

    for (int i = 0; i < size; ++i) {
        a[i] = distribution(generator);
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(4) << a[i];
    }
    std::cout << std::endl;
}

int negetiveellements(int a[], int size, int& count) {
    count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            ++count;
           
        }
    }
    return count;
}


template <typename T>
int negetiveellementsT(T a[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] < 0) {
            ++count;
        }
    }
    return count;
}

int main() {
    const int size = 10;
    int a[size];

    randomnum(a, size);

    std::cout << "Array elements: ";
    printArray(a, size);

    int count;

    negetiveellements(a, size, count);

    std::cout << "Number of negative elements: " << count << std::endl;

    int countRecursiveTemplate = negetiveellementsT(a, size);
    std::cout << "Number of negative elements Template: " << countRecursiveTemplate << std::endl;

    return 0;
}
