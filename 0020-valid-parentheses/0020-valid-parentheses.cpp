class Solution {
public:
    bool isOpen(char el){
        string check="({[";
        for(char el2 : check){
            if(el2 == el)
                return true;
        }
        return false;
    }
    // bool isClose(char el){
    //     string check=")]}";
    //     for(char el2 : check){
    //         if(el2 == el)
    //             return true;
    //     }
    //     return false;
    // }

    char getClose(char el){
        string check="({[";
        if(el==check[0])
            return ')';
        else if(el==check[1])
            return '}';
        else if(el == check[2]) 
            return ']';
        
        return '*';
    }

    bool isValid(string s) {
        stack<char> st;
        for(char el:s){
            if(isOpen(el)) st.push(el);
            else if(!st.empty() && el == getClose(st.top()))
                st.pop();
            else
                st.push(el);
            
        }
        return st.empty();
    }
};