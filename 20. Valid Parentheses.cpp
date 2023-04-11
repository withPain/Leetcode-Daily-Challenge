//cpp solution 
//Runtime = 0ms; beats 100%
class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        if(s.length() == 1){}
        for(int i =0 ;i<s.length();i++){
            char ch = s[i];
            //opening bracket
            if(ch == '(' || ch == '{' || ch == '['){
                c.push(ch);
            }
            //closing bracket
            else{
                if(!c.empty()){
                    char top = c.top();
                    if( (ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') ){
                        c.pop();
                    }
                    // s = '(])'
                    else
                    return false;
                }
                //s = ')'
                else
                return false;
            }
        }

        if(c.empty())
        return true;
        else
        return false;
    }
};
