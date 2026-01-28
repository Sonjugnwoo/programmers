#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int findMaxNextMonthGifts(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    // 1. 친구 이름 → 인덱스 매핑 생성 (문자열을 숫자 인덱스로 변환)
    unordered_map<string, int> id_index;
    for (int i = 0; i < n; i++)
        id_index[friends[i]] = i;  

    // 2. 선물 기록 및 선물 지수 계산
    vector<vector<int>> give(n, vector<int>(n, 0)); // i -> j 에게 준 선물 수 
    vector<int> gift_index(n, 0);                   // i 의 선물 지수(준 선물 - 받은 선물)

    // 모든 선물  처리
    for (auto& gift : gifts) {
        size_t pos = gift.find(' ');
        string from_str = gift.substr(0, pos);
        string to_str = gift.substr(pos + 1);

        // 친구 목록에 있는 사람들만 처리
        if (id_index.count(from_str) && id_index.count(to_str)) {
            int from = id_index[from_str];
            int to = id_index[to_str];

            // 선물 기록 저장
            give[from][to]++;
            // 선물 지수 업데이트: 주는 사람 +1, 받는 사람 -1
            gift_index[from]++;
            gift_index[to]--;
        }
    }
    // 3. 다음 달 선물 예측 (모든 친구 쌍 비교)
    vector<int> next_month(n, 0);   // 각 친구가 다음달에 받을 선물 수

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt_ij = give[i][j];     // j -> i 에게 준 선물 수
            int cnt_ji = give[j][i];     // i -> j 에게 준 선물 수

            // 규칙 1: 더 많이 준 사람이 다음달 선물 받음
            if (cnt_ij > cnt_ji)
                next_month[i]++;
            else if (cnt_ij < cnt_ji)
                next_month[j]++;
            // 주고받은 횟수 같음
            else {
                // 규칙 2: 선물 지수가 높은 사람이 받음
                if (gift_index[i] > gift_index[j])
                    next_month[i]++;
                else if(gift_index[i] < gift_index[j])
                    next_month[j]++;
            }
            // 둘 다 같으면 아무도 안 받음
        }
    }
    // 4. 다음달 가장 많이 받을 선물 수 반환
    for (int cnt : next_month) {
        if (cnt > answer) answer = cnt;
    }
  

    return answer;
}

int main() {
    vector<string> friends = { "a", "b", "c" };
    vector<string> gifts = { "a b", "b a", "c a", "a c", "a c", "c a" };

    auto result = findMaxNextMonthGifts(friends, gifts);

    cout << result << endl;
}