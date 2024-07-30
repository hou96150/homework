#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate_powerset(vector<string>& s, vector<vector<string>>& result, vector<string>& current, int index) {
    if (index == s.size()) {
        result.push_back(current);
        return;
    }
    generate_powerset(s, result, current, index + 1);
    current.push_back(s[index]);
    generate_powerset(s, result, current, index + 1);
    current.pop_back();
}

vector<vector<string>> powerset(vector<string>& s) {
    vector<vector<string>> result;
    vector<string> current;
    generate_powerset(s, result, current, 0);
    return result;
}

int main() {
    vector<string> s = { "a", "b", "c" };
    vector<vector<string>> result = powerset(s);

    cout << "Powerset:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (const auto& element : subset) {
            cout << element << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
