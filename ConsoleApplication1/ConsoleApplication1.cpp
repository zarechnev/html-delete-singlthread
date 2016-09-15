// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
	int start_time = clock();
	ifstream html_file;
	ofstream out_file;

	if (argc > 1) {
		html_file.open(argv[1]);
		if (!html_file.is_open()) {
			cout << "HTML file can not be opened." << endl;
			return -1;
		}
	}

	else {
		cout << "Enter HTML file, please." << endl;
		system("pause");
		return -2;
	}

	string text = "";
	char ch = '\0';
	bool b = false;

	while (html_file.peek() >= 0 && (ch = html_file.get())) {
		if (ch == '>') b = true;
		if (b) {
			if (ch != '<' && ch != '>')
				text += ch;
		}
		if (ch == '<') b = false;
	}

	int algorithm_end_time = clock();
	cout << "Algorithm completed in: " << (algorithm_end_time - start_time) / 1000.0 << " seconds." << endl;

	out_file.open("out_singlethread.txt", ios::trunc);

	out_file << text;

	out_file.close();
	html_file.close();
	return 0;
}