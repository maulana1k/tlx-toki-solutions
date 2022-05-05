#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string id;
    array<int, 3> V;
    Person(char *a, int n1, int n2, int n3)
    {
        id = a;
        V = {n1, n2, n3};
    }
};

void test(vector<bool> *res)
{
    int N, M, n1, n2, n3;
    char select[20], id[20];
    vector<Person> P;
    cin >> N >> M >> select;
    while (N--)
    {
        cin >> id >> n1 >> n2 >> n3;
        Person *p = new Person(id, n1, n2, n3);
        P.push_back(*p);
    }
    int size = P.size();
    for (int i = 0; i < M; i++)
    {
        for (int j = i; j < size; j++)
        {
            Person temp = P[j];
            if (P[j].V[2] > P[i].V[2])
            {
                P[j] = P[i];
                P[i] = temp;
            }
            else if (P[j].V[2] == P[i].V[2] && P[j].V[1] > P[i].V[1])
            {
                P[j] = P[i];
                P[i] = temp;
            }
            else if (P[j].V[1] == P[i].V[1] && P[j].V[0] > P[i].V[0])
            {
                P[j] = P[i];
                P[i] = temp;
            }
        }
    }
    bool lulus = false;
    for (int i = 0; i < M; i++)
    {
        if (P[i].id == select)
            lulus = true;
    }
    res->push_back(lulus);
}

int main()
{
    int T;
    cin >> T;
    vector<bool> res;
    while (T--)
    {
        test(&res);
    }
    for (auto &&i : res)
    {
        i == true
            ? cout << "YA" << endl
            : cout << "TIDAK" << endl;
    }

    return 0;
}