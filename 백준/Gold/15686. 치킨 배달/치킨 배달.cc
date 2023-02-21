#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, building;
int min_distance = 9999999;
vector<pair<int, int> > v_house, v_chicken, v_use_chicken;
vector<bool> v_comb;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> building;

            if (building == 1) {
                v_house.push_back({i, j});
            } else if (building == 2) {
                v_chicken.push_back({i, j});
                v_comb.push_back(1);
            }
        }
    }

    for (int i = 0; i < m; i++) v_comb[i] = 0;

    do {
        int distance = 0;
        for (int i = 0; i < v_comb.size(); i++) {
            if (v_comb[i] == 0) {
                v_use_chicken.push_back(v_chicken[i]);
            }
        }

        for (auto house : v_house) {
            int mn = 9999;
            for (auto chicken : v_use_chicken) {
                int sum = abs(house.X - chicken.X) + abs(house.Y - chicken.Y);
                if (mn > sum) mn = sum;
            }
            distance += mn;
        }

        if (min_distance > distance) min_distance = distance;

        v_use_chicken.clear();
    } while (next_permutation(v_comb.begin(), v_comb.end()));

    cout << min_distance;
}