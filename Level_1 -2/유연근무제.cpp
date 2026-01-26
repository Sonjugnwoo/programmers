#include <iostream>
#include <string>
#include <vector>

using namespace std;

int addTenMinutesToSchedule(int schedule) {
    int hour = schedule / 100;
    int minute = schedule % 100;

    // 분이 60 이상이면 시를 1 증가하고 분에서 60 빼기
    if (minute >= 60) {
        hour += 1;
        minute -= 60;
    }

    return schedule = hour * 100 + minute;
}

int countPossibleSchedules(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    // 요일 배열: 0=SUN, 1=MON, 2=TUE, 3=WED, 4=THU, 5=FRI, 6=SAT
    vector<string> weekdays = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    // 각 작업에 대해 검사
    for (int size = 0; size < timelogs.size(); size++) {      

        bool flag = true;               // 해당 작업이 모든 평일에 가능한지 여부

        // 7일 동안 검사
        for (int i = 0; i < 7; i++) {
            string day = weekdays[(i + startday) % 7 ]; 
            if (day == "SAT" || day == "SUN")   continue;    // 주말(SAT, SUN)은 검사 제외

            // 시간 + 10분이 해당 날 사용 가능 시간보다 작으면 불가능
            int schedule_time = addTenMinutesToSchedule(schedules[size] + 10);
           
            if (schedule_time < timelogs[size][i]) {
                flag = false;
                break;
            }

        }   
        // 모든 평일에 작업이 가능하면 카운트 증가
        if (flag)   
            answer++;
    }
    return answer;
}


int main() {
    vector<int> schedules = { 700,800,1100 };
    vector<vector<int>> timelogs = {
        {710, 2359, 1050, 700, 650, 631, 659},
        {800, 801, 805, 800, 759, 810, 809},
        {1105, 1001, 1002, 600, 1059, 1001, 1100} 
    };
    int startday =5;

    auto result = countPossibleSchedules(schedules, timelogs, startday);

    cout << result << endl;
}