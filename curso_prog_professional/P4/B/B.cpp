#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 100005

int x[MAXN];
int n;

int inline max(int a, int b) {
	return a >= b ? a : b;
}



int dp[MAXN];

void solve() {
	int maxVal = 0;
	
	dp[0] = max(0,x[0]);
	maxVal = dp[0];
	
	for(int i = 1; i < n; i++) {
		dp[i] =  max(0,x[i]+dp[i-1]);
		maxVal = max(maxVal,dp[i]);
	}
	
	cout << maxVal << endl;
	
}


int main() {
	int val;
	char aux;
	
	n = 0;
	
	while(cin >> val) {
		x[n++] = val;
		aux = getchar();
		
		if(aux == '\n' || aux == EOF) {
			solve();
			n = 0;
		}
	}
	
	return 0;
}
