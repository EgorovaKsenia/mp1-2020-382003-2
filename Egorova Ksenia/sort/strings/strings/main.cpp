#include <iostream>
#include <string>
#include "TVector.h"
using namespace std;

int main() {
	TVector<string> arr(2);
	arr[0] = "Song";
	arr[1] = "Film";
	cout << "arr = " << arr << '\n';

	arr.push_back("Book");
	cout << "arr = " << arr << '\n';
}