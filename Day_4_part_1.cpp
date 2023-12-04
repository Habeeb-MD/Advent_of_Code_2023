#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long sum = 0;
    int score, curNum, turn;
    unordered_set<int> winningSet;

    string nextLine;
    ifstream inputFile("input/Day_4_input.txt");

    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            score = turn = curNum = 0;
            winningSet.clear();

            int len = nextLine.size();
            for (int i = 0; i < len; i++)
            {
                char ch = nextLine[i];
                if (ch >= '0' && ch <= '9')
                {
                    curNum = curNum * 10 + (ch - '0');
                }

                if (i == len - 1 or ch < '0' or ch > '9')
                {
                    if (ch == '|')
                    {
                        turn = 1;
                    }
                    else if (i == len - 1 or (ch == ' ' and curNum > 0))
                    {
                        if (turn)
                        {

                            if (winningSet.find(curNum) != winningSet.end())
                            {
                                if (score)
                                    score *= 2;
                                else
                                    score++;
                            }
                        }
                        else
                        {
                            winningSet.insert(curNum);
                        }
                    }
                    curNum = 0;
                }
            }
            sum += score;
        }
        inputFile.close();
        cout << sum;
    }
}
