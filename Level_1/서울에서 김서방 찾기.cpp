#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 김서방 찾는 함수 
string findKimPosition(vector<string> seoul) {
    
    // vector에서 "Kim"의 위치(인덱스) 찾기
    // find() → iterator 반환 → begin() 빼서 인덱스 변환
    auto pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    return "김서방은 " +to_string(pos)+ "에 있다";
    
}

int main() {
    vector<string> seoul = { "Jane","Kim" };

    auto result = findKimPosition(seoul);

    cout << result << endl;
}