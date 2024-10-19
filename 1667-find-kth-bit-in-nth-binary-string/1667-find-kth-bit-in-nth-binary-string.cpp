class Solution {
public:
    void invertBits(string& str) {
        for (auto& it : str) {
            if (it == '0')
                it = '1';
            else
                it = '0';
        }
    }

    // bool invert=false;
    char findKthBit(int n, int k) {
        if (k == 1)
            return  '0'; //invert ? '1' : // The first position is always 1

        int length = pow(2, n) - 1;
        int mid = length / 2;

        if (k == mid)
            return '1'; //invert ? '0' :  // The midpoint is always 1
        else if (k < mid)
            return findKthBit(n - 1, k);
        else {
            return findKthBit(n - 1, length - k + 1)=='0'?'1':'0';
        }
    }
};