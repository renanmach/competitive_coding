//http://acm.timus.ru/problem.aspx?space=1&num=1732
//1732. Ministry of Truth

#include <stdio.h>
#include <stdlib.h>
#include <queue>

#include <string>

#include <iostream>
#include <sstream>
 #include <vector>
 
#define forin(n) for(int i=0;i<n;i++)
#define forjn(n) for(int j=0;j<n;j++)
#define pb push_back
#define pf push_front

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	int n,m;
	
	string original, x;
	vector<string> wanted;
	
	getline(cin,original);
	getline(cin,x);
	
	string buf;
    stringstream ss(x);

    while (ss >> buf)
        wanted.push_back(buf);
		
	bool fail = false;	
    int pos = 0; 
    int before;
    
    forin(wanted.size()) {
		before = pos-1;
		
		pos =  original.find(wanted[i], pos);
		
		if(pos == string::npos) {
			fail = true;
			break;
		}
			
		int j;
		
		for(j = before; j < pos; j++) {
			if(original[j] != ' ')
				original[j] = '_';
		}
		
		pos += wanted[i].size()+1;
	}
	
	
	if(!fail) {
		for(int i = pos-1; i < original.size(); i++) {
			if(original[i] != ' ')
				original[i] = '_';
			
		}
			
		cout << original << endl;
	}
	else
		cout << "I HAVE FAILED!!!" << endl;
}
