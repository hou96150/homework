#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // ���F std::pow

class Term {
public:
    Term(float c = 0, int e = 0) : coef(c), exp(e) {}
    float coef;
    int exp;
};

class Polynomial {
public:
    Polynomial() = default;
    Polynomial(const Polynomial&) = default;
    Polynomial& operator=(const Polynomial&) = default;
    ~Polynomial() = default;

    void AddTerm(float coef, int exp);
    Polynomial Add(const Polynomial& poly) const;
    Polynomial Mult(const Polynomial& poly) const;
    float Eval(float f) const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
    friend std::istream& operator>>(std::istream& is, Polynomial& poly);

private:
    std::vector<Term> terms;

    static bool CompareTerms(const Term& a, const Term& b) {
        return a.exp > b.exp;
    }
};

void Polynomial::AddTerm(float coef, int exp) {
    if (coef == 0) return;

    for (auto& term : terms) {
        if (term.exp == exp) {
            term.coef += coef;
            if (term.coef == 0) {
                terms.erase(std::remove_if(terms.begin(), terms.end(), [exp](const Term& t) { return t.exp == exp; }), terms.end());
            }
            std::sort(terms.begin(), terms.end(), CompareTerms);
            return;
        }
    }

    terms.emplace_back(coef, exp);
    std::sort(terms.begin(), terms.end(), CompareTerms);
}

Polynomial Polynomial::Add(const Polynomial& poly) const {
    Polynomial result = *this;
    for (const auto& term : poly.terms) {
        result.AddTerm(term.coef, term.exp);
    }
    return result;
}

Polynomial Polynomial::Mult(const Polynomial& poly) const {
    Polynomial result;
    for (const auto& term1 : terms) {
        for (const auto& term2 : poly.terms) {
            result.AddTerm(term1.coef * term2.coef, term1.exp + term2.exp);
        }
    }
    return result;
}

float Polynomial::Eval(float f) const {
    float result = 0;
    for (const auto& term : terms) {
        result += term.coef * std::pow(f, term.exp);
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    if (poly.terms.empty()) {
        os << "0";
        return os;
    }
    bool first = true;
    for (const auto& term : poly.terms) {
        if (!first && term.coef > 0) os << " + ";
        if (term.coef < 0) os << " - ";
        if (!first && term.coef < 0) os << -term.coef;
        else os << term.coef;

        if (term.exp > 0) os << "x^" << term.exp;
        first = false;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Polynomial& poly) {
    int numTerms;
    std::cout << "��J���ơG";
    if (!(is >> numTerms) || numTerms < 0) {
        std::cerr << "�L�Ī�����" << std::endl;
        is.setstate(std::ios::failbit);
        return is;
    }

    for (int i = 0; i < numTerms; ++i) {
        float coef;
        int exp;
        std::cout << "��J�Y�ƩM���ơG";
        if (!(is >> coef >> exp)) {
            std::cerr << "�L�Ī��Y�ƩΫ���" << std::endl;
            is.setstate(std::ios::failbit);
            return is;
        }
        poly.AddTerm(coef, exp);
    }

    return is;
}

int main() {
    Polynomial p1, p2;
    std::cout << "��J�h���� 1�G" << std::endl;
    std::cin >> p1;
    std::cout << "��J�h���� 2�G" << std::endl;
    std::cin >> p2;

    Polynomial sum = p1.Add(p2);
    Polynomial product = p1.Mult(p2);

    std::cout << "�h���� 1: " << p1 << std::endl;
    std::cout << "�h���� 2: " << p2 << std::endl;
    std::cout << "�M: " << sum << std::endl;
    std::cout << "�n: " << product << std::endl;

    float x;
    std::cout << "��J�@�ӭȨӵ����h�����G";
    if (std::cin >> x) {
        std::cout << "p1(" << x << ") = " << p1.Eval(x) << std::endl;
        std::cout << "p2(" << x << ") = " << p2.Eval(x) << std::endl;
    }
    else {
        std::cerr << "�L�Ī���J" << std::endl;
    }

    return 0;
}
