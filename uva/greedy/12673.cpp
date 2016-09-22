// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4411
// 12673 - Football
// Greedy

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

#define NMAX 100001
#define SRMAX 101

int main() {
	//sspeed
	int g,n;
	
	while(scanf("%d %d", &n, &g) == 2) {
		int v[SRMAX];
		int points=0,r,s;
		
		// v[i], which i = s-r, when s-r >0, counts how many times 
		// this event (a loss) happened. 
		 memset(v, 0, sizeof(v));
		
		for(int i = 0 ; i < n; i++) {
			scanf("%d %d", &r,&s);
			
			if(s-r>=0) {
				v[s-r]++; // we lost
			}
			
			else {
				points+=3; // we won
			}
		}

		// we have goals to buy and draws
		while(g>0 && v[0]>0) {
			g--; // buy a goal
			points+=3; // get a win 
			v[0]--;
		}
		
		// compute the remaning draws if we do not have more goals to buy
		while(v[0]>0) {
			points++;
			v[0]--;
		}
		
		// checks the rest of the losses
		for(int i = 1 ; i < SRMAX ; i++) {
			// we cant get more points
			if(g < i) 
				break;
			
			while(v[i] > 0) {
				// we can buy a win
				if(g>=i+1) {
					v[i]--;
					g-=(i+1);
					points+=3;
				}
				
				// we only can buy a draw
				else if(g==i) {
					points++;
					g-=i;
				}
				
				
				// we cant get more points
				if(g < i) 
					break;
			}
		}

		printf("%d\n", points);
	}
	
	return 0;
}
