#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheSticks' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> cutTheSticks(vector<int> arr)
{
    std::vector<int> result;
    std::map<int, int> mp;
    int count = arr.size();

    for (const auto &n : arr)
    {
        mp[n]++;
    }

    for (const auto &m : mp)
    {
        result.emplace_back(count);
        count -= m.second;
    }

    // for (auto itr = mp.cbegin(); itr != mp.cend(); ++itr)
    // {
    //     result.emplace_back(count);
    //     count -= itr->second;
    // }

    return result;
}

vector<int> cutTheSticks0(vector<int> arr)
{
    std::vector<int> result;
    std::map<int, int> mp;

    for (const auto &n : arr)
    {
        const auto ret = mp.insert({n, 1});
        if (ret.second == false)
        {
            ret.first->second++;
        }
    }

    while (mp.empty() == false)
    {
        int count_per_round = 0;
        auto iter = mp.begin();
        int min = iter->first;

        while (iter != mp.end())
        {
            count_per_round += iter->second;

            int temp = iter->first;
            if (min == temp)
            {
                iter = mp.erase(iter);
            }
            else
            {
                int temp_key = iter->first - min;
                int temp_count = iter->second;
                iter = mp.erase(iter);
                const auto ret = mp.insert({temp_key, temp_count});
                if (ret.second == false)
                {
                    ret.first->second = temp_count;
                }
            }
        }

        result.push_back(count_per_round);
    }

    return result;
}

vector <int> cutTheSticks1(vector <int> arr)
{
    vector<int> result;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < size; i++)
    {
        if (!arr[i]) continue;
        int cut=0;
        int val = arr[i];

        for (int j = i; j < size; j++)
        {
            if (arr[j])
            {
                arr[j] = arr[j] - val;
                cut++;
            }
        }

        result.push_back(cut);
    }

    return result;
}

vector<int> cutTheSticks2(vector<int> arr)
{
    vector<int> result;
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    while (!arr.empty())
    {
        result.emplace_back(arr.size());

        for (size_t i = 0; i < arr.size(); ++i)
        {
            arr[i] -= arr[arr.size()-1];
        }

        while (arr.back() == 0 && !arr.empty())
        {
            arr.pop_back();
        }
    }

    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
