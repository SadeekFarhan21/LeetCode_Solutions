class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer = "";
        for(int i = 0; i < min(word1.size(), word2.size()); i++){
            answer += word1[i];
            answer += word2[i];
        }
        if(word1.size() < word2.size()){
            answer += word2.substr(word1.size(), word2.size());
        }
        else if(word1.size() > word2.size()){
            answer += word1.substr(word2.size(), word1.size());
        }
        return answer;
    }
};