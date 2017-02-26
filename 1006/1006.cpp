#include <iostream>
#include <string>
using namespace std;
int digit(char c1, char c2){
	return (c1 - '0') * 10 + (c2 - '0');
}
int main(){
	int n;
	cin >> n;
	string sign_in;
	string sign_out;
	long mins = 10000000, maxs = -1;
	for(int ri = 0; ri < n; ri++){
 		string tmp;
		string s_in, s_out;
		cin >> tmp >> s_in >> s_out;
 		long sint = digit(s_in[0], s_in[1]) * 3600 +
					digit(s_in[3], s_in[4]) * 60 +
		 			digit(s_in[6], s_in[7]);
 		long sout = digit(s_out[0], s_out[1]) * 3600 +
					digit(s_out[3], s_out[4]) * 60 +
		 			digit(s_out[6], s_out[7]);
		if(sint < mins){
			mins = sint;
			sign_in = tmp;
		}
		if(sout > maxs){
			maxs = sout;
			sign_out = tmp;
		}
	}
	cout << sign_in << " " << sign_out;
}