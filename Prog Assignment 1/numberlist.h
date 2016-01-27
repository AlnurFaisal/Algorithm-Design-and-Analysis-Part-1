#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**************************************************/
/*               Class Declarations               */
/**************************************************/

class numberlist
{
	private:
	std::vector<int> numbers;
	std::vector<int> numbers1;
	std::vector<int> numbers2; 
	long countInverse;
	
	public:	
	// constructor 
	numberlist();
	// return size of vector
	int getSize();
	int getSize1();
	// generate number list
	void createList(int);
	// half the vector
	void split();
	// return inverse counter
	long getInverseCounter();
	// check for inversion, add to countInversion and sort numbers
	void firstHalf(int);
	void secondHalf(int);
	void find_split_inversion();
	// merge the 2 split arrays and check for inversion, sort the inverse numbers and increase the counter
	void merge_split_inversion();
	// display number list
	void display();
	void display2();
	// clear vector
	void clearVector();
	
};
#endif