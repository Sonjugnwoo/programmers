#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// K번째 수 추출 함수
vector<int> extractKthElements(vector<int> array, vector<vector<int>> commands) {
    vector<int> result;

    for (int i = 0; i < commands.size(); i++) { 
        vector<int> subarray;
        int start = commands[i][0]-1;
        int end = commands[i][1];
        int idx = commands[i][2]-1;
        int idx = commands[i][2]-1;
        
        subarray.insert(subarray.begin(), array.begin() + start, array.begin() + end);
        sort(subarray.begin(), subarray.end());
     
        result.push_back(subarray[idx]);

    }

    return result;
}


int main() {
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };

    auto result = extractKthElements(array,commands);

    for (auto re : result)
        cout << re << " ";

    cout << endl;
}