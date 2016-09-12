// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895
// 10954 - Add All

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

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define pln() printf("\n");

#define NMAX 5000

using namespace std;

int main() {
	int n, x;
	
	scanf("%d", &n);
	
	while(n !=0 ) {
		priority_queue <int> numbers;
		
		forin(n) {
			scanf("%d", &x);
			numbers.push(x*(-1));
		}
		
		int tot =0, cost;
		
		cost = numbers.top();
		numbers.pop();
		
		cost += numbers.top();
		numbers.pop();
		
		tot += cost;
		
		numbers.push(cost);
		
		while(numbers.size() > 1) {
			cost = numbers.top();
			numbers.pop();
			
			cost += numbers.top();
			numbers.pop();
			
			tot += cost;
			numbers.push(cost);
		}
		
		printf("%d\n", tot*(-1));
		
		scanf("%d", &n);
	}
}
