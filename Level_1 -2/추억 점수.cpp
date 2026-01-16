#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> CalcMemoryScore(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> score_by_name;

    // 이름별 그리움 점수 맵 구성
    for (int i = 0; i < static_cast<int>(name.size()); i++) {
        score_by_name.emplace(name[i], yearning[i]);
    }

    // 각 사진별 추억 점수 계산
    for (int i = 0; i < static_cast<int>(photo.size()); i++) {
        int sum = 0;
        // 문자열 복사 방지
        for (const string& person : photo[i]) {
            auto it = score_by_name.find(person);
            if (it != score_by_name.end()) {
                sum += it->second;
            }
        }
        answer.push_back(sum);
    }

    return answer;
}

int main() {
    vector<string> name = { "may", "kein", "kain", "radi" };
    vector<int> yearning = { 5,10,1,3 };
    vector<vector<string>> photo = { 
        {"may", "kein", "kain", "radi"} ,
        {"may", "kein", "brin", "deny"},
        {"kon", "kain", "may", "coni" }
    };

    auto result = CalcMemoryScore(name, yearning, photo);

    for (auto p : result)
        cout << p << " ";
    cout << endl;

}