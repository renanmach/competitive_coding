// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1205
// 10264 - The Most Potent Corner

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
#include <sstream>
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

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln() printf("\n");


#define NMAX 32768

int main(void) {
	int n;
	int cube[NMAX];
	int fw[NMAX]; //final weights
	int x, k;
	
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < pow(2,n); i++) {
			scanf("%d", &cube[i]);
		}
		
		int max2=0;
		
		//  calculate the weights
		for(int i = 0 ; i < pow(2,n); i++)	{
			fw[i] = 0;
			x = i;

			for(int j = 0; j < n; j++) {
				k = pow(2,j);
				
				if(x & 1) {
					fw[i] += cube[i-k];
				}
				else {
					fw[i] += cube[i+k];
				}
				x = x >> 1;
			}
		}
		
		// calculates the neighbors witg maximum weight
		for(int i = 0 ; i < pow(2,n); i++) {
			x = i;
			for(int j = 0; j < n; j++) {
				k = pow(2,j);
				
				if(!(x & 1)) {
					if(fw[i] + fw[i+k] > max2)
						max2 = fw[i] + fw[i+k];
				}

				x = x >> 1;
			}
		}
			
		printf("%d\n", max2);
	}
	
	return 0;
}
