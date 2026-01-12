#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> lottoRankCalculator(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    // 0개수 세기 (와일드카드: 어떤 숫자든 대체 가능)
    int zero_count = count(lottos.begin(), lottos.end(), 0);

    // 실제 당첨번호와 일치하는 개수 세기
    int cnt = 0;
    for (auto num : win_nums) {
        // 이 당첨번호가 lottos에 몇 번 나오는지 카운트
        cnt += count(lottos.begin(), lottos.end(), num);
    }

    // 최대 당첨 가능 개수 (0은 나머지 빈자리 채움)
    int max_match = min(6, cnt + zero_count);

    // 순위 계산: 순위 = 7 - 당첨개수 (1등=최고, 6등=낙첨)
    answer = { 7 - max_match, 7 - cnt };  // {최고가능순위, 최저가능순위}

    // 순위가 6을 넘지 않도록 보장 (7등은 없음)
    if (answer[1] > 6) answer[1] = 6;  // 최저순위 안전장치
    if (answer[0] > 6) answer[0] = 6;  // 최고순위 안전장치

    return answer;
}

int main() {
    vector<int> lottos = { 1,2,3,4,5,6 };
    vector<int> win_nums = { 31, 10, 45, 15, 55, 19 };

    auto result = lottoRankCalculator(lottos, win_nums);

    for (auto p : result)
        cout << p << " ";
    cout << endl;
}
