#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 벡터의 크기를 2의 거듭제곱 크기로 맞추는 함수
vector<int> ArrPow(vector<int> arr) {
    vector<int> result = arr; // 원본 배열 복사
    int len = arr.size();     // 현재 배열의 길이
    int copy_len = len;
    int count = 0;            // 몇 번 2로 나눌 수 있는지 세기 위한 변수
    int pow = 1;              // 2의 거듭제곱 값을 저장

    // copy_len이 1이 될 때까지 2로 나누면서 나눗셈의 횟수를 구함
    while (copy_len != 1) {
        count++;
        copy_len /= 2;
    }

    // count값만큼 2를 곱해서 2의 거듭제곱 값을 계산
    for (int i = 0; i < count; i++)
        pow *= 2;

    // 만약 계산된 2의 거듭제곱이 실제 배열 길이보다 작다면
    // 다음 2의 거듭제곱으로 올림
    if (pow < arr.size())
        pow *= 2;

    // 부족한 길이만큼 0을 뒤에 추가해 새로운 크기의 벡터 완성
    for (int i = 0; i < (pow - len); i++)
        result.push_back(0);
	
	return result;
}

int main() {
	vector<int> arr = { 1,2,3,4,5};

	auto result = ArrPow(arr);

	for (auto res : result)
		cout << res << " ";

	cout << endl;

}