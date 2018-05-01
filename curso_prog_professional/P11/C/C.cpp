#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

typedef unsigned long long ull;

const ull MOD = 1000000007;

class Matrix {
public:
	ull m[2][2];
};

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans;
	ull k;
	
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			for(ans.m[i][j] = k = 0; k < 2; k++) {
				ans.m[i][j] += (a.m[i][k]%MOD)*(b.m[k][j]%MOD);
				ans.m[i][j] %= MOD;
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix mat, ull n) {
	Matrix ans; 
	
	for(int i = 0 ; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			ans.m[i][j] = (i==j);
		}
	}
	
	while(n > 0) {
		if(n%2) ans = matMul(ans,mat);
		mat = matMul(mat, mat);
		n /=2;
	}
	
	return ans;
}

ull solve(ull n) {
	Matrix ans;
	
	ans.m[0][0] = 3; ans.m[0][1] = 1; ans.m[1][0] = 1; ans.m[1][1] = 3;
	ans = matPow(ans, n);
	
	return ans.m[0][0];
}



int main(void) {
	ull n;
	cin >> n;
	
	if(n == 0) cout << "1" << endl;
	
	else {
		cout << solve(n) << endl;
	}
	
	return 0;	
}
