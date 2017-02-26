#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int last = 0;
	long sum = 0;
	for(int ri = 0; ri < n; ri++){
		int now;
		cin >> now;
		if(now > last)
			sum += (now - last) * 6 + 5;
		else
			sum += (last - now) * 4 + 5; 
		last = now;
	}
	cout << sum;
}
