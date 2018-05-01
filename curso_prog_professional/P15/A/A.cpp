#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
typedef unsigned long long ull;

#define debug(x) cout << #x << " = " << x << endl
#define spc ' '
const int MAXN = 1000 + 5;

char s[MAXN];
int ans[3*MAXN];

int mylen() {
	int i = 0;
	while(s[i] != '\0') i++;
	return i;
}


int main(void) {
	int t;
	ios::sync_with_stdio(false);
	
	cin >> t;
	
	while(t--) {
		cin >> s;
		int n = mylen();
		
		if(n == 1) {
			cout << "1" << s[0] << endl;
			continue;
		}

		int j = 0, count = 0;
		
		
		for(int i = 1; i <= n; i++) {
			count++;
			
			if(s[i] != s[i-1]) {
				ans[j++] = count;
				ans[j++] = s[i-1]-'0';
				count = 0;
			}
			

		}
		
		for(int i = 0; i < j; i++) {
			cout << ans[i];
		}
		cout << endl;
	}
	

	
	
	return 0;	
}
