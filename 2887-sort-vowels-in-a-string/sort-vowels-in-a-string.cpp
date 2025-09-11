class Solution {
public:
    string sortVowels(string s) {
        vector<int> arr;
        for(auto it : s) {
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' || it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U') {
                arr.push_back(it);
            }
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        for(int j = 0; j < s.size(); j++) {
            auto it = s[j];
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' || it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U') {
                s[j] = arr[i++];
            }
        }
        return s;
    }
};