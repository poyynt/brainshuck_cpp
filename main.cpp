#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<int, int> MEM;
int INDEX = 0;
vector<int> LOOPS;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr << "Usage:" << endl;
		cerr << argv[0] << " file.bf" << endl;
		return 2;
	}
	ifstream source(argv[1]);
	char c;
	char user_input;
	while (source.tellg() != -1) {
		c = source.get();
		switch (c) {
			case '+':
				MEM[INDEX]++;
				break;
			case '-':
				MEM[INDEX]--;
				break;
			case '>':
				INDEX++;
				break;
			case '<':
				if (INDEX <= 0) {
					continue;
				}
				INDEX--;
				break;
			case '.':
				cout << (char) MEM[INDEX];
				break;
			case ',':
				user_input = getchar();
				MEM[INDEX] = user_input;
				break;
			case '[':
				LOOPS.push_back(source.tellg());
				break;
			case ']':
				if (LOOPS.size() == 0) {
					cerr << "Syntax error at character " << source.tellg();
					cerr << endl;
					return 1;
				}
				if (MEM[INDEX] == 0) {
					LOOPS.pop_back();
					continue;
				}
				source.seekg(LOOPS.back());
				break;
		}
	}
	return 0;
}
