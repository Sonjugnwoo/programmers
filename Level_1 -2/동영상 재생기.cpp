#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int op_start_int = stoi(op_start.substr(0, 2) + op_start.substr(3));
    int op_end_int = stoi(op_end.substr(0, 2) + op_end.substr(3));
    int pos_int = stoi(pos.substr(0, 2) + pos.substr(3));
    cout << op_start_int << endl;
    cout << op_end_int << endl;
    cout << pos_int << endl;

    if (pos_int > op_start_int && pos_int < op_end_int)
        pos_int = op_end_int;

    cout << pos_int<<endl;

    for (string com : commands) {
        com == "next" ? pos_int += 10 : pos_int -= 10;
        cout << pos_int<<endl;
    }
    if (pos_int > op_start_int && pos_int < op_end_int)
        pos_int = op_end_int;
    cout << pos_int<< endl;

    answer = to_string(pos_int);
    answer.insert(2, ":");
    return answer;
}

int main() {
    string video_len = "07:22";
    string pos = "04:05";
    string op_start = "00:15";
    string op_end = "04:07";
    vector<string> commands = { "next", "prev" };

    auto result = solution(video_len,pos,op_start,op_end,commands);

    cout << result << endl;
}