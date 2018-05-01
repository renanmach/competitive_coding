#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>

#define MAXN 100009

using namespace std;

int inline min(int x, int y) {
	return x <= y ? x : y;
}

int a[MAXN];

int main(void) {
	int n, k, myMin=INT_MAX;
	
	cin >> n >> k;
	
	for(int i = 0 ; i < n; i++) {
		cin >> a[i];
		myMin = min(myMin, a[i]);
	}
	
	for(int i = 0 ; i < n; i++) {
		a[i] -= myMin;
	}
	
	long long int steps = 0;
	
	for(int i = 0; i < n; i++) {
		if(a[i] % k != 0) {
			steps = -1;
			break;
		}
		
		steps += a[i] / k;
	}
	
	cout << steps << endl;

	return 0;	
}
