#include <iostream>
#include <string>
#include <vector>

using namespace std;

//문자열 벡터에서 각 문자열의 특정 부분을 추출하여 정수로 변환한 후 k보다 큰 값만 필터링하여 반환하는 함수
vector<int> CreateArr(const vector<string>& int_strs,int k , int l , int s ) {
	vector<int> result;

	for (const auto& str : int_strs) {
		// substr(s, l): s 인덱스부터 l개의 문자 추출
		// stoi(): 문자열을 정수(int)로 변환
		int num = stoi(str.substr(s, l));
		
		if (num > k)	// k 이하인 숫자는 무시
			result.push_back(num);
	}

	return result;
}



int main() {
	vector<string> int_strs = { "0123456789","9876543210","9999999999999" };
	int k, s, l;

	k = 50000;
	s = l = 5;

	vector<int> result = CreateArr(int_strs, k, l, s);

	for (const auto& p : result)
		cout << p << endl;
}