// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=868
// 927 - Integer Sequences from Addition of Terms
// 26 September

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln() printf("\n");
#define sspeed cout.sync_with_stdio(false);


#define MAX_DEGREE 22
int main(void) {
	sspeed
	
	long long pol_coef[MAX_DEGREE];
	long long d, k;
	
	int c, degree;
	cin >> c;
	
	while(c--) {
		cin >> degree;
		
		// read the polynomial
		for(int i = 0; i <= degree; i++) {
			cin >> pol_coef[i];
		}
		
		cin >> d;
		cin >> k;
		
		// gets the current number of terms
		long long count = d;
		
		// degree of the polynomial to calculate
		long long n=1;
		
		// looks for the pol degree of the kth element
		while(count < k) {
			n++;
			count += n*d;
		}
		
		long long ans=0;
		long long npower = 1;
		
		for(int i = 0 ; i <= degree; i++) {	
			ans += pol_coef[i]*npower;
			npower *= n;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
