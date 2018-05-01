#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

#define debug(x) cout << #x << " = " << x << endl
#define spc ' '

const int MAXN = 3*1e5 + 5;
int v[MAXN];
int aux[MAXN];

void mergesort(int l, int r) {
	if(l>=r) return;
	
	int m = (l+r) / 2;
	
	mergesort(l,m);
	mergesort(m+1,r);
	
	int p1 = l, p2 = m+1;
	int pos = l;
	
	for(int i = l ; i <= r; i++) {
		aux[i] = v[i];
	}
	
	while(p1 <= m && p2 <= r) {
		if(aux[p1] <= aux[p2]) v[pos++] = aux[p1++];
		else v[pos++] = aux[p2++];
	}
	
	while(p1 <= m) v[pos++] = aux[p1++];
	while(p2 <= r) v[pos++] = aux[p2++];
}

int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	mergesort(0,n-1);

	cout << v[(n-1)/2] << endl;
	
	return 0;	
}
