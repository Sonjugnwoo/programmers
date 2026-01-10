#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_weight = sizes[0][0];
    int max_high = sizes[0][1];

    for (int i = 1; i < sizes.size(); i++) {
        if (max_weight < sizes[i][0])
            max_weight = sizes[i][0];
        if (max_high < sizes[i][1])
            max_high = sizes[i][1];
    }
  


    return max_high * max_weight;
}



int main() {

    vector<vector<int>> sizes = { {60,50} ,{30,70} ,{60,30} ,{80,40} };

    auto result = solution(sizes);

    cout << result << endl;
}