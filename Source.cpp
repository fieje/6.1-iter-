#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void fillArray(int arr[]) {
    for (int i = 0; i < 25; i++) {
        arr[i] = rand() % (73 - 4 + 1) + 4;
    }
}

void printArray(const int arr[]) {
    for (int i = 0; i < 25; i++) {
        std::cout << std::setw(4) << arr[i];
    }
    std::cout << std::endl;
}

void processArray(int arr[], int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < 25; i++) {
        if (arr[i] % 6 == 0 || !(i % 5 == 0)) {
            count++;
            sum += arr[i];
            arr[i] = 0;
        }
    }
}
int* copyArray(int* arr, int size) {
    int* carr = new int[size];
    for (int i = 0; i < size; i++) {
        carr[i] = arr[i];
    }
    return carr;
}
int main() {
    std::srand(std::time(0));

    int myArray[25];
    int count, sum;

    fillArray(myArray);
    std::cout << "Original Array: ";
    printArray(myArray);

    processArray(myArray, count, sum);
    std::cout << "Modified Array: ";
    printArray(myArray);
    std::cout << "Count of elements satisfying the criteria: " << count << std::endl;
    std::cout << "Sum of elements satisfying the criteria: " << sum << std::endl;

    return 0;
}