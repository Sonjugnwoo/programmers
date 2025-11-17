#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Sequence(vector<int>& arr) {

	for (auto& p : arr) {  // arr의 각 요소를 참조로 순회 
		if (p >= 50 && p % 2 == 0)  // 50 이상 & 짝수
			p /= 2;  // 2로 나눔
		else if (p < 50 && p % 2 == 1)  // 50 미만 & 홀수
			p *= 2;  // 2를 곱함 
	}
	return arr;
}




int main() {
	vector<int> arr = { 1, 2, 3, 100, 99, 98 };

	auto result = Sequence(arr);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}