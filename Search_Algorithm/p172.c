#include <stdio.h>
int pos (char text[], char pattern[])
{
    int i, j;
    /*
    i:テキスト文字列中の探索位置，初期値0
    j:照合文字列中の探索位置，初期値0
    */
    i = j = 0;

    // テキスト文字列の最後または，照合文字列の最後になるまで探索を続ける
    while (text[i] != '\0' && pattern[j] != '\0'){

        // テキスト文字列のi文字目と照合文字列のj文字目が一致したら次の文字を比較する
        if (text[i] == pattern[j]){
            i++;
            j++;
        
        // 照合中に一致しない文字があったら，テキスト文字列の位置を探索前の位置に戻し，その次の位置に移動する
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
   // 見つかった場合，テキスト文字列中の照合文字列の先頭位置を返す
    if(pattern[j] == '\0'){
        return i - j;
    }

    // 見つからなかった
    return -1;
}
int main(void){
    int i;

    // テキスト文字列の設定
    char text[] = "AIUEO",
         // 照合文字列の設定
         pattern[] = "GK";
    printf("position(\"%s\", \"%s\") = %d\n", text, pattern, pos(text, pattern));

    return 0;
}