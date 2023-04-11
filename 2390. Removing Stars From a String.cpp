class Solution {
public:
    string removeStars(string s) {
        // stack<char> c;
        // stack<char> q;
        // string ans;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]!='*')
        //     c.push(s[i]);
        //     else{
        //         if(!c.empty())
        //         c.pop();
        //     }
        // }
        // while(!c.empty()){
        //     char ch = c.top();
        //     c.pop();
        //     q.push(ch);
        // }
        // while(!q.empty()){
        //     ans.push_back(q.top());
        //     q.pop();
        // }
        // return ans;

        string ans;
        for(auto c:s){
            if(c=='*'){
                ans.pop_back();
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};