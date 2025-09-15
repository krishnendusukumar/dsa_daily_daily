class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int i = 0;
        map<int, int> m;
        int count = 0;
        for(auto it : brokenLetters) m[it - 'a']++;
        bool flag = true;
        while(i < text.size()) {
        if(text[i] == ' ') {
            if(flag == true) count++;
            flag = true;
            i++;
        }
        else if(m[text[i] - 'a'] > 0) {cout<<text[i]<<" ";flag = false; i++;}
        else i++;
        }
        if(flag) count++;
        return count;
    }
};