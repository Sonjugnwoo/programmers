#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 배열 길이가 홀수면 짝수 인덱스, 짝수면 홀수 인덱스에 n을 더하는 함수
vector<int> ArrLenOperator(vector<int>& arr, int n) {
    // 시작 인덱스 결정
    int start = arr.size() % 2 == 1 ? 0 : 1;

    // start부터 2칸씩 건너뛰며 n을 더함
    for (int i = start; i < arr.size(); i += 2)
        arr[i] += n;  // 해당 인덱스의 값에 n을 누적 더함
    return arr;
}

int main() {
	vector<int> arr = { 49, 12, 100, 276, 33 };
	int n = 27;
	auto result = ArrLenOperator(arr,27);

	for (auto res : result)
		cout << res << " ";

	cout << endl;

}