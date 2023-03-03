#include <bits/stdc++.h>
using namespace std;

int n;
int score[302];
int D[302][3];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> score[i];

    D[1][1] = score[1];
    D[2][1] = score[2];
    D[2][2] = D[1][1] + score[2];

    for (int i = 3; i <= n; i++) {
        D[i][1] = max(D[i-2][1], D[i-2][2]) + score[i];
        D[i][2] = D[i-1][1] + score[i];
    }

    cout << max(D[n][1], D[n][2]);
}