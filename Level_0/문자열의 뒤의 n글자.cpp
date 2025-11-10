#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열의 뒤에서부터 n개의 문자를 추출하는 함수
string BehindString(string my_string, int n) {
	string result = "";

	// substr(시작위치): 시작위치부터 문자열 끝까지 추출
	result = my_string.substr(my_string.length()-n);

	return result;

}


int main() {
	string my_string = { "ProgrammerS123" };
	int n = 11;

	string result = BehindString(my_string, n);

	cout << result << endl;
}