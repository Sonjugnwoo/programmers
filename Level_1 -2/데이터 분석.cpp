#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;    
    unordered_map<string, int> col_map = {
      {"code", 0}, {"date", 1},
      {"maximum", 2}, {"remain", 3}
    };

    int filter_idx = col_map[ext];
    if (filter_idx == 0) return {};  // map[]은 기본 0 반환

    // 필터링
    for (const auto& product : data) {
        if (product[filter_idx] < val_ext)
            answer.push_back(product);
    }

    // 정렬
    int sort_idx = col_map[sort_by];
    sort(answer.begin(), answer.end(),
        [sort_idx](const auto& a, const auto& b) {
        return a[sort_idx] < b[sort_idx];
    });

    return answer;
}


int main() {
    vector<vector<int>> data = { 
        {1, 20300104, 100, 80},
        {2, 20300804, 847, 37},
        {3, 20300401, 10,  8 }
    };
    string ext = "date";
    int val_ext = 20300501;
    string sort_by = "remain";

    auto result = solution(data,ext,val_ext,sort_by);

    for (auto r : result) {
        for (auto e : r) 
            cout << e << ' ';
        
        cout << endl;
    }
    cout << endl;

}