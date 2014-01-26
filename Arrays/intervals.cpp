// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

#include <list>
#include <iterator>     // std::next

#include <iostream>
using namespace std;
class Interval
{
public:
	int start;
	int end;

	Interval();
	Interval(int a,int b);

	
};

Interval::Interval(){
		start = 0;
		end = 0;
}
Interval::Interval(int a,int b){
		start = a;
		end = b;
}

int overlap(Interval *v1 ,Interval * v2){
	if ((v1->end) < (v2->start)){
		return 0;
	}
	else if (v1->start < v2->start && v1->end > v2->end)
			return 1;
	else if (v1->start > v2->start && v1->end < v2->end)
			return 2;
	else if (v1->start < v2->start && v1->end > v2->start)
			return 3;
	else return -1;
	return -1;
}

list< Interval* > mergeIntervals(list<Interval*> vect ){
	list<Interval*>::iterator it;
	Interval *app1;
	Interval *app2;	
	int i;
	for (it = vect.begin(); distance(it,vect.end())>1; it++){
		app1= *(it);
		advance (it,1);
		app2= *(it);
		advance (it,-1);
		switch(overlap(app1,app2)){
			case 0:
				// no overlap no changes 
				cout << "0"<<endl;
				break;
			case 1:
			cout << "1"<<endl;
				// total left just app1
				app2->start=app1->start;
				app2->end=app1->end;
				vect.erase(it);
				break;
			case 2:
			cout << "2"<<endl;
				// total right just app2
				vect.erase(it);
				break;
			case 3: 
				cout << "3"<<endl;
				// partial new 
				app2->start=app1->start;
				vect.erase(it);
				break;
			default:
				cout << "d" <<endl;
			break;
		}	
		
	}


	return vect;
}

void print(list< Interval *> Result){

	list<Interval*>::iterator it= Result.begin();
	while(it!=Result.end()){
		cout << ' '<< (*it)->start << ' '<<(*it)->end <<endl;
		it++;
	}

}

int main (){
	list< Interval *> Result;
	Interval * v1 =new Interval(1,3); 
	Interval *  v2=new Interval(2,6);
	Interval *  v3=new Interval(8,10);
	Interval *  v4=new Interval(15,18);
    list<Interval*> Intervals ;
    Intervals.insert(Intervals.end(), v1);
    Intervals.insert(Intervals.end(), v2);
    Intervals.insert(Intervals.end(), v3);
    Intervals.insert(Intervals.end(), v4);
	Result = mergeIntervals(Intervals);
	print(Result);
	list<Interval*> Intervals2 ;
	v1 =new Interval(1,7); 
	v2=new Interval(2,6);
	v3=new Interval(16,17);
	v4=new Interval(15,18);
	Interval *  v5=new Interval(17,19);
	Intervals2.insert(Intervals2.end(), v1);
    Intervals2.insert(Intervals2.end(), v2);
    Intervals2.insert(Intervals2.end(), v3);
    Intervals2.insert(Intervals2.end(), v4);
    Intervals2.insert(Intervals2.end(), v5);
    Result = mergeIntervals(Intervals2);
	print(Result);
	return 0;
}