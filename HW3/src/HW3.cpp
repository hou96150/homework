#include <iostream>
#include <chrono>
using namespace std;

class Polynomial {
private:
    struct Node {
        int coeff;   // 系數
        int exp;     // 指數
        Node* next;  // 指向下一個節點的指針
        Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
    };

    Node* head;  // 頭節點指針

public:
    Polynomial() : head(nullptr) {}  // 預設建構函數

    Polynomial(const Polynomial& a) {  // 複製建構函數
        // 實現複製函數
    }

    ~Polynomial() {  // 解構函數
        // 釋放鏈表資源
    }

    Polynomial& operator=(const Polynomial& a) {  // 賦值操作符
        // 實現賦值操作符
        return *this;
    }

    Polynomial operator+(const Polynomial& b) const {  // 加法操作符
        Polynomial result;
        // 實現多項式相加
        return result;
    }

    Polynomial operator-(const Polynomial& b) const {  // 減法操作符
        Polynomial result;
        // 實現多項式相減
        return result;
    }

    Polynomial operator*(const Polynomial& b) const {  // 乘法操作符
        Polynomial result;
        // 實現多項式相乘
        return result;
    }

    float Evaluate(float x) const {  // 多項式評估函數
        float result = 0.0;
        // 計算並返回多項式的值
        return result;
    }

    friend istream& operator>>(istream& is, Polynomial& x) {  // 輸入操作符
        // 實現輸入多項式並轉換為鏈表表示
        return is;
    }

    friend ostream& operator<<(ostream& os, const Polynomial& x) {  // 輸出操作符
        // 實現鏈表表示轉換為外部表示
        return os;
    }
};


int main() {
    Polynomial p1, p2;

    cout << "輸入第一個多項式（例如：3 2 4 1 -5 0 表示 3x^2 + 4x - 5）：";
    cin >> p1;
    cout << "輸入第二個多項式：";
    cin >> p2;

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;
    float eval = p1.Evaluate(2.0);

    cout << "p1 + p2 = " << sum << endl;
    cout << "p1 - p2 = " << diff << endl;
    cout << "p1 * p2 = " << prod << endl;
    cout << "p1(2.0) = " << eval << endl;

    auto start = chrono::high_resolution_clock::now();

   

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "加法操作耗時: " << elapsed.count() << " 秒" << endl;

    return 0;
}


