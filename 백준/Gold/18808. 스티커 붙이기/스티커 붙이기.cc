#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int notebook[42][42];
int sticker[12][12];

bool putable(int x, int y) {
    if ((x + r > n) || (y + c > m)) 
        return false;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (notebook[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }

    return true;
}

void put(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1)
                notebook[x+i][y+j] = 1;
        }
    }
}

void rotate() {
    int tmp[12][12];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sticker[i][j] = tmp[r-1-j][i];
        }
    }

    swap(r, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> k;

    while (k--) {
        cin >> r >> c;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> sticker[i][j];

        bool is_put = false;
        for (int rot = 0; rot < 4; rot++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (putable(i, j)) {
                        put(i, j);
                        is_put = true;
                        break;
                    }
                }
                if (is_put) break;
            }
            if (is_put) break;

            rotate();
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (notebook[i][j] == 1) cnt++;
        }
    }

    cout << cnt;
}