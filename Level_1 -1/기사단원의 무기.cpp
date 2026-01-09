#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calculateKnightWeaponPower(int number, int limit, int power) {
    int answer = 0;
    vector<int> divisor_counts;
    // 1. 각 기사(i)의 무기 공격력 = 약수 개수 계산
    for (int i = 1; i <= number; i++) {
        int count = 0;                 // i의 약수 개수

        // 최적화: √i까지만 확인 (O(√i))
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                // 완전제곱수: 1개, 일반: 2개 (j와 i/j)
                count += (j * j == i) ? 1 : 2;
            }
        }
        divisor_counts.push_back(count);  // 약수 개수 저장
    }

    // 2. 공격력 제한 적용하여 총합 계산
    for (auto num : divisor_counts) 
        num <= limit ? answer += num : answer += power;          

    return answer;
}

int main() {
    int number = 10;
    int limit = 3;
    int power = 2;

    auto result = calculateKnightWeaponPower(number, limit, power);

    cout << result << endl;
}