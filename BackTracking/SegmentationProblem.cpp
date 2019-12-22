#include <bits/stdc++.h>
using namespace std;

class Segmenttext{
private:
    string text;
    int n;
    unordered_set<string> dict;
    static bool isWord(const string& s){
        return true;
    }
    bool isWord(int i, int j){
        return isWord(this->text.substr(i, j-i));
    }
public:
    Segmenttext(vector<string> &words, string &s){
        for(auto &word : words){
            this->dict.insert(word);
        }
        this->text = move(s);
        this->n = (int)this->text.size();
    }
    bool isPartiotionable(int i){
        if(i == this->n) return true;
        for(int j=0; j<this->n; j++){
            if(isWord(i, j)){
                if(isPartiotionable(j+1)){
                    return true;
                }
            }
        }
        return false;
    }
    int numberOfPartitions(int i){
        if(i == this->n) return 1;
        for(int j=i; j<n; j++){
            if(isWord(i, j)){
                if(numberOfPartitions(j+1)){

                }
            }
        }
    }
};

int main(){
    return 0;
}