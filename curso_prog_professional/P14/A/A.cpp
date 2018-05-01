#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
typedef unsigned long long ull;

#define debug(x) cout << #x << " = " << x << endl


int main(void) {
	int t;
	ull g,l;
	
	cin >> t;
	
	while(t--) {
		cin >> g >> l;
		
		if(l % g != 0) {
			cout << "-1" << endl;
		}
		
		else {
			cout << g << " " << l << endl;
		}
	}
	

	return 0;	
}
