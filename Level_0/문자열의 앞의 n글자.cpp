#include <iostream>
#include <string>

using namespace std;

// 문자열의 앞에서부터 n개의 문자를 추출하는 함수
string ForwardString(string my_string, int n) {
	string result = "";

	// substr(시작위치): 시작위치부터 
	result = my_string.substr(0, n);

	return result;

}


int main() {
	string my_string =  "ProgrammerS123" ;
	int n = 11;

	string result = ForwardString(my_string, n);

	cout << result << endl;
}