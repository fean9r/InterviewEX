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
#include <stack>
#include <vector>
using namespace std;

typedef std::vector< std::string > strVector;
typedef std::vector< std::string >::iterator strVecIter;

strVector ex1 = {"2", "1", "+", "3", "*"};
strVector ex2 = {"4", "13", "5", "/", "+"};
strVector ex3 = {"6", "13", "*", "5", "/", "8", "+"};


inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

inline int whichOp(const std::string & s)
{
	int res=0;
	string op1 ("+");
	string op2 ("-");
	string op3 ("*");
	string op4 ("/");
    if (s.compare(op1) == 0)
   		res	=1;
    if (s.compare(op2) == 0)
   		res	=2;
   	if (s.compare(op3) == 0)
   		res	=3;
    if (s.compare(op4) == 0)
   		res	=4;

   return res ;
}


template<class ContainerType>
void evalRPN(ContainerType& sVec){
	stack <string> numbers;
	int op1,op2;
	strVecIter sIter = sVec.begin();

	while (sIter != sVec.end()){

		if (isInteger(*sIter)){
			//cout << *sIter <<" is integer" << endl;
			numbers.push(*sIter);
		}
		else {
			switch (whichOp(*sIter ))
			{	
				case 1: 
					//cout << "+ operand" << endl;
					op1=atoi( numbers.top().c_str() );
					numbers.pop();
					op2=atoi( numbers.top().c_str() );
					numbers.pop();
					numbers.push( to_string(op2 + op1));
	    		break;
				case 2: 
					//cout << "- operand" << endl;
					op1=atoi( numbers.top().c_str() );
					numbers.pop();
					op2=atoi( numbers.top().c_str() );
					numbers.pop();
					numbers.push( to_string(op2 - op1));
	    		break;
				case 3: 
					//cout << "* operand" << endl;
					op1=atoi( numbers.top().c_str() );
					numbers.pop();
					op2=atoi( numbers.top().c_str() );
					numbers.pop();
					numbers.push( to_string(op2 * op1));
	    		break;
	    		case 4: 
					//cout << "/ operand" << endl;
					op1=atoi( numbers.top().c_str() );
					numbers.pop();
					op2=atoi( numbers.top().c_str() );
					numbers.pop();
					numbers.push( to_string(op2 / op1));
	    		break;
				default: 
					cout << "ERROR";
	    		break;
			}
		}
		sIter++;
	}
	while (numbers.size()>0){
		cout << numbers.top() << " "  << endl;
		numbers.pop();
	}
}

int main(){
	evalRPN(ex1);
	evalRPN(ex2);
	evalRPN(ex3);
return 0;
}
