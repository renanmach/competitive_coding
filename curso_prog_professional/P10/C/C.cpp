#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 5;

class Team {
public:
	int K,DA,DB,delta;
	
	Team(int a, int b, int c) {
		K = a;
		DA = b;
		DB = c;
		delta = DA-DB;
		if(delta < 0) delta = -delta;
	}
	
	bool operator<(const Team &a) const{
		return delta>a.delta;
	}
};

vector<Team> team;

int main(void) {
    int n,A,B;
    int x,y,z;
    
    while(cin >> n >> A >> B && n > 0) {
		team.clear();
		for(int i = 0 ; i < n; i++) {
			cin >> x >> y >> z;
			team.push_back(Team(x,y,z));
		}
		
		sort(team.begin(),team.end());
		
		int dist = 0;
		int give;
		
		for(int i = 0 ; i < n; i++) {
			if(team[i].DA < team[i].DB) {
				 give = min(team[i].K, A);
				 A-=give;
				 
				 dist += give*team[i].DA;
				 
				 team[i].K -= give;
				
				 if(team[i].K > 0) {
					 B-=team[i].K;
					 dist += team[i].K *team[i].DB; 
				 }
			}
			 
			else {
				give = min(team[i].K, B);
				B-=give;
				 
				 dist += give*team[i].DB;
				 
				 team[i].K -= give;
				
				 if(team[i].K > 0) {
					 A-=team[i].K;
					 dist += team[i].K *team[i].DA; 
				 }
			}
		}
		
		cout << dist << endl;
	}
    
    
    
    
    return 0;
}
