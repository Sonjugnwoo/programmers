#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;


int SearchString(string my_string, string pat) {
   
	transform(my_string.begin(), my_string.end(), my_string.begin(), ::toupper);
	transform(pat.begin(), pat.end(), pat.begin(), ::toupper);
	return my_string.find(pat) != string::npos;
}



int main() {
	string my_string = { "AbCdEfG" };
	string pat = { "aBc" };

	auto result = SearchString(my_string,pat);

	cout << result << endl;
}