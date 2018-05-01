#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int num[5];
bool found;

bool test_end() {
	return (num[0] == 0 && num[1] == 0 && num[2] == 0 && num[3] == 0 && num[4] == 0);
}

int perform_op(int op, int x, int y) {
	if(op == 0) return x+y;
	if(op == 1) return x-y;
	return x*y;
}

void solve(int a, int b, int c, int d, int e) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				for(int l = 0; l < 3; l++) {
					
					int ans = perform_op(i,a,b);
					ans = perform_op(j,ans,c);
					ans = perform_op(k,ans,d);
					ans = perform_op(l,ans,e);
					
					if(ans == 23) {
						found  = true;
						return;
					}
				}
			}
		}
	}
}

int main(void) {
	
	while(true) {
		found = false;
		cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
		if(test_end()) break;
		
		for(int i = 0 ; i < 5;i++) {
			if(found) break;
			for(int j = 0 ; j < 5;j++) {
				if(found) break;
				for(int k = 0 ; k < 5;k++) {
					if(found) break;
					for(int l = 0 ; l < 5;l++) {
						if(found) break;
						for(int m = 0 ; m < 5;m++) {
							
							if(i == j || i == k || i == l || i == m) continue;
							if(j == k || j == l || j == m) continue;
							if(k == l || k == m) continue;
							if(l == m) continue;
							
							solve(num[i],num[j],num[k],num[l],num[m]);
							if(found) break;
						}
					}
				}
			}
		}	
		
		if(found) cout << "Possible" <<endl;
		else cout << "Impossible" << endl;
	}
	
	return 0;
}
