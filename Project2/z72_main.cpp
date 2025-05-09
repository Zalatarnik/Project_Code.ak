#include "z72_functions.h"

int main() {
    setlocale(LC_ALL, "RU");

    int n = getData();

    int (*fun)(int);

    fun = factorial;
    giveData(n, fun(n), "Факториал числа ");

    fun = sum;
    giveData(n, fun(n), "Сумма чисел от 1 до ");

    fun = countDivBy3;
    giveData(n, fun(n), "Количество чисел, делящихся на 3 в диапазоне от 1 до ");
}