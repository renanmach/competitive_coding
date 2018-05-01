#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

#define INF 1000*21

#define NSTATES 3
#define MAXN 22

int dp[MAXN][NSTATES];

int a[MAXN][NSTATES];

int inline min(int a, int b) {
	return a <= b ? a : b;
}

int main() {
	int t,n;
	
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0 ; j < NSTATES; j++) {
				cin >> a[i][j];
			}
		}
		
		int min_energy = INF;
		//memset(dp,INF,sizeof(dp));
		
		for(int s = 0; s < NSTATES; s++) {
			dp[0][s] = a[0][s];
			for(int k = 0; k < NSTATES ; k++) {
				if(k != s) dp[0][k] = INF; 
			}
			
			for(int i = 1; i < n; i++) {
				for(int k = 0; k < NSTATES; k++) {
					dp[i][k] = INF;
					
					for(int j = 0 ; j < NSTATES; j++) {
						if(j == k) continue;
							dp[i][k] = min(dp[i][k],dp[i-1][j]+a[i][k]);
						}
				}
			}
			
			for(int j = 0 ; j < NSTATES; j++)
				min_energy = min(dp[n-1][j],min_energy);
		}

		cout << min_energy << endl;
	}
	
	return 0;
}
