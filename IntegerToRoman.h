#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;
using std::pair;

/*
    Roman Numerals Chart
    Roman
    Numeral	Number
    I	1	I
    V	5	V
    X	10	X
    XL  40
    L	50	L
    C	100	C
    D	500	D
    CD  400
    M	1,000	M
    I	1,000	_I
    V	5,000	_V
    X	10,000	_X
    L	50,000	_L
    C	100,000	_C
    D	500,000	_D
    M	1,000,000	_M
*/

string intToRoman(int num) {
    string roman = "";
    vector<pair<int, string>> intToRomanMap = { {1000, "M"}, {900, "CM"},
                                                {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
                                                {9, "IX"}, {8, "VIII"}, {7, "VII"}, {6, "VI"}, {5, "V"}, {4, "IV"}, {1, "I"} };

    for (int i = 0; i < intToRomanMap.size(); ++i) {

        while (num >= intToRomanMap.at(i).first) {
            roman += (intToRomanMap.at(i).second);
            num -= intToRomanMap.at(i).first;
        }
    }
    return roman;
}