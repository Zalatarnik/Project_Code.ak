int countDivBy3(int n) {

    int count = 0;

    for (int i = 1; i <= n; ++i)
        if (i % 3 == 0)
            ++count;

    return count;
}