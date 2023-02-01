#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int year;
    cin >> year;
    
    if (year % 4 != 0) {
        cout << 0;
    } else if (year % 100 != 0) {
        cout << 1;
    } else if (year % 400 != 0) {
        cout << 0;
    } else {
        cout << 1;
    }
}