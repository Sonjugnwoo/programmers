#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getMinPaintCount(int n, int m, vector<int> section) {
    int answer = 0;
    int paint_end = 0;        // 마지막으로 칠한 구간의 끝 위치

    // section은 오름차순 정렬되어 있다고 가정 (문제 조건)
    for (int wall : section) {  // 칠해야 할 구간 순회
        if (wall > paint_end) {  // 현재 칠 범위 밖에 있음 → 새로 칠해야 함
            paint_end = wall + m - 1;  // 새 칠 범위: wall부터 m길이만큼
            answer++;                  // 페인트 횟수 증가
        }
        // paint_end 범위 내 → 이미 칠함, 건너뜀
    }
    return answer;
}


int main() {
    int n = 4;
    int m = 1;
    vector<int> section = {1,2,3,4 };

    auto result = getMinPaintCount(n,m,section);

    cout << result << endl;
}