#include <iostream>
using namespace std;

// Перегруженная memory для одномерного массива
void memory(const char* name, int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << name << "[" << i << "] = " << (arr + i)
            << " значение = " << *(arr + i) << endl;
    }
}

// Перегруженная memory для двумерного массива (массив указателей)
void memory(const char* name, int** arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << "-я строка: адрес = " << (arr + i)
            << " значение = " << arr[i] << endl;
    }
}

void input(int* arr, int size) {
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
}

void output(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void output(int** arr, int size) {
    for (int i = 0; i < size; ++i)
        output(arr[i], size);
}

void calculation(int* arr1, int* arr2, int** result, int size) {
    for (int i = 0; i < size; ++i)
        result[0][i] = arr1[i] + arr2[i];

    for (int i = 0; i < size; ++i)
        result[1][i] = arr1[i] - arr2[i];

    for (int i = 0; i < size; ++i)
        result[2][i] = arr1[i] * arr2[i];
}

int main() {
    setlocale(LC_ALL, "RU");
    int size;
    cout << "Введите количество элементов в массивах: ";
    cin >> size;

    // Выделение памяти
    int* arr1 = new int[size];
    int* arr2 = new int[size];

    cout << "Память под массив выделена: адрес = " << arr1 << " значение = " << *arr1 << endl;
    cout << "Память под массив выделена: адрес = " << arr2 << " значение = " << *arr2 << endl;

    input(arr1, size);
    input(arr2, size);

    cout << "Состояние памяти...\n";
    memory("Массив №1", arr1, 1);
    memory("Массив №2", arr2, 1);

    cout << "Начальные одномерные динамические массивы:\n";
    output(arr1, size);
    output(arr2, size);

    // Выделение памяти под двумерный массив
    int** result = new int* [size];
    cout << "Память под массив указателей выделена: адрес = " << result << " значение = ???\n";

    for (int i = 0; i < size; ++i) {
        result[i] = new int[size];
        cout << "Память под " << i + 1 << "-ую строку выделена\n";
    }

    cout << "Состояние памяти...\n";
    memory("Строка", result, size);

    calculation(arr1, arr2, result, size);

    cout << "Результирующий двумерный динамический массив:\n";
    output(result, size);

    // Освобождение памяти
    cout << "Освобождение памяти...\n";
    for (int i = 0; i < size; ++i) {
        delete[] result[i];
        cout << "Память под " << i + 1 << "-ую строку освобождена\n";
    }
    delete[] result;
    delete[] arr1;
    delete[] arr2;
    cout << "Память под массив указателей освобождена\n";

    return 0;
}

