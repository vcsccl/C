// Jon Palmer
// Exercise 2: Vectors

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int DATA_POINTS = 100;

float average(vector<int> data);
int median(vector<int> data);
int minimum(vector<int> data);
int maximum(vector<int> data);
void test();

int main(int argc, const char * argv[]) {
	vector<int> data;

	for (int i = 0; i < DATA_POINTS; ++i) {
		int r = rand();
		cout << "New data : " << r << endl;
		data.push_back(r);
	}

	cout << "Vector Size: " << data.size() << endl;
	cout << "Average: " << average(data) << endl;
	cout << "Median: " << median(data) << endl;
	cout << "Minimum: " << minimum(data) << endl;
	cout << "Maximum: " << maximum(data) << endl;
	cout << "Range: " << maximum(data) - minimum(data) << endl;

	test();

	return 0;
}

float average(vector<int> data) {
	float avg = 0;
	for (int i = 0; i < data.size(); i++) {
		avg += data[i];
	}
	if (avg > 0) {
		avg /= data.size();
	}
	return avg;
}

int median(vector<int> data) {
	sort(data.begin(), data.end());
	int median = data[data.size() / 2];
	return median;
}

int minimum(vector<int> data) {	
	int minimum = *min_element(data.begin(), data.end());
	return minimum;
}

int maximum(vector<int> data) {
	int maximum = *max_element(data.begin(), data.end());
	return maximum;
}

void testAverage(vector<int> data) {
	cout << "testAverage: ";
	if (18 == (int)average(data)) {
		cout << "PASSED\n";
	}
	else {
		cout << "FAILED\n";
	}
}

void testMedian(vector<int> data) {
	cout << "testMedian: ";
	if (median(data) == 16) {
		cout << "PASSED\n";
	}
	else {
		cout << "FAILED\n";
	}
}

void testMinimum(vector<int> data) {
	cout << "testMinimum: ";
	if (minimum(data) == 4) {
		cout << "PASSED\n";
	}
	else {
		cout << "FAILED\n";
	}
}

void testMaximum(vector<int> data) {
	cout << "testMaximum: ";
	if (maximum(data) == 42) {
		cout << "PASSED\n";
	}
	else {
		cout << "FAILED\n";
	}
}

void test() {
	int seedData[] = { 4, 8, 15, 16, 23, 42 };
	vector<int> testData;
	testData.assign(seedData, seedData + 6);
	testAverage(testData);
	testMedian(testData);
	testMinimum(testData);
	testMaximum(testData);
}
