#include <iostream>

void fillArray(int* arr, int size) {
    std::srand(std::time(nullptr)); 
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 50 + 1; // Заполняем массив случайными числами от 1 до 50
    }
}

void findPairs(int* mass, int l, int d) { //функция выводит на экран все пары элементов массива, разность которых равна заданному числу (задается пользователем)
    std::cout << "Пары элементов с разностью " << d << ":" << std::endl;
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {
            if (mass[i] - mass[j] == d) {
                std::cout << "(" << mass[i] << ", " << mass[j] << ")" << std::endl;
            }
        }
    }
}
void printer(int* arr, int size) { //отдельная функция для вывода массива на экран
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int size = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    fillArray(arr, size);
    printer(arr, size);

    int difference;
    std::cout << "Введите число для разности: ";
    std::cin >> difference;

    findPairs(arr, size, difference);

    delete[] arr;
    return 0;
}



















