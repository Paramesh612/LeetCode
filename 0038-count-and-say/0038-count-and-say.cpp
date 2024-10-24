class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = "1";
        int count = 0;
        for (int i = 1; i < n; i++) {
            string temp = "";
            count = 1;
            str += "#";
            for (int j = 0; j < str.size() - 1; j++) {
                if (str[j] == str[j + 1]) {
                    count++;
                } else {
                    temp += (to_string(count) + (str[j]));
                    count = 1;
                }
            }
            str = temp;
        }
        return str;
    }
};