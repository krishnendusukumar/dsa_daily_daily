class Solution {
public:
    bool doesAliceWin(string s) {
        bool flag = false;
        for(auto it : s) if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') flag = true;
    return flag;
    }
};