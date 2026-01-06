#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 3명의 수포자가 정답을 맞춘 횟수를 계산하여 최고점자들을 오름차순 반환
vector<int> findTopScorers(vector<int> answers) {
    vector<int> result;

    // 각 수포자의 찍기 패턴
    vector<vector<int>> patterns = {
        {1,2,3,4,5},           // 1번 수포자: 5개 주기
        {2,1,2,3,2,4,2,5,2,1}, // 2번 수포자: 8개 주기 
        {3,3,1,1,2,2,4,4,5,5}  // 3번 수포자: 10개 주기
    };

    vector<int> scores(3, 0);
    // 1. 점수 계산: 외부-수포자 고정, 내부-문제 순회
    for (int i = 0; i < 3; ++i) {
        const auto& pattern = patterns[i];
        for (size_t j = 0; j < answers.size(); ++j) {
            // 패턴 반복: j % pattern.size()
            if (answers[j] == pattern[j % pattern.size()]) {
                ++scores[i];
            }
        }
    }

    // 2. 최고점 찾기
    int max_score = *max_element(scores.begin(), scores.end());

    // 3. 최고점자들 수집 (동점 가능)
    for (int i = 0; i < 3; ++i) {
        if (scores[i] == max_score) {
            result.push_back(i + 1);
        }
    }

    // 4. 오름차순 정렬
    sort(result.begin(), result.end());

    return result;
}


int main() {

    vector<int> answers = {1,3,2,4,2}; //정답 

    auto result = findTopScorers(answers);

    for (auto re : result)
        cout << re << " ";

    cout << endl;
}