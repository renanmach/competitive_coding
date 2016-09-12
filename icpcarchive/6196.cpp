//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4207
// 6196 - Party Games

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

#define NMAX 1001

#define sspeed std::cout.sync_with_stdio(false);


// TODO translate comments to English
int main(void) {
	sspeed
	
	int n;
	
	cin >> n;
	
	while(n) {
		vector<string> names;
		
		forin(n) {
			string s;
			cin >> s;
			names.pb(s);
		}
			
		sort(names.begin(), names.end());
		
		int m = names.size()/2;
		string s;
		
		string a = names[m-1];
		string b = names[m];
		int sizea = (int)names[m-1].size();
		int sizeb = (int)names[m].size();
		
		
		if(sizea == 1) {
			s = a;
		}	
		
		else {
			int i;
			for(i = 0; i < sizea && i < sizeb; i++) {
				if(a[i] != b[i])
					break;
				s += a[i];
			}
			
			// se i >= size a
			// entao, s = a
			// pois b = a+suffix ou b = a[0:-1]+suffix
			if(i >= sizea-1) {
				s = a;
			}	
			
			// ainda nao copiamos toda a string a
			else {
				if(i < sizeb-1) { // tambem nao copiamos toda a string b
					s += a[i]+1;
				}
				
				else { // nao copiamos toda a, mas chegamos no final de b
					if(b[i]-a[i] > 1) { // difenca eh mais de um caracter
						s += (a[i]+1);
					}
					
					else { // b[i]-a[i]==1, caracteres sequenciais
						s +=a[i];
						i++;
							
						for(; i < sizea; i++) {
							if(a[i] == 'Z')
								s += 'Z';
							else
								break;
						}
						
						if(i == sizea-1) { // quebrou no ultimo caracter de a
							s += a[i];
						}
						
						else if(i < sizea-1) {
							s +=a[i]+1;	
						}
					}
				}
			}
		}
		
		cout << s << endl;
		cin >> n;
	}

	return 0;
}
