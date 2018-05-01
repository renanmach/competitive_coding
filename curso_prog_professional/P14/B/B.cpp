#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

#define debug(x) cout << #x << " = " << x << endl

long long gcd ( long long a , long long b ) { return b == 0 ? a : gcd ( b , a % b ) ; }
long long lcm( long long a , long long b ) { return a * ( b / gcd ( a , b ) ) ; }


int main(void) {
	long long n, a,b,p,q, m1,m2,c1,c2;
	long long ans = 0;
	
	cin >> n >> a >> b >> p >> q;
	
	if(p >= q) {
		m1 = p;
		c1 = a;
		m2 = q;
		c2 = b;
	}
	else {
		m1 = q;
		c1 = b;
		m2 = p;
		c2 = a;
	}
	
	ans += (n/c1)*m1;
	ans += (n/c2)*m2;
	ans -= (n/(lcm(c1,c2)))*m2;	
	
	cout << ans << endl;
	

	return 0;	
}
