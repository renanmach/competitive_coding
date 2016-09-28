// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=565
// 624 - CD
// 27 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define sspeed cout.sync_with_stdio(false);

#define MAXN 22


int **z;

void retrieve_sol(bool *x, int *w, int k, int d) {
	if(k!=0) {
		if(z[k][d] == z[k-1][d]) {
			x[k] = false;
			retrieve_sol(x,w,k-1,d);
		}
		
		else {
			x[k] = true;
			retrieve_sol(x,w,k-1,d-w[k]);
		}
	}	
}

int main(void) {
	sspeed
	
	int W, tracks[MAXN], N;
	bool x[MAXN];
	
	z = (int**) malloc(MAXN*sizeof(int *));
	
	while(cin >> W) {
		cin >> N;
		
		for(int i = 0 ; i < MAXN ; i++)
			z[i] = (int *) malloc((W+1)*sizeof(int));
		
		// tracks from 1 to N
		for(int i = 1 ; i <= N ; i++) {
			cin >> tracks[i];
		}
		
		// when the number of tracks is zero
		for(int d = 0 ; d <= W ; d++)
			z[0][d] = 0;
		
		// when the song lenght is zero
		for(int k = 1 ; k <= N ; k++) 
			z[k][0] = 0;
		
		for(int k = 1 ; k <= N ; k++)  {	// from item 1 to N
			for(int d = 1 ; d<=W ; d++) {	// from duration 1 to W
				z[k][d] = z[k-1][d];
				
				// if we can pick the track k and picking it improves the optimal value
				if((tracks[k] <= d) && ((tracks[k] + z[k-1][d-tracks[k]]) > z[k][d])) {
					z[k][d] = tracks[k] + z[k-1][d-tracks[k]];
				}
			}
		}
		
		for(int i = 1 ; i <= N ; i++) {
			x[i] = false;
		}
		
		retrieve_sol(x, tracks, N, W);
		
		for(int i = 1 ; i <= N; i++) {
			if(x[i])
				cout << tracks[i] << " ";
		}
		
		cout << "sum:" << z[N][W] << endl;
		
		
		for(int i = 0 ; i < MAXN ; i++)
			free(z[i]);
	}
	
	free(z);	
}
