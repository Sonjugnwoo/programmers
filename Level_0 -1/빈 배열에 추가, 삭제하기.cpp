#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 빈 밴열에 arr[i] 만큼 추가 및 삭제
vector<int> EmptyArrAddandErase(const vector<int>& arr, const vector<bool>& flag) {
    vector<int> result;  // 결과를 담을 벡터
    for (int i = 0; i < arr.size(); i++) {
        if (flag[i])
            // flag가 true일 경우, arr[i] 값을 arr[i] * 2개 한 번에 삽입
            result.insert(result.end(), arr[i] * 2, arr[i]);
        else
            // flag가 false일 경우, 벡터 끝에서 arr[i]개 만큼 삭제
            result.erase(result.end() - arr[i], result.end());
    }
    return result;
}
int main() {

    vector<int> arr = { 3,2,4,1,3};
    vector<bool> flag = { true, false, true, false, false };

    auto result = EmptyArrAddandErase(arr,flag);

    for (auto p : result)
        cout << p << " ";
}