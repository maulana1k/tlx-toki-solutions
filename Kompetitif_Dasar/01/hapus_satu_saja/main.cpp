#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A, B;
    getline(cin, A);
    getline(cin, B);
    // if(A.size()==1 && B.size())
    if (A.size() - 1 != B.size())
    {
        cout << "Wah, tidak bisa :(" << endl;
        return 0;
    }
    bool same = false;
    for (int i = 0; i < A.size(); i++)
    {
        string temp = A;
        if (B.compare(temp.erase(i)) != 0)
        {
            same = true;
            break;
        }
    }
    string output = same ? "Tentu saja bisa!" : "Wah, tidak bisa :(";
    cout << output << endl;
    return 0;
}