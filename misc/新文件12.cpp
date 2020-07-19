
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[1001];
    FILE *file;
    while(gets(str))  /* 讀入四則運算式 */
    {
        file = fopen("C:\123.c", "w");  /* 開啟一原始碼檔案 */
        fprintf(file, "#include <stdio.h>\n\n");  /* 寫入程式碼 */
        fprintf(file, "int main() {\n");       /* 使其輸出該四則運算式 */
        //fprintf(file, "    printf(\"%%d\", %s);\n", str);  /* 的答案 */
        fprintf(file, "printf(\"hello\");");
        fprintf(file, "}\n");
        fclose(file);
        system("gcc -o C:\123.exe C:\123.c");  /* 編譯它 */
        system("C:\123.exe");  /* 執行它 */
        printf("\n");
    }
    return 0;
}
