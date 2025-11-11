#include <iostream>
#include <string>
#include <vector>

using namespace std;

// n 이하의 양수 중에서 k의 배수만 추출하여 벡터로 반환하는 함수
vector<int> ArrCreate(int n, int k) {
	vector<int> result;

	// 1부터 n까지 순회
	for (int i = 1; i <= n; i++)
		// i가 k의 배수인지 확인 (나머지가 0이면 배수)
		if (i % k == 0)
			// k의 배수를 벡터의 끝에 추가
			result.push_back(i);

	return result;
}


int main() {
	int n = 10;
	int k = 3;

	auto result = ArrCreate(n,k);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}