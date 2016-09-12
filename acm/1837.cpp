// http://acm.timus.ru/problem.aspx?space=1&num=1837
// 1837. Isenbaev's Number

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

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln() printf("\n");

#define NMAX 300

typedef struct {
	string name;
	int number;
	bool visited;
	vector<int> next;
} Node;

void bfs(vector<Node> &graph, int s) {
	graph[s].visited = true;
	graph[s].number = 0;
	
	queue<int> q;
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(int i = 0; i < (int)graph[u].next.size(); i++) {
			int v = graph[u].next[i];
			if(!graph[v].visited) {
				graph[v].visited = true;
				graph[v].number = graph[u].number+1;
				q.push(v);
			}
		}
	}
}

bool comp(Node g1, Node g2) {
	if(g1.name.compare(g2.name) > 0)
		return false;
	else
		return true;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	int n, i=0;
	string m[3];
	int id[3], id_Isenbaev=-1;
	
	cin >> n;
	
	vector<Node> graph;
	map<string, int> members;
	map<string,int>::iterator it;
	
	while(n--) {	
		forjn(3) {
			cin >> m[j];
			
			it = members.find(m[j]);
		
			if(it == members.end()) {
				members.insert(pair<string,int>(m[j], i));
				id[j] = i;
				
				graph.pb((Node) {m[j], -1, false, vector<int>()});
				i++;
			}
			
			else {
				id[j] = it->second;
			}
			
			if(id_Isenbaev == -1 && m[j].compare("Isenbaev") == 0) {
				id_Isenbaev = id[j];
			}
		}
		
		forjn(3) {
			for(int h = 0 ; h < 3; h++) {
				if(j == h)
					continue;
				graph[id[j]].next.pb(id[h]);	
				
			}
		}
	}
	

	if(id_Isenbaev != -1)
		bfs(graph, id_Isenbaev);
		
	sort(graph.begin(), graph.end(), comp);
	
	forin(graph.size()) {
		if(graph[i].number == -1) {
			cout << graph[i].name << " undefined" << endl;
		}
		
		else {
			cout << graph[i].name << " " << graph[i].number << endl;
		}
	}
}

