// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=5223
// 7211 - Identifying tea

using namespace std;
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
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
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define pb push_back
#define pf push_front
 
#define forlist for(it=lista.begin(); it != lista.end(); ++it) 
#define forin(n) for(int i=0;i<n;i++)
 
int main() {
	int n=5;
	int t,p;
	int count;
	
	while(scanf("%d", &t) != EOF) {
		count = 0;
		
		forin(5) {
			scanf("%d", &p);
			if(p==t)
				count++;
		}
				
		printf("%d\n", count);	
	}
    return 0;
}
