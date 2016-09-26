// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2183
// 11242 - Tour de France
// 26 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 

#define sspeed cout.sync_with_stdio(false);

#define MAXFR 12

int partition(double *v, int l, int r) {
	if(r < l)
		return l;
		
	double x = v[r];
	int j = l;
	double t;
	
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

void quicksort(double *v, int l, int r) {
	if(r-l <= 0)
		return;
		
	int j = partition(v, l, r);
	
	quicksort(v, l, j-1);
	quicksort(v, j+1, r);
}


int main(void) {
	sspeed
	
	int f, r;
	int fv[MAXFR], rv[MAXFR];
	
	// drive ratio
	double dr[MAXFR*MAXFR];
		
	cin >> f;
	
	while(f != 0) {
		cin >> r;
		
		// read front sprockets number of teeth
		for(int i = 0 ; i < f; i++) {
			cin >> fv[i];
		}
		
		// read rear sprockets number of teeth
		for(int i = 0 ; i < r; i++) {
			cin >> rv[i];
		}
		
		// calculate te drive ratio
		for(int i = 0 ; i < r; i++) {
			for(int j = 0 ; j < f; j++) {
				dr[(i*f) + j] = (double) rv[i]/fv[j];
			}
		}
		
		// sort the drive ratio vector
		quicksort(dr, 0, (r*f) -1);
		
		double maxval = -1, curr;
		
		// gets the max spread
		for(int i = 0; i < (r*f)-1;i++) {
			curr = dr[i+1]/dr[i];
			
			if(curr > maxval)
				maxval = curr;
		}
		
		cout << fixed << setprecision(2) << maxval << endl;
		
		cin >> f;
	}
	
	return 0;
}
