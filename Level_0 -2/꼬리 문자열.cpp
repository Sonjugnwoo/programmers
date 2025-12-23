#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string ExcludeContaining(vector<string> str_list, string ex) {
    string result = "";

    // ex가 "포함된" 모든 문자열 삭제 
    str_list.erase(remove_if(str_list.begin(), str_list.end(),
        [&](string x) {return x.find(ex) != string::npos; }), str_list.end()
    );

    // 남은 문자열들을 순서대로 연결

    for (auto& p : str_list)
        result += p;

    return result;
}

int main() {
    vector<string> my_string = { "abc", "def", "ghi" };
    string ex = "ef";

    auto result = ExcludeContaining(my_string, ex);

    cout << result << endl;
}