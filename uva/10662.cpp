// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1603
// 10662 - The Wedding
// 12 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <limits>
#include <fstream>
#include <list>
#include <istream>
#include <iomanip>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <climits>

#define pb push_back
#define pf push_front
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define sspeed std::cout.sync_with_stdio(false);

#define NMAX 20

int main() {
	//sspeed
	
	int t, r, h;
	int tv[NMAX], rv[NMAX], hv[NMAX];
	int trm[NMAX][NMAX], rhm[NMAX][NMAX], htm[NMAX][NMAX];
	
	while(scanf("%d %d %d", &t, &r, &h) == 3) {
		int tmin=-1, rmin=-1, hmin=-1;
		int min_cost = INT_MAX;

		// First block
		for(int i = 0 ; i < t; i++) {
			scanf("%d", &tv[i]);
			for(int j = 0 ; j < r; j++) {	
				scanf("%d", &trm[i][j]);
			}
		}
		
		// Second block
		for(int i = 0 ; i < r; i++) {
			scanf("%d", &rv[i]);
			for(int j = 0 ; j < h; j++) {
				scanf("%d", &rhm[i][j]);
			}
		}
		
		// Third block
		for(int i = 0 ; i < h; i++) {
			scanf("%d", &hv[i]);
			for(int j = 0 ; j < t; j++) {
				scanf("%d", &htm[i][j]);	
			}
		}
		
		for(int i = 0 ; i < t; i++) {
			for(int j = 0; j < r; j++) {
				if(trm[i][j] == 0) {
					for(int k = 0 ; k < h; k++) {
						if(rhm[j][k] == 0 && htm[k][i] == 0) {
							int cost = tv[i] + rv[j] + hv[k];

							// found a min cost
							if(cost < min_cost) {
								min_cost = cost;
								tmin = i;
								rmin = j;
								hmin = k;
							}
						}
					}
				}
			}
		} 
		
		if(tmin == -1) {
			printf("Don't get married!\n");
		}
		
		else {
			printf("%d %d %d:%d\n",tmin,rmin,hmin,min_cost);
		}
	
	}
	
	return 0;
}
