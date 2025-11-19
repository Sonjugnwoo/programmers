#include <iostream>
#include <string>
	

using namespace std;

// 문자열에서 'a'와 'A'는 대문자로, 나머지 문자는 소문자로 변환
string StressA(string &my_string) {
	// 문자열의 모든 문자를 순회
	for (int i = 0; i < my_string.size(); i++) {
		// 현재 문자가 'a' 또는 'A'인지 확인
		if (my_string[i] == 'a' || my_string[i] == 'A')
			my_string[i] = toupper(my_string[i]);  // 대문자로 변환 (이미 'A'면 그대로)
		else
			my_string[i] = tolower(my_string[i]);  // 나머지는 소문자로 변환
	}

	return my_string;  // 수정된 문자열 반환
}


int main() {
	string my_string = "aA";

	auto result = StressA(my_string);

	cout << result << endl;
}