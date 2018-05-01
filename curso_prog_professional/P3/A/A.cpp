#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int f91(int n) {
	if(n <= 100) return f91(f91(n+11));
	return n-10;
}

int main() {
	int n;
	
	cin >> n;
	
	while(n!=0) {
		cout << "f91(" << n << ") = " << f91(n) << endl;
		cin >> n;
	}
	
	return 0;
}
