// Лабораторна робота №5.2
// double
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "------------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x"
        << " |" << setw(12) << "arcsin(x)"
        << " |" << setw(12) << "S(x)"
        << " |" << setw(5) << "n"
        << " |" << endl;
    cout << "------------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(3) << x
            << " |" << setw(12) << setprecision(8) << asin(x)
            << " |" << setw(12) << setprecision(8) << s
            << " |" << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "------------------------------------------------------------" << endl;
    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = x; // перший доданок
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    // рекурентне співвідношення для коефіцієнта
    double R = ((2.0 * n - 1) * (2.0 * n - 1) * x * x) / ((2.0 * n) * (2.0 * n + 1));
    a *= R;
}
