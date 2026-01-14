#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

vector<int> getFileIconBounds(vector<string> wallpaper) {
    vector<int> answer;

    int lux = INT_MAX;     // 파일이 있는 최소 행 인덱스 (좌상단 행)
    int luy = INT_MAX;     // 파일이 있는 최소 열 인덱스 (좌상단 열)
    int rdx = INT_MIN;     // 파일이 있는 최대 행 인덱스 (우하단 행)
    int rdy = INT_MIN;     // 파일이 있는 최대 열 인덱스 (우하단 열)

    // 모든 셀 순회하며 '#' 위치 추적
    for (int i = 0; i < wallpaper.size(); i++) {           // 행 순회
        for (int j = 0; j < wallpaper[i].size(); j++) {    // 열 순회
            if (wallpaper[i][j] == '#') {                  // 파일 아이콘 발견
                lux = min(lux, i);     // 최소 행 갱신
                luy = min(luy, j);     // 최소 열 갱신
                rdx = max(rdx, i);     // 최대 행 갱신
                rdy = max(rdy, j);     // 최대 열 갱신
            }
        }
    }

    // 문제 요구 형식: [최소행, 최소열, 최대행+1, 최대열+1]
    answer = { lux, luy, rdx + 1, rdy + 1 };
    return answer;
}

int main() {
    vector<string> wallpaper = { ".#...", "..#..", "...#." };


    auto result = getFileIconBounds(wallpaper);

    for (auto p : result)
        cout << p << " ";
    cout << endl;
}