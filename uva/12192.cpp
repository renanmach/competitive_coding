// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3344
// 12192 - Grapevine

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
#include <climits>

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln printf("\n");

#define sspeed std::cout.sync_with_stdio(false);

typedef long long LL;

#define NMAX 500

#define ENTRO printf("entro\n");
#define DEBUGINT(x) printf("%d\n",x);

int main(void) {
	int n, m; // n é das linhas, m colunas
	
	scanf("%d %d", &n, &m);
	

	while(n && m) {
		int q;
		int h[n][m];

		forin(n) {
			forjn(m) {
				scanf("%d", &h[i][j]);
			}
		}

		scanf("%d", &q);
		
		for(int c = 0 ; c < q; c++) {
			int min, max;
			
			scanf("%d %d", &min, &max);
			
			int size = 0;
				
			for(int i = 0; i < n; i++) {
				int k =  lower_bound(h[i], h[i]+m, min)- h[i];
				
				for(int t = size; (t+i < n) && (k+t < m); t++) {
					if(h[i+t][k+t] > max)
						break;
						
					if(t + 1 > size) 
						size = t + 1;
				}
			}
			
			printf("%d\n", size);
		}


		printf("-\n");



		scanf("%d %d", &n, &m);
	}

	return 0;
}
