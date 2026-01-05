#include <iostream>
#include <bitset>
#include <string>
#include <vector>

using namespace std;
// 비밀지도  문제 해결
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
   
    for (int i = 0; i < arr1.size(); i++) {
        string temp;
        // 두 지도의 비트 OR 연산
        bitset<16> bit1(arr1[i]);
        bitset<16> bit2(arr2[i]);
        bitset<16> bit_or(bit1 | bit2);

        // 하위 n비트만 순회
        for (int j = n-1; j >=0; j--) {
            // 해당 비트가 1이면 벽(#), 0이면 빈공간( )
            temp += bit_or[j] ? '#' : ' ';
        }
        answer.push_back(temp);  // 완성된 행 추가
    }
   
    return answer;
}

int main() {
    int n = 5;
    vector<int> arr1 = { 9,20,28,18,11 };
    vector<int> arr2 = { 30,1,21,17,28 };

    auto result = solution(n, arr1, arr2);

    for (auto re : result)
        cout << re << endl;

    cout << endl;   
}