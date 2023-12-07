#include <bits/stdc++.h>
using namespace std;

int getCardRank(string s)
{
    unordered_map<char, int> tmp;
    for (int i = 0; i < 5; i++)
        tmp[s[i]]++;

    int j = tmp['J'];
    if (j == 5)
        return 7;

    string t;
    for (auto [a, b] : tmp)
        if (a != 'J')
            t += to_string(b);
    sort(t.begin(), t.end());
    t.back() += j;

    int Rank = 0;
    if (t == "5")
        Rank = 7;
    if (t == "14")
        Rank = 6;
    if (t == "23")
        Rank = 5;
    if (t == "113")
        Rank = 4;
    if (t == "122")
        Rank = 3;
    if (t == "1112")
        Rank = 2;
    if (t == "11111")
        Rank = 1;
    return Rank;
}

int main()
{
    unordered_map<char, int> Value;
    string s = "TQKA";
    Value['J'] = 1;
    for (int i = 2; i < 10; i++)
        Value['0' + i] = i;
    for (int i = 0; i < 5; i++)
        Value[s[i]] = 10 + i;

    auto compareCards = [&](pair<string, int> a, pair<string, int> b)
    {
        int x = getCardRank(a.first);
        int y = getCardRank(b.first);
        if (x == y)
        {
            for (int i = 0; i < 5; i++)
                if (Value[a.first[i]] != Value[b.first[i]])
                    return Value[a.first[i]] < Value[b.first[i]];
        }
        return x < y;
    };

    string nextLine;
    ifstream inputFile("input/Day_7_input.txt");

    vector<pair<string, int>> cards;
    if (inputFile.is_open())
    {
        while (getline(inputFile, nextLine))
        {
            int len = nextLine.size();
            int w = nextLine.find_first_of(' ');
            string x = nextLine.substr(0, w);
            int bid = stoi(nextLine.substr(w + 1, len - w - 1));
            cards.push_back({x, bid});
        }
        inputFile.close();
    }
    sort(cards.begin(), cards.end(), compareCards);
    int n = cards.size();
    long ans = 0;
    for (long int i = 0; i < n; i++)
    {
        ans += (i + 1) * cards[i].second;
    }
    cout << ans;
}