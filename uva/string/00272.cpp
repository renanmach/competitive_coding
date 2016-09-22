// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=208
// 272 - TEX Quotes
// 22 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>


#define MAXN 1000000

int main() {
	string a;
	bool x = false;
	
	while(getline (cin,a)) {
		string b;
		
		for(int i = 0 ; i < a.size(); i++) {
			if(a[i] == '"') {
				if(!x) {
					b.append("``");
					x = true;
				}
				
				else {
					x = false;
					b.append("\'\'");
				}
			}
			
			else {
				b.append(1, a[i]);
			}
		}
		
		cout << b << endl;	
	}
}
