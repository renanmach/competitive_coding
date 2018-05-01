#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int p2[] = {1,2,4,8,16,32,64,128,256};

int main(void) {
	int n,b,p,k,m;
	int bn=0;
	
	cin >> n >> b >> p;
	
	m = n;
	
	while(m > 1) {
		for(k = 8 ; k >=0 ; k--) {
			if(p2[k] <=m) {
				
				
				bn += p2[k]/2 + p2[k]*b; 
				
				//cout << " m= "<<m << " k="<<k << " pk="<<p2[k]<<  " bn=" << bn<< endl;
				break;
			}
		}
		
		m = p2[k]/2 + (m-p2[k]);
	}

	cout << bn << " " << n*p << endl;
	
	return 0;	
}
