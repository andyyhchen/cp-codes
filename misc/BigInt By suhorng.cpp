
/*在實做大數的時候，我們有許多方法，最常見的是包成 struct 或 class 。

在寫一些時間限制比較嚴格的大數時，有兩點注意：

    1.一定要紀錄當前的位數：也就是少跑一些位數。

    2.int 要壓位數。純加減法可以壓到八、九位，乘法壓四位。

除此之外，實際實現時，可以純開陣列、包成 struct 或 class，

而且加減乘除也可以重載運算子。不過那都不在今天的討論範圍之內。

現在這篇要放的，是大數的參考程式碼，含最基本的加減乘除。*/

#include <cstring>
#include<iostream>
using namespace std;

#define li_size 10000                           /*大數陣列的大小*/
#define li_fill 10000                           /*壓四位數*/

#define li_max(a, b) ((a)>(b)?(a):(b))          /*自訂的 max, min 巨集*/
#define li_min(a, b) ((a)>(b)?(a):(b))

typedef struct {                                /*我習慣包成 struct*/
　　int length;                                 /*大數的位數*/
　　int digit[li_size];                         /*大數的陣列*/
} largeint;

const largeint li_unit = {1, {1}};              /*單位加法元素*/

void li_reset(largeint* lhs) {                  /*將大數歸零*/
　　lhs->length = 0;
　　memset(lhs->digit, 0, sizeof(lhs->digit));
}

void li_cpy(largeint* lhs, const largeint* rhs) {       /*複製大數*/
　　lhs->length = rhs->length;
　　memcpy(lhs->digit, rhs->digit, sizeof(lhs->digit));
}

void li_seti(largeint* lhs, const int value) {          /*從整數讀入大數*/
　　int i = 0, v = value;
　　li_reset(lhs);
　　while (v != 0) {
　　　　lhs->digit[i++] = v % li_fill;
　　　　v /= li_fill;
　　}
　　lhs->length = i;
}

void li_read(largeint* lhs, const char * str) {         /*從字串讀入大數*/
　　int i = strlen(str)-1, j, v, len = 0;
　　li_reset(lhs);
　　for (; i-3>=0; i-=4) {
　　　　v = 0;
　　　　for (j=0; j<4; j++)
　　　　　　v = v*10 + str[i-3+j] - '0';
　　　　lhs->digit[len++] = v;
　　}
　　if (i >= 0) {
　　　　v = 0;
　　　　for (j=0; j<=i; j++)
　　　　　　v = v*10 + str[j] - '0';
　　　　lhs->digit[len++] = v;
　　}
　　while (len>0 && !lhs->digit[len-1])
　　　　-- len;
　　lhs->length = len;
}

void li_write(char *str, int len, const largeint *rhs) {     /*將大數轉成字串*/
　　int i, p;
　　if (len == 0) return;
　　if (rhs->length == 0) {
　　　　str[0] = '0';
　　　　str[1] = 0;
　　　　return;
　　}
　　p = snprintf(str, len, "%d", rhs->digit[ rhs->length-1 ]);
　　for (i=rhs->length-2; len && i>=0; i--)
　　　　p += snprintf(str+p, len-p, "%04d", rhs->digit[i]);
}

int li_cmp(const largeint* lhs, const largeint* rhs) {          /*大數比較*/
　　int i, a, b, len1 = lhs->length, len2 = rhs->length;
　　if (len1 > len2) return 1;
　　else if (len1 < len2) return -1;
　　for (i=len1-1; i>=0; i--) {
　　　　a = lhs->digit[i];
　　　　b = rhs->digit[i];
　　　　if (a > b) return 1;
　　　　else if (a < b) return -1;
　　}
　　return 0;
}
/*
續上篇。這篇放的是加、減、乘等基本運算的寫法。

大數到底要怎麼寫？請回想小學學的直式加法、減法以及乘法。

手怎麼算，程式就怎麼寫，這是它的核心思想。

會寫了之後，再來碰優化。

此外，這裡的加 / 減法程式運用的是進 / 借位的概念，

對於加法， 'c' 是 carry，代表進位，

對於減法的 'c' 則是 borrow，為借位。
*/
int li_add(largeint* lhs, const largeint* rhs) {                /*大數加法*/
　　int i, c = 0, m = li_min(lhs->length, rhs->length);
　　for (i=0; i<li_size && (c || i<m); i++) {
　　　　lhs->digit[i] += rhs->digit[i] + c;
　　　　if (lhs->digit[i] >= li_fill) {
　　　　　　lhs->digit[i] -= li_fill;
　　　　　　c = 1;
　　　　} else c = 0;
　　}
　　lhs->length = li_max(lhs->length, i);
　　return c;
}

