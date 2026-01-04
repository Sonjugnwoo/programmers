#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 절댓값 배열과 부호 배열을 받아 실제 값들의 합계를 계산하는 함수
int calculateSignedSum(const vector<int>& absolutes, const vector<bool>& signs) {
    int totalSum = 0;

    // 두 배열의 인덱스를 순회하며 실제 값 계산
    for (size_t i = 0; i < absolutes.size(); i++) {
        // signs[i]가 true면 양수, false면 음수로 처리
        if (signs[i]) {
            totalSum += absolutes[i];      // 양수 더하기
        }
        else {
            totalSum -= absolutes[i];      // 음수 빼기 (더하기의 역)
        }
    }

    return totalSum;
}

int main() {
    vector<int> absolutes = { 4,7,12};
    vector<bool> signs = { true,false,true };

    auto result = calculateSignedSum(absolutes, signs);

    cout << result << endl;
}