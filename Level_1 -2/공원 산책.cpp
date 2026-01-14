#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getFinalParkPosition(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int sx = -1, sy = -1;  // 시작 위치

    int n = park.size();        // 공원 행 수
    int m = park[0].size();     // 공원 열 수

    // 1. 시작 위치 'S' 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (park[i][j] == 'S') {
                sx = i;
                sy = j;
                break;  // 열 루프 탈출
            }
        }
        if (sx != -1) break;  // 행 루프 탈출
    }

    pair<int, int> pos = { sx, sy };  // 현재 위치 [행, 열]

    // 2. 각 이동 명령 처리
    for (const string& route : routes) {
        size_t space = route.find(' ');           // 공백 위치
        string dir = route.substr(0, space);      // 방향: E,W,S,N
        int dist = stoi(route.substr(space + 1)); // 거리

        // 방향 벡터 설정
        int dx = 0, dy = 0;
        if (dir == "E") dy = 1;      // 동: 열+1
        else if (dir == "W") dy = -1; // 서: 열-1
        else if (dir == "S") dx = 1;  // 남: 행+1
        else if (dir == "N") dx = -1; // 북: 행-1

        bool can_walk = true;
        int cur_x = pos.first;
        int cur_y = pos.second;

        for (int i = 0; i < dist; i++) {
            int nx = cur_x + dx;
            int ny = cur_y + dy;

            // 범위 벗어나거나 장애물 → 이동 불가
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || park[nx][ny] == 'X') {
                can_walk = false;
                break;
            }

            // 1칸 성공 → cur 위치 갱신
            cur_x = nx;
            cur_y = ny;
        }
        // 전체 이동 성공 
        if (can_walk) {
            pos.first += dx * dist;
            pos.second += dy * dist;
        }
    }

    answer = { pos.first,pos.second };

    return answer;
}


int main() {
    vector<string> park = { "OSO","OOO","OXO","OOO"};
    vector<string> routes = { "E 2","S 3","W 1" };


    auto result = getFinalParkPosition(park, routes);

    for (auto p : result)
        cout << p << " ";
    cout << endl;
}