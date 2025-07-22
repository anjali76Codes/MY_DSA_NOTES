// 1. print Name n times
#include <bits/stdc++.h>
using namespace std;

void Name(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << "Anjali" << endl;
    Name(i + 1, n);
}

int main()
{

    int n;
    cin >> n;
    Name(1, n);

    return 0;
}

// 2.  print linearly 1 to N times

#include <bits/stdc++.h>
using namespace std;

void num(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << i << endl;
    num(i + 1, n);
}

int main()
{

    int n;
    cin >> n;
    num(1, n);

    return 0;
}

// 3.  print N to 1

#include <bits/stdc++.h>
using namespace std;

void num(int i, int n)
{
    if (i <= 0)
    {
        return;
    }

    cout << i << endl;
    num(i - 1, n);
}

int main()
{

    int n;
    cin >> n;
    num(n, n);

    return 0;
}

// 4.  print 1 to N (backtracking)
#include <bits/stdc++.h>
using namespace std;

void num(int i, int n)
{
    if (i < 1)
    {
        return;
    }

    num(i - 1, n);
    cout << i << endl;
}

int main()
{

    int n;
    cin >> n;
    num(n, n);

    return 0;
}

// 5.  print N to 1 (backtracking)
#include <bits/stdc++.h>
using namespace std;

void num(int i, int n)
{
    if (i > n)
    {
        return;
    }

    num(i + 1, n);
    cout << i << endl;
}

int main()
{

    int n;
    cin >> n;
    num(1, n);

    return 0;
}