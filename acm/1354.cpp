// http://acm.timus.ru/problem.aspx?space=1&num=1354
// 1354. Palindrome. Again Palindrome

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define NMAX 15000000
#define MMAX 10000000

char s1[NMAX];
char s2[MMAX];

char b[MMAX];

int n;

void kmpPreprocess() {
	int j = -1, i = 0;
		
	b[0] = -1;
	
	while(i < n) {
		while(j >= 0 && s2[i] != s2[j])
			j = b[j];
		j++;
		i++;
		b[i] = j;	
	}
}

int kmpSearch_mod() {
	int i =0, j=0;
	
	while(i < n) {
		while(j >=0 && s1[i] != s2[j]) j = b[j];
		i++; j++;
	}
	
	return j;
}
	
int main(void) {
	int i,j;
	
	scanf("%s", s1);
	n = strlen(s1);
	
	// base case
	if(n == 1) {
		s1[1] = s1[0];
		s1[2] = '\0';
		
		printf("%s\n", s1);
		return 0;
	}
	
	// revert string to s2
	for(i = 0, j =  n-1; i< n; i++, j--)
		s2[i] = s1[j];
		
	s2[i] = '\0';
	
	kmpPreprocess();
	int q = kmpSearch_mod();
	
	if(q == n) {
		q = b[q-1]+1;	// previous palindrome
	}
	
	for(i = n, j = q; i < n+(n-q); i++, j++) {
		s1[i] = s2[j];		
	}
	
	s1[i] = '\0';
	
	printf("%s\n", s1);
	
	return 0;
}
