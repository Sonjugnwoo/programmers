#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;
// 완주하지 못한 선수 찾기 함수
string findUnfinishedRunner(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 두 배열 오름차순 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (size_t i = 0; i < completion.size(); i++) {
        if (completion[i] != participant[i]) {
            return participant[i];  // 첫 불일치 = 미완주자
        }
    }

    // 모든 완주자와 일치 → 마지막 참가자가 미완주자
    return participant[participant.size()-1];
}


int main() {
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };

    auto result = findUnfinishedRunner(participant, completion);

    cout << result << endl;
}