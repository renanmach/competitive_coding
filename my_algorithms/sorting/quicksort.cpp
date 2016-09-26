// 23 September 2016
// QuickSort algorithm implementation

#include <stdio.h>
#include <stdlib.h>

int partition(int *v, int l, int r) {
	if(r < l)
		return l;
		
	int x = v[r];
	int j = l;
	int t;
	
	for(int i = l; i <= r-1 ; i++) {
		if(v[i] < x) {
			t = v[i];
			v[i] = v[j];
			v[j] = t;
			j++;
		}
	}
	
	v[r] = v[j];
	v[j] = x;
	
	return j;
}

void quicksort(int *v, int l, int r) {
	if(r-l <= 0)
		return;
		
	int j = partition(v, l, r);
	
	quicksort(v, l, j-1);
	quicksort(v, j+1, r);
}

int main(void) {
	int n;
	int v[100000];
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",&v[i]);	
	}

	quicksort(v, 0, n-1);
	
	for(int i = 0 ; i < n ; i++) {
		printf("%d  ", v[i]);
	}
	
	printf("\n");
	
	return 0;
}
