// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2493
// 11498 - Division of Nlogonia

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <istream>
#include <iomanip>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <climits>

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln printf("\n");

#define NMAX 1001


int main(void) {
	int k;

	cin >> k;
	
	while(k != 0) {
		int n,m;
		int x,y;
		
		cin >> n >> m;
		
		while(k--) {
			cin >> x >> y;
			
			if(x == n) {
				cout << "divisa" << endl;
			}
			
			else if(y == m) {
				cout << "divisa" << endl;
			}
			
			else if(x > n) {
				if(y > m) {
					cout << "NE" << endl;
				}
				else {
					cout << "SE" << endl;
				}
			}
			
			else if(y > m) {
				cout << "NO" << endl;
			}
			
			else {
				cout << "SO" << endl;
			}
		}
		cin >> k;
	} 
}
