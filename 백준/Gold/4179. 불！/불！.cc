#include <bits/stdc++.h>
using namespace std;

#define WALL '#'
#define ROAD '.'
#define FIRE 'F'
#define JIHUN 'J'

#define X first
#define Y second

string _map[1000];
int fire[1000][1000];
int dist[1000][1000];
int r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fire[i][j] = -1;
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < r; i++)
        cin >> _map[i];

    queue<pair<int, int>> q;
    pair<int, int> jihun;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (_map[i][j] == JIHUN) {
                jihun = {i, j};
                dist[i][j] = 0;
            } else if (_map[i][j] == FIRE) {
                q.push({i, j});
                fire[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (fire[nx][ny] >= 0 || _map[nx][ny] == WALL) continue;

            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    q.push(jihun);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << dist[cur.X][cur.Y] + 1;
                exit(0);
            }

            if (dist[nx][ny] >= 0 || _map[nx][ny] == WALL) continue;

            if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;

            q.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";

}