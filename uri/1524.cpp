// https://www.urionlinejudge.com.br/judge/en/problems/view/1524
// Cafeteria Queue
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

#define NMAX 1000000

typedef struct {
	int size;
	int id_cut;
} Group;

bool operator<(const Group& a, const Group& b) {
  return a.size < b.size;
}

int main(void) {
	int n,k;
	
	while(scanf("%d", &n) != EOF) {
		scanf("%d", &k);
		
		vector<int> ppl;
		
		ppl.pb(0);
		
		int j;
		
		forin(n-1) {
			scanf("%d", &j);
			ppl.pb(j);
		}
		
		sort(ppl.begin(), ppl.end());
		
		priority_queue<Group> pq;
		
		for(int i = 0; i < n-1; i ++) {
			Group g;
			g.size  = ppl[i+1]-ppl[i];
			g.id_cut = i;
			
			pq.push(g);
		}
		
		vector<int> cuts; // cuts to make
		
		for(int i = 0; i < k-1; i++) {
			Group g = pq.top();
			pq.pop();
			
			cuts.pb(g.id_cut);
		}
		
		sort(cuts.begin(), cuts.end());
		
		int min_size = 0;
		j = 0;
		for(int i = 0; i < n-1; i++) {
			if(j < k) {
				if(i == cuts[j]) {
					j++;
					continue;
				}
			}
			
			min_size += (ppl[i+1] - ppl[i]);
			
		}
	
		printf("%d\n", min_size);
	}
}
