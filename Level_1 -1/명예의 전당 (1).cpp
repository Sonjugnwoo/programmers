#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> getHonorRanking(int k, vector<int> score) {
    vector<int> answer;
    vector<int> honor;

    for (int i = 0; i < score.size(); i++){
        // 모든 신규 점수를 무조건 honor에 추가
        honor.push_back(score[i]);

        // 매번 정렬하여 순위 계산
        sort(honor.begin(), honor.end());

        // k번째까지는 최하위 점수, 이후는 k등 점수 반환
        if (i < k) 
            // 명예의 전당이 아직 꽉 차지 않은 경우: 최하위 점수
            answer.push_back(*min_element(honor.begin(), honor.end()));
        else 
            // 명예의 전당 꽉 찬 후: k등 점수 (뒤에서 k번째)
            answer.push_back(honor[honor.size() - k]);
    }
    return answer;
}

int main() {
    int k =3 ;
    vector<int> score = { 10, 100, 20, 150, 1, 100, 200 };

    auto result = getHonorRanking(k,score);

    for (auto re : result)
        cout << re << " ";

    cout << endl;
}