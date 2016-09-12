// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3140
// 5139 - Rare Order

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln printf("\n");

#define NMAX 10000

#define ENTRO printf("entro\n");

typedef long long LL;

#define sspeed std::cout.sync_with_stdio(false);

typedef struct {
	bool visited;
	bool used; // marks which letters appeared in the sequences
	int d;
	int f;
	vector<int> next;
	char c;
} Node;

int t = 0;
list<Node> ans;

void dfs_visit(vector<Node> &g, int u) {
	g[u].visited = true;
	g[u].d = (++t);
	
	for(int i = 0 ; i < (int) g[u].next.size(); i++) {
		int v = g[u].next[i];
		
		
		if(!g[v].visited) {

			dfs_visit(g, v);
		}
	}
	
	g[u].f = (++t);
	
	ans.pf(g[u]);
}

void dfs(vector<Node> &g) {
	int n = (int) g.size();
	
	for(int i = 0; i <n ; i++) {
		g[i].visited = false;
	}
	
	for(int i=0;i<n;i++) {
		if(!g[i].visited && g[i].used) {
			dfs_visit(g, i);
		}
	}
	
}

void topological_sort(vector<Node> &g) {
	dfs(g);
}

int main(void) {
	sspeed
	
	vector<string> words;
	string s;
	
	cin >> s;
	
	vector<Node> g;
	
	 // number of letters in the English alphabet
	g.resize(26);
	
	while(s.compare("#") != 0) {
		words.pb(s);
		cin >> s;
	}
	
	// marks which letters appeared in the sequences
	forin(26) {
		g[i].used = false;
		g[i].c = 'A'+i;
	}
	
	for(int i = 0; i < (int) words.size()-1; i++) {
		for(int j = 0; j < (int)words[i].size() && j < (int)words[i+1].size() ; j++) {
			if(words[i].at(j) != words[i+1].at(j)) {				
				g[words[i].at(j)- 'A'].next.pb(words[i+1].at(j) - 'A');
				
				g[words[i].at(j)- 'A'].used = true;
				g[words[i+1].at(j)- 'A'].used = true;
				
				break;	
			}
		}
	}
	
	topological_sort(g);
	
	for (list<Node>::iterator it=ans.begin(); it != ans.end(); ++it) {
		cout << it->c;
	}
	
	cout << endl;
	
	return 0;
}
