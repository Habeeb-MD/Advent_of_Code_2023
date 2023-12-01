#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long sum = 0;
    string nextLine;
    ifstream inputFile("input/Day_1_input.txt");
    char First, Last;
    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            First = '-';
            for (auto ch : nextLine)
            {
                if (ch >= '0' and ch <= '9')
                {
                    if (First == '-')
                        First = ch;
                    Last = ch;
                }
            }
            if (First != '-')
            {
                sum += (First - '0') * 10 + (Last - '0');
            }
        }
        inputFile.close();
        cout << sum;
    }
}
