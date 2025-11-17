#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


string Upper(string my_string) {
	// transform을 사용하여 문자열의 각 문자를 대문자로 변환
	// - my_string.begin(): 시작 반복자
	// - my_string.end(): 끝 반복자
	// - my_string.begin(): 결과를 저장할 위치 (원본 덮어쓰기)
	// - ::toupper: 각 문자에 적용할 함수
	transform(my_string.begin(), my_string.end(), my_string.begin(), ::toupper);
	return my_string;
}



int main() {
	string my_string = { "aBcDeFg" };

	auto result = Upper(my_string);

	cout << result << endl;
}