#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int buildPrefixSum(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    // 공원 크기 계산 (행 h, 열 w)
    int h = park.size();
    int w = park[0].size();

    // int_park: 사람(알파벳)=1(장애물), 빈공간(-1)=0
    vector<vector<int>> int_park(h, vector<int>(w, 0));

    // sum_park: 1-based 누적합 (h+1 x w+1)
    vector<vector<int>> sum_park(h + 1, vector<int>(w + 1, 0));

    // mats 내림차순 정렬 (큰 돗자리부터 검사)
    sort(mats.rbegin(), mats.rend());

    // 1단계: 공원 상태 변환
    // -1(빈공간)=0, 알파벳(사람)=1(장애물로 간주)
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (park[i][j] != "-1")  // 사람이 있는 자리 = 장애물
                int_park[i][j] = 1;
            // -1(빈공간)은 0 유지
        }
    }

    // 2단계: 2D 누적합 테이블 생성 (Python 스타일 1-based)
    // sum_park[i][j] = (0,0)~(i-1,j-1) 장애물 개수
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            // 포함배제 원리
            sum_park[i][j] = int_park[i - 1][j - 1] + sum_park[i - 1][j] +
                sum_park[i][j - 1] - sum_park[i - 1][j - 1];
        }
    }

    // 3단계: 큰 돗자리부터 배치 시도
    for (int map : mats) {
        if (map > h || map > w) continue;  // 공원보다 큰 돗자리 스킵

        // 모든 시작 위치 탐색
        for (int i = 0; i + map <= h; i++) {  // i+map-1 < h
            for (int j = 0; j + map <= w; j++) {  // j+map-1 < w
                int x1 = i;    // 시작행 (1-based: i)
                int y1 = j;    // 시작열 (1-based: j)
                int x2 = i + map;  // 끝행 다음 (1-based: i+map)
                int y2 = j + map;  // 끝열 다음 (1-based: j+map)

                // 1-based prefix sum 쿼리
                int total = sum_park[x2][y2] - sum_park[x1][y2] -
                    sum_park[x2][y1] + sum_park[x1][y1];

                // total==0 → (i,j)~(i+map-1,j+map-1) 완전 빈 공간
                if (total == 0) return map;
            }
        }
    }
    return -1;  // 모든 돗자리 배치 불가
}

int main() {
    vector<int> mats = {5,3,2 };
    vector<vector<string>> park = {
        {"A", "A", "-1", "B", "B", "B", "B", "-1"},
        {"A", "A", "-1", "B", "B", "B", "B", "-1" },
        {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},
        {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"},
        {"D", "D", "-1", "-1", "-1", "-1", "-1", "F"},
        {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}
    };


    auto result = buildPrefixSum(mats, park);

    cout << result << endl;
}