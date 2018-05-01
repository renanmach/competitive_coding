#include <cstdio>
#include <iostream>


using namespace std;

#define MAXN 62
#define INF 10000000 

int cost[MAXN][MAXN];
int freq[MAXN];
int sum[MAXN]; // sum[i] guarda a soma da freq de todos elementos ANTES de i
int n;

int inline min(int a, int b) {
    return a <= b ? a : b;
}

void solve() {
    int c1,c2;
    
    // diagonal principal
    for (int i = 0; i < n; i++)
        cost[i][i] = 0;
    
    // tamanho da arvore
    for(int u = 1; u < n; u++) {
        // testa as diagonais
        for(int i = 0; i < n-u; i++) {
            int j = u + i;
            cost[i][j] = INF;
            
            for(int r = i; r <= j; r++) {
                c1 = (r-1>=i) ? cost[i][r-1]: 0;
                c2 = (r+1 <= j) ? cost[r+1][j] : 0;
                
                cost[i][j] = min(cost[i][j], c1+c2+sum[j+1]-sum[i]-freq[r]);
            }    
        }  
    }   
}


int main() {
    int t=1;
    cin >> n;
    
    while(n) {
        sum[0] = 0;
        
        for(int i = 0 ; i < n; i++) {
            cin >> freq[i];
            sum[i+1] = sum[i] + freq[i];
        }
        
        sum[n] = sum[n-1] + freq[n-1];
        
        solve();
        
        cout << "Teste " << t++ << endl;
        cout << cost[0][n-1] << endl << endl;
        cin >> n;
    }
}
