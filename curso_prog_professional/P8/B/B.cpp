#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>

using namespace std;

const int MAXN =100 + 5;
const int MAXW =100 + 1;
const int INF =MAXN*MAXW;

int g[MAXN][MAXN];
int n,m;
int maxDist[MAXN];

int inline min(int x, int y) {
	return x <= y ? x : y;
}


int inline max(int x, int y) {
	return x >= y ? x : y;
}

int main(void) {
	cin >> n >> m;
	
	for(int i = 0 ; i < n; i++) {
		for(int j = 0 ; j < n; j++) {
			g[i][j] = INF;
		}
		g[i][i] = 0;
	}
	
	int a,b,c;
	for(int i = 0 ; i < m ; i++) {
		cin >> a >> b >> c;
		
		g[a][b] = min(g[a][b],c);
		g[b][a] = g[a][b];
	}
	
	for(int k = 0 ; k < n; k++) {
		for(int i = 0 ; i < n; i++) { 
			for(int j = 0 ; j < n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	
	
	memset(maxDist,-1,sizeof(maxDist));
	
	for(int j = 0; j < n; j++) {
		for(int i = 0 ; i < n; i++) {
			maxDist[j] = max(maxDist[j],g[i][j]);
		}
	}
	
	int ans = maxDist[0];
	
	for(int j = 1; j < n; j++) {
		ans = min(ans,maxDist[j]);
	}
	
	cout << ans << endl;


	return 0;	
}
