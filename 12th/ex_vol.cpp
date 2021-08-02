#include<iostream>
#include<vector>
#include<random>
using namespace std;

void Heapify(vector<int> &a, int i, int N) {
    int child1 = i * 2 + 1; // 左の子供
    if (child1 >= N) return; // 子供がないときは終了

    // 子供同士を比較
    if (child1 + 1 < N && a[child1 + 1] > a[child1]) ++child1;
    
    if (a[child1] <= a[i]) return; // 逆転がなかったら終了

    // swap
    swap(a[i], a[child1]);

    // 再帰的に
    Heapify(a, child1, N);
}

// 配列 a をソートする
void HeapSort(vector<int> &a) {
    int N = (int)a.size();

    // ステップ 1: a 全体をヒープにするフェーズ
    for (int i = N / 2 - 1; i >= 0; --i) {
        Heapify(a, i, N);
    }

    // // ステップ 2: ヒープから 1 個 1 個最大値を pop するフェーズ
    // for (int i = N - 1; i > 0; --i) {
    //     swap(a[0], a[i]); // ヒープの最大値を左詰め
    //     Heapify(a, 0, i); // ヒープサイズは i に
    // }
}
struct Heap {
    vector<int> heap;
    Heap() {}

    // ヒープに値 x を挿入
    void push(int x) {
        heap.push_back(x); // 最後尾に挿入
        int i = (int)heap.size() - 1; // 挿入された頂点番号
        while (i > 0) {
            int p = (i - 1) / 2; // 親の頂点番号
            if (heap[p] >= x) break; // 逆転がなければ終了
            heap[i] = heap[p]; // 自分の値を親の値にする
            i = p; // 自分は上に行く
        }
        heap[i] = x; // x は最終的にはこの位置にもってくる
    }

    // 最大値を知る
    int top() {
        if (!heap.empty()) return heap[0];
        else return -1;
    }

    // 最大値を削除
    void pop() {
        if (heap.empty()) return;
        int x = heap.back(); // 頂点にもってくる値
        heap.pop_back();
        int i = 0; // 根から降ろしていく
        while (i * 2 + 1 < (int)heap.size()) {
            // 子頂点同士を比較して大きい方を child1 とする
            int child1 = i * 2 + 1, child2 = i * 2 + 2;
            if (child2 < (int)heap.size()
                && heap[child2] > heap[child1]) {
                child1 = child2;
            }
            if (heap[child1] <= x) break; // 逆転がなければ終了
            heap[i] = heap[child1]; // 自分の値を子頂点の値にする
            i = child1; // 自分は下に行く
        }
        heap[i] = x; // x は最終的にはこの位置にもってくる
    }
};

int main(){
    std::random_device rnd;
    std::cout << "12:SORT 12.3" << std::endl;

    std::vector<int> input;
    std::vector<int> a;
    Heap h;

    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; ++i){
        input.push_back(rnd() % 100);
    }
    for(int i = 0; i < N; ++i){
        cout << input[i] << ", ";
    }
    std::cout  << std::endl;
    cout << "-----------" << endl;
    for(int i = 0; i < K - 1; ++i){
        h.push(input[i]);
    }
    cout << "-----------" << endl;
    for(int i = K - 1; i < N; ++i){
        h.push(input[i]);
        for(int j = 0; j < (int)h.heap.size();j++){
            cout << h.heap[j] << ", ";
        }
        cout << " ===> ";
        cout << h.top() << endl;
        h.pop();
    }
    return 0;
}