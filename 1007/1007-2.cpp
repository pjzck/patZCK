#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	int ansi, ansj;
	cin >> n;
	int num[n];
	for(int ri = 0; ri < n; ri++)
		cin >> num[ri];
	int si = 0,sj = n-1;
	long maxsum = -1;
	long sum = 0;
	for(int ri = 0; ri < n; ri++){
		if(sum >= 0){
			sum += num[ri];
			sj = ri;
		}
		else{
			sum = num[ri];
			sj = si = ri;
		}
//		if(sum > maxsum){
		if(sum > maxsum || (sum == 0 && sj == n-1)){
			maxsum = sum;
			ansi = si;
			ansj = sj;
		}
	}
	if(maxsum == -1){
		ansi = 0;
		ansj = n-1;
	}
	cout << maxsum << " " << num[ansi] << " " << num[ansj];
}
