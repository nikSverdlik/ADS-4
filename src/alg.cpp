// Copyright 2021 NNTU-CS
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
    int res = 0;
    for (int a = 0; a < len; a++) {
        for (int b = a + 1; b < len; b++) {
            if (arr[a] + arr[b] == value) {
                res++;
                while (b + 1 < len && arr[b] == arr[b + 1]) {
                    b++;
                }
            }
        }
        while (a + 1 < len && arr[a] == arr[a + 1]) {
            a++;
        }
    }
    return res;
}

int findFirst(int *data, int lo, int hi, int target) {
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (data[mid] == target) {
            ans = mid;
            hi = mid - 1;
        }
        else if (data[mid] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}

int findLast(int *data, int lo, int hi, int target) {
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (data[mid] == target) {
            ans = mid;
            lo = mid + 1;
        }
        else if (data[mid] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}

int countPairs2(int *arr, int len, int value) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        int need = value - arr[i];
        int first = findFirst(arr, i + 1, len - 1, need);
        if (first != -1) {
            int last = findLast(arr, i + 1, len - 1, need);
            res += (last - first + 1);
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return res;
}

int countPairs3(int *arr, int len, int value) {
    int res = 0;
    int L = 0;
    int R = len - 1;
    
    while (L < R) {
        int cur = arr[L] + arr[R];
        if (cur == value) {
            if (arr[L] == arr[R]) {
                int n = R - L + 1;
                res += n * (n - 1) / 2;
                break;
            }
            int cntL = 0, cntR = 0;
            int valL = arr[L];
            int valR = arr[R];
            while (L <= R && arr[L] == valL) {
                cntL++;
                L++;
            }
            while (L <= R && arr[R] == valR) {
                cntR++;
                R--;
            }
            res += cntL * cntR;
        }
        else if (cur < value) {
            L++;
        }
        else {
            R--;
        }
    }
    return res;
}
