// Finding the longest palindromic substring

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;



inline bool isPalindrom(const std::string & s)  {
	int j= s.size();
	if (j <= 1)
		return true ;
	if(s[0]==s[j-1]){
		return isPalindrom(s.substr(1,j-2));
	}
	return false;
}

inline std::string longestPalindrom(const std::string & s){
	int i;
	int len=0;
	string maxLenSring;
	string sN ;
	for(i=0;i<s.size();i++){
		for(len=1;len<s.size()-i+1;len++){
			sN=s.substr(i,len);
			if(isPalindrom(sN) && len>maxLenSring.size())
				maxLenSring=sN; 
		}
	}
	return maxLenSring;
}

inline std::string longestPalindromEfficient(const std::string & s){
	int i;
	int j=s.size();
	string maxLenS;

	for(i=0;i<j;i++){
		
	}



}

int main(){
	string s1 ="abccba";
	string s2 ="abcdcba";
	string s3 ="abccbas123abcdcbas123abccbas123321sa";
	// cout << "The string is palindrom "<< isPalindrom(s1) << endl;
	// cout << "The string is palindrom "<< isPalindrom(s2) << endl;
	cout << "In the string : " << s3 << " the longest palindrom word is: "<<longestPalindrom(s3) << endl;


	return -1;
}