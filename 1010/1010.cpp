#include <iostream>
#include <cstdio>
using namespace std;
int nnum(char c){
	if(c >= '0' && c <= '9')
		return c - '0';
	else
		return c - 'a' + 10;
}
long long num(string nums, int radix){
	int len = nums.length();
	long long ba = 1;
	long long ans = 0;
	for(int ri = len - 1; ri >= 0; ri--){
		ans += ba * nnum(nums[ri]);
		ba *= radix;
	}
	return ans;
}

int main(){
	string N1,N2;
	long long num1, num2;
	int tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	int maxn = 0;
	bool flag = false;
	if(tag == 1){
		num1 = num(N1, radix);
		for(int ri = 0; ri < N2.length(); ri++)
			if(nnum(N2[ri]) > maxn)
				maxn = nnum(N2[ri]);
		if(num1 > 100000000){
			
		
		long long ramin = maxn+1, ramax = num1 + 1;
		if(num(N2, ramax) == num1){
			flag = true;
			cout << ramax;			
		}
		if(num(N2, ramin) == num1){
			flag = true;
			cout << ramin;
		}
		if(num(N2, ramin) > num1){
			flag = true;
			cout << "Impossible";
		}
		for( ;ramin < ramax - 1 && !flag;){
			long long ramid = (ramin + ramax) / 2;
			num2 = num(N2, ramid);
			if(num2 < num1)
				ramin = ramid;
			else if(num2 > num1)
				ramax = ramid;
			else{
				flag = true;
				cout << ramid;
			}
		}
		}
		else {
			
		for(long long ri = maxn + 1; ri <= num1 + 1; ri++){
			num2 = num(N2, ri);
			if(num2 == num1){
				flag = true;
				cout << ri;
				break;
			}
			else if(num2 > num1)
				break;
		}
		}
		if(!flag)
			cout << "Impossible";
	}
	else{
		num2 = num(N2, radix);
		for(int ri = 0; ri < N1.length(); ri++)
			if(nnum(N1[ri]) > maxn)
				maxn = nnum(N1[ri]);
		for(long long ri = maxn + 1; ri <= num2 + 1; ri++){
			num1 = num(N1, ri);
			if(num1 == num2){
				flag = true;
				cout << ri;
				break;
			}
			else if(num1 > num2)
				break;
		}
		if(!flag)
			cout << "Impossible";
	}
}
