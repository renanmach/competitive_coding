#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100

vector<int> a;

int main(void) {
	int n,m;
	
	cin >> n;
	cin >> m;
	a.assign(n,0);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(),a.end());
	
	int count = 0;
	for(int i = n-1; i >=0 && m > 0;i--) {
		count++;
		
		m-=a[i];
	}
	
	cout << count << endl;
	
	return 0;
}
