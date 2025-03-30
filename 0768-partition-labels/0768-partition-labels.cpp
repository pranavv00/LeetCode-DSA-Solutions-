class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<char> order;
        unordered_map<char, pair<int, int>> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]].first == 0) 
            {
                mp[s[i]].first = i + 1;
                order.push_back(s[i]);
            }
            mp[s[i]].second = i + 1;
        }

        vector<int> res;
        int right = mp[order[0]].second, left = mp[order[0]].first;
        for (int i = 0; i < order.size(); i++)
        {
            if (mp[order[i]].first > right)
            {
                res.push_back(right - left + 1);
                left = mp[order[i]].first;
            }
            right = max(right, mp[order[i]].second);
        }
        res.push_back(right - left + 1);
        return res;
    }
};