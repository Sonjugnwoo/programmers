#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> dateToTotalDays(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    // 오늘 날짜 파싱 및 총일수 변환 (1년=336일)
    size_t first_pos = today.find_first_of('.');
    size_t finish_pos = today.find_last_of('.');
    int year = stoi(today.substr(0, first_pos));
    int month = stoi(today.substr(first_pos+1, finish_pos));
    int day = stoi(today.substr(finish_pos + 1));
    int total_day = year * 336 + month * 28 + day;

    // 약관 맵 생성 
    map<string, string> term;
    for (auto it : terms) {
        size_t pos = it.find(' ');
        if (pos != string::npos) {
            auto ter = it.substr(0, pos);      // 약관 타입
            auto time = it.substr(pos + 1);    // 개월수 문자열

            term.emplace(ter, time);
        }
    }
    // 각 개인정보 검사
    int idx = 1;
    for (string check : privacies) {
        
        char c = check.back();
        check.pop_back();

        string type(1,c);

        // 수집일 파싱
        size_t year_pos = check.find_first_of('.');
        size_t month_pos = check.find_last_of('.');
        int check_year = stoi(check.substr(0, year_pos));;
        int check_month = stoi(check.substr(year_pos+1, month_pos));
        int check_day = stoi(check.substr(month_pos + 1));

        // 유효기간 더하기
        auto it = term.find(type);
        if (it != term.end()) 
            check_month += stoi(it->second);

        // 유효기간 끝 날짜 계산
        int check_total_day = check_year * 336 + check_month * 28 + check_day;

        // 오늘보다 이전/같으면 파기
        if (check_total_day <= total_day)
            answer.push_back(idx);

        idx++;
    }
    return answer;
}

int main()
{
    string today = "2022.05.19";
    vector<string> terms = { "A 6", "B 12", "C 3" };
    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };
 
    auto result = dateToTotalDays(today,terms,privacies);


    for (auto p : result)
        cout << p << " ";
    cout << endl;
}
