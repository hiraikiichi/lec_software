# include<stdio.h>
# include<string.h>
int pos(char text[], char pattern[]){
    int i, j, k, len;
    int skip[256];
    char c, tail;

    // 文字列の長さ
    len = strlen((char*)pattern);

    // 最後の文字
    tail = pattern[len - 1];

    // 長さ1の場合
    if (len == 1){
        for (i = 0; text[i] != '\0'; i++){
            if (text[i] == tail){
                return i;
            }
        }
    }
    // 長さ2以上の場合
    else{
        // 表を作成
        for (i = 0; i <= 255; i++){
            skip[i] = len;
        }
        for (i = 0; i < len - 1; i++){
            skip[pattern[i]] = len - 1 - i;
        }
        // i = len - 1;
        // 照合開始
        while((c = text[i]) != '\0'){
            // 探索状態の表示
            printf("テキスト文字列:%s\n", text);
            printf("照合文字列:%*s\n", i + 1, pattern);

            // 照合文字列の最後尾文字とテキスト文字列が等しい場合
            if (c == tail){
                j = len - 1;
                k = i;

                // 文字が一致する場合，1文字前の文字を比較
                while(pattern[--j] == text[--k]){
                    // 照合文字列の先頭まで達した場合，照合文字列がテキスト中に存在する
                    if (j == 0)return k;
                }
            }
            // 等しくない場合，照合文字列の上の文字を取り出し，おsの文字をリストで引きずらす
            i += skip[c];
        }
    }
    // 照合文字列がテキスト文字列中にない場合，-1を返す
    return -1;
}

void main(){
    int p;
    char text[] = "MOJIRETUTANS\0";
    char pattern[] = "ETU\0";
    p = pos(text, pattern);
    if (p >= 0){
        printf("位置=%d\n", p);
    }else{
        printf("見つかりません．\n\n");
    }
}