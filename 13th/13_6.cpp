#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;
vector<bool> seen;
vector<int> cycle; // トポロジカルソート順を表す
bool rec(const Graph &G, int v, int cycle_org) {
    seen[v] = true;
    for (auto prev_v : G[v]) {
        cycle.push_back(prev_v); // すでに訪問済みなら探索しない
        if (prev_v == cycle_org) {
            return true;
        }
        //cout << "--" << prev_v;
        if(rec(G, prev_v, cycle_org)){
            return true;
        }
    }
    cycle.pop_back();
    return false;
}
int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取
    Graph G(N);
    seen.assign(N, false); // 初期状態では全頂点が未訪問
    vector<int> deg(N, 0); // 各頂点の出次数
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a); // 逆向きに辺を張る
        deg[a]++; // 出次数
    }

    // シンクたちをキューに挿入する
    queue<int> que;
    for (int i = 0; i < N; ++i) if (deg[i] == 0) que.push(i);

    // 探索開始
    vector<int> order;
    while (!que.empty()) {
        // キューから頂点を取り出す
        int v = que.front(); que.pop();
        order.push_back(v);

        // v へと伸びている頂点たちを探索する
        for (auto nv : G[v]) {
            // 辺 (nv, v) を削除する
            --deg[nv];

            // それによって nv が新たにシンクになったらキューに挿入
            if (deg[nv] == 0) que.push(nv); 
        }
    }
    
    
    // 答えをひっくり返す
    reverse(order.begin(), order.end());
    for (auto v : order) cout << v << endl;
    
    int cycle_org = -1;
    for (int i = 0; i < N; ++i) if (deg[i] != 0) cycle_org = i;
   // cout << cycle_org << endl;
    if(cycle_org != -1){
        rec(G, cycle_org, cycle_org);
        for (auto v : cycle) cout << v << " <- ";
        cout << endl;
    }
/*    if(cycle_org == -1) return 0;
    cout << cycle_org << endl;
    return 0;
    
    int cpoint = cycle_org;
    vector<int> cycle;
    cycle.push_back(cpoint);
    do{
        for (auto nv : G[cpoint]) {
            if (deg[nv] != 0){
                cpoint = nv;
                cycle.push_back(cpoint);
            }
        }
    } while(cycle_org != cpoint);
*/

}