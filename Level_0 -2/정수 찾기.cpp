#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int ContainsValue(vector<int> num_list, int n) {
    // find(): 앞에서부터 순차 탐색
    // 성공: 위치 iterator, 실패: end() iterator
    return find(num_list.begin(), num_list.end(), n) != num_list.end();
}

int main() {
    vector<int> num_list = { 1, 2, 3, 4, 5 };
    int n = 3;
    auto result = ContainsValue(num_list, n);

    cout << result << endl;
}