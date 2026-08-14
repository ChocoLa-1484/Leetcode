class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> pos;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
            pos[arr[i]].emplace_back(i);    
    }
    
    int query(int left, int right, int value) {
        auto it = pos.find(value);
        if (it == pos.end())   return 0;
        auto& v = it->second;
        return ranges::upper_bound(v, right) - ranges::lower_bound(v, left);
    }
};