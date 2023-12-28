#include <iostream>
#include <string>
using namespace std;
void Hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << "-->" << c << endl;
        return;
    }
    else
    {
        Hanoi(n - 1, a, c, b);
        cout << a << "-->" << c << endl;
        Hanoi(n - 1, b, a, c);
    }
}
void MultiTablepPrinting(int n)
{
    for (int i = 1; i < n; i++)
    {
        string s;
        for (int j = 1; j <= i; j++)
        {
            if (sizeof(s) == 0)
                s = to_string(j) + "*" + to_string(i) + '=' + to_string(i * j) + "\t";
            else
                s = s + to_string(j) + "*" + to_string(i) + "=" + to_string(i * j) + "\t";
        }
        cout << s << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    Hanoi(n, 'a', 'b', 'c');
    // MultiTablepPrinting(10);
    system("pause");
    return 1;
}