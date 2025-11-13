#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 벡터에서 첫 번째 음수의 인덱스를 찾는 함수
int FirstNegativeNumber(const vector<int>& num_list) {
	// 벡터의 모든 요소를 순회
	for (int i = 0; i < num_list.size(); i++) {
		// 현재 요소가 음수인지 확인
		if (num_list[i] < 0)
			return i;  // 음수를 찾으면 해당 인덱스 반환
	}

	// 음수를 찾지 못한 경우 -1 반환
	return -1;
}

int main() {
	vector<int> num_list = { 12,4,15,46,38,-2,15 };

	auto result = FirstNegativeNumber(num_list);

	cout << result << endl;
}