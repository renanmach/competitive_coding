// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996
// 10055 - Hashmat the Brave Warrior
// 26 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

int main() {
	std::cout.sync_with_stdio(false);
	long long n,m;
	
	while(cin >> n >> m) {
		if(n>m)
			cout << n-m << endl;
		else
			cout << m-n << endl;
	}
}
