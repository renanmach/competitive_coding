// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2349
// 11364 - Parking
// 22 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

#define sspeed std::cout.sync_with_stdio(false);

#define MAXN 25

int main() {
	sspeed
	
	int t;
	
	cin >> t;
	
	while(t--) {
		int n;
		int pos[MAXN];
		
		cin >> n;
		
		// gets the maximum and minimum positions
		// the optimal parking could be at the minimum pos
		// Michal is going to walk
		// 2*(max-min)
		int max,min;
		
		for(int i = 0 ; i < n ; i++) {
			cin >> pos[i];
			
			if(i == 0) {
				max = pos[i];
				min = pos[i];
			}
			
			else {
				if(max < pos[i]) max = pos[i];
				if(min > pos[i]) min = pos[i];
			}
		}
		cout << ((max-min)<<1) << endl;
	}
}
