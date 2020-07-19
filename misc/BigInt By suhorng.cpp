
/*�b�갵�j�ƪ��ɭԡA�ڭ̦��\�h��k�A�̱`�����O�]�� struct �� class �C

�b�g�@�Ǯɶ��������Y�檺�j�ƮɡA�����I�`�N�G

    1.�@�w�n������e����ơG�]�N�O�ֶ]�@�Ǧ�ơC

    2.int �n����ơC�¥[��k�i�H����K�B�E��A���k���|��C

�������~�A��ڹ�{�ɡA�i�H�¶}�}�C�B�]�� struct �� class�A

�ӥB�[����]�i�H�����B��l�C���L�������b���Ѫ��Q�׽d�򤧤��C

�{�b�o�g�n�񪺡A�O�j�ƪ��Ѧҵ{���X�A�t�̰򥻪��[����C*/

#include <cstring>
#include<iostream>
using namespace std;

#define li_size 10000                           /*�j�ư}�C���j�p*/
#define li_fill 10000                           /*���|���*/

#define li_max(a, b) ((a)>(b)?(a):(b))          /*�ۭq�� max, min ����*/
#define li_min(a, b) ((a)>(b)?(a):(b))

typedef struct {                                /*�ڲߺD�]�� struct*/
�@�@int length;                                 /*�j�ƪ����*/
�@�@int digit[li_size];                         /*�j�ƪ��}�C*/
} largeint;

const largeint li_unit = {1, {1}};              /*���[�k����*/

void li_reset(largeint* lhs) {                  /*�N�j���k�s*/
�@�@lhs->length = 0;
�@�@memset(lhs->digit, 0, sizeof(lhs->digit));
}

void li_cpy(largeint* lhs, const largeint* rhs) {       /*�ƻs�j��*/
�@�@lhs->length = rhs->length;
�@�@memcpy(lhs->digit, rhs->digit, sizeof(lhs->digit));
}

void li_seti(largeint* lhs, const int value) {          /*�q���Ū�J�j��*/
�@�@int i = 0, v = value;
�@�@li_reset(lhs);
�@�@while (v != 0) {
�@�@�@�@lhs->digit[i++] = v % li_fill;
�@�@�@�@v /= li_fill;
�@�@}
�@�@lhs->length = i;
}

void li_read(largeint* lhs, const char * str) {         /*�q�r��Ū�J�j��*/
�@�@int i = strlen(str)-1, j, v, len = 0;
�@�@li_reset(lhs);
�@�@for (; i-3>=0; i-=4) {
�@�@�@�@v = 0;
�@�@�@�@for (j=0; j<4; j++)
�@�@�@�@�@�@v = v*10 + str[i-3+j] - '0';
�@�@�@�@lhs->digit[len++] = v;
�@�@}
�@�@if (i >= 0) {
�@�@�@�@v = 0;
�@�@�@�@for (j=0; j<=i; j++)
�@�@�@�@�@�@v = v*10 + str[j] - '0';
�@�@�@�@lhs->digit[len++] = v;
�@�@}
�@�@while (len>0 && !lhs->digit[len-1])
�@�@�@�@-- len;
�@�@lhs->length = len;
}

void li_write(char *str, int len, const largeint *rhs) {     /*�N�j���ন�r��*/
�@�@int i, p;
�@�@if (len == 0) return;
�@�@if (rhs->length == 0) {
�@�@�@�@str[0] = '0';
�@�@�@�@str[1] = 0;
�@�@�@�@return;
�@�@}
�@�@p = snprintf(str, len, "%d", rhs->digit[ rhs->length-1 ]);
�@�@for (i=rhs->length-2; len && i>=0; i--)
�@�@�@�@p += snprintf(str+p, len-p, "%04d", rhs->digit[i]);
}

int li_cmp(const largeint* lhs, const largeint* rhs) {          /*�j�Ƥ��*/
�@�@int i, a, b, len1 = lhs->length, len2 = rhs->length;
�@�@if (len1 > len2) return 1;
�@�@else if (len1 < len2) return -1;
�@�@for (i=len1-1; i>=0; i--) {
�@�@�@�@a = lhs->digit[i];
�@�@�@�@b = rhs->digit[i];
�@�@�@�@if (a > b) return 1;
�@�@�@�@else if (a < b) return -1;
�@�@}
�@�@return 0;
}
/*
��W�g�C�o�g�񪺬O�[�B��B�����򥻹B�⪺�g�k�C

�j�ƨ쩳�n���g�H�Ц^�Q�p�ǾǪ������[�k�B��k�H�έ��k�C

�����A�{���N���g�A�o�O�����֤߫�Q�C

�|�g�F����A�A�ӸI�u�ơC

���~�A�o�̪��[ / ��k�{���B�Ϊ��O�i / �ɦ쪺�����A

���[�k�A 'c' �O carry�A�N��i��A

����k�� 'c' �h�O borrow�A���ɦ�C
*/
int li_add(largeint* lhs, const largeint* rhs) {                /*�j�ƥ[�k*/
�@�@int i, c = 0, m = li_min(lhs->length, rhs->length);
�@�@for (i=0; i<li_size && (c || i<m); i++) {
�@�@�@�@lhs->digit[i] += rhs->digit[i] + c;
�@�@�@�@if (lhs->digit[i] >= li_fill) {
�@�@�@�@�@�@lhs->digit[i] -= li_fill;
�@�@�@�@�@�@c = 1;
�@�@�@�@} else c = 0;
�@�@}
�@�@lhs->length = li_max(lhs->length, i);
�@�@return c;
}

