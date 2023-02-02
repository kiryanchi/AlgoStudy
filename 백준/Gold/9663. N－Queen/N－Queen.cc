#include <bits/stdc++.h>
using namespace std;

int n;
int result = 0;
int isUsed1[40];
int isUsed2[40];
int isUsed3[40];

bool putable(int i, int cnt) {
    return !(isUsed1[i] || isUsed2[i + cnt] || isUsed3[n + i - cnt]);
}

void putQueen(int i, int cnt) {
    isUsed1[i] = 1;
    isUsed2[i + cnt] = 1;
    isUsed3[n + i - cnt] = 1;
}

void takeQueen(int i, int cnt) {
    isUsed1[i] = 0;
    isUsed2[i + cnt] = 0;
    isUsed3[n + i - cnt] = 0;
}

void solve(int cnt) {
    if (cnt == n) {
        result++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!putable(i, cnt)) {
            continue;
        }
        putQueen(i, cnt);
        solve(cnt + 1);
        takeQueen(i, cnt);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    solve(0);

    cout << result;
}