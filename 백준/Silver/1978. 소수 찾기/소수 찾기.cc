#include <bits/stdc++.h>
using namespace std;

int n, num, cnt;

bool isPrime(int number) {
  if (number == 1) return false;

  for(int i = 2; i*i <= number; i++) {
    if (number % i == 0) return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;

  while (n--) {
    cin >> num;

    if (isPrime(num)) cnt++;
  }

  cout << cnt;
}