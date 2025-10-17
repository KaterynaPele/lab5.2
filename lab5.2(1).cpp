// Лабораторна робота №5.2
// Варіант 19. Обчислення arcsin(x) за рядом Тейлора
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s;
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
        s = S(x, eps, n);
        cout << "|" << setw(7) << setprecision(3) << x
            << " |" << setw(12) << setprecision(8) << asin(x)
            << " |" << setw(12) << setprecision(8) << s
            << " |" << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "------------------------------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int& n)
{
    n = 0;
    double a = x;
    double s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, const int n, double a)
{
    double R = ((2.0 * n - 1) * (2.0 * n - 1) * x * x) / ((2.0 * n) * (2.0 * n + 1));
    return a * R;
}