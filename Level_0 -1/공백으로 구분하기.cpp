#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 공백을 기준으로 문자열을 분리하는 함수
vector<string> SpaceSeparator(string str_arr) {
    vector<string> result;  // 분리된 단어들을 저장할 벡터
    stringstream ss(str_arr);  // 입력 문자열을 stringstream으로 변환
    string word;  // 각 단어를 임시로 저장할 변수
    
    // stringstream에서 공백 단위로 단어를 추출
    while (ss >> word)  // >> 연산자는 자동으로 공백을 구분자로 사용
        result.push_back(word);  // 추출한 단어를 벡터에 추가

    return result;  // 분리된 단어들이 담긴 벡터 반환
}
int main() {

	string str_arr = "i love you";

	auto result = SpaceSeparator(str_arr);

	for (auto p : result)
		cout << p << " ";
}