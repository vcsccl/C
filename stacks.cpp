//Jon Palmer
//Exercise 04: Stacks

#include "stdafx.h"
#include "fstream"
#include "iostream"
#include <string>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
	ifstream myfile;
	stack<string> lines;
	string currentLine;

	myfile.open("story_backwards.txt");

	while (getline(myfile, currentLine)) {
		lines.push(currentLine);
	}

	myfile.close();

	while (!lines.empty()) {
		cout << lines.top() << endl;
		lines.pop();
	}

	stack<char> palindromeChecker;
	string palindromeCheck;
	string palindromePass;

	cout << "Enter a palindrome: ";
	cin >> palindromeCheck;

	for (int i = 0; i < palindromeCheck.length(); i++) {
		palindromeChecker.push(palindromeCheck.at(i));
	}

	while (!palindromeChecker.empty()) {
		palindromePass += palindromeChecker.top();
		palindromeChecker.pop();
	}

	if (palindromePass == palindromeCheck) {
		cout << "Yipee! Palindrome!" << endl;
	}
	else {
		cout << "Not!" << endl;
	}
	
    return 0;
}

