#include <bits/stdc++.h>
using namespace std;

int n, m, idx = 0, ptr1 = 0, ptr2 = 0;
int arr1[1000002];
int arr2[1000002];
int res[2000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    while (1) {
        if (ptr1 == n || ptr2 == m) break;

        if (arr1[ptr1] < arr2[ptr2]) res[idx++] = arr1[ptr1++];
        else res[idx++] = arr2[ptr2++];
    }

    while (ptr1 < n) {
        res[idx++] = arr1[ptr1++];
    }

    while (ptr2 < m) {
        res[idx++] = arr2[ptr2++];
    }

    for (int i = 0; i < idx; i++)
        cout << res[i] << ' ';
}