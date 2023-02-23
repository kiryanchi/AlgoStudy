#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000002];
int tmp[1000002];

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int ptr1 = start, ptr2 = mid;

    for (int i = start; i < end; i++) {
        if (ptr1 == mid) tmp[i] = arr[ptr2++];
        else if (ptr2 == end) tmp[i] = arr[ptr1++];
        else if (arr[ptr1] <= arr[ptr2]) tmp[i] = arr[ptr1++];
        else tmp[i] = arr[ptr2++];
    }

    for (int i = start; i < end; i++)
        arr[i] = tmp[i];
}

void merge_sort(int start, int end) {
    if (end == start+1) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;


    for (int i = 0; i < n; i++) cin >> arr[i];

    merge_sort(0, n);

    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}