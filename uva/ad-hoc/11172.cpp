// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2113
// 11172 - Relational Operator
// 22 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

int main() {
	std::cout.sync_with_stdio(false);
	int t;
	
	cin >> t;
	
	while(t--) {
		int a, b;
		cin >> a >> b;
		
		if(a > b) cout << ">" << endl;
		if(a < b) cout << "<" << endl;
		if(a == b) cout << "=" << endl;
	}
}
