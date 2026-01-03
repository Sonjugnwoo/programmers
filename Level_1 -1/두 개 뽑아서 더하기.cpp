#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 배열의 모든 두 수 조합의 합을 구하고 중복 제거하는 함수
vector<int> getAllPairSums(const vector<int>& numbers) {
    vector<int> result;  // 모든 조합의 합을 저장할 결과 벡터

    // 모든 두 수의 조합을 찾아서 합을 계산
    for (size_t i = 0; i < numbers.size(); i++) {
        for (size_t j = i + 1; j < numbers.size(); j++) {
            // i번째 수 + j번째 수의 합을 결과에 추가 (중복 조합 방지)
            result.push_back(numbers[i] + numbers[j]);
        }
    }

    // 오름차순 정렬
    sort(result.begin(), result.end());

    // 중복된 값들을 제거 (unique는 정렬된 범위에서만 동작)
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
}

int main() {
    vector<int> numbers = { 2,1,3,4,1 };

    auto result = getAllPairSums(numbers);

    for (auto re : result)
        cout << re << " ";

    cout << endl;
}