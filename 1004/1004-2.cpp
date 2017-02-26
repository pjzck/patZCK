#include <iostream>
using namespace std;

int par[101];
int lev[101];

int fcount(int k){
	if(lev[k] != -1)
		return lev[k];

	if(par[k] == 0){
		lev[k] = 0;
		return 0;		
	}
	
	lev[k] = fcount(par[k]) + 1;
	
	return lev[k];
}

int main(){
	int m, n;
	cin >> n >> m;
	bool haschild[101], isin[101];
	int maxlev = -1;
	for(int i = 0; i < 101; i++)
		lev[i] = par[i] = -1;
	for(int i = 0; i < 101; i++)
		haschild[i] = isin[i] = false;
	for(int i = 0; i < m; i++){
		int parent;
		int k;
		cin >> parent >> k;
		haschild[parent] = true;
		isin[parent] = true;
		if(par[parent] == -1)
			par[parent] = 0;
		for(int ri = 0; ri < k; ri++){
			int child;
			cin >> child;
			par[child] = parent;
			isin[child] = true;
		}
	}
	int count[101];
	for(int i = 0; i < 101; i++)
		count[i] = 0;
	for(int i = 0; i < 101; i++)
		if(isin[i] && !haschild[i]){
			count[fcount(i)]++;
			if(lev[i] > maxlev)
				maxlev = lev[i];
		}
	count[0] = n - m;
	for(int i = 1; i < maxlev+1; i++)
		count[0] -= count[i];
	cout << count[0];
	for(int i = 1; i < maxlev+1; i++)
		cout << " " << count[i];
}
