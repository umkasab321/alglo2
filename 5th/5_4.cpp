#include<iostream>
#include<iomanip>
#include<vector>
#include<random>

using namespace std;

template<class T> bool chmin(T& a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> void chmax(T& a, T b){
    if (b == 1){
        a = b;
    }
}

int main(){
    std::random_device rnd;
    int N,W,k;
    cin >> N;
    cin >> W;
    cin >> k;

    vector<int> a(N);
    vector<vector<int>> dp(W+1, vector<int>(N+1,100));
    int i = 0;
    for(i = 0; i < N; i++){
        a[i] = rnd() % 20;
        cout << "a[" << i << "]: " << a[i] << endl;
    }

    for(i = 0; i < N+1; ++i){
        dp[0][i] = 0;
    }
    
    int w = 0;
    for(w = 1;w < W + 1; ++w){
        for(i = 1;i < N + 1; ++i){
            chmin(dp[w][i], dp[w][i - 1]);
            if(w - a[i - 1] >= 0){
                chmin(dp[w][i], dp[w - a[i - 1]][i - 1] + 1);
            }
        }
    }

    cout << right << setw(4) << "W\\N";
    for(i = 0;i < N + 1; ++i){
        cout << right << setw(4) << i;
    }
    cout << endl;
    for(w = 0;w < W + 1; ++w){
        cout << left << setw(4) << w; 
        for(i = 0;i < N + 1; ++i){
            cout << right << setw(4) << dp[w][i];
        }
        cout << endl;
    }
    // int cnt = 0;
    // for(w = 1; w < W+1; ++w){
    //     if(dp[w][N] == 1) cnt++;
    // }
    // cout << "NUM: " << cnt << endl;

    if(dp[W][N] <= k) cout << "ENABLE" << endl;
    else cout << "DISABLE" << endl;

    // cout << dp[N-1] << endl;
    return 0;
}