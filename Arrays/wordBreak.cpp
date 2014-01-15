// Given a string s and a dictionary of words dict, 
// determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// For example, given
// s = “leetcode”,
// dict = ["leet", "code"].

// Return true because “leetcode” can be segmented as “leet code”.

#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
vector<string> dict = {"let","code","your","children","app","isletcodeyourappappletyourcode"};

inline bool isInside(string s){
	string iterString;

	for (vector<string>::iterator it = dict.begin(); it != dict.end(); it++){
		iterString = *it;
		if(iterString.compare(s) == 0)
			return true;
	}

	return false ;
}

inline bool wordbreak (string s){
	bool isBreakable= false;
	int i;
	bool breaked=false;
	int stringSize= s.size();
	string app="";
	string rest="";

	if (s.size()==0){
		return true;
	}

	for ( i = 1; i <= stringSize; i++){
		app = s.substr(0,i);
		if (isInside(app)){
			breaked =true;
			break;
		}
	}
	if (breaked){
		rest = s.substr(i,stringSize);
		isBreakable = wordbreak(rest);
	}
	else 
		isBreakable =false;
	return isBreakable;
}

int main(){
	string s="letcode";
	cout << "the string : " << s<< " is " << wordbreak(s) <<endl;
	s="letcodeyourapp";
	cout << "the string : " << s<< " is " << wordbreak(s) <<endl;
	s="letcodeyourappappletyourcode";
	cout << "the string : " << s<< " is " << wordbreak(s) <<endl;
	s="isletcodeyourappappletyourcode";
	cout << "the string : " << s<< " is " << wordbreak(s) <<endl;
	s="aa";
	cout << "the string : " << s<< " is " << wordbreak(s) <<endl;
	return -1;
}
