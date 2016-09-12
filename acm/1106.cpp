// http://acm.timus.ru/problem.aspx?space=1&num=1106
// 1106. Two Teams

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
 
#define forin(n) for(int i=0;i<n;i++)
#define forjn(n) for(int j=0;j<n;j++)
#define pb push_back 
#define pf push_front

#define NMAX 100

typedef struct node node;

struct node {
	int v;
	bool visited;
	bool team;
	vector<int> next;
};

void bfs(vector<node> &g, int n, int s) {
	
	queue<node> q;
	
	g[s].visited = true;
	q.push(g[s]);
	
	while(!q.empty()) {
		node u = q.front();
		q.pop();
		
		for(int i = 0; i < u.next.size(); i++) {
			int v = u.next[i]-1;
			
			if(g[v].visited)
				continue;
			if(g[u.v-1].team)
				g[v].team = false;
			else
				g[v].team = true;
			
			g[v].visited = true;	
			q.push(g[v]);
		}
	}
}
 
int main() {
	int n, x;
	vector<node> g;
		
	int m = 0;
	
	scanf("%d",&n);
	
	// initialize
	forin(n) {
		g.pb(node());
		g[i].v = i+1;
		g[i].visited = false;
		g[i].team = false;
	}
	
	forin(n) {
		while(true) {
			scanf("%d", &x);
			if(x==0)
				break;
			g[i].next.pb(x);
			
		}
	}
	
	forin(n) {
		if(!g[i].visited)
			bfs(g,n,i);
	}
	
	int v;

	forin(n) {
		if(!g[i].team)
			m++;
	}
	
	printf("%d\n", m);
	
	forin(n) {
		if(!g[i].team)
			printf("%d ", g[i].v);
	}
	
	printf("\n");
	
    return 0;
}
