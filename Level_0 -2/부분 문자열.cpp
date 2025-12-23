#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Contains(string str1, string str2) {
    // my_string에서 target 찾기
    // find() 성공: 위치 인덱스 반환
    // find() 실패: string::npos 반환
    return str2.find(str1) != string::npos ? 1 : 0;
}

int main() {
    string my_string = "tbt";     
    string target = "tbbttb";        
    auto result = Contains(my_string, target); 

    cout << result << endl; 
}