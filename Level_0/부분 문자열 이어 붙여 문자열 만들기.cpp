#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 여러 문자열의 특정 구간을 추출하여 하나의 문자열로 연결하는 함수
string AddString(const vector<string>& my_string, const vector<vector<int>>& parts) {
	string result = "";  // 결과를 저장할 문자열
	int idx = 0;         // parts의 인덱스 추적 변수

	// my_string의 각 문자열을 순회
	for (const auto& str : my_string) {
		int start = parts[idx][0];    // 시작 인덱스
		int end = parts[idx][1];      // 끝 인덱스
		int length = end - start + 1; // substr()는 길이를 요구하므로 끝-시작+1로 계산

		// str에서 start 위치부터 lenght 개수만큼 추출
		string substr = str.substr(start, length);
		result += substr;
		idx++;
	}

	return result;
}


int main() {
	vector<string> my_string = { "progressive", "hamburger", "hammer", "ahocorasick" };
	vector<vector<int>> parts = { {0,4},{1,2},{3,5},{7,7} };

	string str = AddString(my_string, parts);

	cout << str << endl;
}