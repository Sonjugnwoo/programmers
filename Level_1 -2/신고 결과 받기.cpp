#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> ReportResultProcessing(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, int> id_index, report_cnt;
    unordered_map<string, unordered_set<string>> reported_by;
    unordered_map <string, pair<int, int>>map;
                    
    // id_list 순서대로 인덱스 맵 생성 (muzi=0, frodo=1, ...)
    for (int i = 0; i < id_list.size(); i++)
        id_index[id_list[i]] = i;  // "con"=0, "ryan"=1

    // 중복 신고 제거: ["ryan con", "ryan con", ...] → ["ryan con"]
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    // 1단계: 신고 관계 분석 (O(n))
    for (auto& r : report) {  // 각 신고 기록 순회
        size_t pos = r.find(' ');  // "ryan con" → 공백 위치
        string from = r.substr(0, pos);  // 신고자: "ryan"
        string to = r.substr(pos + 1);   // 피신고자: "con"

        // id_list에 없는 사용자 무시 
        if (id_index.count(from) && id_index.count(to)) {
            reported_by[to].insert(from);  // con → {ryan} set 저장
            report_cnt[to]++;              // con: 1 (중복 제거 후)
        }
    }

    // 2단계: 메일 발송 처리 (O(신고 횟수))
    for (auto& p : report_cnt) {  // 각 피신고자 확인
        string to = p.first;      // 피신고자 이름
        int cnt = p.second;       // 신고받은 횟수
        if (cnt >= k) {           // k회 이상 신고 → 메일 발송!
            for (auto& from : reported_by[to]) {  // 이 사람들 신고한 모든 사용자
                answer[id_index[from]]++;         // 신고자 메일 +1
            }
        }
    }

    //////////// 너무 느림 ////////////////
    /*for (int i = 0; i < report.size();i++) {
        size_t pos = report[i].find(' ');
        string name = report[i].substr(0, pos);
        string rept = report[i].substr(pos + 1);

        auto it = map.find(rept);

        if (it != map.end()) 
            it->second.second++;        
    }*/
    
   /* for (auto &it : map) {
        if (it.second.second >= k) {
            for (auto str : report) {
               size_t pos = str.find(' ');
               string rept = str.substr(pos + 1);

               if (rept == it.first) {
                   string name = str.substr(0, pos);
                   auto check = map.find(name);
                   if (check != map.end()) {
                       check->second.first++;
                   }
               }
            }
        }
    }*/
    //for (auto &id : id_list) 
    //    answer.push_back(map[id].first);

    
    return answer;
}

int main() {
    vector<string> id_list = { "con", "ryan"};
    vector<string> report = { "ryan con", "ryan con", "ryan con", "ryan con" };
    int k = 3;

    auto result = ReportResultProcessing(id_list, report,k);

    for (auto p : result)
        cout << p << " ";
    cout  << endl;
}