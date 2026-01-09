#include <iostream>
#include <string>
#include <vector>

using namespace std;

string foodFightTournament(vector<int> food) {
    string answer = "";
    // 1. 왼쪽 반 음식 배치 (1번 음식부터, 물(0번)은 제외)
    for (int i = 1; i < food.size(); i++) {
        int count = food[i] / 2;  // 짝수 쌍만 사용 (홀수면 1개 남김)

        // count만큼 i번 음식 왼쪽에 배치
        for (int j = 0; j < count; j++)
            answer += to_string(i);
    }

    // 2. 오른쪽 반: 왼쪽 복사 후 역순 배치
    string right = answer;
    reverse(right.begin(), right.end());

    // 3. 중앙에 물(0) 배치
    answer += '0';
    answer += right;


    return answer;
}
int main()
{
    vector<int> food = { 1,3,4,6 };

    auto result = foodFightTournament(food);

    cout << result << endl;
}
