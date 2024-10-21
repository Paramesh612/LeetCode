class Solution {
public:
    bool isVowel(char x) {
        static set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return vowels.count(tolower(x)) > 0;
    }
    string reverseVowels(string s) {
        int low = 0, high = s.size() - 1;
        // for(int i=0;i<s.size()/2  && low<high;i++)
        while (low < high) {
            while (low < high && !isVowel(s[low])) {
                low++;
            }
            while (low < high && !isVowel(s[high])) {
                high--;
            }
            if (low < high) {
                swap(s[low], s[high]);
                low++; high--;
            }
        }
        return s;
    }
};