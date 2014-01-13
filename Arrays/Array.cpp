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
#include <array>
using namespace std;

template<typename T>

class MyDArray {
	int A_Lenght;
public:
	std::array<T,int > MyDArray(T type, int leng);
	virtual ~MyDArray();
};

int main(){
	int ris=0;
	array<int, 3> a = {1,2,3}; ;
	
return 0;
}
