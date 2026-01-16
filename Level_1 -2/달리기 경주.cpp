#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> CalcRunningRace(vector<string> players, vector<string> callings) {
    unordered_map<string, int> name_to_pos;

    // 초기 맵 구성 (선수별 위치 저장)
    for (int i = 0; i < players.size(); i++)
        name_to_pos[players[i]] = i;

    // 각 호출 처리
    for (const string& call : callings) {
        int idx = name_to_pos[call];  // 현재 호출된 선수 위치

        // 1등(0번)은 이동 불가
        if (idx > 0) {
            int front_idx = idx - 1;      // 앞자리 선수 위치
            string front_name = players[front_idx];  // 앞자리 선수 이름
            string curr_name = players[idx];         // 호출된 선수 이름

            // 선수 순서 교환
            swap(players[idx], players[front_idx]);

            // 맵 갱신: 이름별 새 위치 업데이트
            name_to_pos[front_name] = idx;      // 앞자리 선수가 밀려난 위치
            name_to_pos[curr_name] = front_idx; // 호출 선수가 올라온 위치
        }
    }
    return players;
}

int main() {
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> callings = { "kai", "kai", "mine", "mine" };

    auto result = CalcRunningRace(players, callings);

    for (auto p : result)
        cout << p << " ";
    cout << endl;

}