#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100000+5;

typedef pair<int,int> pii;
typedef long long unsigned int ull;


vector< pair<int, pii> > edges;
int milkman[MAXN];
int connected;


class UnionFind {
public:
	vector<int> rank;
	vector<int> p;
	vector<int> hasMilkman;
	vector<int> numNormal;
	
	UnionFind(int n) {
		rank.assign(n,0);
		p.assign(n,0);
		hasMilkman.assign(n,0);
		numNormal.assign(n,0);
		
		for(int i = 0; i < n; i++) {
			p[i] = i;
			if(milkman[i]) hasMilkman[i] = 1;
			else numNormal[i] = 1;
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
	
	void UnionSet(int i, int j) {
		if(isSameSet(i,j)) return;
		
		int x = findSet(i), y = findSet(j);
		
		if(hasMilkman[x] == 1 || hasMilkman[y] == 1) hasMilkman[x] = hasMilkman[y] = 1;

		if(rank[x] == rank[y]) {
			rank[y]++;
			p[x] = y;
			numNormal[y] += numNormal[x];
		}
		
		else if(rank[x] > rank[y]) {
			p[y] = x;
			numNormal[x] += numNormal[y];
		}
		
		else {
			p[x] = y;
			numNormal[y] += numNormal[x];
		}
	}
};



ull agm(int n, int m) {
	ull cost = 0;
	UnionFind uf(n);
	
	sort(edges.begin(),edges.end());

	for(int i = 0 ; i < m; i++) {
		if(connected == n) return cost;
		
		pair<int, pii> front = edges[i];
		
		int a = front.second.first, b = front.second.second;
		if(!uf.isSameSet(a,b)) {
			int x = uf.findSet(a); 
			int y = uf.findSet(b);
			
			if(uf.hasMilkman[x] == 1 && uf.hasMilkman[y] == 1) continue;
			
			if(uf.hasMilkman[x] == 1 && uf.hasMilkman[y] == 0) connected += uf.numNormal[y];
			else if(uf.hasMilkman[x] == 0 && uf.hasMilkman[y] == 1) connected += uf.numNormal[x];
			
			cost += front.first;
			uf.UnionSet(x,y);
		}
	}
	
	return cost;
}


int main(void) {
	int T;
	int n,m,a,b;
	int c;
	
	cin >> T;
	
	while(T--) {
		connected = 0;
		edges.clear();
		cin >> n >> m;
		
		for(int i =0 ; i < n; i++) {
			cin >> milkman[i];
			if(milkman[i]) connected++;
		}
		
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			a--;b--;
			
			edges.push_back(pair<int,pii>(c,pii(a,b)));
		}
		
		ull ret = agm(n,m);
		
		if(connected == n)
			cout << ret << endl;
		else cout << "impossible" << endl;
	}
	
	return 0;	
}
