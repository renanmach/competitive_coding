#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <queue>

#define pb push_back

using namespace std;

const int MAXN = 1000+5;
const int INF = INT_MAX/3;

class Edge {
public:
	int v,c,t; // vertex,cost,time
	
	Edge(int vv, int cc, int tt) {
		v = vv; c = cc; t = tt;
	}
};

class Node {
public:
	int dc,dt,nt,id;

	// false ou igual this menor
	bool operator < (const Node &a) const {
		if(dc < a.dc) return false;
		if(dc == a.dc) {
			if(dt < a.dt) return false;
			if(dt == a.dt) {
				if(nt <= a.nt) return false;
				return true;
			}
			return true;
		}
		
		return true;
	}
};

Node g[MAXN];
vector<Edge> adjList[MAXN];

void dijkstra(int s, int t) {
	g[s].dc = g[s].dt = g[s].nt = 0;
	
	priority_queue<Node> pq;
	
	pq.push(g[s]);
	
	while(!pq.empty()) {
		Node nodeU = pq.top(); pq.pop();
		int u = nodeU.id, udc=nodeU.dc, udt=nodeU.dt, unt=nodeU.nt;

		if(udc > g[u].dc) continue;
		if(udt > g[u].dt) continue;
		if(unt > g[u].nt) continue;
		
		udc = g[u].dc;
		udt = g[u].dt;
		unt = g[u].nt;
		
		for(int j = 0; j < (int)adjList[u].size(); j++) {
			Edge e = adjList[u][j];
			
			if(udc + e.c < g[e.v].dc) {
				g[e.v].dc = udc + e.c;
				g[e.v].dt = udt + e.t;
				g[e.v].nt = unt + 1;
				pq.push(g[e.v]);
			}
			
			else if(udc + e.c == g[e.v].dc) {
				if(udt + e.t < g[e.v].dt) {
					g[e.v].dt = udt + e.t;
					g[e.v].nt = unt + 1;
					pq.push(g[e.v]);
				}
				
				else if(udt + e.t == g[e.v].dt && unt + 1 < g[e.v].nt) {
					g[e.v].nt = unt + 1;
					pq.push(g[e.v]);
				}
			}
		}
	}
}

int main(void) {
	char type;
	int n, m, a, b, time, cost;
	
	int source,terminal;
	cin >> n >> m >> type;
	cin >> source >> terminal;
	source--; terminal--;
	
	for(int i = 0; i < n; i++) {
		g[i].dc = g[i].dt = g[i].nt = INF;
		g[i].id = i;
	}
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> cost >> time;
		a--;b--;
		
		if(type == 'P') adjList[a].pb(Edge(b,cost,time));
		else adjList[a].pb(Edge(b,time,cost));
	}
	
	dijkstra(source,terminal);
	
	if(g[terminal].dc != INF)
		if(type == 'P')
			cout <<  g[terminal].dc << " " << g[terminal].dt << " " << g[terminal].nt-1 << endl;
			
		else
			cout <<  g[terminal].dt << " " << g[terminal].dc << " " << g[terminal].nt-1 << endl;
	else
		cout << "-1" << endl;

	return 0;	
}
