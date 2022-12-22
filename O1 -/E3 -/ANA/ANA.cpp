#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string sorted_word;
    map<string,vector<string>> wordlist;
    string words[3000];
    for (int i =0;i<n;i++)
    {
        cin >> words[i];
    }
    for (int i = 0;i<n;i++)
    {
        sorted_word = words[i];
        sort(sorted_word.begin(), sorted_word.end());
        if(wordlist.count(sorted_word) == 0)
        {
            wordlist[sorted_word] = vector<string> {};
        }
        if(find(wordlist[sorted_word].begin(),wordlist[sorted_word].end(),words[i]) == wordlist[sorted_word].end())
        {
            wordlist[sorted_word].push_back(words[i]);
        }
        
    }
    vector<vector<string>> output;
    for (auto it = wordlist.begin(); it != wordlist.end(); ++it) 
    {
        sort(it->second.begin(),it->second.end());
        output.push_back(it->second);
    }
    sort(output.begin(), output.end(), [](const std::vector<string>& a, const std::vector<string>& b) 
    {
    return a[0] < b[0];
    });
    for(int i = 0;i<output.size();i++)
    {
        for(int j = 0;j<output[i].size();j++)
        {
            cout << output[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}