/*
 * prova.cpp
 *
 *  Created on: Jan 10, 2014
 *      Author: fean9r
 */
#include <iostream>
using namespace std;

bool compareChars(char c,char p){
	if((c-p)==0 || (c-'.')==0 || ('.'-p)==0)
		return true;
	return false;
}

// move the index while the i val in Str is the same of c
int burnAll(char * Str, char c , int i  ){
	while (compareChars(Str[i],c))
		i=i+1;
	return i;
}

bool match(char * S, char * P ){
	// the indexes for s and for p
	int iS=0;
	int jP=0;
	char x1,x2,y1,y2;
	// untill we are not out of the strings :
	while(S[iS] || P[jP]){
		x1 = S[iS];
		x2 = S[iS+1];
		y1 = P[jP];
		y2 = P[jP+1];

		if(compareChars(x2,'*')){
			jP=burnAll(P,x1,jP);
			iS =iS+2;
		} else if(compareChars(y2,'*')){
			iS=burnAll(S,y1,iS);
			jP =jP+2;
		} else if(compareChars(x1,y1)){
			iS=iS+1;
			jP=jP+1;
		} else 
			return false;
	}

	return true;
}

int main(){

	char s[] = "aaaabddc*";
	char p[] = "aa*bc*d*";

	cout << match(s,p) <<endl;
	char a[] = "aaa.bddc*";
	char b[] = "aa*bc*d*";

	cout << match(a,b) <<endl;
	return 0;
}