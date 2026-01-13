#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<pair<int, char>> key_path;
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            key_path.push_back(make_pair(j, keymap[i][j]));
        }
    }

    for (auto ch : targets) {
        int sum = 0; 
        for (auto ta : ch) {
            auto pos = find_if(key_path.begin(), key_path.end(), [=](const pair<int, char>& p) {return p.second == ta; });
            auto rpos = find_if(key_path.rbegin(), key_path.rend(), [=](const pair<int, char>& p) {return p.second == ta; });


            if (pos->first > rpos->first) sum += rpos->first + 1;
            else if (pos->first < rpos->first)   sum += pos->first + 1;
            else if (pos == key_path.end() && rpos == key_path.rend()) sum = -1;
            else    sum += pos->first + 1;
                
        }
        answer.push_back(sum);
    }


    return answer;
}


int main() {
    vector<string> keymap = { "ABACD", "BCEFD" };
    vector<string> targets = { "ABCD","AABB" };

    auto result = solution(keymap, targets);

    for (auto p : result)
        cout << p << " ";

    cout << endl;
}