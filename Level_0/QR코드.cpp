#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열에서 q로 나눈 나머지가 r인 위치의 문자들을 추출하는 함수
string QRcode(int q, int r, string code) {
	string result = "";

	// r번 인덱스부터 시작하여 문자열 끝까지 순회
	for (int i = r; i < code.length(); i++) {
		// i를 q로 나눈 나머지가 r인지 확인
		// 즉, q 간격마다 r번째 위치의 문자만 선택
		if (i % q == r)
			result += code[i];
	}
	return result;
}


int main() {
	int q = 3;
	int r = 1;

	string code = { "qjnwezgrpirldywt" };

	string result = QRcode(q, r, code);

	cout << result << endl;

}