#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int> id_index, gift_cnt;
    unordered_map<string, unordered_set<string>> gift_by;
    unordered_map <string, pair<int, int>>map;

    for (int i = 0; i < friends.size(); i++)
        id_index[friends[i]] = i;  

    for (auto& gift : gifts) {
        size_t pos = gift.find(' ');
        string from = gift.substr(0, pos);
        string to = gift.substr(pos + 1);

        if (id_index.count(from) && id_index.count(to)) {
            gift_by[to].insert(from);
            gift_cnt[to]++;
        }
    }

    for (auto& gift : gift_cnt) {
        string to = gift.first;
        int cnt = gift.second;
        for (int i = 0; i < gift_by.size(); i++) {
            if(to == gift_by[i].first)
        }

    }

    return answer;
}

int main() {
    vector<string> friends = { "a", "b", "c" };
    vector<string> gifts = { "a b", "b a", "c a", "a c", "a c", "c a" };

    auto result = solution(friends, gifts);

    cout << result << endl;
}