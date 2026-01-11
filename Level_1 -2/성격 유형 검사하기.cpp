#include <iostream>
#include <string>
#include <vector>

using namespace std;

string determineMBTIPersonality(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<pair<int, char>> scores = {
         {0,'R'}, {0,'T'},  // 1번째 지표
        {0,'C'}, {0,'F'},  // 2번째 지표  
        {0,'J'}, {0,'M'},  // 3번째 지표
        {0,'A'}, {0,'N' }  // 4번째 지표
    };

    // 각 질문 처리
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] > 4) {                    // 5~8: 뒤 MBTI 점수 증가
            char mbti = survey[i].back();        // 두번째 문자
            for (auto& score : scores) {
                if (mbti == score.second) {
                    score.first += abs(choices[i] - 4);  // 점수: 1,2,3,4
                    break;
                    }
                }
            }
        else if (choices[i] < 4) {               // 1~3: 앞 MBTI 점수 증가  
            char mbti = survey[i].front();       // 첫번째 문자
            for (auto& score : scores) {
                if (mbti == score.second) {
                    score.first += abs(choices[i] - 4);  // 점수: 3,2,1
                    break;
                    }
                }
            }
       }     // choices[i] == 4: 중립 → 점수 변화 없음

    // 각 지표별 승자 결정 (앞>뒤, 동점시 앞 우선)
    for (int i = 0; i < scores.size() - 1; i += 2) {
        if (scores[i].first >= scores[i + 1].first)     // 앞 ≥ 뒤
            answer += scores[i].second;
        else                                            // 뒤 > 앞
            answer += scores[i + 1].second;
    }


    return answer;
}


int main() {
    vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
    vector<int> choices = { 5, 3, 2, 7, 5 };

    auto result = determineMBTIPersonality(survey, choices);

    cout << result << endl;
}