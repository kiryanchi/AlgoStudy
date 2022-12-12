#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2200][2200];
int result[3];

bool check(int x, int y, int n) {
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (paper[x][y] != paper[i][j])
                return false;

    return true;
}

void func(int x, int y, int z) {
    if (check(x, y, z)) {
        result[paper[x][y] + 1]++;
        return;
    }

    int n = z / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            func(x+i*n, y+j*n, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    func(0, 0, N);

    for (int i = 0; i < 3; i++) cout << result[i] << '\n';
}