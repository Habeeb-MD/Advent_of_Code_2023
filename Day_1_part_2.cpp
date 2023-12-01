#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long sum = 0;
    string digits[] = {"", "one", "two", "three", "four",
                       "five", "six", "seven", "eight", "nine"};

    char First, Last;
    auto updateFirstLast = [&](char ch)
    {
        if (First == '-')
            First = ch;
        Last = ch;
    };

    string nextLine;
    ifstream inputFile("input/Day_1_input.txt");
    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            First = '-';
            int len = nextLine.size();
            for (int i = 0; i < len; i++)
            {
                char ch = nextLine[i];
                if (ch < '0' || ch > '9')
                {
                    for (int j = 1; j <= 9; j++)
                    {
                        int digitLen = digits[j].size();
                        if (digits[j][0] == ch and i + digitLen <= len and
                            nextLine.substr(i, digitLen) == digits[j])
                        {
                            ch = '0' + j;
                            break;
                        }
                    }
                }
                if (ch > '0' and ch <= '9')
                {
                    updateFirstLast(ch);
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
