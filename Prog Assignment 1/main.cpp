/*	
 *	Developed by Alnur Faisal A1674847
 *	Bachelor of Computer Science, University of Adelaide
 */

#include "numberlist.h" 
#include <iostream>
#include <string>
#include <fstream>  
#include <vector>

using namespace std;


/*********************************************/
/*               Main Function               */
/*********************************************/

/* Idea is to retrieve from a text file the list of numbers from 1 to 100,000 inclusive in no sorted order and there
   are no repeated numbers. The task is to compute the number of inversion in the text file given. Inversion is when 
   a pair of integer where the front is larger than the integer at the back. A[i] > A [j]. So long as the numbers are not sorted 
   in ascending order, there will be an inversion. 
*/

 // Use divide and conquer technique to reduce the running time of the algorithm.
 // When there is an inversion, add it to the counter and swap its places to sort the array of numbers.
 // The sorting and counting will happen when the array of numbers is split and merge back together.
 // When doing merge and split, swap the location of the values one unit at a time to view the inversion.
 // The swaps determine the number of times an inversion occur.
 // Once pull the numbers from the text file and transfered to vector, split into half and check for inversion,
 // count inversion and sort, after completing, merge, then count inversion and sort

int main()
{

	int readNum;
	long countInversion;
	numberlist* nlist = new numberlist(); 

	cout << "This program task is to read a list of numbers from a text file, ";
	cout << "count the number of inversion and sort the numbers in ascending order. " << endl;
	
	fstream infile("/Users/alnurfaisal/Desktop/inversion.txt");
	
	// create an class of the object
	// declare a vector inside the class numberlist so the object can use the vector
	// to store integer values to it 
	// the numberlist vector will be divided to 2 after all numbers are stored
	// once the array of vectors are divided to 2, we will count the inversion after checking and sort the array of numbers 
	// for both half cocurrently at the same time and swap one unit at a time to track inversion for merge and split
	// then we will combine both the sorted array, then check for inversion, count inversion and sort the array

	cout << "Reading from text file..." << endl;

	if(infile.is_open())
	{
		for(int i=0; i < 100000; i++)
		{

			if(!infile.eof())
			{
				infile >> readNum;
				cout << readNum << ", " ; 
				nlist->createList(readNum);
				
			}
			else
			{
				break;
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Unable to open file. " << endl;
	}

	cout << endl;
	cout << "Storing of numbers to vectors completed." << endl;
	cout << endl;	

	nlist->display();

	cout << "Now will divide the inversion problem to half..." << endl;
	cout << endl;

	nlist->split();

	cout << "Divided the inversion to subproblems." << endl;
	cout << endl;

	nlist->display2();

	cout << "Checking for inversion and sorting the inverse numbers..." << endl;
	cout << endl;

	nlist->find_split_inversion();

	cout << "Checked for inversion in split arrays and sorted arrays in order." << endl;
	cout << endl;

	nlist->display2();
	nlist->clearVector();

	cout << "Merging the 2 split arrays, check for inversion and sort them..." << endl;
	cout << endl;

	nlist->merge_split_inversion();

	cout << "Merging and sorting completed." << endl;

	cout << "Displaying array output and the amount of inversion found." << endl;
	cout << endl;

	nlist->display();
	countInversion = nlist->getInverseCounter();
	cout << "The number of inversions found is: " << countInversion << endl;


	return 0;
}