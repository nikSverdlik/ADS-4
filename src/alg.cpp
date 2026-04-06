// Copyright 2021 NNTU-CS
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                res++;
            }
        }
    }
    return res;
}

int findFirst(int *data, int lo, int hi, int target) {
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (data[mid] == target) {
            ans = mid;
            hi = mid - 1;
        } else if (data[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int findLast(int *data, int lo, int hi, int target) {
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (data[mid] == target) {
            ans = mid;
            lo = mid + 1;
        } else if (data[mid] < target) {
            lo = mid + 1;
        } else {
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
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                res += n * (n - 1) / 2;
                break;
            }
            int leftCount = 0, rightCount = 0;
            int leftVal = arr[left];
            int rightVal = arr[right];
            while (left <= right && arr[left] == leftVal) {
                leftCount++;
                left++;
            }
            while (left <= right && arr[right] == rightVal) {
                rightCount++;
                right--;
            }
            res += leftCount * rightCount;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return res;
}
