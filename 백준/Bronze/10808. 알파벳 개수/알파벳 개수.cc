#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

int arr[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    
    for (auto c : s) {
        arr[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}