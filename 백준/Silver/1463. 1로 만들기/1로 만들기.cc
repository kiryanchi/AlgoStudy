#include <bits/stdc++.h>

using namespace std;

int N;
int board[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i=0; i<1000002; i++) board[i] = -1;

    queue<int> q;
    board[N] = 0;

    q.push(N);

    while (q.front() != 1) {
        auto n = q.front(); q.pop();
        if (n % 3 == 0) {
            if (board[n / 3] == -1) {
                board[n / 3] = board[n] + 1;
                q.push(n / 3);
            }
        }
        if (n % 2 == 0) {
            if (board[n / 2] == -1) {
                board[n / 2] = board[n] + 1;
                q.push(n / 2);
            }
        }
        if (board[n - 1] == -1) {
            board[n - 1] = board[n] + 1;
            q.push(n -1);
        }
    }

    cout << board[1];
}