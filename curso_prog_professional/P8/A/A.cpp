#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>

const int MAXN = 100 + 4;
#define INF -1


using namespace std;


int g[MAXN][MAXN];
int money[MAXN];
int n,m;

int main(void) {
	int a,b,c;
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			g[i][j] = INF;
			money[i] = 0;
		}
	}
	
	for(int i = 0; i < n; i++) g[i][i] = 0;
	
	for(int k = 0 ; k < m; k++) {
		cin >> a >> b >> c;
		a--;b--;
		g[a][b] = c;
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(g[i][j] != INF) {
				// paga
				money[i] -= g[i][j];
			}
			
			if(g[j][i] != INF) {
				// recebe
				money[i] += g[j][i];
			}
		}
	}
	
	
	for(int i = 0; i < n; i++) {
		if(money[i] > 0) ans += money[i];
	}
	
	cout << ans << endl;
	

	return 0;	
}
