// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1491	
// 10550 - Combination Lock
// 22 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define pb push_back
#define pf push_front
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define sspeed std::cout.sync_with_stdio(false);

#define NMAX 40

int main() {
	int ini,c1,c2,c3;
	
	int degree_num = 360/NMAX;

	while(true) {
		cin >> ini >> c1 >> c2 >> c3;
		
		if(ini==0&&c1==0&&c2==0&&c3==0)
			break;
			

		// start at the initial position
		int curr = ini;
		
		// turn the dial clockwise 2 full turns
		int answer = 720;
		
		// stop at the first number of the combination
		
		// if the first number is greater than the current position
		if(curr >= c1) {
			answer += (degree_num*(curr-c1));
		}
		
		else {
			answer += (degree_num*(curr+NMAX-c1));
		}
		
		curr = c1;
		
		// turn the dial counter-clockwise 1 full turn
		answer += 360;

		if(curr <= c2) {
			answer += (degree_num*(c2-curr));
		}
		
		else {
			answer += (degree_num*(NMAX+c2-curr));
		}
		
		curr = c2;
		
		if(curr >= c3) {
			answer += (degree_num*(curr-c3));
		}
		
		else {
			answer += (degree_num*(curr+NMAX-c3));
		}
		
		cout << answer << endl;
	}
}
