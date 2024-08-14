#include <vector>
#include <list>
#include <set>
#include <iterator>
#include "Point.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
    set<Point> setPoints = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	vector<Point> vecPoints(setPoints.rbegin(), setPoints.rend());

	sort(vecPoints.rbegin(), vecPoints.rend());
  	printContainer(vecPoints);

	//Stream Iterator - ostream_iterator 	
	copy(setPoints.begin(), setPoints.end(), std::ostream_iterator<Point>(std::cout, " "));
	copy(vecPoints.begin(), vecPoints.end(), std::ostream_iterator<Point>(std::cout, " "));

  
	//Insertion Iterators
	//back_inserter()
	//front_inserter()  only for list, deque
	//inserter() 

	vector<Point> newVec = { {0,0}, {-1,-1} };
  	copy(setPoints.begin(), setPoints.end(), back_inserter(vecPoints));
  	printContainer(vecPoints);
	

	copy(vecPoints.begin(), vecPoints.end(), inserter(newVec, newVec.end()));
    printContainer(newVec);
	
	vector<Point> exclPoint = { {-1,-1}, {-2,-2} };

	copy(exclPoint.begin(), exclPoint.end(), inserter(setPoints, setPoints.begin()));
	printContainer(setPoints);
	  
    return 0;
}
