// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int k = 0;
    int r = size - 1;
    int l = 0;
    while (r >= l) {
        if (arr[(r+l) / 2] == value) {
            ++k;
            int i = 1;
            while (true) {
                if (arr[((r+l) / 2) - i] == value)
                    ++k;
                if (arr[((r + l) / 2) + i] == value)
                    ++k;
                int m = (r + l) / 2;
                if (arr[m - i] != value && arr[m + i] != value)
                    break;
                ++i;
            }
            break;
        } else {
            if (arr[(r + l) / 2] > value)
                r = (r + l) / 2;
            if (arr[(r + l) / 2] < value)
                l = (r + l) / 2;
        }
    }
    return k;
}
int countPairs1(int *arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value)
                ++k;
        }
    }
    return k;
}
int countPairs2(int *arr, int len, int value) {
    int k = 0;
    int p = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (arr[i] == value) {
            k = countPairs1(arr, i+1, value);
            break;
        }
    }
    return k;
}
int countPairs3(int *arr, int len, int value) {
    int k = 0;
    int p = 1;
    for (int i = 0; i < len; ++i) {
        if (arr[i] == (value/2)+1)
            break;
        if (arr[i] == value / 2) {
            k += cbinsearch(arr, len, value - arr[i]);
            k -= p;
            p++;
        } else {
            k += cbinsearch(arr, len, value - arr[i]);
        }
    }
    return k;
}
