// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3701
// 1260 - Sales
// 26 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>

#define sspeed cout.sync_with_stdio(false);

#define MAXN 1005

int main(void) {
	sspeed
	
	int t, n;
	int a[MAXN], b[MAXN];
	
	cin >> t;
	while(t--) {
		cin >> n;
		
		// read the list a
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i];
		}
		
		// set zero to the b list (counters)
		memset(b,0,sizeof(a));
		
		// check if the sales of the previous days are less or equal than
		// the sales of the current day, if so, increment the counter for the day
		for(int i = 1 ; i < n ; i++) {
			for(int j = 0 ; j < i ; j++) {
				if(a[i] >= a[j])
					b[i]++;
			}
		}
		
		// sum the n-1 values of b
		int count = 0;
		for(int i = 1; i<n; i++) {
			count += b[i];
		}
		
		cout << count<< endl;
	}
}
