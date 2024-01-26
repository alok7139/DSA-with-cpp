/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

*/
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            bool match =true;
            for(int j=1;j<n;j++){
                if(strs[j].size()<i or ch!=strs[j][i]){
                    match=false;
                    break;
                }
            }
            if(match==false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }