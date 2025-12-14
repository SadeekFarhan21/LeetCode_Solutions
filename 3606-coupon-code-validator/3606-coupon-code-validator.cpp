class Solution {
public:
    bool is_valid(string coupon, string category){
        if(coupon.empty()){
            return false;
        }
        if(!(category == "electronics" || category == "grocery" || category == "pharmacy" || category == "restaurant")){
            return false;
        }
        for(char c : coupon){
            if(iswalnum(c) || c == '_'){
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector <pair<string, string>> mapping;
        for(int i = 0; i < isActive.size(); i++){
            if(isActive[i] && is_valid(code[i], businessLine[i])){
                mapping.push_back({businessLine[i], code[i]});
            }
        }
        sort(mapping.begin(), mapping.end());
        vector <string> answer;
        for(int i = 0; i < mapping.size(); i++){
            answer.push_back(mapping[i].second);
        }
        return answer;
    }
};