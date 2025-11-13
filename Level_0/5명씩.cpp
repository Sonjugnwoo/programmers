#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 입력 벡터에서 매 5번째 인덱스에 있는 요소들만 추출하여 반환
vector <string> People5(vector<string> name) {
	vector<string> result;
	int idx = 0;

	// 인덱스가 벡터 크기를 넘지 않는 동안 반복
	while (idx < name.size()) {
		// 현재 인덱스의 요소를 결과 벡터의 끝에 추가
		result.push_back(name[idx]);

		// 다음 5번째 위치로 이동 (0 -> 5 -> 10 -> 15 ...)
		idx += 5;
	}
	return result;
}

int main() {
	vector<string> name = { "nami", "ahri", "jayce", "garen", "ivern", "vex", "jinx" };

	auto result = People5(name);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}