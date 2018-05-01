#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100005

int k,n;

class UnionFind {
public:
	vector<int> rank;
	vector<int> p;
	
	UnionFind(int n) {
		rank.assign(n,0);
		p.assign(n,0);
		for(int i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	
	int findSet(int x) {
		if(p[x] == x) return x;
		
		p[x] = findSet(p[x]);
		
		return p[x];
	}
	
	bool isSameSet(int x, int y) {
		return findSet(x) == findSet(y);
	}
	
	void UnionSet(int x, int y) {
		if(isSameSet(x,y)) return;
		
		int k = findSet(x), l = findSet(y);
		
		if(rank[k] == rank[l]) {
			rank[l]++;
			p[l] = k;
		}
		
		else if(rank[k] > rank[l]) {
			p[l] = k;
		}
		
		else {
			p[k] = l;
		}
	}
};

int main(void) {
	char op;
	int x,y;
	
	cin >> n >> k;
	
	UnionFind uf(n);
	
	for(int q = 0 ; q < k; q++) {
		cin >> op >> x >> y;
		x--;
		y--;
		
		if(op == 'C') {
			if(uf.isSameSet(x,y)) cout << "S" << endl;
			else cout << "N" << endl;
		}
		
		else {
			uf.UnionSet(x,y);
		}
	}
	
	return 0;
}
