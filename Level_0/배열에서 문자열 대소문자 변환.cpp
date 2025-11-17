#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> TransformString(vector<string> my_string) {
    // 벡터의 각 문자열을 순회
    for (int i = 0; i < my_string.size(); i++)
        if (i % 2 == 0)  // 짝수 인덱스 (0, 2, 4, ...)
            // 해당 문자열을 소문자로 변환
            transform(my_string[i].begin(), my_string[i].end(), my_string[i].begin(), ::tolower);
        else  // 홀수 인덱스 (1, 3, 5, ...)
            // 해당 문자열을 대문자로 변환
            transform(my_string[i].begin(), my_string[i].end(), my_string[i].begin(), ::toupper);

    return my_string;
}


int main() {
    vector<string> my_string = {"AAA","BBB","CCC","DDD"};
    
    auto result = TransformString(my_string);

    for (auto p : result)
        cout << p << " ";

    cout << endl;

}