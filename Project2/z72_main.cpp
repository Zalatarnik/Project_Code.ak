#include "z72_functions.h"

int main() {
    setlocale(LC_ALL, "RU");

    int n = getData();

    int (*fun)(int);

    fun = factorial;
    giveData(n, fun(n), "��������� ����� ");

    fun = sum;
    giveData(n, fun(n), "����� ����� �� 1 �� ");

    fun = countDivBy3;
    giveData(n, fun(n), "���������� �����, ��������� �� 3 � ��������� �� 1 �� ");
}