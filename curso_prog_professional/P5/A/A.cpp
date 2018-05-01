#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#define MAXN 1009

using namespace std;

int inline max(int x, int y) {
	return x >= y ? x : y;
}

string a;
string b;
int n,m;

int dp[MAXN][MAXN];

int score(int x, int y) {
	if(a[x] == b[y]) return 1;
	return -1000000;
}

int lcs() {
	n = (int)a.size();
	m = (int)b.size();

	dp[0][0] = 0;
	
	for(int i = 1 ; i <= n; i++) {
		dp[0][i] = 0;
	}
	
	for(int i = 1 ; i <= m; i++) {
		dp[i][0] = 0;
	}
	
	for(int i = 1 ; i <= n; i++) {
		for(int j = 1 ; j <=m; j++) {
			dp[i][j] = max(dp[i-1][j-1]+score(i-1,j-1), max(dp[i-1][j],dp[i][j-1]));
		}
	}
	

	return dp[n][m];
}


int main(void) {
	
	
	
	while(getline(cin, a)) {
		getline(cin, b);
		cout << lcs() << endl;
	}
	
	return 0;	
}
