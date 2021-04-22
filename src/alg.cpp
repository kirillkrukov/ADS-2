// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    
    int k = 0;
    int sum = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            sum = arr[i] + arr[j];
                if (sum == value) {
                    k++;
                }
        }
    }
    return k;
}


int countPairs2(int* arr, int len, int value) {
    
    int k = 0;
    int sum = 0;
    int i = len - 1;
    while (arr[i] > value) {
        i--;
    }
    for (i; i > 0; i--) {
        for (int j = 0; j < len; j++) {
            sum = arr[i] + arr[j];
            if (sum == value) {
                k++;
            }
        }
    }
}

int countPairs3(int* arr, int len, int value) {
    
    int left = 0, right = len, middle = 0;
    while (left < right - 1) {
        middle = (left + right) / 2;
        if (arr[middle] <= value)
            left = middle + 1;
        else
            right = middle;
    }
    len = right;
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        int left = i, right = len;
        while (left < right - 1) {
            middle = (left + right) / 2;
            if (arr[i] + arr[middle] == value) {
                k++;
                int j = middle + 1;
                while (arr[i] + arr[j] == value && j < right) {
                    k++;
                    j++;
                }
                j = middle - 1;
                while (arr[i] + arr[j] == value && j > left) {
                    k++;
                    j--;
                }
                break;
            }
            if (arr[i] + arr[middle] > value)
                right = middle;
            else
                left = middle;
        }
    }
    return k;
}

