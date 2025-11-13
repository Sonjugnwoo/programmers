#include <iostream>
#include <string>
#include <vector>

using namespace std;

// n번째 인덱스를 기준으로 배열을 회전시키는 함수
vector<int> RotateArr(vector<int> num_list, int n) {
	vector<int> result;
	// 첫 번째 반복문: n번째 인덱스부터 끝까지 추가
	for (int i = n; i <num_list.size(); i++)
		result.push_back(num_list[i]);

	// 두 번째 반복문: 처음부터 (n-1)번째 인덱스까지 추가
	for (int i = 0; i < n; i++)
		result.push_back(num_list[i]);

	//rotate(num_list.begin(), num_list.begin() + n, num_list.end());   std 활용 
	return result;
}


int main() {
	vector<int> num_list = {5,2,1,7,5};
	int n = 3;

	auto result = RotateArr(num_list, n);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}