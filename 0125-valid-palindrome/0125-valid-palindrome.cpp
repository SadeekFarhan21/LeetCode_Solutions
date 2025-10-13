class Solution {
public:
    string alphanumeric(string s){
        string alp = "";
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                alp += tolower(s[i]);
            }
        }
        return alp;
    }
    bool isPalindrome(string s) {
        s = alphanumeric(s);
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};