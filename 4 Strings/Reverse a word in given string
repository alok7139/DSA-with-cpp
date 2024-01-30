/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
*/
    string reverseWords(string s) {
        int n=s.size();
        stack<string>st;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            string word="";
            while(s[i]!=' ' and i<n){
                word+=s[i];
                i++;
            }
            st.push(word);
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top()+" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }