//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4763
// 12898 - And Or

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
	int t,c =0;
	unsigned long long int a, b;
	
	scanf("%d", &t);
	
	while(c < t) {
		c++;
		scanf("%llu %llu", &a, &b);
		unsigned long long x = a;
		unsigned long long ans_or=0;
		unsigned long long ans_and=1111111111111111111;
		
		while(x<=b) {
			ans_or = x|ans_or;
			ans_and = x&ans_and;
			x++;
		}
		printf("Case %d: %llu %llu\n",c, ans_or, ans_and);
	}
	
	return 0;
}
