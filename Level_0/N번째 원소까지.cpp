#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 벡터의 처음 n개 요소만 남기고 나머지를 삭제
vector<int> NthIndex(vector<int> num_list, int n) {
	//  n번째 인덱스부터 끝까지 삭제
	num_list.erase(num_list.begin()+n, num_list.end());

	return num_list;
}


int main() {
	vector<int> num_list = { 5,2,1,7,5 };
	int n = 3;

	auto result = NthIndex(num_list, n);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}