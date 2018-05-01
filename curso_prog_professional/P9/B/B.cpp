#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

char mat[11][11];


int main(void) {
	
	
	for(int i = 0 ; i < 10; i++) {
		cin >> mat[i];
	}
	
	
	int curr = 0;
	bool found = false;
	int k;
	
	for(int i = 0 ; i < 10 && !found; i++) {
		curr = 0;
		for(int j = 0 ; j < 10 && !found; j++) {
			
			
			if(mat[i][j] == 'O') curr = 0;
			
			else if(mat[i][j] == 'X' ||  mat[i][j] == '.') {
				k = j+1;
				bool tried = false;
				if(mat[i][j] == '.') tried = true;
				curr = 1;

				while(k < 10 && (mat[i][k] == 'X' || (tried == false && mat[i][k] == '.'))) {
					if(mat[i][k] == '.') tried = true;
					k++;
					curr++;
					if(curr >=5) {
						found = true;
						break;
					}
				}
			}
		}
	}
	
	
	// DOWN
	for(int j = 0 ; j < 10 && !found; j++) {
		curr = 0;
		for(int i = 0 ; i < 10 && !found; i++) {
			if(mat[i][j] == 'O') curr = 0;
			
			else if(mat[i][j] == 'X' ||  mat[i][j] == '.') {
				k = i+1;
				bool tried = false;
				if(mat[i][j] == '.') tried = true;
				curr = 1;

				while(k < 10 && (mat[k][j] == 'X' || (tried == false && mat[k][j] == '.'))) {
					if(mat[k][j] == '.') tried = true;
					k++;
					curr++;
					if(curr >=5) {
						found = true;
						break;
					}
				}
			}
		}
	}
	
	// DIAG >>
	for(int i = 0 ; i < 10 && !found; i++) {
		curr = 0;
		for(int j = 0 ; j < 10 && !found; j++) {
			if(mat[i][j] == 'O') curr = 0;
			
			else if(mat[i][j] == 'X' ||  mat[i][j] == '.') {
				k = 1;
				bool tried = false;
				if(mat[i][j] == '.') tried = true;
				curr = 1;

				while(i+k < 10 && j+k < 10 && (mat[i+k][j+k] == 'X' || (tried == false && mat[i+k][j+k] == '.'))) {
					if(mat[i+k][j+k] == '.') tried = true;
					k++;
					curr++;
					if(curr >=5) {
						found = true;
						break;
					}
				}
			}
		}
	}
	
	// DIAG <<
	for(int i = 0 ; i < 10 && !found; i++) {
		curr = 0;
		for(int j = 0 ; j < 10 && !found; j++) {
			if(mat[i][j] == 'O') curr = 0;
			
			else if(mat[i][j] == 'X' ||  mat[i][j] == '.') {
				k = 1;
				bool tried = false;
				if(mat[i][j] == '.') tried = true;
				curr = 1;

				while(i+k < 10 && j-k >= 0 && (mat[i+k][j-k] == 'X' || (tried == false && mat[i+k][j-k] == '.'))) {
					if(mat[i+k][j-k] == '.') tried = true;
					k++;
					curr++;
					if(curr >=5) {
						found = true;
						break;
					}
				}
			}
		}
	}
	
	
	
	
	if(found) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;	
}
