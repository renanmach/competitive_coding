#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;
typedef unsigned long long ull;

#define debug(x) cout << #x << " = " << x << endl
#define spc ' '
const int INF = 0x3f3f3f3f;

double getNum(string a, int k) {
	bool negative = false;
	double ans = 0;
	
	if(a[k]=='-') {
		negative = true;
		k++;
	}
	
	while(a[k] >= '0' && a[k] <= '9') {
		ans *= 10;
		ans += a[k++]-'0';
	}
	
	
	if(a[k] == '.') {
		double dec = 0;
		int div = 0;
		k++;
		while(a[k] >= '0' && a[k] <= '9') {
			dec *= 10;
			dec += a[k++]-'0';
			div++;
		}
		
		while(div-- > 0) {
			dec /= 10;
		}
		
		ans += dec;
	}
	
	
	if(a[k] == 'm') {
		ans /= 1000.0;
	}
	
	else if(a[k] == 'k') ans *= 1000.0;
	else if(a[k] == 'M') ans *= 1000000.0;
	
	if(negative) ans*=-1;
	
	return ans;
}

int main(void) {
	int t;
	
	scanf("%d\n",&t);

	for(int tt = 1 ; tt <= t; tt++) {
		string buffer;
		getline(cin,buffer);
		
		double U=INF,P=INF,I=INF;
		
		for(int i= 0 ; i < (int)buffer.size(); i++) {
			if(buffer[i] == '=') {
				if(buffer[i-1] == 'U') {
					U = getNum(buffer, i+1);
				}
				
				else if(buffer[i-1] == 'P') {
					P = getNum(buffer, i+1);
				}
				
				else {
					I = getNum(buffer, i+1);
				}
			} 
		}
		
		double ans;
		char op,unit;
		
		if(U == INF) {
			 ans = I != 0 ? P / I : 0;
			 op = 'U';
			 unit = 'V';
		}
		
		else if(P == INF) {
			ans = U*I;
			op = 'P';
			unit = 'W';
		}
			
		else {
			ans = U != 0 ? P / U : 0;
			op = 'I';
			unit = 'A';
		}
		
		
		cout << "Problem #"<<tt<<endl;
		cout << op << '=' << fixed << setprecision(2) << ans << unit << endl << endl;
	}
	
	
	return 0;	
}
