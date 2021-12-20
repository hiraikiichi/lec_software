#include<stdio.h>

// N:ノード数
#define N 6

// 無向グラフの行列表現
int a[N][N] = {
    {0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0}};

// ノードが探索済みかどうか識別するための配列
int val[N] = {0, 0, 0, 0, 0, 0};

// start:探索を開始するノード番号(0-5)ノード2から探索を開始
// id:探索済みのノード数を格納する変数
int start = 2;
int id = 0;
int route[N];

// バックトラック法による探索サブプログラム
void visit(int k){
    int i, t;

    // route[]:探索経路をノード番号で示す変数
    // k:現在ノード位置
    route[id] = k;
    val[k] = ++id;

    // ノードを6個探索済みで，かつ，現在ノード位置から探索開始位置にグラフが繋がっているならば
    // この状態に至る経路が階の1つになる．経路情報を出力する
    if((id == 6) && (a[k][start] == 1)){
        printf("route=");
        for (i = 0; i < N; i++){
            printf("%3d", route[i]);
        }
        printf("\n");
    }

    // 探索が途中状態にあるならば，現在ノードから次にたどり着けるノードを全て見つけ
    // 条件に合致するノード探索を行うため，再帰的に探索プログラムを呼び出す
    for (t = 0; t < N; t++){
        if(a[k][t]){
            if(val[t] == 0){
                visit(t);
            }
        }
    }

    // 探索条件を満足するノードがない場合は
    // 1つ前のノードにバックし，このノードから先のノードの探索を中止する
    route[id] = 0;
    id--;
    val[k] = 0;
}

int main(void){
    int i;

    // 経路情報をセットする
    route[id] = start;

    // startノードから探索を行うため，探索のサブプログラムを呼び出す
    visit(start);

    return 0;
}