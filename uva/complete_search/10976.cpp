// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917
// 10976 - Fractions Again?!
// 26 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define sspeed cout.sync_with_stdio(false);

int main(void) {
	sspeed
	
	int k,y;
	vector<int> xv,yv;
	
	while(cin >> k) {
		xv.clear();
		yv.clear();
		
		// 1/k = 1/x + 1/y
		// 1/k = (x+y)/(x*y)
		// k = (x*y)/(x+y)
		
		// x = (y*k)/(y-k)
		
		// loops for every valid y and check if x is an integer
		// y ranges between k+1 and 2k
		for(y = k+1; y <= 2*k ;y++) {
			if((y*k) % (y-k) == 0) {
				xv.pb((y*k)/(y-k));
				yv.pb(y);
			}
		}
		
		cout << xv.size() << endl;
		for(int i = 0; i <xv.size(); i++) {
			cout << "1/"<< k << " = 1/" << xv[i] << " + 1/"<< yv[i] << endl;
		}
	}
	
	return 0;
}
