#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int tomatoes[1000][1000];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool check_all_riped = true;

    // cout << "done\n";
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tomatoes[i][j];
            if (check_all_riped && tomatoes[i][j] == 0) {
                check_all_riped = false;
            }
        }
    }
    // cout << "done\n";

    if (check_all_riped) {
        cout << 0;
        exit(0);
    }
    // cout << "done\n";

    queue<pair<pair<int, int>, int>> q;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (tomatoes[i][j] == 1) {
                q.push({{i, j}, 0});
            }
        }
    }
    // cout << "done\n";

    int mx = 0;

    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X.X + dx[dir];
            int ny = cur.X.Y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (tomatoes[nx][ny] != 0) continue;
            tomatoes[nx][ny] = cur.Y + 1;
            q.push({{nx, ny}, cur.Y + 1});
        }

        mx = max(mx, cur.Y);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (tomatoes[i][j] == 0) {
                cout << -1;
                exit(0);
            }
        }
    }

    cout << mx;
}