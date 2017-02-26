#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int k1,k2;
	cin >> k1;
	int exp1[k1];
	float coe1[k1];
	for(int ri = 0; ri < k1; ri++)
		cin >> exp1[ri] >> coe1[ri];
	cin >> k2;
	int exp2[k2];
	float coe2[k2];
	for(int ri = 0; ri < k2; ri++)
		cin >> exp2[ri] >> coe2[ri];
	int anstol = exp1[0] + exp2[0];
	float coeans[anstol + 1];
	for(int ri = 0; ri < anstol + 1; ri++)
		coeans[ri] = 0;
	for(int r1 = 0; r1 < k1; r1++)
		for(int r2 = 0; r2 < k2; r2++)
			coeans[ exp1[r1] + exp2[r2] ] += coe1[r1] * coe2[r2];
	int ans = 0;
	for(int ri = 0; ri < anstol + 1; ri++)
		if(coeans[ri] != 0)
			ans++;
	cout << ans;
	for(int ri = anstol; ri >= 0; ri --)
		if(coeans[ri] != 0)
			printf(" %d %.1f", ri, coeans[ri]);
} 
