// 352 - The Seasonal War
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXN 27

int nwe;
char mat[MAXN][MAXN];



void remove_war_eagle(int x, int y, int n) {
    mat[x][y] = 0;
    
    for(int i = x-1; i <= x+1; i++) {
        if(i < 0 || i > n) continue;
        for(int j = y-1; j <= y+1; j++) {
            if(j < 0 || j > n) continue;
            
            if(mat[i][j] == '1') remove_war_eagle(i,j,n);
        }
    }
}


int main() {
    int n,count=1;
    
    while(scanf("%d",&n) != EOF) {
        nwe = 0;

        for(int i = 0 ; i < n; i++) {
            getchar();
            for(int j = 0 ; j < n; j++) {
                scanf("%c",&mat[i][j]);
            }
        }
        
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n; j++) {
                if(mat[i][j] == '1') {
                    nwe++;
                    remove_war_eagle(i,j,n);
                }
            }
        }
        
        cout << "Image number " << count++ << " contains " << nwe << " war eagles." << endl;
    }
    
    
    
    return 0;
}
