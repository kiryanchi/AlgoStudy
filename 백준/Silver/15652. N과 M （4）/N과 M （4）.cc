#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void solve(int num, int idx) {
    if (idx == m) {
        for (int i = 0; i < idx; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = num; i <= n; i++) {
        arr[idx] = i;
        solve(i, idx+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    solve(1, 0);
}