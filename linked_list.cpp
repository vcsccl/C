// Jon Palmer
// Exercise 6: Linked Lists

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include <list> 

using namespace std;

const int DATA_POINTS = 1000000;
const int MAGIC_NUMBER = 42;

void printElapsedTime(clock_t start, clock_t end, string label);

void fillArray(int data[], int numberOfElements);
void changeElement(int data[], int index, int newValue);
void insertElement(int data[], int lastIndex, int index, int newValue);

void fillList(list<int> *data, int numberOfValues);
void changeElementInList(list<int> *data, int position, int newValue);
void insertElementIntoList(list<int> *data, int position, int newValue);

int main(int argc, const char * argv[]) {
	clock_t start;
	clock_t end;

	std::list<int> mylist;
	std::list<int>::iterator it;

	// Make it twice the size we need, for extra space during insertion.
	int *data = new int[DATA_POINTS * 2]; 

	// Benchmark: Storing data in an array.
	start = clock();
	fillArray(data, DATA_POINTS);
	end = clock();
	printElapsedTime(start, end, "fillArray");

	// Benchmark: Change an existing value in an array.
	start = clock();
	changeElement(data, DATA_POINTS / 2, MAGIC_NUMBER);
	end = clock();
	printElapsedTime(start, end, "changeElement");

	// Benchmark: Insert a value into an array.
	start = clock();
	insertElement(data, DATA_POINTS - 1, DATA_POINTS / 2, MAGIC_NUMBER);
	end = clock();
	printElapsedTime(start, end, "insertElement");


	// Create a linked list for integers *on the heap*, named `linkedData`.
	list<int> *linkedData = new list<int>;

	// Benchmark: Storing data in a linked list.
	start = clock();
	fillList(linkedData, DATA_POINTS);
	end = clock();
	printElapsedTime(start, end, "fillList");

	// Benchmark: Change an existing value in a linked list.
	start = clock();
	changeElementInList(linkedData, DATA_POINTS / 4, MAGIC_NUMBER);
	end = clock();
	printElapsedTime(start, end, "changeElementInList");

	// Benchmark: Insert a value into a linked list.
	start = clock();
	insertElementIntoList(linkedData, DATA_POINTS / 4, MAGIC_NUMBER);
	end = clock();
	printElapsedTime(start, end, "insertElementIntoList");

	return 0;
}

// Append `numberOfValues` random integers to `data`.
void fillList(list<int> *data, int numberOfValues) {
	for (int i = 0; i < numberOfValues; ++i) {
		data->push_back(rand());
	}
}

// Change the element at `position` to `newValue`.
void changeElementInList(list<int> *data, int position, int newValue) {
	list<int>::iterator it = data->begin();
	for (int i = 0; i < position; i++) {
		it++;
	}
	data->insert(it, newValue);
	it++;
	data->erase(it);
}

// Insert `newValue` into the `data` at `position`.
void insertElementIntoList(list<int> *data, int position, int newValue) {
	list<int>::iterator it = data->begin();
	for (int i = 0; i < position; i++) {
		it++;
	}
	data->insert(it, newValue);
}

void printElapsedTime(clock_t start, clock_t end, string label) { 
	cout << label << ": " << double(end - start) << endl;
}

// Fill the array with random numbers. An O(n) operation.
void fillArray(int data[], int numberOfElements) {
	for (int i = 0; i < numberOfElements; ++i) {
		data[i] = rand();
	}
}

// Change the value at `index`. An O(1) operation.
void changeElement(int data[], int index, int newValue) {
	data[index] = newValue;
}

// Insert an element at `index`, shifting all values to the right. An O(n) operation.
void insertElement(int data[], int lastIndex, int index, int newValue) {
	int valueToMove = data[index];
	for (int i = index; i <= lastIndex; ++i) {
		int temp = data[i + 1];
		data[i + 1] = valueToMove;
		valueToMove = temp;
	}
	data[index] = newValue;
}
