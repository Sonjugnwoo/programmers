#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 체육복을 빌려줄 수 있는 학생 정보를 바탕으로 수업을 들을 수 있는 학생 수를 계산하는 함수
int solveGymSuit(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 1: 기본 1벌 있음, 0: 없음, 2: 여벌 1벌 포함 총 2벌
    vector<int> student(n, 1);

    for (int i : reserve) student[i - 1] = 2;
    for (int i : lost) student[i - 1] = 0;

    // 여벌이 있지만 동시에 도난당한 경우(실제로는 1벌만 가진 상태) 정리
    // lost 목록의 학생이 reserve에도 있으면 student를 1로 되돌림
    for (auto m : lost) {
        auto pos = find(reserve.begin(), reserve.end(), m);
        if (pos != reserve.end()) {
            // m번 학생은 여벌도 있었지만 잃어버린 상태이므로 실제로는 1벌
            student[m - 1] = 1;
        }
    }

    // 체육복 빌려주기 로직
    for (int i = 0; i < n; i++) {
        // 이미 체육복이 1벌 이상 있으면 넘어감
        if (student[i] >= 1) continue;

        // student[i]가 0인 경우에만 빌리기 시도
        if (student[i] == 0) {
            // 왼쪽 학생이 여벌이 있는 경우
            if (i > 0 && student[i - 1] == 2) {
                student[i] = 1;       // 현재 학생 1벌 확보
                student[i - 1] = 1;   // 왼쪽 학생은 1벌만 남음
            }
            // 왼쪽에서 못 빌렸다면 오른쪽 학생에게 빌리기 시도
            else if (i < n - 1 && student[i + 1] == 2) {
                student[i] = 1;       // 현재 학생 1벌 확보
                student[i + 1] = 1;   // 오른쪽 학생은 1벌만 남음

                for (int i = 0; i < student.size(); i++) {
                    if (student[i] >= 1)    answer++;
                }
                return answer;
            }
        }
    }
}


int main() {
    int n = 3;
    vector<int> lost = {3};
    vector<int> reserve = {1};

    auto result = solveGymSuit(n, lost, reserve);

    cout << result << endl;
}