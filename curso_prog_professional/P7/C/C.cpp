#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

#define pb push_back

using namespace std;

const int MAXN = 300+5;
const int INF = -1;

class Node {
public:
    bool visited;
    int pi;
    vector<int>next;
};

Node g[MAXN];
int cities[MAXN];
int n,k;
int used_edge[MAXN][MAXN];


void dfs(int u) {
    int v;
    g[u].visited = true;
    
    for(int j = 0 ; j < (int) g[u].next.size(); j++) {
        v = g[u].next[j];
        
        if(!g[v].visited) {
            g[v].pi = u;
            dfs(v);
        }
    }
}


int solve() {
    memset(used_edge,0,sizeof(used_edge));
    
    int tickets = 0;

    for(int i = 0 ; i < n; i++) {
        g[i].visited = false;
        g[i].pi = -1;
    }
    
    dfs(0);
    
    for(int i = 0 ; i < k; i++) {
        int x = cities[i];
        int y = g[x].pi;
        
        while(y!=-1 && !used_edge[x][y]) {
            used_edge[x][y] = used_edge[y][x] = 1;
            
            tickets++;
            
            x = y;
            y = g[x].pi;
        }
    }
    
    return tickets << 1;
}

int main(void) {
    int a,b,tt=1;
    cin >> n >> k;
    
    while(n!=0&&k!=0) {
        for(int i =0 ; i < n; i++) {
            g[i].next.clear();
        }
        
        for(int i = 0 ; i < n-1; i++) {
            cin >> a >> b;
            a--;b--;
            
            g[a].next.pb(b);
            g[b].next.pb(a);
        }
        
        
        for(int i = 0; i < k; i++) {
            cin >> cities[i];
            cities[i]--;
        }
        
        cout << "Teste " << tt++ << endl;
        cout << solve() << endl << endl;
        
        cin >> n >> k;
    }
    
    
    return 0;
}
