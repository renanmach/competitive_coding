#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f
const int MAXN = 500+5;
const int MAXM = 10000 + 5;


typedef pair<int,int> pii;
typedef vector<pii> vii;

class Edge {
public:
    int v, w,u;
    bool valid;
    Edge(int a, int b) {
        v = a; w = b;
        valid = true;
    }
};

class Node {
public:
    int d;
    vector<Edge*> pi;
    int id;
    bool visited;
    
    bool operator < (const Node &a) const {
        if(d < a.d) return false;
        return true;
    }
};

vector<Edge> edges[MAXM];
Node g[MAXN];

int n,m;


void dijkstra(int s) {
    int u, v,uvd;
    
    g[s].d = 0;
    
    priority_queue<Node> pq;
    pq.push(g[s]);
    
    while(!pq.empty()) {
        Node nu = pq.top(); pq.pop();
        u = nu.id;
        
        for(int j = 0 ; j < (int) edges[u].size(); j++) {
            v = edges[u][j].v;
            uvd = edges[u][j].w;
            
            if(g[u].d + uvd < g[v].d) {
                g[v].d = g[u].d + uvd;
                g[v].pi.clear();
                
                // aresta da posicao j da lista do vertice u pertence a um
                // caminho minimo
                g[v].pi.pb(&edges[u][j]);
                pq.push(g[v]);
            }
            else if(g[u].d + uvd == g[v].d) {
                g[v].pi.pb(&edges[u][j]);
                pq.push(g[v]);
            }
        }
    }
}

void dfs(int u) {
    g[u].visited = true;
    
    for(int j =0 ; j < (int) g[u].pi.size(); j++) {
        if(g[g[u].pi[j]->u].visited) continue;
        g[u].pi[j]->valid = false;
        g[g[u].pi[j]->u].visited = true;
        dfs(g[u].pi[j]->u);
    }
}

// marca toda arestas de todos caminhos minimos como invalidas
void markEdges(int t) {
    dfs(t);
}

void dijkstra2(int s, int t) {
    int u,v,uvd;
    
    for(int i = 0 ; i < n; i++) {
        g[i].d = INF;
    }
    
    g[s].d = 0;
    priority_queue<Node> pq;
    pq.push(g[s]);
    
    while(!pq.empty()) {
        Node nu = pq.top(); pq.pop();
        u = nu.id;
        
        for(int j = 0 ; j < (int) edges[u].size(); j++) {
            if(edges[u][j].valid == false) continue;
            
            v = edges[u][j].v;
            uvd = edges[u][j].w;
            
            if(g[u].d + uvd < g[v].d) {
                g[v].d = g[u].d + uvd;
                pq.push(g[v]);
            }
        }
    }
}

int main() {
    int s,t,a,b,c;
    cin >> n >> m;
    
    while(n != 0) {
        cin >> s >> t;
        for(int i = 0 ;i < n; i++) {
            g[i].d = INF;
            g[i].id = i;
            g[i].pi.clear();
            edges[i].clear();
            g[i].visited = false;
        }
        
        for(int i = 0 ; i < m; i++) {
            cin >> a >> b >> c;
            edges[a].pb(Edge(b,c));
            edges[a].back().u = a;
        }
        
        dijkstra(s);
        markEdges(t);
        dijkstra2(s,t);
        
        
        cout << (g[t].d == INF ? -1 : g[t].d) << endl;
        
        cin >> n >> m;
        
    }
    
    return 0;
}
