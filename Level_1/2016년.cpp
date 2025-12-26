#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 2016년 에서 'a월 b일'의 요일을 반환하는 함수
string getDayOf2016(int a, int b) {
    // 각 월의 일수
    // 인덱스를 월 번호와 동일하게 맞추기 위해 맨 앞에 0 추가
    vector<int> MONTH_DAYS = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

    // 각 월의 1일이 무슨 요일인지 표현한 인덱스
    // 요일 배열 Week의 인덱스: MON(0)~SUN(6)
    vector<int> day_Index = { 0,4,0,1,4,6,2,4,0,3,5,1,3 };

    // 요일 이름 배열
    vector<string> week = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

    // 입력값 검증: 존재하지 않는 날짜 방지
    if (MONTH_DAYS[a] < b || b < 1)
        return "range_of_error";

    // 요일 계산 식
    // (a월 1일의 요일 인덱스 + (b - 1)일 후) % 7 → 요일 계산
    string answer = week[(day_Index[a] + (b - 1)) % 7];
    return answer;
}

int main() {
    int month = 5;
    int day = 24;

    auto result = getDayOf2016(month, day);

    cout << result << endl;
}