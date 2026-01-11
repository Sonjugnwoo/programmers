#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int findMissingNumber(vector<int> numbers) {
    // 1+2+...+9 = 45 (고정값)
    int total_sum = 45;

    // 입력 숫자들의 합계 계산 (STL accumulate 활용)
    int sum_numbers = accumulate(numbers.begin(), numbers.end(), 0);

    // 없는 숫자 = 전체합 - 입력합
    return total_sum - sum_numbers;
}

int main() {
    vector<int> numbers = { 1,2,3,4,6,7,8,0 };

    auto result = findMissingNumber(numbers);

    cout << result << endl;
}