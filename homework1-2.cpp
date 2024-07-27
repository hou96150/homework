#include <iostream>
#include <stack>
using namespace std;

int ackermann_non_recursive(int m, int n) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(m, n));

    while (!stk.empty()) {
        pair<int, int> p = stk.top();
        m = p.first;
        n = p.second;
        stk.pop();
        if (m == 0) {
            n = n + 1;
        }
        else if (n == 0) {
            stk.push(make_pair(m - 1, 1));
        }
        else {
            stk.push(make_pair(m - 1, -1)); // Mark position to continue with this m
            stk.push(make_pair(m, n - 1));
            continue;
        }

        if (!stk.empty() && stk.top().second == -1) {
            stk.pop();
            n = stk.top().first;
            stk.pop();
            stk.push(make_pair(m, n));
        }
        else if (stk.empty()) {
            return n;
        }
    }
    return n;
}

int main() {
    int m = 2, n = 3;
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann_non_recursive(m, n) << endl;
    return 0;
}
