#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// 정수 벡터의 모든 원소의 평균을 계산하는 함수
double calculateAverage(const vector<int>& numbers) {
    // numbers의 모든 원소를 더한 뒤, 원소 개수로 나누어 평균을 구함
    // 초기값을 0.0으로 주어 합의 타입을 double로 맞춰준다
    double sum = accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

int main() {
    vector<int> numbers = { 1,2,3,4 };

    auto result = calculateAverage(numbers);

    cout << result << endl;
}