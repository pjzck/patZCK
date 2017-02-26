#include <iostream>
using namespace std;

int main(){
	int m, n;
	cin >> n >> m;
	int par[101];
	int lev[101];
	bool haschild[101], isin[101];
	int maxlev = -1;
	for(int i = 0; i < 101; i++)
		lev[i] = par[i] = 0;
	for(int i = 0; i < 101; i++)
		haschild[i] = isin[i] = false;
	for(int i = 0; i < m; i++){
		int parent;
		int k;
		cin >> parent >> k;
		haschild[parent] = true;
		isin[parent] = true;
		if(lev[parent] > maxlev)
			maxlev = lev[parent];
		for(int ri = 0; ri < k; ri++){
			int child;
			cin >> child;
			par[child] = parent;
			lev[child] = lev[parent] + 1;
			isin[child] = true;
			if(lev[child] > maxlev)
				maxlev = lev[child];
		}
	}
	int count[maxlev + 1];
	for(int i = 0; i < maxlev+1; i++)
		count[i] = 0;
	for(int i = 1; i < n + 1; i++)
		if(isin[i])
			count[lev[i]] += haschild[i] ? 0 : 1;
	count[0] = n - m;
	for(int i = 1; i < maxlev+1; i++)
		count[0] -= count[i];
	cout << count[0];
	for(int i = 1; i < maxlev+1; i++)
		cout << " " << count[i];
}
