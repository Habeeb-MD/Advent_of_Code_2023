#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long sum = 0;
    int gameId, curNum, valid;

    string nextLine;
    ifstream inputFile("input/Day_2_input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            gameId = curNum = 0;
            valid = 1;
            int len = nextLine.size();
            for (int i = 0; i < len; i++)
            {
                char ch = nextLine[i];
                if (ch >= '0' && ch <= '9')
                {
                    curNum = curNum * 10 + (ch - '0');
                }
                else
                {
                    if (ch == ':')
                    {
                        gameId = curNum;
                    }
                    else if (ch == ' ' and curNum > 0)
                    {
                        switch (nextLine[i + 1])
                        {
                        case 'r':
                            valid &= (curNum <= 12);
                            break;
                        case 'g':
                            valid &= (curNum <= 13);
                            break;
                        case 'b':
                            valid &= (curNum <= 14);
                            break;
                        }
                    }
                    curNum = 0;
                }
            }
            if (valid)
            {
                sum += gameId;
            }
        }
        inputFile.close();
        cout << sum;
    }
}