int li_sub(largeint* lhs, const largeint* rhs) {                /*�j�ƴ�k*/
�@�@int i, c = 0, m = li_min(lhs->length, rhs->length);
�@�@for (i=0; i<li_size && (c || i<m); i++) {
�@�@�@�@lhs->digit[i] -= rhs->digit[i] + c;
�@�@�@�@if (lhs->digit[i] < 0) {
�@�@�@�@�@�@lhs->digit[i] += li_fill;
�@�@�@�@�@�@c = 1;
�@�@�@�@} else c = 0;
�@�@}
�@�@lhs->length = li_max(lhs->length, i);
�@�@while (lhs->length && !lhs->digit[lhs->length-1])
�@�@�@�@-- lhs->length;
�@�@return c;
}

/*���k����·ШǡC�^�Q�@�U�G

            1 2 3
_x__________4_5_6____
            7 3 8
          6 1 5
        4 9 2
_____________________
        5 6 0 8 8

�J���[��A�ڭ̱N���Ƥ@��@����}�ӳB�z�A�M��֥[��ӤW���C

�B�z���ƪ��Ĥ@��ɡA�Q���ƪ��Ĥ@�B�G�B�K��֥[��Ӫ��Ĥ@�B�G�B�K��A

�B�z���ƪ��ĤG��ɡA�Q���ƪ��Ĥ@�B�G�B�K��֥[��Ӫ��ĤG�B�T�B�K��A

�B�z���ƪ��ĤT��ɡA�Q���ƪ��Ĥ@�B�G�B�K��֥[��Ӫ��ĤT�B�|�B�K��C


���L�`�N���{������Ʊq�s�}�l�A�N�p�P��u�t���۵M�Ƥ@�ˡC*/
                                                                /*�j�ƭ��k*/
int li_mul(largeint* rsl, const largeint* lhs, const largeint* rhs) {
�@�@int i, j, k, product, len = 0, overflow = 0;
�@�@li_reset(rsl);
�@�@for (i=0; i<lhs->length; i++) {
�@�@�@�@for (j=0; j<rhs->length; j++) {
�@�@�@�@�@�@product = lhs->digit[i] * rhs->digit[j];
�@�@�@�@�@�@for (k=i+j; k<li_size && product; k++) {
�@�@�@�@�@�@�@�@product += rsl->digit[k];
�@�@�@�@�@�@�@�@rsl->digit[k] = product % li_fill;
�@�@�@�@�@�@�@�@product /= li_fill;
�@�@�@�@�@�@}
�@�@�@�@�@�@if (k > len)
�@�@�@�@�@�@�@�@len = k;
�@�@�@�@�@�@if (k==li_size && product)
�@�@�@�@�@�@�@�@overflow = 1;
�@�@�@�@}
�@�@}
�@�@rsl->length = len;
�@�@return overflow;
}
/*
�ӤW�g�C���{������������⪽�����k�A���B���A�h�[�����C
*/

const int li_pow[4] = {1, 10, 100, 1000};

void li_div(largeint* qtnt, largeint* rmdr,
                        const largeint *c_dnd, const largeint *dsr) {

�@�@int i, m, high, cmp; static largeint dnd, sbr;
�@�@cmp = li_cmp(c_dnd, dsr);
�@�@if (cmp < 0) {
�@�@�@�@li_cpy(rmdr, c_dnd);
�@�@�@�@li_reset(qtnt);
�@�@�@�@return;
�@�@} else if (cmp == 0) {
�@�@�@�@li_reset(rmdr);
�@�@�@�@li_cpy(qtnt, &li_unit);
�@�@�@�@return;
�@�@}
�@�@li_reset(qtnt);
�@�@li_reset(&sbr);
�@�@li_cpy(&dnd, c_dnd);
�@�@m = dnd.length - dsr->length + 1;
�@�@for (i=0; i+m<li_size && i<dsr->length; i++)
�@�@�@�@sbr.digit[i+m] = dsr->digit[i];
�@�@sbr.length = dsr->length + m;
�@�@high = m << 2;
�@�@qtnt->length = m + 1;
�@�@while (high >= 0) {
�@�@�@�@cmp = li_cmp(&sbr, &dnd);
�@�@�@�@if (cmp > 0) {
�@�@�@�@�@�@m = 0;
�@�@�@�@�@�@for (i=sbr.length-1; i>=0; i--) {
�@�@�@�@�@�@�@�@m = m*li_fill + sbr.digit[i];
�@�@�@�@�@�@�@�@sbr.digit[i] = m / 10;
�@�@�@�@�@�@�@�@m %= 10;
�@�@�@�@�@�@}
�@�@�@�@�@�@while (sbr.length && !sbr.digit[sbr.length-1])
�@�@�@�@�@�@�@�@-- sbr.length;
�@�@�@�@�@�@-- high;
�@�@�@�@} else {
�@�@�@�@�@�@li_sub(&dnd, &sbr);
�@�@�@�@�@�@qtnt->digit[high>>2] += li_pow[high&3];
�@�@�@�@}
�@�@}
�@�@while (qtnt->length && !qtnt->digit[qtnt->length-1])
�@�@�@�@-- qtnt->length;
�@�@li_cpy(rmdr, &dnd);
}
int main()
{
	return 0;
}







