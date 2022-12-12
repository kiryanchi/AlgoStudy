#include <bits/stdc++.h>

using namespace std;

int N;
int board[8000][8000];

void solve(int x, int y, int z) {
    if (z == 1) {
        board[x][y] = 1;
        return;
    }

    int n = z / 3;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i == 1 && j == 1) continue;
            solve(x+i*n, y+j*n, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve(0, 0, N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}