#include <iostream>
#include <vector>

using namespace std;


// date1이 date2보다 **이른 날짜**인지 확인 (1:이름, 0:늦거나 같음)
int IsEarlierDate(vector<int> date1, vector<int> date2) {
    // 1. **연도 비교** (가장 중요한 기준)
    if (date1[0] > date2[0])
        return 0;  // date1 연도가 더 큼 → date1이 더 늦음

    // 2. **월~일 순차 비교** (연도가 같을 때만 실행)
    for (int i = 1; i < date1.size(); i++) {
        if (date1[i] < date2[i])
            return 1;   // date1의 해당 자리(date2보다 작음 → date1이 더 이름

        if (date1[i] > date2[i])
            return 0;   // date1의 해당 자리(date2보다 큼 → date1이 더 늦음
    }

    return 0;  // 같거나 늦은 경우
}

int main() {
    vector<int> date1 = { 2023, 12, 1 };
    vector<int> date2 = { 2023, 1, 23 };
    
    auto result = IsEarlierDate(date1, date2);

    cout << result << endl;
}