#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int simulateBandaging(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int currentHealth = health;      // 현재 체력
    int continuousHealing = 0;       // 연속 성공 시간 (붕대 몇 초째 감는 중)
    unordered_map<int, int> damage;  // 공격 정보를 저장 (시간 -> 피해량)
    int lastAttackTime = attacks.back()[0]; // 마지막 공격 시점

    // 공격 정보를 해시맵에 저장
    for (const vector<int>& at : attacks)
        damage.emplace(at[0], at[1]);

    // 1초부터 마지막 공격 시간까지 시뮬레이션
    for (int time = 1; time <= lastAttackTime; time++) {
        auto attack = damage.find(time);

        // 공격이 없는 경우 → 체력 회복
        if (attack == damage.end()) {
            continuousHealing++;
            currentHealth += bandage[1];  // 초당 회복량 적용

            // 체력이 최대치를 넘어가면 보정
            if (currentHealth >= health) {
                currentHealth = health;
                continue;
            }
        }
        // 공격이 있는 경우 → 피해 처리
        else {
            currentHealth -= attack->second;
            if (currentHealth <= 0)
                return -1; // 체력이 0 이하이면 사망

            continuousHealing = 0; // 연속 회복 중단
        }

        // 붕대 시전 완성 시 추가 회복 보너스 적용
        if (continuousHealing == bandage[0]) {
            continuousHealing = 0;
            currentHealth += bandage[2];
            if (currentHealth >= health)
                currentHealth = health;
        }
    }

    return currentHealth;
}

int main() {
    vector<int> bandage = {1,1,1};
    int health = 5;
    vector<vector<int>> attacks = { {1,2 }, {3, 2 } };

    auto result = simulateBandaging(bandage, health,attacks);

    cout << result << endl;
}