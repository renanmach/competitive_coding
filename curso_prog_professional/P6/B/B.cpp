#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 14;

int inline max(int x, int y) {
	return x >= y ? x : y;
}

char buffer[MAXN+1];
int mat[MAXN][MAXN];
int memo[MAXN+1][(1 << MAXN)+5];
int n,k,m;


int solve(int i, int bitmask) {
	if(memo[i][bitmask] != -1) return memo[i][bitmask];
	//cout << i << " " << bitmask << endl;
	
	int bits = 0 ;
	
	for(int j = 0 ; j < m; j++) {
		if(bitmask & (1 << j)) bits++;
	}
	
	if(bits == k) {
		return 1;
	}
	
	if(i >= n) return 0;
	
	int ans =  solve(i+1,bitmask);
	
	for(int j = 0 ; j < m; j++) {
		int bit = (bitmask >> j) & 1;
		if(mat[i][j] && !bit)
			ans += solve(i+1, bitmask | (1 << j));
	}
	
	return memo[i][bitmask] = ans;
}

int main(void) {
	int t;
	
	cin >> t;
	
	while(t--) {
		cin >> n >> m >> k;
		for(int i = 0; i < n ; i++) {
			cin >> buffer;
			for(int j = 0; j < m; j++) {
				mat[i][j] = buffer[j]-'0';
			}
		}

		memset(memo,-1,sizeof(memo));
		
		cout << solve(0,0) << endl;
	}
	
	return 0;	
}
