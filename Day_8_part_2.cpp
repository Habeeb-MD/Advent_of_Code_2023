#include <bits/stdc++.h>
using namespace std;

int main()
{
    string moves;
    unordered_map<string, array<string, 2>> Map;
    vector<string> startingNodes;

    string nextLine;
    ifstream inputFile("input/Day_8_input.txt");

    if (inputFile.is_open())
    {
        string key, leftVal, rightVal;
        while (getline(inputFile, nextLine))
        {
            if (nextLine.empty())
                continue;

            if (moves.empty())
            {
                moves = nextLine;
                continue;
            }

            key = nextLine.substr(0, nextLine.find_first_of(' '));
            leftVal = nextLine.substr(nextLine.find_first_of('(') + 1, 3);
            rightVal = nextLine.substr(nextLine.find_first_of(',') + 2, 3);
            Map[key] = {leftVal, rightVal};

            if (key.back() == 'A')
                startingNodes.push_back(key);
        }
        inputFile.close();
    }
    int n = moves.size();
    vector<int> movesTaken;
    for (auto curNode : startingNodes)
    {
        int curMoves = 0;
        for (int i = 0; curNode.back() != 'Z'; i = (i + 1) % n)
        {
            curNode = moves[i] == 'L' ? Map[curNode][0] : Map[curNode][1];
            curMoves++;
        }
        movesTaken.push_back(curMoves);
    }

    long ans = movesTaken[0];
    for (int i = 1; i < movesTaken.size(); i++)
    {
        ans = (ans * movesTaken[i]) / __gcd((long)movesTaken[i], ans);
    }
    cout << ans;
}