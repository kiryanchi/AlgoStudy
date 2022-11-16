#include<cstdio>
#include <queue>
#include <functional>
using namespace std;
const int MAXN = 25;
const int MAX_SIZE = 625;
int N;
int arr[MAXN][MAXN];
int parent[MAX_SIZE];
priority_queue<int,vector<int>,greater<int>> que;

int find(int x){
  if (parent[x] < 0){
    return x;
  }
  else{
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}

void Union(int x, int y){
  x = find(x);
  y = find(y);
  
  if (x == y)  return;  
  if (parent[x] < parent[y]){
    parent[x] += parent[y];
    parent[y] = x;
  }
  else {
    parent[y] += parent[x];
    parent[x] = y;
  }
}

bool ispass(int y,int x){ return ( y >= 0 && y < N && x >= 0 && x < N && arr[y][x] != 0 ); }
void solve(){
	int y,x;
	int dy[4] = {0,1,0,-1};
	int dx[4] = {1,0,-1,0};
	
	for (int i=0; i<MAX_SIZE; i++)	{
		if (ispass(i/N,i%N)) parent[i] = -1;
	}
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			for (int k = 0; k < 4; k++) {
				int ny = y+dy[k];
				int nx = x+dx[k];
				if ( arr[y][x] != 0 && ispass(ny,nx) ) {
					Union(y*N+x,ny*N+nx);
				}
			}
		}
	}
	for (int j = 0; j < MAX_SIZE; j++) {
		if (parent[j] < 0) que.push(-parent[j]);
	}
	printf("%d\n", que.size());
	while (!que.empty()) { 
		int res;
		res = que.top();
		printf("%d\n", res);
		que.pop();
	}
	
}
void init(){
	scanf("%d", &N);
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			scanf("%1d", &arr[j][i]);
		}		
	}
}
int main(){
	//freopen("단지.txt","r",stdin);
	init();
	solve();
	return 0;
}