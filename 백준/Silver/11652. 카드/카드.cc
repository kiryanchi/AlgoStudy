#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int idx = 0;
    int mx_cnt = 0;
    int mx_idx = 0;
    while (idx < n) {
        int idx2 = idx;
        int cnt = 0;
        while (arr[idx] == arr[idx2]) {
            cnt++;
            idx2++;
        }
        if (mx_cnt < cnt) {
            mx_cnt = cnt;
            mx_idx = idx;

        }
        idx = idx2;
    }

    cout << arr[mx_idx];
}