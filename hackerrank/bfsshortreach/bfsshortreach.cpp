// https://www.hackerrank.com/contests/master/challenges/bfsshortreach?h_r=internal-search
// 	Breadth First Search: Shortest Reach
// 20 September 2016

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

#define MAXN 1001
#define pb push_back

using namespace std;

typedef struct node {
	bool visited;
	int distance;
	vector<int> next;
} Node;


void bfs(Node g[], int s) {
	g[s].visited = true;
	g[s].distance = 0;
	
	queue<int> q;
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(unsigned int i = 0 ; i < g[u].next.size(); i++) {
			int v = g[u].next[i];
			
			if(!g[v].visited) {
				g[v].visited = true;
				q.push(v);
				g[v].distance = g[u].distance+6;	// increment by six
			}
		}
	}
}

int main(void) {
	int q;
	
	scanf("%d", &q);
	
	while(q--) {
		int n,m,u,v,s;
		Node g[MAXN];
		
		scanf("%d %d",&n,&m);
		
		// start graph
		for(int i = 1 ; i <= n; i++) {
			g[i].visited = false;
			g[i].distance = -1;
		}
		
		// read edges
		for(int i = 0 ; i < m ; i++) {
			scanf("%d %d", &u, &v);
			
			g[u].next.pb(v);
			g[v].next.pb(u);
		}
		
		scanf("%d",&s);
		
		// run bfs to calculate the distances from s
		bfs(g,s);
		
		// to correctly print the output
		bool first_space = false;
		
		for(int i = 1 ; i <= n; i++) {
			if(i != s) {
				if(first_space)
					printf(" ");
				else
					first_space = true;
					
				printf("%d", g[i].distance);
			}
		}
		
		printf("\n");
	}
	
	return 0;
}
