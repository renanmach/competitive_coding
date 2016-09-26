// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1428
// 10487 - Closest Sums
// 26 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>

#define sspeed cout.sync_with_stdio(false);

#define MAXN 1005
#define MAXM 30
#define FLAG -1e9
#define INF 1e9

void mergesort(int *v, int*b, int l, int r) {
	int m = (r+l)/2;
	
	if(r > l) {	
		mergesort(v,b,l,m);
		mergesort(v,b,m+1,r);
	}
	
	for(int i = l; i <=m; i++) {
		b[i] = v[i];
	}
	
	for(int j = m+1; j <= r; j++) {
		b[r-j+m+1] = v[j];
	}
	
	int i = l, j = r;
	
	for(int k = l ; k <=r; k++) {
		if(b[i] < b[j]) {
			v[k] = b[i++];
		}
		else {
			v[k] = b[j--];
		}
	}
}

// return |a-b|
inline int absolute_sub(int a, int b) {
	return a>b ? a-b : b-a;
}

int main(void) {
	sspeed
	
	int n, m;
	int numbers[MAXN], aux[MAXN];
	int queries[MAXM];
	int ccc = 1;
	
	cin >> n;
	while(n != 0) {
		for(int i = 0 ; i < n ; i++) {
			cin >> numbers[i];
		}
		
		cin >> m;
		
		for(int i = 0 ; i < m; i++) {
			cin >> queries[i];
		}
		
		mergesort(numbers,aux,0,n-1);
		
		int ct1,ct2;
		int curr;
		
		cout << "Case " << ccc << ":" << endl;
		
		for(int q = 0 ; q < m; q++) {
			int closest = INF;
			for(int i = 0 ; i < n; i++) {
				for(int j = i+1 ; j < n; j++) {
					curr = absolute_sub(numbers[i]+numbers[j], queries[q]);
					
					// if the current value is smaller than the closest 
					if(curr < closest) {
						closest = curr;
						ct1 = numbers[i];
						ct2 = numbers[j];
					}
				}
			}
			cout << "Closest sum to " << queries[q] << " is " << ct1+ct2 << "." << endl;
		}
		
		cin >> n;
		ccc++;
	}
}
