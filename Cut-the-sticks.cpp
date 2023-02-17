vector<int> cutTheSticks(vector<int> arr)
{
    std::vector<int> result;
    std::map<int, int> mp;
    int count = arr.size();

    for (const auto &n : arr)
    {
        mp[n]++;
    }
    
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        result.emplace_back(count);
        count -= itr->second;
    }
    
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
