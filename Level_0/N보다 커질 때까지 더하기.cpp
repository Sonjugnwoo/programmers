#include <iostream>
#include <string>
#include <vector>

using namespace std;


int NumberAdd(vector<int> numbers, int n) {
	int sum = 0;

	for (auto p : numbers) {  // numbers 컨테이너의 각 요소를 순회
		if (sum > n)  // 현재 합계가 n을 초과하면
			return sum;  // 즉시 현재 합계 반환 (조기 종료)
		sum += p;  // 현재 요소를 합계에 누적
	}

	return sum;
}


int main() {
	vector<int> numbers = { 34,5,71,29,100,34 };
	int n = 123;

	auto result = NumberAdd(numbers, n);

	cout << result << endl;
}