#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
typedef unsigned long long ull;

#define debug(x) cout << #x << " = " << x << endl
#define spc ' '

#define MATCH 0
#define MISMATCH 1
#define GAP 1

const int MAXN = 1000 + 5;
const int MAXM = 100;

int dp[MAXN][MAXN];
char dict[MAXN][22];
int len[MAXN];
char buffer[MAXN];
int ans[MAXN];
int ansSize;
int n,m;

int editDistance(char a[], char b[], int aLen, int bLen) {
	int delta;
	
	for(int i = 1; i <= aLen; i++) {
		for(int j = 1; j <= bLen; j++) {
			delta = (a[i-1] == b[j-1]) ? MATCH : MISMATCH;
			dp[i][j] = min(dp[i-1][j-1]+ delta, min(dp[i][j-1], dp[i-1][j])+GAP);
		}
	}
	
	return dp[aLen][bLen];
}

int main(void) {
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for(int i = 0 ; i < MAXN; i++) {
		dp[i][0] = i*GAP;
	}
	
	for(int i = 1 ; i < MAXN; i++) {
		dp[0][i] = i*GAP;
	}
	
	for(int i = 0; i < n; i++) {
		cin >> dict[i];
		len[i] = strlen(dict[i]);
	}

	for(int i = 0 ; i < m; i++) {
		cin >> buffer;
		ansSize = 0;
		
		for(int j = 0 ; j < n; j++) {
			if(editDistance(dict[j],buffer,len[j],strlen(buffer)) <= 2) ans[ansSize++] = j;
		}
		
		if(ansSize > 0) cout << dict[ans[0]];
		
		for(int j = 1 ; j < ansSize; j++) {
			cout << " " << dict[ans[j]];
		}
		
		cout << endl;
	}
	
	
	
	return 0;	
}
