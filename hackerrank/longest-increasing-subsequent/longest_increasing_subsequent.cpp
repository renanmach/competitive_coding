// https://www.hackerrank.com/challenges/longest-increasing-subsequent
// The Longest Increasing Subsequence

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000001

int binary_search(int a[], int t[] ,int l, int r, int v) {
	int m;
	
	while(r>l+1) {
		m = l + (r-l)/2;
		
		if(v <= a[t[m]]) {
			r = m;
		}
	
		else {
			l = m;
		}
	}
	
	return r;
}

int main(void) {
	int n, a[MAXN], pos;
	
	// t stores the intermediate results
	// r stores the final results
	int t[MAXN], len=0;

	scanf("%d",&n);

	for(int i = 0 ; i < n; i++) {
		scanf("%d",&a[i]);
	}
	
	t[0] = 0;
	
	for(int i = 1 ; i < n ; i++) {
		// found a biggest value 
		if(a[i] > a[t[len]]) {
			len++;
			t[len] = i;
		}
		
		else if(a[i] < a[t[0]]) {
			t[0] = i;
		} 
		
		else {
			pos = binary_search(a, t, -1, len, a[i]);
			t[pos] = i;
		}
	}
	
	printf("%d\n",len+1);

	return 0;
}
