#include <iostream>
using namespace std;

// ������������� memory ��� ����������� �������
void memory(const char* name, int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << name << "[" << i << "] = " << (arr + i)
            << " �������� = " << *(arr + i) << endl;
    }
}

// ������������� memory ��� ���������� ������� (������ ����������)
void memory(const char* name, int** arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << "-� ������: ����� = " << (arr + i)
            << " �������� = " << arr[i] << endl;
    }
}

void input(int* arr, int size) {
    cout << "������� �������� �������: ";
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
    cout << "������� ���������� ��������� � ��������: ";
    cin >> size;

    // ��������� ������
    int* arr1 = new int[size];
    int* arr2 = new int[size];

    cout << "������ ��� ������ ��������: ����� = " << arr1 << " �������� = " << *arr1 << endl;
    cout << "������ ��� ������ ��������: ����� = " << arr2 << " �������� = " << *arr2 << endl;

    input(arr1, size);
    input(arr2, size);

    cout << "��������� ������...\n";
    memory("������ �1", arr1, 1);
    memory("������ �2", arr2, 1);

    cout << "��������� ���������� ������������ �������:\n";
    output(arr1, size);
    output(arr2, size);

    // ��������� ������ ��� ��������� ������
    int** result = new int* [size];
    cout << "������ ��� ������ ���������� ��������: ����� = " << result << " �������� = ???\n";

    for (int i = 0; i < size; ++i) {
        result[i] = new int[size];
        cout << "������ ��� " << i + 1 << "-�� ������ ��������\n";
    }

    cout << "��������� ������...\n";
    memory("������", result, size);

    calculation(arr1, arr2, result, size);

    cout << "�������������� ��������� ������������ ������:\n";
    output(result, size);

    // ������������ ������
    cout << "������������ ������...\n";
    for (int i = 0; i < size; ++i) {
        delete[] result[i];
        cout << "������ ��� " << i + 1 << "-�� ������ �����������\n";
    }
    delete[] result;
    delete[] arr1;
    delete[] arr2;
    cout << "������ ��� ������ ���������� �����������\n";

    return 0;
}

