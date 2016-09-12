//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1287
// UVA 10346 - Peter's Smokes

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <limits>
#include <fstream>
#include <list>
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
#include <algorithm>
#include <vector>
#include <climits>

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define pln printf("\n");

typedef long long LL;

#define ENTRO printf("entro\n");
#define DEBUGINT(x) printf("%d\n",x);

#define sspeed std::cout.sync_with_stdio(false);

int main(void) {
	int n, k;
	
	while(scanf("%d %d", &n, &k) != EOF) {
		int c=n, b=0;
		int ans = 0;
		int ant;
		
		do {
			ant = ans;
			ans += c;
			
			b+=c;
			
			c = b/k;
			b = b%k;
		} while(ant != ans);
		
		printf("%d\n",ans);	
	}

	return 0;
}
