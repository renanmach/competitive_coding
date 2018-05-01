#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

#define MAXN 200009
#define MAX_JUMPS 19

char a[MAXN];
int alen, njumps;

int dp[MAXN][MAX_JUMPS];

int inline sigma(int i) {return (a[i] == 'P')?1:-1;}

int solve(int game, int jumps) {
    if(game >= alen) return 0;
    if(dp[game][jumps] != INT_MIN) return dp[game][jumps];
    return dp[game][jumps] = max(solve(game+1,jumps)+sigma(game), solve((game + 1) + (1 << jumps), jumps+1)-1);
}

int main() {
	int t;
    
	cin >> t;
    
	while(t--) {
		cin >> a;
        alen = strlen(a);
        njumps = ceil(log2(alen));
        
        for(int i = 0 ; i <= alen; i++) 
            for(int j = 0; j <= njumps; j++) 
                dp[i][j] = INT_MIN;
            
        cout << solve(0,0) << endl;
	}
    
	return 0;
}
