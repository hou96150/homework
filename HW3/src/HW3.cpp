#include <iostream>
#include <chrono>
using namespace std;

class Polynomial {
private:
    struct Node {
        int coeff;   // �t��
        int exp;     // ����
        Node* next;  // ���V�U�@�Ӹ`�I�����w
        Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
    };

    Node* head;  // �Y�`�I���w

public:
    Polynomial() : head(nullptr) {}  // �w�]�غc���

    Polynomial(const Polynomial& a) {  // �ƻs�غc���
        // ��{�ƻs���
    }

    ~Polynomial() {  // �Ѻc���
        // �������귽
    }

    Polynomial& operator=(const Polynomial& a) {  // ��Ⱦާ@��
        // ��{��Ⱦާ@��
        return *this;
    }

    Polynomial operator+(const Polynomial& b) const {  // �[�k�ާ@��
        Polynomial result;
        // ��{�h�����ۥ[
        return result;
    }

    Polynomial operator-(const Polynomial& b) const {  // ��k�ާ@��
        Polynomial result;
        // ��{�h�����۴�
        return result;
    }

    Polynomial operator*(const Polynomial& b) const {  // ���k�ާ@��
        Polynomial result;
        // ��{�h�����ۭ�
        return result;
    }

    float Evaluate(float x) const {  // �h�����������
        float result = 0.0;
        // �p��ê�^�h��������
        return result;
    }

    friend istream& operator>>(istream& is, Polynomial& x) {  // ��J�ާ@��
        // ��{��J�h�������ഫ�������
        return is;
    }

    friend ostream& operator<<(ostream& os, const Polynomial& x) {  // ��X�ާ@��
        // ��{������ഫ���~�����
        return os;
    }
};


int main() {
    Polynomial p1, p2;

    cout << "��J�Ĥ@�Ӧh�����]�Ҧp�G3 2 4 1 -5 0 ��� 3x^2 + 4x - 5�^�G";
    cin >> p1;
    cout << "��J�ĤG�Ӧh�����G";
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

    cout << "�[�k�ާ@�Ӯ�: " << elapsed.count() << " ��" << endl;

    return 0;
}


