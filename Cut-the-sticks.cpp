vector <int> cutTheSticks(vector <int> arr)
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

vector<int> cutTheSticks1(vector<int> arr)
{
    vector<int> result;
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    while (!arr.empty())
    {
        cout << arr.size() << endl;

        for (int i = 0; i < arr.size(); ++i)
            arr[i] -= arr[arr.size()-1];

        while (arr.back() == 0 && !arr.empty())
            arr.pop_back();
    }

    return arr;
}

