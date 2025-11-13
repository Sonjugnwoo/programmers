#include <iostream>
#include <string>
#include <vector>

using namespace std;

// n번째 인덱스 이전의 모든 요소를 제거하는 함수
vector<int> NthIndex(vector<int> num_list, int n) {
	// 처음부터 (n-1)번째 인덱스 직전까지의 요소 삭제
	num_list.erase(num_list.begin(), num_list.begin()+(n-1));
	
	return num_list;
}


int main() {
	vector<int> num_list = {5,2,1,7,5};
	int n = 2;

	auto result = NthIndex(num_list, n);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}