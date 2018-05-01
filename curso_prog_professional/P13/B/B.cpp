#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>


using namespace std;

#define WARCRAFT '#'
#define WATER '.'

const int MAXN = 100 + 5;
char grid[MAXN][MAXN];
int m[MAXN][MAXN];

// 2 ... nships+1
int count[MAXN*MAXN];
int N,M;

int dx[] = {0,  0, 1, 1,  1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1,  0,  1, -1};

void markShip(int i, int j, int id) {
	m[i][j] = id;
	for(int k = 0; k < 8; k++) {
		if(i+dx[k] >= 0 && i+dx[k] < N && j+dy[k] >= 0 && j+dy[k] < M && m[i+dx[k]][j+dy[k]] == 1) {
			markShip(i+dx[k],j+dy[k],id);
		}
	}
}

int getShips() {
	int id = 2;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(m[i][j] == 1) {
				markShip(i,j,id);
				id++;
			}
		}
	}
	return id;
}

int main(void) {
	int k,l,c,destroyed=0;
	
	cin >> N >> M;
	
	for(int i = 0 ; i < N; i++) {
		cin >> grid[i];
	}
	
	for(int i = 0 ; i < N; i++) {
		for(int j = 0 ; j < M; j++)	{
			m[i][j] = grid[i][j] == WATER ? 0 : 1;
		}
	}
	
	int nships = getShips()-1;
	
	cin >> k;
	
	for(int i = 0 ; i < k; i++) {
		cin >> l >> c; l--; c--;
		m[l][c] = 0;
	}
	
	for(int i = 0 ; i < N; i++) {
		for(int j = 0 ; j < M; j++)	{
			if(m[i][j] != 0) {
				count[m[i][j]]++;
			}
		}
	}
	
	for(int i = 2; i <= nships; i++) {
		if(count[i]==0) destroyed++;
	}
	
	
	cout << destroyed << endl;

	return 0;	
}
