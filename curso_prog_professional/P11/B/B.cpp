#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

const int MAXN = 1e5 + 5;
int bid[MAXN];


int main(void) {
	int n;
	
	cin >> n;
	for(int i = 0 ; i < n; i++) {
		cin >> bid[i];
		
		while(bid[i] %2 == 0 && bid[i] > 0) bid[i] /=2; 
		while(bid[i] %3 == 0 && bid[i] > 0) bid[i] /=3; 
	}
	
	bool possible = true;
	
	for(int i = 1 ; i < n; i++) {
		if(bid[i]!=bid[i-1]) {
			possible = false;
			break;
		}
	}
	
	if(possible) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;	
}
