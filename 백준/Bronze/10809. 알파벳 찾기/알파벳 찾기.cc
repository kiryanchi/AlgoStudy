#include<bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	vector<int>vec(33,-1);
	for(int i=0; i < s.size(); i++)
	{
		if(vec[s[i]-'a'] == -1) vec[s[i]-'a'] = i;
	}
	for(int i=0; i < 26; i++) cout << vec[i] << ' ';

}
