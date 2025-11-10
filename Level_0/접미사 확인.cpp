#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 주어진 문자열이 특정 접미사(suffix)를 가지고 있는지 확인하는 함수
int SuffixFind(string my_string, string is_suffix) {

	// 찾으려는 접미사가 원본 문자열보다 길면 불가능
	if (is_suffix.length() > my_string.length())
		return 0;

	// 문자열의 각 위치부터 끝까지의 모든 접미사를 생성하며 확인
	for (int i = 0; i < my_string.length(); i++) {
		string suffix = my_string.substr(i);

		// 생성된 접미사가 찾는 문자열과 일치하는지 확인
		if (suffix == is_suffix)
			return 1;
	}

	return 0;
}

int main() {
	string my_string = { "banana" };
	string is_suffix = { "ana" };

	int result = SuffixFind(my_string, is_suffix);

	cout << result << endl;
}