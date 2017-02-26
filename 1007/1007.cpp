#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	long sum = 0;
	long fsum = 0;
	long maxsum = -1;
	int fcount = 0;
	int ansi, ansj;
	int lasti = 0, lastj = -1;
	int num[n];
	for(int ri = 0; ri < n; ri++){
		int tmp;
		cin >> tmp;
		num[ri] = tmp;
		long tmps = sum + tmp;
		if(tmps <= 0){
			sum -= fsum;
			if(sum > maxsum){
				maxsum = sum;
				ansi = lasti;
				ansj = lastj - fcount;
				fcount = 0;
				sum = 0;
				fsum = 0;
				lasti = lastj = ri + 1;
				lastj--;
			}
		}
		else{
			sum = tmps;
			if(tmp < 0){
				fsum += tmp;
				fcount ++;
			}
			else{
				fsum = 0;
				fcount = 0;
			}
			lastj ++;
		}
	}
	sum = sum - fsum;
	if(sum > maxsum){
		maxsum = sum;
		ansi = lasti;
		ansj = lastj - fcount;
	}
	if(maxsum == -1)
		cout << 0 << " " << num[0] << " " << num[n-1];
	else
		cout << maxsum << " " << num[ansi] << " " << num[ansj];
}
