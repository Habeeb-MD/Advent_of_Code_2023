#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long sum = 0;
    int curNum, maxR, maxG, maxB;

    string nextLine;
    ifstream inputFile("input/Day_2_input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            curNum = maxR = maxG = maxB = 0;
            int len = nextLine.size();
            for (int i = 0; i < len; i++)
            {
                char ch = nextLine[i];
                if (ch >= '0' and ch <= '9')
                {
                    curNum = curNum * 10 + (ch - '0');
                }
                else
                {
                    if (ch == ' ' and curNum > 0)
                    {
                        switch (nextLine[i + 1])
                        {
                        case 'r':
                            maxR = max(maxR, curNum);
                            break;
                        case 'g':
                            maxG = max(maxG, curNum);
                            break;
                        case 'b':
                            maxB = max(maxB, curNum);
                            break;
                        }
                    }
                    curNum = 0;
                }
            }
            sum += maxR * maxG * maxB;
        }
        inputFile.close();
        cout << sum;
    }
}
