#include "numberlist.h"
#include <iostream>
#include <string>
#include <vector>

/**************************************************/
/*               Class Definition                 */
/**************************************************/

using namespace std;

numberlist::numberlist()
{

}
int numberlist::getSize()
{
	return numbers.size();
}
int numberlist::getSize1()
{
	return numbers1.size();
}
void numberlist::createList(int x)
{
	
	numbers.push_back(x);

}
long numberlist::getInverseCounter()
{
	return countInverse;
}
void numberlist::clearVector()
{
	std::vector<int>().swap(numbers);
}
void numberlist::split()
{
	int ii = 0;
	int size = getSize();
	int size1 = size / 2;

	for(int i = 0; i < size1; i++)
	{
		numbers1.push_back(numbers[ii]);
		ii++;
	}
	for(int i = 0; i < size1; i++)
	{
		numbers2.push_back(numbers[ii]);
		ii++;
	}

}
void numberlist::find_split_inversion() 
{
 	int i;
 	int size = getSize1();

 	for (i = 1; i < size; i++) 
 	{
 		firstHalf(i);
 		secondHalf(i);
 	}

}
void numberlist::firstHalf(int index)
{
	int j ,tmp;
	j = index;


 	while (j > 0 && numbers1[j - 1] > numbers1[j]) 
 	{
 		tmp = numbers1[j];
 		numbers1[j] = numbers1[j - 1];
 		numbers1[j - 1] = tmp;
 		j--;
 		countInverse++;
 	}

}
void numberlist::secondHalf(int index)
{
	int j ,tmp;
	j = index;


 	while (j > 0 && numbers2[j - 1] > numbers2[j]) 
 	{
 		tmp = numbers2[j];
 		numbers2[j] = numbers2[j - 1];
 		numbers2[j - 1] = tmp;
 		j--;
 		countInverse++;
 	}

}
void numberlist::merge_split_inversion()
{
	int j, tmp, size, size2;

	size2 = getSize1();



	// merge the split arrays 

	for(int ii=0; ii < size2; ii++)
	{
		numbers.push_back(numbers1[ii]);

	}
	
	for(int ii=0; ii < size2; ii++)
	{
		numbers.push_back(numbers2[ii]);
	}

	size = getSize();

	for (int i = 1; i < size; i++) 
 	{
 		j = i;

 		// check for inversion, sort them and increase inverse counter

 		while (j > 0 && numbers[j - 1] > numbers[j]) 
 		{
 			tmp = numbers[j];
 			numbers[j] = numbers[j - 1];
 			numbers[j - 1] = tmp;
 			j--;
 			countInverse++;
 		}
 	}

}
void numberlist::display()
{
	int size;

	size = getSize();

	cout << "Full Array: ";

	for(int i=0; i < size; i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;
	cout << endl;
}
void numberlist::display2()
{
	int size;

	size = getSize1();

	cout << "Split Array 1: "; 

	for(int i=0; i < size; i++)
	{
		cout << numbers1[i] << ",";
	}
	cout << endl;
	cout << endl;

	cout << "Split Array 2: ";
	for(int i=0; i < size; i++)
	{
		cout << numbers2[i] << ",";
	}
	cout << endl;
	cout << endl;
}


