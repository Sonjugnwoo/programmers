#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 예산 내 최대 신청 건수 계산 함수
int solution(vector<int> d, int budget) {
    int request_count = 1;

    sort(d.begin(), d.end());       // 신청 금액 오름차순 정렬 (탐욕법)

    int sum = d[0];

    // 예산이 첫 번째 신청금액보다 작으면 0건
    if (sum > budget) return 0;

    for (int i = 1; i < d.size(); i++) {
        sum += d[i];
        // 예산 초과시 직전까지 처리한 건수 반환
        if (sum > budget) return request_count;

        // 한 건 더 처리 가능
        request_count++;
    }
    return request_count;
}

int main() {
    vector<int> d = { 1,3,2,5,4 };
    int budget = 9;

    auto result = solution(d, budget);

    cout << result << endl;
}