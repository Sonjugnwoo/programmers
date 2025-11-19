#include <iostream>
#include <string>

using namespace std;

// 주어진 문자열(alp)에 포함된 문자들을 my_string에서 찾아 대문자로 변환
string SpecificChar(string& my_string, string alp) {
	// my_string의 각 문자를 순회 (참조자로 받아 직접 수정 가능)
	for (auto& str : my_string) {
		// alp에 포함된 각 문자와 비교
		for (auto ch : alp) {
			// 현재 문자가 alp에 포함된 문자와 일치하는지 확인
			if (str == ch)
				str = toupper(str);  // 일치하면 대문자로 변환
		}
	}
	return my_string;  // 수정된 문자열 반환
}


int main() {
	string my_string = "programmers";
	string alp = "p";

	auto result = SpecificChar(my_string,alp);

	cout << result << endl;
}