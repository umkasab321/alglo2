#include<iostream>
#include<vector>
using namespace std;
struct UnionFind{
    vector<int> par, siz, diff_weight; //diff_weightは親からの相対的重み

    UnionFind(int n): par(n, -1) , siz(n,1) , diff_weight(n, 0) {}

    int root(int x){
        if (par[x] == -1) return x;
        else {
            int r = root(par[x]); //再起でrootを走らせてdiff_weighをrootからの絶対重みにする
            diff_weight[x] += diff_weight[par[x]]; //経路圧縮で親の親とつながる->親の親はroot担っているので、絶対重みと同じ

            return par[x] = root(par[x]); //親の親をrootに設定
        } 

    }

    int weight(int x){
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool unite(int x, int y, int w){ //x親
        w += weight(x); x = root(x); 
        w -= weight(y); y = root(y); 

        if(x == y )return false;

        if(siz[x] < siz[y]){
            swap(x, y);
            w= -w;
        } 

        par[y] = x;
        siz[x] += siz[y];
        diff_weight[y] = w;
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }

    int diff(int x, int y){
        return weight(y) - weight(x);
    }
};
int main(){
    std::cout << "helloooo" << std::endl;

    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    for(int i = 0; i < M; ++i){
        int  l, r, d;
        cin >> l >> r >> d;
        --l,--r;
        if(uf.issame(l,r)){
            int diff = uf.diff(l,r);
            if(diff != d){
                cout << "NO" << endl;
                return 0;
            }
        }else{
            uf.unite(l,r,d);
        }
    }
    cout << "YES" << endl;
    return 0;
}
