Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0,maxLength=0;
        unordered_map<char,int> mp;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l){
                    l=mp[s[r]]+1;
                }
            }
            maxLength=max(maxLength,r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return maxLength;
    }
};
