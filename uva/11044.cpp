// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1985
// 11044 - Searching for Nessy
// 22 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define pb push_back
#define pf push_front
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define sspeed std::cout.sync_with_stdio(false);

int main() {
	sspeed;
	
	int t;
	
	cin >> t;
	
	while(t--) {
		int n,m;
		cin >> n >> m;
		
		cout << int((n/3)*(m/3)) << endl;
		
	}
}
