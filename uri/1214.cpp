//https://www.urionlinejudge.com.br/judge/en/problems/view/1214
// Above Average

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

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln printf("\n");

#define NMAX 1001

int main(void) {
	int c, n;
	
	scanf("%d", &c);
	
	while(c--) {
		scanf("%d", &n);
		double grades[NMAX];
		double avg=0;
		
		for(int i = 0 ; i < n; i++) {
			scanf("%lf", &grades[i]);
			avg += grades[i];
		}	
		avg /= n;
		
		int count =0;
		
		for(int i = 0 ; i < n; i++) {
			if(grades[i] > avg)
				count++;
		}
		
		double answer = count*100.0;
		answer /= n;
		
		printf("%.3lf%%\n", answer);
	}
	
	return 0;
}
