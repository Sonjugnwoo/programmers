#include <iostream>
#include <string>

using namespace std;


int CountString(string my_string, string pat) {
	int count = 0;           // 패턴을 찾은 횟수를 저장하는 카운터
	int len = pat.size();    // 패턴의 길이를 저장

	// my_string의 각 위치를 시작점으로 검사
	for (int i = 0; i < my_string.size(); i++) {
		int idx = 0;         // 패턴 내에서 현재 비교 중인 문자의 인덱스

		// pat의 각 문자를 순회하며 일치 여부 확인
		for (auto ch : pat) {
			// my_string의 i+idx 위치 문자와 pat의 현재 문자가 일치하는지 확인
			if (my_string[i + idx] == ch)
				idx++;       // 일치하면 다음 문자로 이동

			// 패턴의 모든 문자가 일치했는지 확인
			if (idx == len)
				count++;     // 모두 일치하면 카운트 증가
		}
		return count;
	}
}

int main() {

	string my_string = "aaaa";

	string pat = "aa";

	auto result = CountString(my_string, pat);

	cout << result << endl;
}