#include <bits/stdc++.h>
using namespace std;

char stars[3200][6400];

void drawStar(int x, int y) {
    stars[x][y+2] = '*';
    stars[x+1][y+1] = '*';
    stars[x+1][y+3] = '*';
    for (int i=0; i<5; i++)
        stars[x+2][y+i] = '*';
}

void func(int x, int y, int z) {
    if (z == 3) {
        drawStar(x, y);
        return;
    }
    int n = z / 2;
    // 위
    func(x, y + n, n);
    
    // 왼아 오아
    func(x + n, y, n);
    func(x + n, y + z, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    func(0, 0, n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<2*n+1; j++) {
            if (stars[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}