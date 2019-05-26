class Solution {
public:
    bool isValid(string s) {
        //O(n2) recursive solution
        if(s.size() == 0)
            return true;
        
        //if "()" doesnt = string end pos
        if(s.find("()") != string::npos){
            int index = s.find("()");
            s.replace(index, 2, "");
            return isValid(s);
        }
        else if(s.find("{}") != string::npos){
            int index = s.find("{}");
            s.replace(index, 2, "");
            return isValid(s);
        }
        else if(s.find("[]") != string::npos){
            int index = s.find("[]");
            s.replace(index, 2, "");
            return isValid(s);
        }
        else
            return false;
    }
};