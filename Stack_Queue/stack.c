#include <stdio.h>

#define N 10 // スタックの大きさをNとする

typedef int data_t; // intと同じ型を持つ型名data_tを作成

data_t stack[N]; // スタックに使う配列を宣言(intグローバル変数)
int size; // 配列のindex スタックの要素数を保持する

// スタックの大きさを初期化
void init(void) {
    size = 0;
}

// size 変数の値が N 以上のとき，それ以上データを追加できない
// 「stack overflow」と出力し return で処理を終了
void push(data_t x) {
    if (size >= N) {
        printf("stack overflow\n");
        return;
    }
    stack[size] = x;
    size++;
}

// size 変数の値が 0 以下のとき，それ以上データを取り出せない
// 「stack underflow」と出力して return で処理を終了
void pop(data_t *x) {
    if (size <= 0) {
        printf("stack underflow\n");
        return;
    }
    *x = stack[size - 1];
    size--;
}

int main(void) {
    // スタックの初期化
    init();
    
    // スタックに値を追加
    push(10);
    push(20);

    // スタックから値を取り出す
    int x;
    pop(&x);
    printf("%d\n", x);
    pop(&x);
    printf("%d\n", x);
}