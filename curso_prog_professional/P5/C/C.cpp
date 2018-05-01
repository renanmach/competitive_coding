#include <cstdio>
#include <cstring>
#include <iostream>

#define MAXN 2009
#define min(a,b) ((a) < (b) ? (a) : (b))


using namespace std;

char a[MAXN];
int n;
int palindrome[MAXN][MAXN];
int dp[MAXN];


void print_palindrome_mat() {
    cout << endl;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            cout << palindrome[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_dp() {
    cout << endl;
    
     for(int i = 0 ; i < n; i++) {
         cout << dp[i] << " ";
     }
    
    
    cout << endl << endl;
    
}


void preprocess() {
    memset(palindrome,0,sizeof(palindrome));
    
    // caso base
    for(int i = 0; i < n; i++) {
        palindrome[i][i] = 1;
    }
    
    // preenche diagonais
    for(int k = 1; k < n; k++) {
        for(int i = 0; i < n; i++) {
            // pontas da substring diferentes
            if(a[i] != a[i+k]) continue;
            
            // substring de tamanho dois e com dois caracteres iguais
            if(k == 1) {
                palindrome[i][i+k] = 1;
            }

            else if(palindrome[i+1][i+k-1] == 1) {
                palindrome[i][i+k] = 1;
            }
        }
    }
    
   // print_palindrome_mat();
    
}

void solve() {
    preprocess();
    
    dp[0] = 0;
    
    for(int i = 1 ; i < n; i++) {
        dp[i] = n+1; // infinito
        for(int k = i; k>=0; k--) {
            if(palindrome[k][i]) {
                dp[i] = min(dp[i], (k > 0) ? dp[k-1] +1: 0);     
            }  
        }
    }
    
   // print_dp();
    
}


int main(void) {
    int t = 0;
    
    while(cin >> n && n != 0) {
        cin >> a;
        solve();
        
        cout << "Teste " << ++t << endl;
        cout << dp[n-1]+1 << endl << endl;
    }
    
    return 0;
}
