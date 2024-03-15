/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
*/
    bool isValid(string s) {
        // if(s.size()==0){
        //     return true;
        // }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' or s[i]=='[' or s[i]=='('){
                st.push(s[i]);
            }
            else if(st.size()>0 and s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                   // break;
                }
            }
            else if(st.size()>0 and s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                    //break;
                }
            }
            else if(st.size()>0 and s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                   // break;
                }
            }
            else{
            return false;
            }
            
        }
        return st.empty();
        
    }