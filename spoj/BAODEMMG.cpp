// http://br.spoj.com/problems/BAODEMMG/
// BAODEMMG - Problema Bão Demais, sô

using namespace std;
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <istream>
#include <iomanip>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define pb push_back 
#define pf push_front
 
#define forlist for(it=lista.begin(); it != lista.end(); ++it) 
 
#define forin(n) for(int i=0;i<n;i++)
#define forjn(n) for(int j=0;j<n;j++)

int main() {
	int e, t;
	int np; // numero pessoas escola
	int needed;
	int w;

	scanf("%d", &e);

	forin(e) {
		needed = 0;
		
		scanf("%d", &t);
		
		//numero pessoas da escola
		np = t;
		
		forjn(t) {
			scanf("%d", &w);
			needed += w;
		}
		
		//	needed *= 3;
		
		if(needed > np)
			printf("precisa\n");
		else
			printf("nao precisa\n");
	}

    return 0;
}
