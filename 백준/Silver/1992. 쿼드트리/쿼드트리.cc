#include <bits/stdc++.h>
using namespace std;

int N;
string movie[64];

bool check(int x, int y, int z) {
    for (int i = x; i < x + z; i++)
    for (int j = y; j < y + z; j++)
        if (movie[i][j] != movie[x][y]) return false;
    return true;
}

void solve(int x, int y, int z) {
    if (check(x, y, z)) {
        cout << movie[x][y];
        return;
    }

    cout << '(';
    int n = z / 2;
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
        solve(x + i * n, y + j * n, n);
    cout << ')';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> movie[i];

    solve(0, 0, N);
}
