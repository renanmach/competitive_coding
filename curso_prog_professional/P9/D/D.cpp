#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2*1e5 + 5;

int cap[MAXN];
int curr[MAXN];

class UnionFind {
public:
    vector<int> p;
    int nel;
    
    UnionFind(int n) {
        nel = n;
        p.assign(n,0);
        
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int findSet(int x) {
        if(x == p[x]) return x;
        p[x] = findSet(p[x]);
        return p[x];
    }
        
    bool isSameSet(int x, int y) {
        return findSet(x) == findSet(y);
    }
    
    void UnionSet(int i, int j) {        
        if(isSameSet(i,j)) return;
        
        int x = findSet(i), y = findSet(j);
        
        if(y > x) {
            p[x] = y;
        }
        else {
            p[y] = x;
        }
    }
};


int main() {
    int n,m,op,x,p;

    cin >> n;
    
    UnionFind uf(n);

    for(int i = 0 ; i < n ; i++) {
       cin >> cap[i];
       curr[i] = 0;
    } 
    
    cin >> m;
    
    while(m--) {
        cin >> op;
        
        if(op == 1) {
            cin >> x >> p; x--;

            while(p > 0) { 
                x = uf.findSet(x);
                
                if(x == n-1 && curr[x] == cap[x]) break;
                
                if(curr[x]+p >= cap[x]) {
                    p = p - (cap[x] - curr[x]);
                    curr[x] = cap[x];
                    if(x == n-1) p = 0;
                    else uf.UnionSet(x,x+1);
                }
                
                else {
                    curr[x] += p;
                    p = 0;
                }
            }
        }
        
        else {
            cin >> x; x--;
            cout << curr[x] << endl;  
        }
    }
    
    return 0;
}
