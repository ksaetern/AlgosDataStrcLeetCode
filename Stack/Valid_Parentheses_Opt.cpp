class Solution {
public:
    //Leetcode speed: 4ms
    bool isValid(string s) {
        int size = s.size();
        if(size == 0) return true;
        if(size == 1) return false;
        if(size % 2 != 0) return false;
        
        //can assume size >= 2
        stack<char> st;
        if(s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;
        else
            st.push(s[0]);
        
        for(int i = 1; i < size; i++)
        {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(st.empty())
                    return false;
                else
                {
                    if(valParen(st.top(), s[i]))
                        st.pop();
                    else
                        return false;                        
                }
            }
            else
                st.push(s[i]);
        }
        if(st.empty()) return true;
        return false;
    }
    
private:
    bool valParen(char a, char b)
    {
        if(a == '[' && b == ']')
            return true;
        else if(a == '{' && b == '}')
            return true;
        else if(a == '(' && b == ')')
            return true;
        else
            return false;
    }
};