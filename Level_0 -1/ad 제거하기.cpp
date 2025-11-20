#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>  RemoveAD(vector<string> str_arr) {
	vector<string> result;  // "ad"가 없는 문자열을 저장할 새 벡터

	// 벡터의 각 문자열을 순회
	for (auto& str : str_arr) {
		// 현재 문자열에서 "ad" 부분 문자열 찾기
		auto pos = str.find("ad");

		// "ad"가 없으면 (string::npos는 "찾지 못함"을 의미)
		if (pos == string::npos)
			result.push_back(str);  // 결과 벡터에 추가
		// "ad"가 있으면 추가하지 않음 (암묵적으로 제거됨)
	}
}

int main() {

	vector<string> str_arr = { "and","notad","abcd" };

	auto result = RemoveAD(str_arr);

	for (auto p : result)
		cout << p << " ";
}