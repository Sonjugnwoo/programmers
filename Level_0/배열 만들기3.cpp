#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 주어진 구간들(intervals)에 해당하는 배열 요소들을 순서대로 추출하는 함수
vector<int> CreateArr(vector<int> arr, vector<vector<int>> intervals) {
	vector<int> result;
	
	// 범위 기반 for문으로 모든 구간을 순회 (개선된 부분)
	for (const auto& interval : intervals) {
		// 현재 구간의 시작 인덱스
		auto start = interval.front();
		// 현재 구간의 끝 인덱스
		auto end = interval.back();

		// 시작부터 끝까지 해당 인덱스의 요소들을 결과에 추가
		for (int j = start; j <= end; j++) {
			result.push_back(arr[j]);
		}
	}
	return result;
}

int main() {
	vector<int> arr = { 1,2,3,4,5 };
	vector<vector<int>> intervals = { {1,3},{0,4} };

	auto result = CreateArr(arr, intervals);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}