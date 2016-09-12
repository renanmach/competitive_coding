// https://www.urionlinejudge.com.br/judge/en/problems/view/1258
// T-Shirts 1258

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
#include <sstream>
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

#define forlist for(it=lista.begin(); it != lista.end(); ++it) 

#define forin(n) for(int i=0;i<(int)n;i++)
#define forjn(n) for(int j=0;j<(int)n;j++)
#define pb push_back //insere final
#define pf push_front //insere comeco
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define pln() printf("\n");

#define NMAX 5000

using namespace std;

typedef struct {
	string color;
	char size;
	string name;
	int sizee;
} Shirt;

bool cmp(Shirt a, Shirt b) {
	if(a.color < b.color)
		return true;
		
	if(a.color == b.color) {
		if(a.sizee < b.sizee)
			return true;
			
	if(a.sizee == b.sizee)
		if(a.name < b.name)
			return true;
	}
			
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	string a;

	cin >> n;
	getline(cin, a);
	
	while(n!=0) {
		vector<Shirt> shirts;
		
		for(int i = 0; i < 2*n; i+=2) {
			Shirt s;
			getline(cin, s.name);
			cin >> s.color;
			cin >> s.size;
			
			if(s.size == 'P')
				s.sizee = 1;
			else if(s.size == 'M')
				s.sizee = 2;
			else 
				s.sizee = 3;
				
			getline(cin, a);
			shirts.pb(s);
		}
		
		sort(shirts.begin(), shirts.end(), cmp);
		
		forin(shirts.size())
			cout << shirts[i].color << " " << shirts[i].size << " " << shirts[i].name << endl;
		
		cin >> n;
		
		if(n == 0)
			break;
			
		cout << endl;
		getline(cin, a);
	}
}
