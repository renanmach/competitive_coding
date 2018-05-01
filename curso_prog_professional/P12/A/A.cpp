#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

const int MAXN = 1e5 + 7;

char s[MAXN];
int pos1[MAXN],pos2[MAXN];


using namespace std;


int main(void) {
	cin >> s;
	
	int p1n = 0, p2n= 0;
	
	int len = strlen(s);
	
	
	for(int i =0 ; i < len-1; i++) {
		if(s[i] == 'A' && s[i+1] == 'B') pos1[p1n++] = i;
		if(s[i] == 'B' && s[i+1] == 'A') pos2[p2n++] = i; 
	}
	
	
	bool found = false;
	for(int i = 0 ; i < p1n && !found; i++) {
		for(int j = 0; j < p2n && !found; j++) {
			if(max(pos1[i],pos2[j])-min(pos1[i],pos2[j]) > 1) found = true;
		}
	}
	
	if(found) cout << "YES\n";
	else cout << "NO\n";

	return 0;	
}
