#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int findMinRectangleArea(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;

    // 각 명함을 순회하며 처리
    for (int i = 0; i < sizes.size(); i++) {
        // 명함의 두 변 중 작은 값을 세로, 큰 값을 가로로 정규화
        if (sizes[i][0] < sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);

        // 현재 명함의 가로가 최대 가로보다 크면 갱신
        if (max_width < sizes[i][0])
            max_width = sizes[i][0];
        // 현재 명함의 세로가 최대 세로보다 크면 갱신
        if (max_height < sizes[i][1])
            max_height = sizes[i][1];
    }

    // 최소 인쇄 직사각형의 면적 반환
    return max_height * max_width;
}



int main() {

    vector<vector<int>> sizes = { {60,50} ,{30,70} ,{60,30} ,{80,40} };

    auto result = findMinRectangleArea(sizes);

    cout << result << endl;
}