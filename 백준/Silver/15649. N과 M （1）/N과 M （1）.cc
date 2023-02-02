#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int isUsed[9];

void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            arr[cnt] = i;
            isUsed[i] = 1;
            solve(cnt + 1);
            isUsed[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    solve(0);
}