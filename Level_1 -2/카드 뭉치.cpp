#include <iostream>
#include <string>
#include <vector>

using namespace std;

string checkGoalSequence(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int idx1 = 0;  // cards1 현재 위치
    int idx2 = 0;  // cards2 현재 위치

    // goal의 각 단어를 순서대로 확인
    for (int i = 0; i < goal.size(); i++) {
        // cards1에서 순서대로 다음 단어 매칭
        if (goal[i] == cards1[idx1])
            idx1++;
        // cards2에서 순서대로 다음 단어 매칭
        else if (goal[i] == cards2[idx2])
            idx2++;
        // 어느 카드에도 없으면 불가능
        else
            return "No";
    }

    return "Yes";
}

int main() {
    vector<string> cards1 = { "i", "drink", "water"};
    vector<string> cards2 = { "want", "to" };
    vector<string> goal = { "i", "want", "to", "drink", "water" };

    auto result = checkGoalSequence(cards1,cards2,goal);

    cout << result << endl;
}