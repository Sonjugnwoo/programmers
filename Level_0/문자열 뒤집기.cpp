#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 문자열의 특정 구간을 뒤집는 함수
string ReverseString(string my_string, int s, int e) {
	 // reverse(시작반복자, 끝반복자): 지정된 범위를 뒤집음
	 // begin() + s: 시작 인덱스
	 // begin() + e + 1: 끝 인덱스의 다음 (reverse는 끝 반복자를 포함하지 않으므로 +1)
	 reverse(my_string.begin() + s, my_string.begin()+ e+1);
	 return my_string;
}


int main() {
	string my_string = { "Progra21Sremm3" };
	int s = 6;
	int e = 12;

	string result = ReverseString(my_string, s, e);

	cout << result << endl;

}