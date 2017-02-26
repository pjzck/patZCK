#include <iostream>
#include <cstdio>
#include <string>
using namespace std; 
string eng[10] = {
	"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine"
};
int main(){
	string s;
	cin >> s;
	int pos = 0;
	if(s[pos] == '-')
		pos++;
	long sum = 0;
	while(pos < s.length())
		sum += s[pos++] - '0';
	if(sum == 0){		
		cout << "zero";
		return 0;
	}
	long tmp = 1;
	while(tmp <= sum)
		tmp *= 10;
	tmp /= 10;
	while(tmp > 0){
		int tmpp = sum / tmp;
		if(tmp != 1)
			cout << eng[tmpp] << " ";
		else
			cout << eng[tmpp];
		sum = sum % tmp;
		tmp /= 10;
	}
}
