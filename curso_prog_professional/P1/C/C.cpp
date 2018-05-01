#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN (1 << 20) + 5

typedef unsigned long long ull;

ull tree[MAXN];

int inline get_p_id(int p, int n) {
    return (1 << n) + (p-1);
}

void build_tree(int n) {
    int start = 1 << n;
    
    for(int i = start; i < start+(1 << n); i++) {
        cin >> tree[i];
    }
    
    bool op = true;
    int level = n;
    
    while(level != 0) {
        for(int i = 1 << level; i < (1 << (level+1)); i+=2) {
            tree[i/2] = op ? tree[i] | tree[i+1]: tree[i] ^ tree[i+1]; 
        }
        
        op = !op;
        level--;
    }
}

void calculate_v(int pid, int n) {
    int level = n;
    
    int father = pid/2,s1,s2;
    bool op = true;
    
    while(level != 0) {
        s1 = pid;
        s2 = pid % 2 ? pid-1 : pid+1;
        
        tree[father] = op ? tree[s1] | tree[s2]: tree[s1] ^ tree[s2]; 
        
        op = !op;
        
        level--;
        pid = father;
        father = father/2;
    }
}

int main(void) {
    int n,m,p,pid;
    ull b;
    
    cin >> n >> m;
    
    build_tree(n);
    
    
    for(int i = 0; i < m; i++) {
        cin >> p >> b;
        pid = get_p_id(p,n);
        tree[pid] = b;
        
        calculate_v(pid, n);
        
        cout << tree[1] << endl;
    }
     
    
    return 0;
}
