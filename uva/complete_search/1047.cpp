// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3488
// 1047 - Zones
// 27 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
#include <set>

#define sspeed cout.sync_with_stdio(false);

#define MAXN 21
#define MAXM 11

#define SIZE_SN (1 << 20)

int main(void) {
	sspeed
	
	int n,t,m;
	
	int curr_count, answer, max_count;
	
	cin >> n >> t;
	
	int customers[MAXN];
	
	// each common service area is going to have a key and a number of costumers
	int csa_key[MAXM];
	int csa_customers[MAXM];
	
	int test = 1;
	while(n!=0 || t != 0) {
		for(int i = 0 ; i < n ; i++)
			cin >> customers[i];
		
		cin >> m;
		
		int asize, key, v;
		for(int i = 0; i < m ; i++) {
			cin >> asize;
			key = 0;	// key of the pair representing the area
			for(int j = 0 ; j < asize; j++) {
				cin >> v;
				
				// sets 1 to the bits corresponding to the index of the towers
				// present in the common service area. From 0...n-1
				key |= (1 << (v-1));
				
			}
			
			csa_key[i] = key;
			// number of customers
			cin >> csa_customers[i];
		}
		
		max_count = -1e8;
		answer = 0;
		
		// loops through every subset of n
		for(int i = 0; i < (1 << n); i++) {
			// check if the size of the subset is t
			if(__builtin_popcount(i) != t)
				continue;

			curr_count = 0;	
			for(int j = 0 ; j < n ; j++) {
				// if bit j is set
				if(i & (1 << j)) {
					curr_count += customers[j];
				}
			}
			
			if(curr_count < max_count) continue;
			
			// apply the inclusion-exclusion principle
			int match, nmatches;
			// loop through the common service areas
			for(int j = 0 ; j < m ; j++) {
				// matches the area j with the current subgroup of towers
				match = (csa_key[j] & i);
				nmatches = 0;
				for(int k = 0; k < n; k++) {
					if(match & (1 << k)) {
						nmatches++;
					}
				}
				
				if(nmatches > 1) {
					// inclusion-exclusion principle
					curr_count -= (nmatches-1)*csa_customers[j];
				}
			}
			
			if(curr_count >= max_count) {
				if(curr_count == max_count) {
					int x,y;
					// check if the current answer has order less than the
					// max answer
					for(int j = 0; j < n; j++) {
						x = (i & (1 << j));
						y = (answer & (1 << j));
						
						// the jth is different
						if(x!=y) {
							// our current answer has a lower id tower set
							// so change answers
							if(x>0) {
								answer = i;
							}
							break;
						}
					}
				}
				
				// curr_count > max_count
				else {
					max_count = curr_count;
					answer = i;	// the subgroup chosen
				}
			}
		}
		
		cout << "Case Number  " << test << endl;
		cout << "Number of Customers: " << max_count << endl;
		cout << "Locations recommended:";
				
		for(int i = 0 ; i < n; i++) {
			if(answer & (1 << i)) {
				cout << " " << i+1;
			}
		}
		
		cout << endl << endl;
		
		cin >> n >> t;
		test++;
	}
}
