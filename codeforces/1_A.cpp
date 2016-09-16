// http://codeforces.com/problemset/problem/1/A
// Theatre Square
// math
// 15 September 2016

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
 
int main() {
	double m,n,a; 
	
	cin >> m >> n >> a;
	
	double mx = m/a;
	double nx = n/a;
	
	
	long long mxx = mx;
	long long nxx = nx;
	
	if(fmod(mx,1.0) > 0.0) {
		mxx++;
	}
	
	if(fmod(nx,1.0) > 0.0) {
		nxx++;
	}
	
	cout << mxx*nxx << endl;
	
    return 0;
}
