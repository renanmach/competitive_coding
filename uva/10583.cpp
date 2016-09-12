// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1524
// 10583 - Ubiquitous Religions

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
#define pb push_back
#define pf push_front
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln printf("\n");

#define NMAX 100001

typedef struct {
	bool visited;
	vector<int> next;
} Node;

void dfs_visit(Node g[NMAX], int n, int u) {
	g[u].visited = true;
	
	for(int i = 0; i < (int) g[u].next.size(); i++) {
		int v =  g[u].next[i];
		if(!g[v].visited) {
			dfs_visit(g,n,v);		
		}
	}
}

int dfs(Node g[NMAX], int n) {
	int religions = 0;
	
	
	for(int i =0; i <=n ; i++) {
		g[i].visited = false;
	}
	
	for(int i = 1; i <=n; i++) {
		if(!g[i].visited) {
			religions++;
			dfs_visit(g,n,i);
		}
	}
	
	return religions;
}

int main(void) {
	int n, m, c=0;

	scanf("%d %d", &n, &m);
	
	while(n !=0 && m != 0) {
		c++;
		
		int a, b;
		
		Node g[NMAX];
		
		forin(m) {
			scanf("%d %d", &a, &b);
			g[a].next.pb(b);	
			g[b].next.pb(a);	
		}
		
		int religions = dfs(g, n);
		
		printf("Case %d: %d\n", c, religions);
		
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}
