#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	int n;
	long long count = 1ll*0;
	long long ten = 1ll*1;
	long long acc = 1ll*0;
	
	cin >> n;
	long long x = n;
	
	const long long minusone = 1;
	
	long long mypow = 1;
	
	while(x > 0) {
		mypow *= 10;
		long long v = (mypow - minusone) - acc;
		acc += v;
		
		if(x > v) {
			x-= v;
			count += v*ten;
		}
		
		else {
			count += x*ten;
			break;
		}
		
		ten++;
	}
	
	cout << count << endl;

	return 0;	
}
