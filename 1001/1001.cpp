#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	long x, y;
	long ans;
	string anss;
	cin >> x >> y;
	ans = x + y;
	if(ans == 0)
	{
		cout << 0;
		return 0;
	}
	int flag = 1;
	if(ans < 0){
		flag = -1;		
		ans = -1 * ans;
	}
	int count = 0;
	while(ans > 0){
		count ++;
		anss += '0' + ans % 10;
		if(count == 3 && ans > 9)
		{
			anss += ',';
			count = 0;			
		}
		ans /= 10;
	}
	if(flag == -1)
		anss += '-';
//	reverse(anss.begin(), anss.end());
	string ansss;
	for(int i = 0; i < anss.length(); i++)
		ansss += anss[anss.length() - 1 - i];	
	cout << ansss; 
} 
