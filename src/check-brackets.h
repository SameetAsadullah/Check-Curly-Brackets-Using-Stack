#pragma once
#include"stack.h"
#include<string>
#include<fstream>

bool checkCurlyBrackets(string filename) {
	Stack<char> s;
	char str;
	ifstream f1;
	f1.open(filename);

	if (f1.good()) {

		while (!f1.eof()) {
			f1 >> str;

			if (str == '{') {
				s.push(str);
			}

			if (str == '}') {
				if (!s.isEmpty()) {
					s.pop();
				}

				else {
					f1.close();
					return false;
				}
			}
			str = '\0';
		}

		f1.close();

		if (s.isEmpty()) {
			return true;
		}
		return false;
	}
	return false;
}