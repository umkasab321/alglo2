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
    vector<vector<int>> dp2(S.size()+1, vector<string>(T.size()+1,0));
    dp[0][0] = "";
    dp2[0][0] = 0;
    int s, t = 0;
    for(s = 1; s < S.size() + 1; ++s){
        for(t = 1; t < T.size() + 1; ++t){
           if(S[s - 1] == T[t - 1]){
               
               chmax(dp2[s][t], dp2[s - 1][t - 1] + 1);
           }
           if()
        //    if(s > 0) chmax(dp[s][t], dp[s - 1][t] + S[s - 1]);
        }
    }

    return 0;
}