#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findPositionsToRemove(string str1, string str2) {
    vector<int> result;
    
    // Traverse through str1 and check by removing one character at a time
    for (int i = 0; i < str1.size(); i++) {
        string modifiedStr = str1.substr(0, i) + str1.substr(i + 1);
        
        // Check if the modified string matches str2
        if (modifiedStr == str2) {
            result.push_back(i);
        }
    }
    
    return result;
}

int main() {
    string str1 = "abdgggda";
    string str2 = "abdggda";
    
    vector<int> positions = findPositionsToRemove(str1, str2);
    
    cout << "Positions to remove: ";
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;
    
    return 0;
}
