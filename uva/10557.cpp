// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1498
// UVA 10557 - XYZZY

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

#define NMAX 10000
#define __INFINITY__ INT_MIN
#define ENTRO printf("entro\n");

typedef struct {
	int w;
	bool visited;
	int energy;
	vector<int> next;
	//int pi;
} Node;

bool transverse(Node g[NMAX], int n, int s, int t) ;
void dfs_visit(Node g[NMAX], int n, int v);

void initialize_single_source(Node g[NMAX], int n, int s) {
	for(int i = 0 ; i < n; i++) {
		 g[i].energy = __INFINITY__;
	}
	
	g[s].energy = 100; 
}

// maximize energy
void relax(Node g[NMAX], int u, int v) {
	if(g[u].energy > 0)
		if(g[v].energy < g[u].energy + g[v].w) {
			g[v].energy = g[u].energy + g[v].w;
		}
}

bool bellman_ford(Node g[NMAX], int n) {
	initialize_single_source(g,n,0);
	int v;
	
	for(int k = 0 ; k < n-1; k++) {
		for(int i = 0 ; i < n; i++) {
			for(int j = 0 ; j < (int)g[i].next.size(); j++) {
				relax(g, i, g[i].next[j]);
			}
		}
	}

	if(g[n-1].energy > 0)
		return true;
	
	for(int i = 0 ; i < n; i++) {
		for(int j = 0 ; j < (int)g[i].next.size(); j++) {
			v = g[i].next[j];
			
			// relaxed, we can get more energy due to the positive cycle
			if(g[i].energy>0) // check if the enrgy is positive
				if(g[v].energy < g[i].energy + g[v].w) {
					return (transverse(g,n, i,n-1) && transverse(g,n, 0,n-1)) ;
				}
		}
	}
	
	// there is no negative cycles and the energy of the last node is negative
	return false;
}

void dfs_visit(Node g[NMAX], int n, int v) {
	g[v].visited = true;
	
	forin((int) g[v].next.size()) {
		int u = g[v].next[i];
		
		if(!g[u].visited)
			dfs_visit(g,n,u);
	}	
}

bool transverse(Node g[NMAX], int n, int s, int t) {
	forin(n) 
		g[i].visited = false;
		
	dfs_visit(g, n, s);
	
	return g[t].visited;
}

int main(void) {
	int n, m, k;
	
	scanf("%d", &n);
		
	while(n != -1) {		
		Node g[NMAX];
		
		for(int i = 0 ; i < n; i++) {
			scanf("%d", &g[i].w);
			scanf("%d", &m);
			
			for(int j = 0 ; j < m; j++) {
				scanf("%d", &k);
				g[i].next.pb(k-1);
			}
		}
		
		if(bellman_ford(g,n)) {	
			printf("winnable\n");
		}
		
		else
			printf("hopeless\n");
		
		scanf("%d", &n);
	}
	
	return 0;
}
