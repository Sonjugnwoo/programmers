#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> ChoiceK(vector<int>& arr,int k ) {
    vector<int> result;
    unordered_set<int> seen;           // 중복 체크용 해시셋

    for (auto v : arr) {
        if (seen.find(v) == seen.end()) {  // 중복이 아니면
            seen.insert(v);                  // 방문 처리
            result.push_back(v);             // 결과에 추가
            if (result.size() == k)          // k개 채웠으면 종료
                break;
        }
    }

    // 필요한 길이만큼 -1로 채우기
    while (result.size() < k) {
        result.push_back(-1);
    }
    return result;
}
int main() {

    vector<int> arr = { 0, 1, 1, 1, 1 };
    int k = 4;

    auto result = ChoiceK(arr, k);

    for (auto p : result)
        cout << p << " ";
}