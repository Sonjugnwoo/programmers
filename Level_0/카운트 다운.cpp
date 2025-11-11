#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 시작 숫자부터 끝 숫자까지 역순으로 카운트하는 함수
vector<int> Count(int start_num, int end_num) {
	vector<int> result;

	// start_num부터 시작해서 end_num까지 1씩 감소하며 반복
	for (int i = start_num; i >= end_num; i--)
		// 현재 i 값을 벡터 끝에 추가
		result.push_back(i);

	return result;
}

int main() {
	int start_num = 10;
	int end_num = 3;

	auto result = Count(start_num,end_num);

	for (auto p : result)
		cout << p << " ";
}