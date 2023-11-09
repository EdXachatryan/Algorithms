#pragma once
#include <string>
#include <vector>;

/*
	Input: num1 = "123", num2 = "456"
	Output: "56088"
*/

using std::string;
using std::vector;

string multiply(string num1, string num2) {


	int num1Size = num1.size() - 1;
	int num2Size = num2.size() - 1;

	string result(num1Size + num2Size + 2, '0');

	for (int posNum1 = num1Size; posNum1 >= 0; posNum1--) {
		for (int posNum2 = num2Size; posNum2 >= 0; posNum2--) {

			int number = (num1[posNum1] - '0') * (num2[posNum2] - '0') + (result[posNum1 + posNum2 + 1] - '0');
			result[posNum1 + posNum2 + 1] = number % 10 + '0';
			result[posNum1 + posNum2] += number / 10;
		}
	}

	for (int pos = 0; pos < result.size(); ++pos) {
		if (result[pos] != '0')
			return result.substr(pos);
	}
	return "0";
}