#include <bits/stdc++.h>

using namespace std;

// true -> pop_back
// false -> pop_front
int T;

void parse(string& arr, deque<int>& d) {
    int cur = 0;
    for (int i = 1; i < arr.size() - 1; i++) {
        if (arr[i] == ',') {
            d.push_back(cur);
            cur = 0;
        } else {
            cur = 10 * cur + (arr[i] - '0');
        }
    }

    if (cur != 0) {
        d.push_back(cur);
    }
}

int main() {
    cin >> T;

    while (T--) {
        bool is_reverse = false, is_error = false;
        string fun, arr;
        int n;
        deque<int> d;

        cin >> fun >> n >> arr;
        parse(arr, d);

        for (int i = 0; i < fun.size(); i++) {
            if (fun[i] == 'R') {
                is_reverse = !is_reverse;
            } else {
                if (d.empty()) {
                    is_error = true;
                    cout << "error\n";
                    break;
                } else {
                    if (is_reverse) d.pop_back();
                    else d.pop_front();
                }
            }
        }

        if (!is_error) {
            if (d.empty()) {
                cout << "[]\n";
            } else {
                if (is_reverse) {
                    reverse(d.begin(), d.end());
                }

                cout << "[";
                for (int i = 0; i < d.size()-1; i++) {
                    cout << d[i] << ',';
                }
                cout << d.back() << "]\n";
            }
        }
    }
}