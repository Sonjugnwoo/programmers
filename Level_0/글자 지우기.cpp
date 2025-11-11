#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 문자열에서 특정 인덱스들의 문자를 제거하는 함수
string RemoveString(string my_string, vector<int> indices) {
	string result = my_string;
	// indices 배열의 모든 인덱스를 순회
	for (auto p : indices)
		// 제거할 인덱스 위치에 null 문자('\0')로 표시
		// 0은 자동으로 null 문자로 변환됨 (ASCII 코드 0)
		result[p] = 0;

	// erase-remove 이디엄 사용
	result.erase(remove(result.begin(), result.end(), '\0'),result.end());
	return result;
}


int main() {
	string my_string = "apporoograpemmemprs";
	vector<int> indices = { 1,16,6,15,0,10,11,3 };


	auto result = RemoveString(my_string, indices);

	cout << result << endl;
}