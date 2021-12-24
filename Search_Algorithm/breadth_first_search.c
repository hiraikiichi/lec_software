# include<stdio.h>

// ノード数
int n = 7;

//探索済みか否かをチェックするテーブル
int visited[7];

// 無向グラフ隣接行列の定義
int adj[7][7] = {{0, 1, 1, 0, 0, 0, 0},
                 {1, 0, 1, 0, 1, 0, 0},
                 {1, 1, 0, 1, 1, 1, 0},
                 {0, 0, 1, 0, 0, 0, 0},
                 {0, 1, 1, 0, 0, 1, 0},
                 {0, 0, 1, 0, 1, 0, 1},
                 {0, 0, 0, 0, 0, 1, 0}};

// 待ち行列初期設定
int queue[7], q_front = 0, q_end = 0;

// 待ち行列登録テーブル：待ち行列に登録されているノードをチェックするテーブル
int in_que[7];

// ノードを待ち行列へ追加するサブルーチン
void add_que(int k){
    queue[q_end++] = k;
    printf("add_que%d q_front=%d q_end=%d \n", k, q_front, q_end);
    in_que[k] = 1;
}

// 待ち行列からデータを取り出すサブルーチン
int out_que(){
    // 待ち行列から取り出したノードの番号と，待ち行列の状態を表示
    printf("out_que%d q_front=%d q_end=%d \n", queue[q_front], q_front, q_end);
    return queue[q_front++];
}

// 待ち行列にデータが存在するかを確認するサブルーチン
int emptyque(){
    // 待ち行列にデータが存在しないとき
    return (q_end == q_front);
}

// 広がり優先探索のサブルーチン
void visit(i){
    int j, new_node;

    // ノードiが未探索の場合
    if (!visited[i]){
        // 待ち行列にそのノードを登録する
        add_que(i);

        // 待ち行列に未探索のノードが存在する間，次の処理をおこなう
        while(!emptyque()){
            // 待ち行列から未探索のノードを取り出す
            new_node = out_que();

            // 取り出した未探索ノードを探索済みに変更
            visited[new_node] = 1;

            // 探索を開始するノード番号を表示
            printf("new_node=%d \n", new_node);

            // このノードから辺1つ隔てて，到達可能な未探索ノードを待ち行列に登録する
            for (j = 0; j < n; j++){
                if (adj[new_node][j] &&! visited[j] &&! in_que[j]){
                    add_que(j);
                }
            }
        }
    }
}

// メインプログラム
main(){
    int i, j;

    // 探索テーブルの初期化，待ち行列の初期化
    for (i = 0; i < n; i++){
        visited[i] = 0;
        queue[i] = -1;
        in_que[i] = 0;
    }

    // ノード番号0番から順に探索を実行
    for (i = 0; i < n; i++){
        // i番目のノードが未探索の場合，探索を実施し結果を出力 再帰式で定義
        printf("start search Node No=%d\n", i);
        visit(i);
    }

    // ノード探索順序の表示
    for (i = 0; i < n; i++){
        printf("%d", queue[i]);
    }
}