#include<iostream>
#include<vector>

using namespace std;

template<class T> bool chmin(T& a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> bool chmax(T& a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;

    vector<long long int> dp(N);
    vector<long long int> a(N);
    vector<long long int> b(N);
    vector<long long int> c(N);
    int i = 0;
    for(i = 0; i < N; i++){
        cout << i << endl;
        cin >> a[i] >> b[i] >> c[i];
        cout << a[i] << b[i] << c[i] << endl;
    }
    dp[0] = 0;
    int flg = -1;

    for(i = 1;i < N; ++i){
        int flg2 = -1;
        if ((flg != 0) && chmax(dp[i], dp[i-1] + a[i])){
            flg2 = 0;
        }
        if ((flg != 1) && chmax(dp[i], dp[i-1] + b[i])){
            flg2 = 1;
        }
        if ((flg != 2) && chmax(dp[i], dp[i-1] + c[i])){
            flg2 = 2;
        }
    }

    cout << dp[N-1] << endl;
    return 0;
}