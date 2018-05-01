#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 1000
#define MAXVC 5000
#define MAXT 2000

using namespace std;

int DP[MAXT + 1];
int n,t;

typedef pair<int,int> pii;

vector<pii> rods;

int inline max(int x, int y) { return (x > y) ? x : y;};

int solve() {
	DP[0] = 0;
	
	for(int i = 1 ; i <= t; i++) {
		DP[i] = 0;
		for(int j = 0 ; j < n; j++) {
			if(rods[j].first <= i) {
				DP[i] = max(rods[j].second+DP[i-rods[j].first], DP[i]);
			}
		}
	}
	
	return DP[t];
}

int main(void) {
	cin >> n >> t;
	int a,b;
	
	
	for(int i = 0 ; i < n; i++) {
		cin >> a >> b;
		rods.push_back(pii(a,b));
	}
	
	//sort(rods.begin(),rods.end());
	
	cout << solve() << endl;
	
	return 0;
}
