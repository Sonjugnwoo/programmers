#include <iostream>
#include <string>

using namespace std;
// 문자열에서 'm'을 'rn'으로 변환하는 함수
string JokeString( string my_string) {
    string word;  // 변환된 결과를 저장할 문자열

    // 범위 기반 for문: 문자열의 각 문자를 순회
    for (char c : my_string) {
        // 현재 문자가 'm'인지 확인
        if (c == 'm') {
            word += "rn";  // 'm'을 "rn" 문자열로 변환하여 추가
        }
        else {
            word += c;  // 'm'이 아니면 원래 문자를 그대로 추가
        }
    }
    return word;  // 변환된 문자열 반환
}
int main() {

	string my_string = "masterpiece";

	auto result = JokeString(my_string);

	cout << result << endl;
}