#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

int Sequence(vector<int> arr) {
    vector<int> prev_arr;  // 이전 상태를 저장할 벡터
    int count = 0;  // 변환 작업 수행 횟수

    while (true) {  // 배열이 더 이상 변하지 않을 때까지 반복
        prev_arr = arr;  // 현재 배열 상태를 백업

        // 배열 전체를 한 번 변환
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= 50 && arr[i] % 2 == 0)  // 50 이상 & 짝수
                arr[i] /= 2;  // 2로 나눔
            else if (arr[i] < 50 && arr[i] % 2 == 1)  // 50 미만 & 홀수
                arr[i] = arr[i] * 2 + 1; 
        }

        count++;  // 변환 횟수 증가

        if (prev_arr == arr)  // 벡터 간 비교 
            break;
    }

    return count - 1;  // 마지막 변화 없는 회차 제외
}




int main() {
	vector<int> arr = { 1, 2, 3, 100, 99, 98 };

	auto result = Sequence(arr);

	cout << result<< endl;
}