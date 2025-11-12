#include <iostream>
#include <string>
#include <vector>

using namespace std;


// n 값에 따라 벡터를 자르는 함수
vector<int> ListCut(int n, vector<int> slicer, vector<int> num_list) {
	vector<int> result;

	if (n == 1) {
		// 케이스 1: 0부터 slicer[1]까지
		for (int i = 0; i <= slicer[1]; i++) {
			result.push_back(num_list[i]);
		}
		return result;
	}
	else if (n == 2) {
		// 케이스 2: slicer[0]부터 끝까지
		for (int i = slicer[0]; i < num_list.size(); i++) {
			result.push_back(num_list[i]);
		}
		return result;
	}
	else if (n == 3) {
		// 케이스 3: slicer[0]부터 slicer[1]까지
		for (int i = slicer[0]; i <= slicer[1]; i++) {
			result.push_back(num_list[i]);
		}
		return result;
	}
	else if (n == 4) {
		// 케이스 4: slicer[0]부터 slicer[1]까지 slicer[2] 간격으로
		for (int i = slicer[0]; i <= slicer[1]; i += slicer[2]) {
			result.push_back(num_list[i]);
		}
		return result;
	}

	// n이 1~4가 아니면 빈 벡터 반환
	return {}; // 기본 생성자 호출 (empty vector)
}


int main() {
	int n = 5;
	vector<int> slicer = { 1,5,2 };
	vector<int> num_list = { 1,2,3,4,5,6,7,8,9 };


	auto result = ListCut(n, slicer, num_list);

	for (const auto& p : result)
		cout << p << " ";

	cout << endl;
}