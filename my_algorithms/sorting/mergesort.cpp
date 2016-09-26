// 24 September 2016
// Merge sort algorithm implementation

#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
	int n;
	int v[10000];
	int b[10000];
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",&v[i]);	
	}

	mergesort(v, b, 0, n-1);
	
	for(int i = 0 ; i < n ; i++) {
		printf("%d  ", v[i]);
	}
	
	printf("\n");
	
	return 0;
}
