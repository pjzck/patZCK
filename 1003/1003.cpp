#include <iostream>
#include <cstdio>
using namespace std;

int map[501][501];
bool used[501];
int num[501];

int ansr, ansn;
long mins = 1000000000, maxs = 0;
int n, m;
int c1, c2;

void dfs(int nowpos, int sum, int len){
	if(nowpos == c2){
		if(len < mins){
			mins = len;
			maxs = sum;
			ansr = 1;
		}
		else if(len == mins){
			ansr++;
			if(sum > maxs)
				maxs = sum;
		}
	}
	else{
		for(int i = 0; i < n; i++)
			if(!used[i] && map[nowpos][i] > 0){
				used[i] = true;
				dfs(i, sum+num[i], len+map[nowpos][i]);
				used[i] = false;
			}
	}
}

int main(){
	cin >> n >> m >> c1 >> c2;
	for(int ri = 0; ri < n; ri++)
		cin >> num[ri];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			map[i][j]=0;
	for(int i = 0; i < n; i++)
		used[i] = false;
	for(int ri = 0; ri < m; ri++){
		int x, y, len;
		cin >> x >> y >> len;
		map[x][y] = len;
		map[y][x] = len;
	}
	used[c1] = true;
	dfs(c1, num[c1], 0);
	ansn = maxs;
	cout << ansr << " " << ansn << endl;
}
