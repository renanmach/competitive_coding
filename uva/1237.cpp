//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3678
// 1237 - Expert Enough?

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

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln printf("\n");

typedef long long LL;
	
#define ENTRO printf("entro\n");
#define DEBUGINT(x) printf("%d\n",x);

#define sspeed std::cout.sync_with_stdio(false);

typedef struct {
	char m[22];
	int l;
	int h;
} Car;

bool comp(Car const& a, Car const&b) {
	return a.l <= b.l;
}

int main(void) {
	int t, d;
	
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &d);
		vector<Car> c1(d); // sorted by ascending  lower price
		//char m[22], l,h;
		
		for(int i =0 ; i < d; i++) {
			scanf("%s %d %d", c1[i].m, &c1[i].l, &c1[i].h);
		}
		
		sort(c1.begin(), c1.end(), &comp);

		int q;
		
		scanf("%d", &q);
		
		while(q--) {
			int p;
			scanf("%d",&p);
			char answer[22];
			strcpy(answer, "UNDETERMINED");
			
			for(int i = 0 ;  i < (int) c1.size(); i++) {	
				// found one
				if(c1[i].l <= p && c1[i].h >= p) {
					strcpy(answer, c1[i].m);
					
					for(int j = i+1;  j < (int) c1.size(); j++) {
						if(c1[j].l <=  p && c1[j].h >= p) {
							strcpy(answer, "UNDETERMINED");
							break;
						}
					}
					break;
				}
			}
			
			printf("%s\n", answer);
		}
		
		if(t!=0)
			printf("\n", t);
	}

	return 0;
}
