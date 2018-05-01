#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 6010
#define push_back pb

int coolness[MAXN];
int count[MAXN];

int inline min(int a, int b) {
	return a <= b ? a : b;
}

int main() {
	int n,val,ans=0;
	cin >> n;
	
	memset(count,0,MAXN*sizeof(int));
	//memset(coolness,0,n*sizeof(int));
	
	for(int i = 0 ; i  < n ; i++) {
		cin >> val;
		count[val-1]++;
	}
	
	for(int i = 0; i <= 2*n; i++) {
		if(count[i] < 2) continue;
		int k = i+1;
		
		while(count[i] != 1) {
			int j = k;
			while(count[j] != 0) j++;
			
			count[j]++;
			count[i]--;
			
			ans += j - i; 
			k = j+1;
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}
