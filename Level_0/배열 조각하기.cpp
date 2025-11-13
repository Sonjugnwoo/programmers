#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
// query 배열의 인덱스에 따라 arr를 잘라내는 함수
vector<int> PieceArr(vector<int> &arr, vector<int> query) {

	// query 배열의 각 인덱스를 순회
	for (int i = 0; i < query.size(); i++) {
		// i가 짝수인 경우 (query 인덱스 기준)
		if (i % 2 == 0)
			// query[i]+1 번째 인덱스부터 끝까지 삭제
			arr.erase(arr.begin() + (query[i] + 1), arr.end());
		else
			// i가 홀수인 경우 (query 인덱스 기준)
			// 처음부터 query[i] 번째 인덱스 직전까지 삭제
			arr.erase(arr.begin(), arr.begin() + query[i]);
	}
	return arr;
}


int main() {
	vector<int> arr = { 0,1,2,3,4,5 };
	vector<int> query = { 4,1,2 };

	auto result = PieceArr(arr, query);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}