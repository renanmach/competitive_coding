//https://www.urionlinejudge.com.br/judge/en/problems/view/1897
// URI Online Judge | 1897

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
#include <unordered_map>

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln printf("\n");

typedef long long LL;

#define ENTRO printf("entro\n");
#define DEBUGINT(x) printf("%d\n",x);

#define sspeed std::cout.sync_with_stdio(false);


int solve(int n , int m) {
	unordered_map<int, int> visited;
	unordered_map<int, int>::iterator it;
	
	if(n == m)
		return 0;
	
	visited.insert({n, 0});
	
	queue<int> q;
	
	q.push(n);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		int du = visited.find(u)->second;
	
		if(m == u/2 || m == u/3|| m == 2*u|| m == 3*u|| m == u+7|| m == u-7)
			return du+1;
			
		int v = u/2;
		
		it = visited.find(v);
		
		if(it == visited.end()) { // still not visited
			visited.insert({v, du+1});
			q.push(v);
		}
		
		v = u/3;
		
		it = visited.find(v);
		
		if(it == visited.end()) { // still not visited
			visited.insert({v, du+1});
			q.push(v);
		}
		
		v = 2*u;
		
		it = visited.find(v);
			
		if(it == visited.end()) { // still not visited
			visited.insert({v, du+1});
			q.push(v);
		}
		
		v = 3*u;
			
		it = visited.find(v);
			
		if(it == visited.end()) { // nao visitou ainda
			visited.insert({v, du+1});
			q.push(v);
		}
		
		v = u+7;
			
		it = visited.find(v);
			
		if(it == visited.end()) { // still not visited
			visited.insert({v, du+1});
			q.push(v);
		}
		
		v = u-7;
		
		it = visited.find(v);
			
		if(it == visited.end()) { // nao visitou ainda
			visited.insert({v, du+1});
			q.push(v);
		}
	}
	
	return INT_MAX;
}

int main(void) {
	sspeed
	
	int n,m;
	
	cin >> n >> m;
	
	cout << solve(n,m) << endl;

	return 0;
}
