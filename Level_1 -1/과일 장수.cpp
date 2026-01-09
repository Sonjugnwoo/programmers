#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int fruitSellerProfit(int k, int m, vector<int> score) {
    int answer = 0;
    // 높은 점수부터 정렬 (내림차순)
    sort(score.begin(), score.end(),greater<int>());

    //  m개씩 그룹화
    for (int i = 0; i+m <=score.size() ; i+=m) {
        // 그룹 내 최저 점수 (가장 낮은 과일로 상자 가격 결정)
        int min_score = *min_element(score.begin() + i, score.begin() + i + m);

        // 상자 1개 수익 = 최저 점수 × m개
        answer += min_score * m;
    }

    return answer;
}

int main() {
    int k = 4;
    int m = 3;
    vector<int> score = { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 };

    auto result = fruitSellerProfit(k, m, score);

    cout << result << endl;
}