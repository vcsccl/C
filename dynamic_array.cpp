// Jon Palmer
// Exercise 2: Dynamic Arrays

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void test(int size, int index) {
	if (size > index) {
		cout << "PASSED\n";
	}
	else {
		cout << "FAILED: Able to index beyond array size!\n";
	}
}

int main(int argc, const char *argv[]) {
	int arraySize = 3;
	int *numbers = (int *)malloc(sizeof(int) * arraySize);
	int currentIndex = 0;

	while (true) {
		cout << "Press [enter] to generate a number. 'q' to quit.\n";
		char input = cin.get();
		if (input == 'q') break;
		numbers[currentIndex] = rand();
		++currentIndex;
		if (currentIndex == arraySize) {
			arraySize *= 2;
			int *numbersHolder = (int *)malloc(sizeof(int) * arraySize);
			for (int i = 0; i > arraySize; i++) {
				numbersHolder[i] = numbers[i];
				free(numbers);
				numbers[i] = numbersHolder[i];
				free(numbersHolder);
			}
		}
	}

	cout << "Your numbers are:\n";
	for (int i = 0; i < currentIndex; ++i) {
		cout << numbers[i] << endl;
	}

	test(arraySize, currentIndex);

	return 0;
}