// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2498
// 11503 - Virtual Friends
// 16 september

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
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <climits>

#define pb push_back
#define pf push_front
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define sspeed std::cout.sync_with_stdio(false);

// to map the string names to ids
typedef unordered_map<string,int> intmap; 

#define NMAX 100100

int parent[NMAX];


// get the parent of the group
// if the value of the parent is negative, then it is the size of the group
// *-1
// Uses path compression
int find_parent(int x) {
	if(parent[x] < 0) 
		return x;	// parent[x]*-1 is the size of the group and x is the representative of the group
	
	// path compression
	parent[x] = find_parent(parent[x]);
	
	return parent[x];
}

int main() {
	sspeed
	int n,f;
	
	cin >> n;
	

	while(n--) {
		cin >> f;
		
		int last_index = -1;
		int aid,bid,paid,pbid;
	
		
		// map the string name to ids
		intmap mymap;
		
		string a,b;

		memset(parent,-1,sizeof(parent));

		// while there is friendships beginning
		while(f--) {
			cin >> a >> b;
			
			intmap::iterator got = mymap.find(a);
			
			// did not find a
			if(got == mymap.end()) {
				mymap.insert({a,++last_index});
				aid=last_index;
			} 
			
			else {
				aid = got->second;
			}
			
			got = mymap.find(b);
			
			if(got == mymap.end()) {
				mymap.insert({b,++last_index});
				bid=last_index;
			} 
			
			else {
				bid = got->second;
			}	
			
			paid = find_parent(aid);
			pbid = find_parent(bid);
			
			// if the new friends belong to the same group
			if(paid == pbid) {
				// output the size of the group
				cout << parent[paid]*-1 << endl;
			}
			
			else if(parent[paid] < parent[pbid]){
				// unite the groups
				parent[paid] += parent[pbid];
				
				// the representative of the group that b belongs will point to
				// the representative of the group a belongs
				parent[pbid] = paid;
				
				cout << parent[paid]*-1 << endl;
			}
			
			else {
				parent[pbid] += parent[paid];
				parent[paid] = pbid;
				
				cout << parent[pbid]*-1 << endl;
			}
			
		}
			 
	}
	
	return 0;
}
