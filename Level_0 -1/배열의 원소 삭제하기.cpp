#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> ArrDelete(vector<int> num_list,vector<int> num_delete) {
    // 1. num_delete를 O(1) 조회 가능한 해시셋으로 변환
    unordered_set<int> delete_list(num_delete.begin(), num_delete.end());

    // 2. **erase-remove idiom** 사용: num_list에서 삭제 대상 제거
    // remove_if: 삭제 대상들을 맨 뒤로 몰아넣고 새 끝 위치 반환
    // erase: 그 뒤 부분 실제 삭제
    num_list.erase(
        remove_if(num_list.begin(), num_list.end(),
            [&](int x) { return delete_list.count(x); }  // 삭제 대상 체크
        ),
        num_list.end()
    );

    return num_list;
}

int main() {

    vector<int> num_list = { 293, 1000, 395, 678, 94 };
    vector<int> num_delete = { 94, 777, 104, 1000, 1, 12 };

    auto result = ArrDelete(num_list, num_delete);

    for (auto p : result)
        cout << p << " ";
}