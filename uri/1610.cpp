// https://www.urionlinejudge.com.br/judge/en/problems/view/1610
// Dudu Service Maker

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

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
	vector<int> next;
	int color;
} Node;

#define NMAX 10002

bool dfs_visit(Node graph[], int u);
bool dfs(Node graph[], int nv);

int main(void) {
	int t, nv,ne, a,b;
	
	
	scanf("%d", &t);
	
	while(t--) {
		Node graph[NMAX]; 
		scanf("%d %d", &nv, &ne);
		
		for(int i = 0; i < ne; i++) {
			scanf("%d %d", &a, &b);
			graph[a].next.pb(b);
		}
			
		if(dfs(graph, nv))
			printf("NAO\n"); // no loop
		else
			printf("SIM\n"); // loop
	}
	
	return 0;
}

bool dfs(Node graph[], int nv) {
	for(int i = 1; i <= nv; i++) {
		graph[i].color = WHITE;
	}
	
	for(int i = 1; i <= nv; i++) {
		if(graph[i].color == WHITE)
			if(!dfs_visit(graph, i))
				return false;
	}
	
	return true;
}

// return false if there is a loop
bool dfs_visit(Node graph[], int u) {
	graph[u].color = GRAY;
	
	for(int i = 0; i < graph[u].next.size(); i++) {
		int v = graph[u].next[i];
		
		if(graph[v].color == GRAY) // back edge found
			return false;
		if(graph[v].color == WHITE)
			if(!dfs_visit(graph, v))
				return false;
	}
	
	graph[u].color = BLACK;
	return true;	
}
