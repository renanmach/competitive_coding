#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

const int MAXN = 200 + 5;

using namespace std;

int c[MAXN][MAXN];
int n, m;

int s1[1005];
int s2[1005];
char s3[1005];

void shift_row(int x, int y) {
	int t;
	
	for(int i = 0 ; i < m; i++) {
		t = c[x][i];
		c[x][i] = c[y][i];
		c[y][i] = t;
	}
}

void shift_col(int x, int y) {
	int t;
	
	for(int i = 0 ; i < n; i++) {
		t = c[i][x];
		c[i][x] = c[i][y];
		c[i][y] = t;
	}
}


int main(void) {
	int k = 0, row = 0;
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(c[i][j] == 1) {
				row = i;
				break;
			}
		}
	}
	
	for(int j = 0; j < m; j++) {
		if(c[row][j] == j+1) continue;
		for(int l = j+1; l < m; l++) {
			if(c[row][l] == j+1) {
				shift_col(j, l); 
				s1[k] = l+1;
				s2[k] = j+1;
				s3[k] = 'C';
				k++;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(c[i][0] == i*m+1) continue;
		
		for(int l = i+1; l < n; l++) {
			if(c[l][0] == i*m+1) {
				shift_row(i, l); 
				s1[k] = l+1;
				s2[k] = i+1;
				s3[k] = 'L';
				k++;
			}
		}
	}
	
	cout << k << endl;
	
	for(int i = 0 ; i < k; i++) {
		cout << s3[i] << " " << s2[i] << " " << s1[i] << endl;
	}
	

	

	return 0;	
}
