#include <bits/stdc++.h>

using namespace std;

int N, L;
deque<pair<int, int>> d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;
    
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        if (!d.empty() && d.front().first + L == i) d.pop_front();

        while (!d.empty() && d.back().second > n) d.pop_back();

        d.push_back({i, n});

        cout << d.front().second << ' ';
    }
}