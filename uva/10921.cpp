//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1862
// UVA 10921 - Find the Telephone

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
	string exp;
	
	while(getline(cin, exp)) {
		string res="";
		
		for(int i = 0; i < (int) exp.length(); i++) {
			if(exp.at(i) == '1') 	
				res.append("1");
			else if(exp.at(i) == '0') {
				res.append("0");
			}
			else if(exp.at(i) == '-') {
				res.append("-");
			}
			else if(exp.at(i) == 'A' || exp.at(i) == 'B' || exp.at(i) == 'C') {
				res.append("2");
			}
			else if(exp.at(i) == 'D' || exp.at(i) == 'E' || exp.at(i) == 'F') {
				res.append("3");
			}
			else if(exp.at(i) == 'G' || exp.at(i) == 'H' || exp.at(i) == 'I') {
				res.append("4");
			}
			else if(exp.at(i) == 'J' || exp.at(i) == 'K' || exp.at(i) == 'L') {
				res.append("5");
			}
			else if(exp.at(i) == 'M' || exp.at(i) == 'N' || exp.at(i) == 'O') {
				res.append("6");
			}
			else if(exp.at(i) == 'P' || exp.at(i) == 'Q' || exp.at(i) == 'R'|| exp.at(i) == 'S') {
				res.append("7");
			}
			else if(exp.at(i) == 'T' || exp.at(i) == 'U' || exp.at(i) == 'V') {
				res.append("8");
			}
			else if(exp.at(i) == 'W' || exp.at(i) == 'X' || exp.at(i) == 'Y'|| exp.at(i) == 'Z') {
				res.append("9");
			}
		}
		cout << res << endl;
	}

	return 0;
}
