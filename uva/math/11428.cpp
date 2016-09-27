// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2423
// 11428 - Cubes
// 26 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>

#define sspeed std::cout.sync_with_stdio(false);
#define pb push_back

#define INF 10000

int main(void) {
	sspeed
	
	int n,x,y,c;
	
	cin >> n;
	
	while(n != 0) {
		y = INF;
		
		// 100 = sqrt(10000)
		for(int i = 1 ; i <= 100; i++) {
			c = i*i*i;
			for(int j = 1 ; j <= i ; j++) {
				
				// check if i and j satisfy the formula
				// and if we found a smaller y
				if(c - j*j*j == n && j < y) {
					y = j;
					x = i;
					break;
				} 
			}
		}

		if(y == INF)
			cout << "No solution" << endl;
		else 
			cout << x << " " << y << endl;
			
		cin >> n;
	}
}
