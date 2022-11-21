#include <iostream>
#include <list>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string input;
        cin >> input;
        list<char> L = {};
        auto cursor = L.begin();

        for (auto op : input) {
            if (op == '<') {
                if (cursor != L.begin()) cursor--;
            }
            else if (op == '>') {
                if (cursor != L.end()) cursor++;
            }
            else if (op == '-') {
                if (cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else {
                L.insert(cursor, op);
            }

        }

        for (auto c : L) {
            cout << c;
        }

        cout << '\n';

    }


    return 0;
}