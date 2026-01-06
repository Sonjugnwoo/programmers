#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 실패율이 높은 스테이지 번호 순서대로 반환
vector<int> getFailedStageOrder(int N, vector<int> stages) {
    vector<int> answer; 
    vector<pair<double,int>> failure_rate;   // {실패율, 스테이지번호}

    for (int i = 1; i <= N; i++) {
        int no_clear = 0;  // i번째 스테이지 도달자 수
        int clear = 0;     // i번째 스테이지 클리어한 사람 수

        for (auto st : stages) {
            if (st >= i) no_clear++;  // i번째 스테이지에 도달한 사람
            if (st > i) clear++;      // i번째 스테이지 클리어한 사람
        }
        // 실패율 = (도달했으나 클리어 못한 사람) / 도달한 사람
        double fail_rate = no_clear > 0 ? (double)(no_clear - clear) / no_clear : 0;

        failure_rate.push_back(make_pair(fail_rate,i));
    }

    // 2. 실패율 내림차순, 같으면 스테이지 번호 오름차순 정렬
    sort(failure_rate.begin(), failure_rate.end(),
        [](const auto& a, const auto& b) {
        if (a.first != b.first)
            return a.first > b.first;      // 실패율 높은 순
        return a.second < b.second;        // 실패율 같으면 스테이지 낮은 순
    });

    // 3. 스테이지 번호만 answer에 추가
    for (auto& p : failure_rate)
        answer.push_back(p.second);
    
    
    return answer;
}
int main() {
    int n = 5;  
    vector<int> stages = { 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4 };   

    auto result = getFailedStageOrder(n, stages);

    for (auto p : result)
        cout << p << " ";

    cout << endl;
}