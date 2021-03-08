#include<iostream>
#include<iomanip>
#include<vector>
#include<random>
#include<string>

using namespace std;

template<class T> bool chmin(T& a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> void chmax(T& a, T b){
    if (a.size() < b.size()){
        a = b;
    }
}

int main(){
    // std::random_device rnd;
    // int N,W,k;
    // cin >> N;
    // cin >> W;
    // cin >> k;

    string S, T;
    S = "logistic";
    T = "algorithm";

    vector<vector<string>> dp(S.size()+1, vector<string>(T.size()+1,""));
    int s, t = 0;
    for(s = 0; s < S.size(); ++s){
        for(t = 0; t < T.size(); ++t){
            
        }
    }

    return 0;
}