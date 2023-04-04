#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int st[100], n, k;

int modul(int x)
{
    if (x < 0)
        x = -x;
    return x;
}

int valid(int k)
{
    int i;
    for (i = 1; i <= k - 1; i++)
        if ((st[i] == st[k]) || (modul((st[k] - st[i])) == (k - i)))
            return 0;
    return 1;
}

int solutie(int k)
{
    if (k == n)
        return 1;
    return 0;
}

void initial(int k)
{
    st[k] = 0;
}

void bck(int k)
{
    initial(k);
    int i;
    for (i = 1; i <= n; i++)
    {
        st[k] = i;
        if (valid(k) == 1)
        {
            if (solutie(k) == 1)
                tipar();
            else
                bck(k + 1);
        }
    }
}

void tipar()
{
    int i, j;
    k++;
    cout << endl;
    cout << "Solution " << k << " is" << endl;

    for (i = 1; i <= n; i++)
    {
        cout << endl;
        for (j = 1; j <= n; j++)
            if (st[j] == i)
                cout << "+ ";
            else
                cout << "- ";
    }
    cout << endl;
}

int main()
{
    cout << "The number of queens is ";
    cin >> n;
    bck(1);
    cout << "The number of solutions is " << k << endl;

    return 0;
}
