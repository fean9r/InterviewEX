//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//Valid operators are +, -, *, /.
//Each operand may be an integer or another expression.

//Some examples:
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//["6", "13", "*", "5", "/", "8", "+"] -> (((6 *13) /5)+ 8)
// input : one array with numbers and operators
// output: a float number


/*
 * If scanning the array n is a number and n+1 is a number and n+2 is an operator,
 * then create a new array [0,.., n-1,apply (n n+2 n+1) ,n+3,.., length ]
 * if n+2 is out of length
 *
 * */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef std::vector< std::string > strVector;
typedef std::vector< std::string >::iterator strVecIter;

strVector ex1 = {"2", "1", "+", "3", "*"};
strVector ex2 = {"4", "13", "5", "/", "+"};
strVector ex3 = {"6", "13", "*", "5", "/", "8", "+"};


template<class ContainerType>
void evalRPN(ContainerType& sVec){

	strVecIter sIter = sVec.begin();

	while (sIter != sVec.end()){

		cout << *sIter << endl;
		sIter++;
	}

}

int main(){
	evalRPN(ex1);
return 0;
}
