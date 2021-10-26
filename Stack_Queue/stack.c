#include <stdio.h>

/* 管理するデータの上限個数 */
#define MAX_NUM 10

/* スタック構造体 */
typedef struct STACK {
    /* データの最後尾 */
    int tail;
    /* スタックされているデータ */
    int data[MAX_NUM];
} STACK_T;

void initSack(STACK_T*);
void printSack(STACK_T*);
void push(STACK_T*, int);
int pop(STACK_T*);

/* スタックを初期化する関数 */
void initStack(STACK_T *stack){

    /* スタックを空に設定 */
    stack->tail = -1;
}

/* PUSHする関数 */
void push(STACK_T *stack, int input){

    /* スタックが満杯なら何もせず関数終了 */
    if(stack->tail >= MAX_NUM - 1){
        printf("スタックが満杯でPUSHできません\n");
        return;
    }

    /* データをデータの最後尾の１つ後ろに格納 */
    stack->data[stack->tail + 1] = input;

    /* データの最後尾を１つ後ろに移動 */
    stack->tail = stack->tail + 1;
}

/* POPする関数 */
int pop(STACK_T *stack){
    int ret = 0;

    /* スタックが空なら何もせずに関数終了 */
    if(stack->tail == -1){
        printf("スタックが空です\n");
        return -1;
    }

    /* データの最後尾からデータを取得 */
    ret = stack->data[stack->tail];

    /* データの最後尾を１つ前にずらす */
    stack->tail = stack->tail - 1;

    /* 取得したデータを返却 */
    return ret;
}

/* スタックの中身を表示 */
void printStack(STACK_T *stack){
    int i = 0;

    printf("左側がスタックの上側を表しています\n");
    for(i = 0; i <= stack->tail; i++){
        printf("%d,", stack->data[stack->tail - i]);
    }
    printf("\n");
}

int main(void){

    int m;
    int input;
    int output;
    STACK_T stack;

    /* スタックを初期化 */
    initStack(&stack);

    while(1){
        /* ユーザからメニューを選んでもらう */
        printf("メニュー\n 1:PUSH\n 2:POP\n 3:スタック表示\n それ以外の数字:終了\n");
        scanf("%d", &m);

        /* 選ばれたメニューに応じて処理を分岐 */
        if(m == 1){
            printf("PUSHする数は？（正の整数のみ化）");
            scanf("%d", &input);
            if (input < 0) {
                printf("負の値は受け付けていません!\n");
                continue;
            }
            printf("%dをPUSHします\n", input);
            push(&stack, input);
        }else if(m == 2){
            printf("POPします\n");
            output = pop(&stack);
            if(output != -1){
                printf("%dをPOPしました\n", output);
            }
        } else if(m == 3){
            printf("スタックの中身を表示します\n");
            printStack(&stack);
        } else {
            /* 1, 2, 3以外の場合はwhile文を抜け出すためにbreakを実行 */
            printf("終了します\n");
            break;
        }
    }
    return 0;
}