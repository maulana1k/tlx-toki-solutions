#include <bits/stdc++.h>
using namespace std;

bool match(string w, string p)
{
    bool result = true;
    int ip = p.size();
    int iw = w.size();
    for (int i = 0; i < iw && i < ip; i++)
    {
        if (p[i] != '*')
        {
            if (p[i] != w[i])
            {
                result = false;
                break;
            }
        }
        else
            break;
    }
    while (ip-- && iw--)
    {
        if (p[ip] != '*')
        {
            if (p[ip] != w[iw])
            {
                result = false;
                break;
            }
        }
        else
            break;
    }

    return result;
}

int main()
{
    string pattern;
    int N;
    vector<string> words;
    getline(cin, pattern);
    cin >> N;
    cin >> ws;
    while (N--)
    {
        string temp;
        getline(cin, temp);
        words.push_back(temp);
    };
    for (auto word : words)
    {
        if (match(word, pattern))
            cout << "\n"
                 << word;
    };

    // cout << pattern.size();

    return 0;
}