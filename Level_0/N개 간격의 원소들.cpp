#include <iostream>
#include <string>
#include <vector>

using namespace std;
// n개 간격으로 요소를 추출하는 함수
vector<int> intervalNth(vector<int> num_list, int n) {
	vector<int> result;
	// 인덱스 0부터 시작하여 n씩 증가하며 순회
	for (int i = 0; i < num_list.size(); i += n)
		result.push_back(num_list[i]);
	return result;
}

int main() {
	vector<int> num_list = { 4,2,6,1,7,6 };
	int n = 2;
	auto result = intervalNth(num_list, n);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}