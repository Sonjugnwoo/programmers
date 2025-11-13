#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열을 m개의 열로 나누고 c번째 열의 모든 문자를 추출하는 함수
string Column(string my_string, int m, int c) {
	string result = "";
	int index = c - 1;
	// index가 문자열 범위 내에 있는 동안 반복
	while (my_string.length() > index) {	
		result += my_string[index];
		index += m;
	}
	return result; 
}

int main() {
	string my_string = { "ihrhbakrfpndopljhygc" };
	int m = 4;
	int c = 2;

	string result = Column(my_string, m, c);

	cout << result << endl;

}