#include <iostream>
using namespace std;
int R, C;

void hilang(int B[][8], int *R, int *C);
bool isFull(int cols[], int n)
{
    bool full = true;

    for (int i = 0; i < n; i++)
        if (cols[i] == 0)
        {
            full = false;
            break;
        }

    return full;
}
void runtuh(int B[][8], int *R, int *C, int *lr)
{
    for (int c = 0; c < *C; c++)
    {
        int base = *lr;
        while (base < *R)
        {
            if (B[base + 1][c] == 0)
                base++;
            else
                break;
        }
        for (int r = base; r >= 0; r--)
        {
            if (B[r][c] == 1)
            {
                B[r][c] = 0;
                B[base][c] = 1;
                base--;
            }
        }
    }
    for (int r = 0; r < *R; r++)
    {
        if (isFull(B[r], *C))
            hilang(B, R, C);
    }
}
void hilang(int B[][8], int *R, int *C)
{
    int last_row = 0;
    bool isRuntuh = false;
    for (int r = 0; r < *R; r++)
    {
        if (isFull(B[r], *C))
        {
            isRuntuh = true;
            for (int c = 0; c < *C; c++)
                B[r][c] = 0;
            last_row = r;
        }
    }
    if (isRuntuh)
        runtuh(B, R, C, &last_row);
}
void printAll(int B[][8], int *R, int *C)
{
    for (int i = 0; i < *R; i++)
    {
        for (int j = 0; j < *C; j++)
        {
            cout << B[i][j];
        }
        cout << endl;
    }
}
int main()
{
    cin >> R >> C;

    int block[20][8] = {};

    for (int r = 0; r < R; r++)
    {
        char row[C];
        cin >> row;
        for (int c = 0; c < C; c++)
            block[r][c] = row[c] - '0';
    }
    if (!(R > 1 && C == 1))
        hilang(block, &R, &C);

    printAll(block, &R, &C);

    return 0;
}
