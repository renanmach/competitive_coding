// http://codeforces.com/problemset/problem/615/A
// A. Bulbs

using namespace std;
#include <stdio.h>
#include <stdlib.h>
 
#define forin(n) for(int i=0;i<n;i++)
#define forjn(n) for(int j=0;j<n;j++)
 
int main() {
	int n,m;
	bool on[101];
	
	scanf("%d %d", &n, &m);
	
	for(int i=1;i<=m;i++)
		on[i]=false;
	
	int x,y;
	
	forin(n) {
		scanf("%d", &y);
		forjn(y) {
			scanf("%d", &x);
			on[x] = true;
		}
	}
	
	int i;
	for(i=1;i<=m;i++) {
		if(on[i]==false) {
			printf("NO\n");
			break;
		}
	}
		
	if(i>m)
		printf("YES\n");

    return 0;
}
