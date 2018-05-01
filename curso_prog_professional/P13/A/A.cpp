#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

const int MAXN = 100 + 5;
const int MAXM = 51234;

#define NORTH 'N'
#define SOUTH 'S'
#define WEST 'O'
#define EAST 'L'
#define RIGHT_TURN 'D'
#define LEFT_TURN 'E'
#define FORWARD 'F'
#define FORBIDDEN '#'
#define EMPTY '.'
#define STAMP '*'

#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3

// down,up,right,left
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

using namespace std;

char grid[MAXN][MAXN];
int n,m,s,ans,x,y;
char instr[MAXM];
int dir;

inline bool isTurn(char c) {
	if(c == RIGHT_TURN || c == LEFT_TURN) return true;
	return false;
}

inline int getDir(char c) {
	if(c == NORTH) return UP;
	if(c == SOUTH) return DOWN;
	if(c == EAST) return RIGHT;
	return LEFT;
}

inline int changeDir(char c, int dir) {
	if(c == RIGHT_TURN) {
		if(dir == DOWN) return LEFT;
		if(dir == LEFT) return UP;
		if(dir == UP) return RIGHT;
		return DOWN; 
	}
	
	if(dir == DOWN) return RIGHT;
	if(dir == RIGHT) return UP;
	if(dir == UP) return LEFT;
	return DOWN; 
}


int main(void) {
	while(cin >> n >> m >> s && n > 0) {
		ans = 0;
		for(int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				if(grid[i][j] == NORTH || grid[i][j] == SOUTH || grid[i][j] == EAST || grid[i][j] == WEST) {
					y = i;
					x = j;
					dir = getDir(grid[i][j]);
				}
			}
		}
		
		cin >> instr;
		
		for(int k = 0 ; k < s; k++) {
			if(isTurn(instr[k])) {
				dir = changeDir(instr[k], dir);
				continue;
			}
			
			if(x+dx[dir] < 0 || x+dx[dir] >= m || y+dy[dir] < 0 || y+dy[dir] >= n || grid[y+dy[dir]][x+dx[dir]] == FORBIDDEN)
				continue;
			
			x += dx[dir]; y+=dy[dir];
			if(grid[y][x] == STAMP) {
				grid[y][x] = EMPTY;
				ans++;
			}
		}

		cout << ans << endl;
	}

	return 0;	
}
