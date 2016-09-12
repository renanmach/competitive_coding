// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2619
// 11572 - Unique Snowflakes

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
#include <set>
#include <algorithm>
#include <vector>

#include <unordered_map> //C++11


#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln() printf("\n");

#define NMAX 1000000

using namespace std;

typedef std::unordered_map<long,int> intmap;

intmap map(NMAX);


/*
 * Starts counting the snowflakes and add them in a map with the value to the index
 * */
int main(void) {
	int t, n; 
	long number;
	
	scanf("%d", &t);
	
	while(t-- > 0) {
		scanf("%d", &n);
		
		// base
		if(n == 0) {
			printf("%d\n",n);
			continue;	
		}
		
		map.clear();
		
		int begin = 0, count = 0, max =0; // beginning of the block
		for(int i = 1 ; i < n+1; i++) {
			scanf("%ld", &number);
			unordered_map<long,int>::iterator got = map.find(number);
				
			if(got == map.end()) { // not found
				map[number] = i ;
				count++;
			}
			
			else { // found
				if(got->second < begin) { // it was here before the block begins			
					got->second = i;
					count++;
				}
				
				else { // the element is between the actual count
					count = i - got->second; // take the number of the previous elements
					begin = got->second+1;
					
					got->second = i;
				}
			}
			
			max = MAX(max,count);	
		}
		
		printf("%d\n", max);
		
	}

	return 0;
}
