#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
// 벡터에서 첫 번째 2와 마지막 2 사이의 모든 요소를 반환하는 함수
vector<int> Between2(vector<int> arr) {
	vector<int> result;
	// 정방향 검색: 첫 번째 2의 위치를 찾는 반복자
	auto start_it = find(arr.begin(), arr.end(), 2);

	// 역방향 검색: 마지막 2의 위치를 찾는 역방향 반복자
	auto end_it = find(arr.rbegin(), arr.rend(), 2);

	// 첫 번째 2의 인덱스 계산: begin()부터 start_it까지의 거리
	auto start = distance(arr.begin(), start_it);

	// 마지막 2의 인덱스 계산: 역방향 반복자를 정방향 인덱스로 변환
	// rend()부터 end_it까지의 거리에서 1을 빼면 실제 인덱스
	auto end = distance(end_it, arr.rend()) - 1;

	// 2를 찾지 못한 경우
	if (start_it == arr.end() || end_it == arr.rend())
		return { -1 };
	else {
		// start 인덱스부터 end 인덱스까지 모든 요소를 result에 추가
		for (int i = start; i <= end; i++)
			result.push_back(arr[i]);
	}

	return result;
}
 
int main() {
	
	vector<int> arr = {1,1,1};

	auto result = Between2(arr);

	for (auto p : result)
		cout << p << " ";

	cout << endl;
}