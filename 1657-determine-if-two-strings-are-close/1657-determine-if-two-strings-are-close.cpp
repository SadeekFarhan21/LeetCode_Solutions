class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() == word2.size()){                
            set <char> s1(word1.begin(), word1.end());
            set <char> s2(word2.begin(), word2.end());
            if(s1 == s2 ){
                map <char, int> mapping_1;
                map <char, int> mapping_2;
                
                // build the first map
                for(int i = 0; i < word1.size(); i++){
                    mapping_1[word1[i]]++;
                }

                // build the second map 
                for(int i = 0; i < word2.size(); i++){
                    mapping_2[word2[i]]++;
                }

                // build the vector
                vector <int> counts_1;
                vector <int> counts_2;

                for(auto x : mapping_1){
                    counts_1.push_back(x.second);
                }
                for(auto x : mapping_2){
                    counts_2.push_back(x.second);
                }
                sort(counts_1.begin(), counts_1.end());
                sort(counts_2.begin(), counts_2.end());
                return counts_1 == counts_2;
            }
        }
        return false;
    }
};