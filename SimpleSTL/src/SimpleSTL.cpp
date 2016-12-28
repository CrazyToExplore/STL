//============================================================================
// Name        : SimpleSTL.cpp
// Author      : Shrikant
// Version     :
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * STL standard template lisbrary covers
 * 1 ) Container
 * 2 ) Algorithm
 * 3 ) Iterator
 *
 * Container are used to collection of data objects like queue,list,vector and maps etc.
 * Algorithm can act on the container from which you can perform operations like sorting,searching and
 *           transforming the contents of the container.
 * Iterator  Iterartor are use are used to step throught the elements of the conatiner.
 *
 */

int findMajorityExist(int a[], int size);
void thirdLarge(int a[], int size);
class ContainerUsage {
private:
	vector<int> intVector;

public:
	ContainerUsage();
	virtual ~ContainerUsage();
	void printVectorSize();
	void insertElemet(int elements);
	void sortPrint();
};

ContainerUsage::ContainerUsage() {

}

ContainerUsage::~ContainerUsage() {

}

void ContainerUsage::printVectorSize() {
	cout << "Vector size :: " << intVector.size() << endl;
	return;
}

void ContainerUsage::insertElemet(int element) {
	intVector.push_back(element);
}

void ContainerUsage::sortPrint() {
	sort(intVector.begin(), intVector.end());
	for (int i = 0; i < intVector.size(); i++) {
		cout << intVector[i] << " ";
	}
}

int main() {
	ContainerUsage mContainerUsage;
	mContainerUsage.printVectorSize();
	mContainerUsage.insertElemet(6);
	mContainerUsage.insertElemet(3);
	mContainerUsage.insertElemet(4);
	mContainerUsage.insertElemet(1);
	mContainerUsage.printVectorSize();
	mContainerUsage.sortPrint();
	int array[] = {1,4,3,3,6,7,8,3,4,5,6,8,9,4,3,6,7,92 };
	int size = (sizeof(array) / sizeof(array[0]));
	findMajorityExist(array, size);
	thirdLarge(array,size);
	return 0;
}

int findMajorityExist(int a[], int size) {
	int count = 1;
	int majority_index = 0;
	for (int i = 1; i < size; i++) {
		if (a[majority_index] == a[i]) {
			count++;
		} else {
			count--;
		}
		if (count == 0) {
			majority_index = i;
			count = 1;
		}
	}
	cout << "Majority element : " << a[majority_index];
	return a[majority_index];
}

void thirdLarge(int a[], int size) {
	int l1, l2, l3;
	for (int i = 0; i < size; i++) {
		if ( a[i] > l1) {
			l3 = l2;
			l2 = l1;
			l1 = a[i];
		}
	}
	cout << "1 largest number  : " << l1 << endl;
	cout << "2 largest number  : " << l2 << endl;
	cout << "3 largest number  : " << l3 << endl;
	cout << " Should trigger an Jenkins build !!!! " << endl;
}
