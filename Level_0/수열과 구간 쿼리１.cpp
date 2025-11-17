#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Sequence(vector<int> arr, vector<vector<int>> queries) {
	// queries의 각 쿼리를 순회 (외부 루프)
	for (int i = 0; i < queries.size(); i++) {
		// 현재 쿼리의 시작점(queries[i][0])부터 끝점(queries[i][1])까지 순회 (내부 루프)
		for (int j = queries[i][0]; j <= queries[i][1]; j++)
			arr[j] += 1;  // 범위 내의 각 인덱스 값을 1씩 증가
	}
	return arr;
}

int main() {
	vector<int> arr = { 0,1,2,3,4 };
	vector<vector<int>> queries = { {0,1}, {1,2},{2,3} };

	auto result = Sequence(arr, queries);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}