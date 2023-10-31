#ifndef ZIGZAG_CONV_H
#define ZIGZAG_CONV_H

/*

	The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R
	And then read line by line: "PAHNAPLSIIGYIR"

	Write the code that will take a string and make this conversion given a number of rows:

	Input: s = "PAYPALISHIRING", numRows = 3
	Output: "PAHNAPLSIIGYIR"
*/

#include <vector>
#include <string>

using std::string;
using std::vector;

string convert(string s, int numRows) {
	if (numRows <= 1)
		return s;

	vector<string> words(numRows, "");

	int wordsPos = 0;
	int dir = -1;
	
	for (int pos = 0; pos < s.length(); ++pos) {
		
		if (wordsPos == numRows - 1 || wordsPos == 0)
			dir *= -1;

		words[wordsPos] += s[pos];

		if (dir == 1)
			wordsPos++;
		else
			wordsPos--;
	}

	string result;

	for (string word : words) {
		result += word;
	}

	return result;
}


#endif // !ZIGZAG_CONV_H