#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
typedef unsigned long long ull;

#define debug(x) cout << #x << " = " << x << endl
#define spc ' '

const int MAXN = 30 + 5;
const int MAXK = 50 + 5;
const int INF = 0x3f3f3f3f;

int dp[MAXN][MAXN][MAXK];

int solve(int n, int m, int k) {
	if(n < 1 || m < 1) return INF;
	if(dp[n][m][k] != -1) return dp[n][m][k];
	
	if(n*m < k) return INF;
	if(n*m == k || k < 1) return 0;
	
	
	
	int currMin = INF;
	
	for(int x = 1; x < (n/2)+1; x++) {
		for(int z = 0; z <= k; z++) {
			currMin = min(currMin, solve(n-x,m,z)+solve(x,m,k-z)+m*m);
		}
	}
	
	for(int x = 1; x < (m/2)+1; x++) {
		for(int z = 0; z <= k; z++) {
			currMin = min(currMin, solve(n,m-x,z)+solve(n,x,k-z)+n*n);
		}
	}

	dp[n][m][k] = currMin;
	
	return dp[n][m][k];
}


int main(void) {
	int t,n,m,k;
	ios::sync_with_stdio(false);
	cin >> t;
	
	memset(dp,-1,sizeof(dp));
	while(t--) {
		cin >> n >> m >> k;
		cout << solve(n,m,k) << endl;
	}
	
	return 0;	
}
