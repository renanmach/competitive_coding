// http://codeforces.com/problemset/problem/712/C
//  Memory and De-Evolution
// Greedy and math

using namespace std;
#include <stdio.h>
#include <stdlib.h>
 
int main() {
	int x,y;
	scanf("%d %d", &x,&y);
	
	// triangles sides
	// we go from y to x
	
	int s1=y,s2=y,s3=y;
	
	int counter = 0;
	while(true) {
		if(s1>=x && s2>=x && s3>=x) {
			printf("%d\n", counter);
			break;
		}
		
		// The current triangle must obey the triangle inequality
		// a > b+c
		// b > a+c
		// c > a+b
		
		if(counter % 3 == 0) {
			s1 = s2+s3-1;
		}
		
		else if(counter % 3 == 1) {
			s2 = s1+s3-1;
			
		}
		
		else {
			s3 = s1+s2-1;
		}
		
		counter++;
	}
	
	
    return 0;
}
