// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886
// 12455 - Bars
// 26 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 

#define sspeed cout.sync_with_stdio(false);

#define MAXP 22

int main(void) {
	sspeed
	
	int t, n, p; 
	cin >> t;
	
	int b[MAXP];
	
	while(t--) {
		cin >> n;	// length of the bar we want
		cin >> p;	// number of bars we have
		
		long long sum=-1;
		
		for(int i = 0 ; i < p ; i++)
			cin >> b[i];
		
		// i is the bitmask
		for(int i = 0 ; i < (1 << p) ; i++) {	// for each subset
			sum = 0;
			for(int j = 0 ; j < p ; j++) {
				if(i & (1 << j)) { // if the jth bit i on
					sum += b[j];
				}
			}
			// found a subset which the sum of its elements is n
			if(sum == n)
				break;
		}
		
		if(sum == n) 
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
