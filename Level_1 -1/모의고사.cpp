#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer = answers;
    vector<vector<int>> math;
    map<int, vector<int>> map;
    vector<int> result;
    answer.insert(answer.end(),answers.begin(), answers.end());

    map[1] = { 1,2,3,4,5,1,2,3,4,5 };
    map[2] = { 2,1,2,3,2,4,2,5,2,1 };
    map[3] = { 3,3,1,1,2,2,4,4,5,5 };


    for (int i = 0; i < map.size();i++) {
        for (auto& p : map) {
            for (int j = 0; j < answer.size(); j++) {
               if(p.)
            }
        }
        result.push_back(map[i].size());
    }


    sort(result.begin(), result.end());


    return result;
}

int main() {

    vector<int> answers = { 1,2,3,4,5 }; //Á¤´ä 

    auto result = solution(answers);

    for (auto re : result)
        cout << re << " ";

    cout << endl;
}