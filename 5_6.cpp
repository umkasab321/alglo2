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
    vector<int> m(N);
    vector<vector<int>> dp(W+1, vector<int>(N+1,100));
    int i = 0;
    for(i = 0; i < N; i++){
        a[i] = rnd() % 20;
        m[i] = rnd() % 5;
        cout << "a[" << i << "]: " << a[i] << ", " << "m[" << i << "]: " << m[i] << endl;
    }

    for(i = 0; i < N+1; ++i){
        dp[0][i] = 0;
    }

    // m[0] = 3;
    // m[1] = 4;
    // m[2] = 3;
    // m[3] = 3;
    // m[4] = 3;
    
    int w = 0;
    // int loop_cnt[5] = {0,0,0,0,0};
    vector<vector<vector<int>>> loop_cnt(W+1, vector<vector<int>>(N+1, vector<int>(5, 0)));
    for(i = 1;i < N + 1; ++i){
        for(w = 0; w < W+1; ++w){
            if(w + a[i-1] <= W && loop_cnt[w][i][i - 1] <= m[i - 1] - 1 ){
                if(i == 5)cout << "loop_cnt: " << loop_cnt[w][i][i-1] << ", w: " << w << ", a[i-1]: " << a[i -1] << endl;
                if(chmin(dp[w + a[i-1]][i], dp[w][i] + 1)) loop_cnt[w + a[i-1]][i][i-1] = loop_cnt[w][i][i-1] + 1;
            }
            if(i+1 <= N) chmin(dp[w][i+1], dp[w][i]);
        }
    }

    int width = 8;
    cout << right << setw(width) << "W\\N";
    for(i = 0;i < N + 1; ++i){
        if(i == 0) cout << right << setw(width-4) << i << "[" << right << setw(2) << "--" << "]";
        else cout << right << setw(width-4) << i << "[" << right << setw(2) << a[i - 1] << "]";
    }
    cout << endl;
    for(w = 0;w < W + 1; ++w){
        cout << left << setw(width) << w; 
        for(i = 0;i < N + 1; ++i){
            cout << right << setw(width) << dp[w][i];
        }
        cout << endl;
    }

    cout << right << setw(width) << "W\\N";
    for(i = 0;i < N + 1; ++i){
        if(i == 0) cout << right << setw(width-4) << i << "[" << right << setw(2) << "--" << "]";
        else cout << right << setw(width-4) << i << "[" << right << setw(2) << a[i - 1] << "]";
    }
    cout << endl;
    for(w = 0;w < W + 1; ++w){
        cout << left << setw(width) << w; 
        for(i = 0;i < N + 1; ++i){
            cout << right << setw(width-4) << loop_cnt[w][i][0] << loop_cnt[w][i][1] << loop_cnt[w][i][2] << loop_cnt[w][i][3] << loop_cnt[w][i][4];
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