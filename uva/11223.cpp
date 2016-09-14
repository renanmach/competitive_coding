// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2164
// 11223 - O: dah dah dah!
// 14 September 2016

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <istream>
#include <vector>
#include <unordered_map>

#define pb push_back
#define pf push_front
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define sspeed std::cout.sync_with_stdio(false);

#define NMAX 20


typedef unordered_map<string,string> stringmap;

stringmap construct_morse_code_map() {
	stringmap morse_map;
	
	morse_map.insert({".-","A"});
	morse_map.insert({"-...","B"});
	morse_map.insert({"-.-.","C"});
	morse_map.insert({"-..","D"});
	morse_map.insert({".","E"});
	morse_map.insert({"..-.","F"});
	morse_map.insert({"--.","G"});
	morse_map.insert({"....","H"});
	morse_map.insert({"..","I"});
	morse_map.insert({".---","J"});
	morse_map.insert({"-.-","K"});
	morse_map.insert({".-..","L"});
	morse_map.insert({"--","M"});
	morse_map.insert({"-.","N"});
	morse_map.insert({"---","O"});
	morse_map.insert({".--.","P"});
	morse_map.insert({"--.-","Q"});
	morse_map.insert({".-.","R"});
	morse_map.insert({"...","S"});
	morse_map.insert({"-","T"});
	morse_map.insert({"..-","U"});
	morse_map.insert({"...-","V"});
	morse_map.insert({".--","W"});
	morse_map.insert({"-..-","X"});
	morse_map.insert({"-.--","Y"});
	morse_map.insert({"--..","Z"});
	
	morse_map.insert({"-----","0"});
	morse_map.insert({".----","1"});
	morse_map.insert({"..---","2"});
	morse_map.insert({"...--","3"});
	morse_map.insert({"....-","4"});
	morse_map.insert({".....","5"});
	morse_map.insert({"-....","6"});
	morse_map.insert({"--...","7"});
	morse_map.insert({"---..","8"});
	morse_map.insert({"----.","9"});
	
	morse_map.insert({".-.-.-","."});
	morse_map.insert({"--..--",","});
	morse_map.insert({"..--..","?"});
	morse_map.insert({".----.","'"});
	morse_map.insert({"-.-.--","!"});
	morse_map.insert({"-..-.","/"});
	morse_map.insert({"-.--.","("});
	morse_map.insert({"-.--.-",")"});
	morse_map.insert({".-...","&"});

	
	morse_map.insert({"---...",":"});
	morse_map.insert({"-.-.-.",";"});
	morse_map.insert({"-...-","="});
	morse_map.insert({".-.-.","+"});
	morse_map.insert({"-....-","-"});
	morse_map.insert({"..--.-","_"});
	morse_map.insert({".-..-.","\""});
	morse_map.insert({".--.-.","@"});	
	
	
	return morse_map;
}

int main() {
	sspeed
	
	stringmap morse_map = construct_morse_code_map();
	
	int t;
	
	cin >> t;
	string aux;
	getline(cin,aux); // ignores \n
	
	// read all tests
	for(int j = 0 ; j < t; j++) {
		string line;
		getline(cin,line);
		
		vector<string> output;
		
		int k=0;
		for(int i = 0 ; i < line.size(); i++) {
			// last character
			if(i==line.size()-1 && line[i] != ' ') {
				output.pb(morse_map.find(line.substr(k,i))->second);
				
				continue;
			}
			
			// found a pause
			if(line[i] == ' ') {
				// double pause
				if(line[i+1] == ' ') {
					output.pb(morse_map.find(line.substr(k,i-k))->second);
					output.pb(" ");
					
					i++;
					k=i+1;
				}
				
				// simple pause
				else {
					string x = morse_map.find(line.substr(k,i-k))->second;
					
					output.pb(morse_map.find(line.substr(k,i-k))->second);
					k=i+1;
				}
			}
		}
		
		// prints the result
		cout << "Message #"<< j+1 << endl;
		for(int i = 0 ; i < output.size(); i++) {
			cout << output[i];
		}
		
		// do not print an empty line at the end
		if(j==t-1)
			cout << endl;
		else
			cout << endl << endl;
	}
	
	return 0;
}
