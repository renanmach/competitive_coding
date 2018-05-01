#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAXN 1009
#define INF 0x3f3f3f3f

int inline min(int x, int y) {
	return x <= y ? x : y;
}

int dp[MAXN][MAXN];
int n;
char a[MAXN];

void print_dp() {
	cout << endl;
	for(int i = 0 ; i <=n ; i++) {
		for(int j = 0 ; j <=n ;j++) {
			cout << dp[i][j] << " " ;
		}
		cout << endl;
	}
	
	cout << endl;
}

int solve(int l, int r) {
	if(dp[l][r] != INF) return dp[l][r];
	
	if(l>=r) {
		dp[l][r] = 0; 
	}
	
	else if(a[l] == a[r]){
		// igual e nao paga nada
		dp[l][r] = solve(l+1, r-1);
	}
	 
	else {
		// diferente
		// min de adicionar, remover ou substituir
		dp[l][r] = min(solve(l+1,r)+1,min(solve(l,r-1)+1,solve(l+1, r-1)+1)); 
	}
	 
	 return dp[l][r];
}


int main(void) {
	int t;
	
	cin >> t;
	
	for(int tt = 1; tt <= t; tt++) {
		cin >> a;
		n = strlen(a);
		memset(dp,INF,sizeof(dp));
		
		cout << "Case " << tt << ": " << solve(0,n-1) << endl;
	}

	return 0;	
}
