#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int k1, k2;
	
	cin >> k1;
	float a1[k1];
	int n1[k1];
	for(int ri = 0; ri < k1; ri++)
		cin >> n1[ri] >> a1[ri];
	
	cin >> k2;
	float a2[k2];
	int n2[k2];
	for(int ri = 0; ri < k2; ri++)
		cin >> n2[ri] >> a2[ri];

	float aa[k1+k2];
	int na[k1+k2];
	int ra = 0;
	int r1 = 0, r2 = 0;
	while(r1 < k1 && r2 < k2){
		if(n1[r1] < n2[r2]){
			aa[ra] = a2[r2];
			na[ra++] = n2[r2++]; 
		}		
		else if(n1[r1] > n2[r2]){
			aa[ra] = a1[r1];
			na[ra++] = n1[r1++];
		}
		else{
			float tmp = a1[r1] + a2[r2];
			r1++; r2++;
			if(tmp == 0)
				break;
			aa[ra] = a1[r1 - 1] + a2[r2 - 1];
			na[ra] = n1[r1 - 1];
			ra++;
		}
	}
	while(r1 < k1){
		aa[ra] = a1[r1];
		na[ra++] = n1[r1++];
	}
	while(r2 < k2){
		aa[ra] = a2[r2];
		na[ra++] = n2[r2++];
	}
	cout << ra;
	for(int ri = 0; ri < ra; ri++)
		printf(" %d %.1f", na[ri], aa[ri]);		
	cout << endl;
}
