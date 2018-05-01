#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	int n, val, m;
	cin >> n;
	bool found = false;
	
	for(m = 1; m <= 1000 && !found; m++) {
		val = n*m+1;
		if(val%2 == 0 && val != 2) break;
		for(int i = 3; i <= (val/2)+1; i+=2) {
			if(val % i == 0) {
				found = true;
				m--;
				break;
			}
		}
	}
	
	cout << m << endl;
	
	return 0;	
}
