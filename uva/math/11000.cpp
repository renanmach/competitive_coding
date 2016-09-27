// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1941
// 11000 - Bee
// 26 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>

#define sspeed std::cout.sync_with_stdio(false);

typedef long long LL;

typedef pair<LL, LL> PLL;

#define pb push_back
int main(void) {
	sspeed
	
	int n;
	
	cin >> n;
	vector<PLL> v;
	v.pb(make_pair(0, 1));
	
	while(n != -1) {
		// we've already calculated
		if(n < v.size()) {
			cout << v[n].first << " " << v[n].second << endl;
		}
		
		// calculate it and store the values until we reach n
		else {
			for(int i = v.size(); i <= n; i++) {
				v.pb(make_pair(v[i-1].second, v[i-1].first+v[i-1].second+1));
			}	
			
			cout << v[n].first << " " << v[n].second << endl;
		}
		
		cin >> n;
	}
}
