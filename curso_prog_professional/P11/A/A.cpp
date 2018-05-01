#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

const int MAXN = 1000005;

using namespace std;

int bs[1009];
int primes[1009];
int primesLen;

void sieve(int upper) {
	memset(bs,1,sizeof(bs));
	bs[0] = bs[1] = 0;
	primesLen = 0;
	
	for(long long i = 2 ; i <=  upper+1; i++) {
		if(bs[i]) {
			for(long long j = i*i; j*j <= upper+1; j+=i) {
				bs[j] = 0;
			}
			primes[primesLen++] = i;	
		}
	}
}

int solve(int x) {
	int ans = 0;
	
	int k = 0, pf = primes[k];
	
	while(x != 1 && (pf*pf <= x)) {
		if(x % pf == 0) {
			ans ++;
			while(x % pf == 0) x /= pf;
		}
		pf = primes[++k];
	}

	if(x != 1) ans++;
	
	return ans;
}

int main(void) {
	int n;
	
	sieve(1005);
	
	while(cin >> n && n != 0) {
		cout << n << " : " << solve(n) << endl;	
	}
	
	return 0;	
}
