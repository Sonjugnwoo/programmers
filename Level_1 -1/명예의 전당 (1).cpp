#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> scores(score.size(),0);
    vector<int> temple;
    for (int i = 0; i < score.size(); i++) {
        
    }


    return answer;
}

int main() {
    int k = 3;
    vector<int> score = { 10, 100, 20, 150, 1, 100, 200 };

    auto result = solution(k,score);

    for (auto re : result)
        cout << re << " ";

    cout << endl;
}