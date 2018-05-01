#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1000
#define INF MAXN*MAXN*(-501)
#define LEFT 0
#define RIGHT 1
#define UP 2

int n,m;
// 0 ->, 1 <-, 2 \/
int memo[MAXN][MAXN][3];
int worm[MAXN][MAXN];

int inline max(int a, int b) {
    return a >= b ? a : b;
}

int main() {
    int t = 1;
    
    cin >> n >> m;
    
    while(n != 0 && m != 0) {
        //memset(memo,-1,sizeof(memo));
        
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                cin >> worm[i][j];
            }
        }
        
        memo[0][0][LEFT] = memo[0][0][UP] =  worm[0][0];
        memo[0][0][RIGHT] = INF;
        
        for(int j = 1 ; j < m; j++) {
            memo[0][j][LEFT] = memo[0][j][UP] = memo[0][j-1][LEFT] + worm[0][j];
            memo[0][j][RIGHT] = INF;
        }
        
        for(int i = 1; i < n; i++) {
            memo[i][0][LEFT] = INF;
            memo[i][0][UP] = max(memo[i-1][0][UP],memo[i-1][0][RIGHT])+worm[i][0];
            
            for(int j = 1 ; j < m; j++) {
                memo[i][j][LEFT] = max(memo[i][j-1][LEFT],memo[i][j-1][UP]) + worm[i][j];
                memo[i][j][UP] = max(memo[i-1][j][UP],max(memo[i-1][j][LEFT],memo[i-1][j][RIGHT])) + worm[i][j];
            }
            
            memo[i][m-1][RIGHT] = INF;
            memo[i][m-1][UP] = max(memo[i-1][m-1][UP],memo[i-1][m-1][LEFT])+worm[i][m-1];
            
            for(int j = m-2; j >=0; j--) {
                 memo[i][j][RIGHT] = max(memo[i][j+1][RIGHT],memo[i][j+1][UP]) + worm[i][j];
            }
        }
        
        cout << "Teste " << t++ << endl;
        
        cout << max(memo[n-1][m-1][LEFT],memo[n-1][m-1][UP]) << endl << endl;
        
        cin >> n >> m;
    } 
}
