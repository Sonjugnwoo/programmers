#include <iostream>
#include <string>
#include <vector>

using namespace std;

// MM:SS 형식 문자열을 초 단위 정수로 변환
int convertToSeconds(string& t) {
    int m = stoi(t.substr(0, 2));
    int s = stoi(t.substr(3, 2));
    return m * 60 + s;
}

// 초 단위 정수를 MM:SS 형식 문자열로 변환
string formatToTimeString(int current) {
    string time ="";

    int h = current / 60;
    int m = current % 60;

    time += to_string(h / 10) + to_string(h % 10);
    time += ":";
    time += to_string(m / 10) + to_string(m % 10);

    return time;
}
// 동영상 재생기 시뮬레이션 메인 로직
string videoPlayerSolution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

    int video = convertToSeconds(video_len);
    int current = convertToSeconds(pos);
    int op_s = convertToSeconds(op_start);
    int op_e = convertToSeconds(op_end);

    // 각 명령어 처리
    for (const auto& cmd : commands) {
        // 1. 현재 위치가 오프닝 구간이면 오프닝 끝으로 스킵
        if (current >= op_s && current < op_e) current = op_e;

        // 2. 명령어에 따른 이동
        if (cmd == "next") {                // 다음으로 10초 이동 (영상 끝 경계 체크)
            current += 10;
            if (current > video) current = video;
        }
        if (cmd == "prev") {                // 이전으로 10초 이동 (영상 처음 경계 체크)
            current -= 10;
            if (current < 0) current = 0;
        }
    }
    // 모든 명령 처리 후 최종 오프닝 체크
    if (current >= op_s && current < op_e) current = op_e;

    return formatToTimeString(current);
}

int main() {
    string video_len = "10:55";
    string pos = "00:05";
    string op_start = "00:15";
    string op_end = "06:55";
    vector<string> commands = { "prev","next","next" };

    auto result = videoPlayerSolution(video_len,pos,op_start,op_end,commands);

    cout << result << endl;
}