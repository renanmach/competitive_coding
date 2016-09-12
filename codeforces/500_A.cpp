// http://codeforces.com/problemset/problem/500/A
// A. New Year Transportation

using namespace std;
#include <stdio.h>
#include <stdlib.h>
 
#define forin(n) for(int i=0;i<n;i++)
#define forjn(n) for(int j=0;j<n;j++)
 
int main() {
	int n,t, a;
	
	scanf("%d %d", &n, &t);
	
	int curr = 1;
	int i=0;
	
	while(curr <t) {
		i++;

		scanf("%d", &a);
		if(i!=curr)
			continue;
			
		curr += a;
	}

	if(curr == t) 
		printf("YES\n");
		
	else
		printf("NO\n");
	
    return 0;
}
