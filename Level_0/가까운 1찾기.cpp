#include <iostream>
#include <string>
#include <vector>

using namespace std;

// idx부터 시작하여 가장 가까운 1의 위치를 찾는 함수
int SearchNearOne(const vector<int>& arr, int idx) {
	// 문제: int와 size_t(unsigned) 비교 - 컴파일러 경고 발생
	// i가 음수일 경우 unsigned로 변환되면 매우 큰 값이 됨
	for (int i = idx; i < arr.size(); i++) {
		if (arr[i] == 1)
			return i;  // 1을 찾으면 해당 인덱스 반환
	}
	return -1;  // 1을 못 찾으면 -1 반환
}

int main() {
	vector<int> arr = { 1,0,0,1,0,0 };

	int idx = 4;

	auto result = SearchNearOne(arr, idx);

	cout << result << endl;
}