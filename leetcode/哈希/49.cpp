class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unorded_map<string,vector<string>> mp;  
            for(const string& str : strs) {
                string key = str;
                sort(key.begin(),key.end());
                mp[key].push_back(str);
            }
            
        }
    };