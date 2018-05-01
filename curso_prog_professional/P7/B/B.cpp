#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <queue>

#define pb push_back
#define INF 1000000000

using namespace std;

class Node {
	public:
	vector<int> next;
	bool visited;
	int d;
};

Node g[64];
bool found;

int bfs(int s, int t) {
	for(int i =0 ; i < 64; i++) {
		g[i].d = INF;
		g[i].visited = false;
	}
	
	g[s].d = 0;
	g[s].visited = true;
	
	queue<int> q;
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(int j = 0 ; j < (int) g[u].next.size(); j++) {
			int v = g[u].next[j];
			if(!g[v].visited) {
				g[v].d = g[u].d + 1;
				q.push(v);
				if(v == t) {
					return g[v].d;
				}
			}
		}
	}
	
	return -1;
}


int inline convert(int x, int y) {
	return x*8+y;
}

int main(void) {
	int T,s,t;
	char a[3],b[3];
	
	cin >> T;
	
	memset(g,0,sizeof(g));
	
	for(int i = 0 ; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			int u = convert(i,j);
			if(i+1 < 8 && j+2 < 8) g[u].next.pb(convert(i+1,j+2));
			if(i+2 < 8 && j+1 < 8) g[u].next.pb(convert(i+2,j+1));	
			if(i+2 < 8 && j-1 >= 0) g[u].next.pb(convert(i+2,j-1));	
			if(i+1 < 8 && j-2 >= 0) g[u].next.pb(convert(i+1,j-2));
			
			if(i-1 >=0 && j+2 < 8) g[u].next.pb(convert(i-1,j+2));
			if(i-2 >=0 && j+1 < 8) g[u].next.pb(convert(i-2,j+1));	
			if(i-2 >=0 && j-1 >= 0) g[u].next.pb(convert(i-2,j-1));	
			if(i-1 >=0 && j-2 >= 0) g[u].next.pb(convert(i-1,j-2));
		}
	}
	
	while(T--) {
		s = t = 0;
		cin >> a >> b;
		
		s = 8*(a[1]-'0'-1) + (a[0]-'a');
		t = 8*(b[1]-'0'-1) + (b[0]-'a');
		
		//cout << s << " " << t << endl;
		
		if(s == t) cout << "0" << endl;
		else cout << bfs(s,t) << endl;
	}

	return 0;	
}
