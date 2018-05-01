#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define MAXN 1005
string s;
char s2[MAXN];


int main(void) {
	getline(cin,s);
	
	int j = 0;
	for(int i = 0 ; s[i] != '\0'; i+=2) {
		if(s[i] == ' ') {
			 i--;
			 s2[j++] = ' ';
			 continue;
		 }
		s2[j++] = s[i+1];
	}
	
	cout << s2 << endl;
	
	return 0;
}
