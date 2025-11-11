#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

vector<int> CharCount(string my_string){
	// 크기 52의 벡터를 0으로 초기화
	vector<int> result(52, 0);

	// 문자열의 모든 문자를 순회
	for (int i = 0; i < my_string.length(); i++) {
		int idx = 0;

		// 대문자인 경우
		if (isupper(my_string[i]))
			idx = my_string[i] - 'A';
		// 소문자인 경우
		else
			idx = my_string[i] - 'a' + 26;

		// 해당 문자의 빈도수 증가
		result[idx]++;
	}
	return result;
}

int main() {
	string my_string =  "Programmers" ;

	auto result = CharCount(my_string);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
		if (i % 10 == 9 )
			cout << endl;
	}
}