int li_sub(largeint* lhs, const largeint* rhs) {                /*大數減法*/
　　int i, c = 0, m = li_min(lhs->length, rhs->length);
　　for (i=0; i<li_size && (c || i<m); i++) {
　　　　lhs->digit[i] -= rhs->digit[i] + c;
　　　　if (lhs->digit[i] < 0) {
　　　　　　lhs->digit[i] += li_fill;
　　　　　　c = 1;
　　　　} else c = 0;
　　}
　　lhs->length = li_max(lhs->length, i);
　　while (lhs->length && !lhs->digit[lhs->length-1])
　　　　-- lhs->length;
　　return c;
}

/*乘法比較麻煩些。回想一下：

            1 2 3
_x__________4_5_6____
            7 3 8
          6 1 5
        4 9 2
_____________________
        5 6 0 8 8

仔細觀察，我們將乘數一位一位分開來處理，然後累加到商上面。

處理乘數的第一位時，被乘數的第一、二、…位累加到商的第一、二、…位，

處理乘數的第二位時，被乘數的第一、二、…位累加到商的第二、三、…位，

處理乘數的第三位時，被乘數的第一、二、…位累加到商的第三、四、…位。


不過注意此程式的位數從零開始，就如同資工系的自然數一樣。*/
                                                                /*大數乘法*/
int li_mul(largeint* rsl, const largeint* lhs, const largeint* rhs) {
　　int i, j, k, product, len = 0, overflow = 0;
　　li_reset(rsl);
　　for (i=0; i<lhs->length; i++) {
　　　　for (j=0; j<rhs->length; j++) {
　　　　　　product = lhs->digit[i] * rhs->digit[j];
　　　　　　for (k=i+j; k<li_size && product; k++) {
　　　　　　　　product += rsl->digit[k];
　　　　　　　　rsl->digit[k] = product % li_fill;
　　　　　　　　product /= li_fill;
　　　　　　}
　　　　　　if (k > len)
　　　　　　　　len = k;
　　　　　　if (k==li_size && product)
　　　　　　　　overflow = 1;
　　　　}
　　}
　　rsl->length = len;
　　return overflow;
}
/*
承上篇。此程式直接模擬手算直式除法，此處不再多加說明。
*/

const int li_pow[4] = {1, 10, 100, 1000};

void li_div(largeint* qtnt, largeint* rmdr,
                        const largeint *c_dnd, const largeint *dsr) {

　　int i, m, high, cmp; static largeint dnd, sbr;
　　cmp = li_cmp(c_dnd, dsr);
　　if (cmp < 0) {
　　　　li_cpy(rmdr, c_dnd);
　　　　li_reset(qtnt);
　　　　return;
　　} else if (cmp == 0) {
　　　　li_reset(rmdr);
　　　　li_cpy(qtnt, &li_unit);
　　　　return;
　　}
　　li_reset(qtnt);
　　li_reset(&sbr);
　　li_cpy(&dnd, c_dnd);
　　m = dnd.length - dsr->length + 1;
　　for (i=0; i+m<li_size && i<dsr->length; i++)
　　　　sbr.digit[i+m] = dsr->digit[i];
　　sbr.length = dsr->length + m;
　　high = m << 2;
　　qtnt->length = m + 1;
　　while (high >= 0) {
　　　　cmp = li_cmp(&sbr, &dnd);
　　　　if (cmp > 0) {
　　　　　　m = 0;
　　　　　　for (i=sbr.length-1; i>=0; i--) {
　　　　　　　　m = m*li_fill + sbr.digit[i];
　　　　　　　　sbr.digit[i] = m / 10;
　　　　　　　　m %= 10;
　　　　　　}
　　　　　　while (sbr.length && !sbr.digit[sbr.length-1])
　　　　　　　　-- sbr.length;
　　　　　　-- high;
　　　　} else {
　　　　　　li_sub(&dnd, &sbr);
　　　　　　qtnt->digit[high>>2] += li_pow[high&3];
　　　　}
　　}
　　while (qtnt->length && !qtnt->digit[qtnt->length-1])
　　　　-- qtnt->length;
　　li_cpy(rmdr, &dnd);
}
int main()
{
	return 0;
}







