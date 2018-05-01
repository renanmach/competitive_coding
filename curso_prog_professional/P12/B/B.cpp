#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

typedef unsigned long long ull;

const ull MOD = 1e9 + 9;

#define DIM 3

class Matrix {
public:
	ull m[DIM][DIM];
};

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans;
	ull k;
	
	for(int i = 0; i < DIM; i++) {
		for(int j = 0; j < DIM; j++) {
			for(ans.m[i][j] = k = 0; k < DIM; k++) {
				ans.m[i][j] += (a.m[i][k]%MOD)*(b.m[k][j]%MOD);
				ans.m[i][j] %= MOD;
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix mat, ull n) {
	Matrix ans; 
	
	for(int i = 0 ; i < DIM; i++) {
		for(int j = 0; j < DIM; j++) {
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
	
	memset(ans.m,0,sizeof(ans.m));
	ans.m[0][0] = ans.m[0][1] = ans.m[0][2] = ans.m[1][0] = ans.m[2][1] = 1;
	
	ans = matPow(ans, n-1);
	
	return (ans.m[0][1])%MOD;
}

int main(void) {
	ull n;
	
	while(cin >> n && n != 0) {
		if(n == 1) cout << "0" << endl;
		else if(n == 2) cout << "1" << endl;
		else if(n == 3) cout << "2" << endl;
		else cout << solve(n) << endl;	
	}
	
	return 0;	
}
