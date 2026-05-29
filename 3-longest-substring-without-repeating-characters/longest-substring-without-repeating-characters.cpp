#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> freq;
        int left = 0;
        int right = s.size();
        int maxLen = 0;

        for(int i = 0; i < right; i++){
            if(freq.find(s[i]) == freq.end()){
                freq.emplace(s[i], i);
            }
            else {
                if(freq[s[i]] >= left){
                    left = freq[s[i]] + 1;
                }
                freq[s[i]] = i;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};