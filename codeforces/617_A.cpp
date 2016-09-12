// http://codeforces.com/problemset/problem/617/A
// Elephant

using namespace std;
#include <stdio.h>
#include <stdlib.h>
 
int main() {
	int n;
	scanf("%d", &n);
	
	int x;
	
	(n%5)==0?x=0:x=1;
	
	printf("%d\n", (n/5)+x);

    return 0;
}
