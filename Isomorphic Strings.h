#pragma once

#include <string>
#include <map>
using std::string;

/*
	Example 1:
	Input: s = "egg", t = "add"
	Output: true
	
	Example 2:
	Input: s = "foo", t = "bar"
	Output: false

*/

bool isIsomorphic(string s, string t) {

	if (s.length() != t.length())
		return false;
	std::map<char, char> mappingStoT, mappingTtoS;

	for (int pos = 0; pos < s.length(); ++pos) {

		if (mappingStoT[s[pos]] && mappingStoT[s[pos]] != t[pos])
			return false;
		if (mappingTtoS[t[pos]] && mappingTtoS[t[pos]] != s[pos])
			return false;

		mappingStoT[s[pos]] = t[pos];
		mappingTtoS[t[pos]] = s[pos];

	}
	return true;
}