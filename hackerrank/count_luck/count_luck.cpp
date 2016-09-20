// https://www.hackerrank.com/contests/master/challenges/count-luck
// Count luck
// 20 September 2016

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

#define TREE 'X'
#define PORTKEY '*'
#define EMPTY '.'
#define START 'M'


char mat[MAXN][MAXN];
int m,n;
bool answer;


// check if they can go up
bool check_up_dir(int si,int sj,int cfi, int cfj) {
	// check matrix limt and if this direction is not returning to 
	// the "came from" position
	if(si-1 >= 0 && (cfi != si-1 || cfj != sj))	{
		if(mat[si-1][sj] != TREE) {
			return true;
		}
	}
		
	return false;
}

bool check_down_dir(int si,int sj,int cfi, int cfj) {
	if(si+1 < n  && (cfi != si+1 || cfj != sj))	{
		if(mat[si+1][sj] != TREE) {
			return true;
		}
	}
	
	return false;
}


bool check_right_dir(int si,int sj,int cfi, int cfj) {
	if(sj+1 < m  && (cfi != si || cfj != sj+1))	{
		if(mat[si][sj+1] != TREE) {
			return true;
		}
	}
	
	return false;
}

bool check_left_dir(int si,int sj,int cfi, int cfj) {
	if(sj-1 >= 0  && (cfi != si || cfj != sj-1)) {
		if(mat[si][sj-1] != TREE) {
			return true;
		}
	}
		
	return false;
}

// return the number of directions they can go
// we use di, and dj (direction i,j) if this function returns 1, then
// we do to di,dj without calling the recursion again
int check_number_of_dirs(int si,int sj,int cfi, int cfj, int &di, int&dj) {
	int ndir = 0;
	
	if(check_up_dir(si,sj,cfi,cfj)) {
		ndir++;
		di = si-1;
		dj = sj;
	}
	
	if(check_down_dir(si,sj,cfi,cfj)) {
		ndir++;
		di = si+1;
		dj = sj;
	}
	
	if(check_right_dir(si,sj,cfi,cfj)) {
		ndir++;
		di = si;
		dj = sj+1;
	}
	
	if(check_left_dir(si,sj,cfi,cfj)) {
		ndir++;
		di = si;
		dj = sj-1;
	}
	
	return ndir;
}

// si start pos i
// sj start pos j
// pi portkey pos i
// pj portkey pos j
// k number of Ron's guesses
// current count of wand waves
// cfi,cfj came from i,j
void count_luck(int si, int sj, int pi, int pj, int k, int count,int cfi, int cfj) {
	//printf("si=%d sj=%d count=%d\n",si,sj,count);
	
	// if we've already found the path
	if(answer)
		return;
		
	// reached the portkey
	if(si == pi && sj == pj) {
		if(count == k)
			answer = true;
		return;
	}
	
	int ndirs;
	
	// loops while the number of directions to follow is 0 or 1
	while(true) {
		int di,dj;
		
		ndirs = check_number_of_dirs(si,sj,cfi,cfj,di,dj);
		
		//printf("si=%d sj=%d count=%d ndirs=%d\n",si,sj,count,ndirs);
	
		// reached a deadend
		if(ndirs == 0)
			return;
			
		// move to direction
		if(ndirs == 1) {
			cfi = si;	// i came from (cfi) si
			cfj = sj;	// j came from (cjf) sj
			si = di;	// start i = direction i
			sj = dj;	// start j = direction j
			
			// reached the portkey
			if(si == pi && sj == pj) {
				if(count == k)
					answer = true;
				return;
			}
		}
		
		// we will call the recursion
		else {
			break;
		}	
	}
	
	// check which direction they can go and call recursion
	// with count+1 (one more wand wave)
	if(check_up_dir(si,sj,cfi,cfj)) {
		count_luck(si-1,sj,pi,pj,k,count+1,si,sj);
	}
	
	if(check_down_dir(si,sj,cfi,cfj)) {
		count_luck(si+1,sj,pi,pj,k,count+1,si,sj);
	}
	
	if(check_right_dir(si,sj,cfi,cfj)) {
		count_luck(si,sj+1,pi,pj,k,count+1,si,sj);
	}	
	
	if(check_left_dir(si,sj,cfi,cfj)) {
		count_luck(si,sj-1,pi,pj,k,count+1,si,sj);
	}
}

int main(void) {
	int t;
	int k,si,sj,pi,pj;
	
	scanf("%d",&t);
	
	while(t--) {
		answer = false;
		// read n,m and \n
		scanf("%d %d\n", &n, &m);
		
		// read matrix
		for(int i = 0 ; i < n; i++) {
			for(int j = 0 ; j < m; j++) {
				mat[i][j] = getchar();
				if(mat[i][j] == START) {	// get initial position
					si = i;
					sj = j;
				}
				
				else if(mat[i][j] == PORTKEY) {	// get portkey position
					pi = i;
					pj = j;
				}
			}
			getchar();	// \n
		}
					
		scanf("%d", &k);
	
		count_luck(si,sj,pi,pj,k,0,si,sj);
		
		if(answer)
			printf("Impressed\n");
		else
			printf("Oops!\n");
	}
	
	return 0;
}
