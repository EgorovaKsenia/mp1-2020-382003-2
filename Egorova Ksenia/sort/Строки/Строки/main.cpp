#include <iostream>
#include "text_editor.h"
using namespace std;

int main() {
	TextEditor test;
	test.load_from_file("input.txt", "dict.txt");
	test.find_mistakes();
	test.correct_mistakes();
	test.save_to_file("output.txt");

	return 0;
}