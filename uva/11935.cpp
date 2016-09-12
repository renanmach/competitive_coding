//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3086
// 11935 - Through the Desert

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
	sspeed
	
	while(true) {
		int km;
		float cons;
		string state;
		 
		cin >> km >> state >> state >> cons;
		
		if(cons == 0)
			break;
		
		int leak = 0, km0;
		float litres=0, max_litres=0;
		cons /=100;
		
		while(true) {
			km0 = km; // older km
			
			cin >> km >> state;
				
			litres += ((km-km0)*(cons+leak));
			
			max_litres = MAX(max_litres, litres);
			
			if(state.compare("Goal") == 0) {
				break;
			}
			
			else if(state.compare("Fuel") == 0) {
				cin >> state >> cons;
				cons /=100;
				
			}
			
			else if(state.compare("Leak") == 0) {
				leak++;		
			}
			
			else if(state.compare("Gas") == 0) {
				cin >> state;
				litres = 0;
			}
			
			else if(state.compare("Mechanic") == 0) {
				leak = 0;
			}
		}
		cout << fixed << setprecision(3) << max_litres << endl;
	}
	
	return 0;
}
