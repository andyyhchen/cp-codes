
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[1001];
    FILE *file;
    while(gets(str))  /* Ū�J�|�h�B�⦡ */
    {
        file = fopen("C:\123.c", "w");  /* �}�Ҥ@��l�X�ɮ� */
        fprintf(file, "#include <stdio.h>\n\n");  /* �g�J�{���X */
        fprintf(file, "int main() {\n");       /* �Ϩ��X�ӥ|�h�B�⦡ */
        //fprintf(file, "    printf(\"%%d\", %s);\n", str);  /* ������ */
        fprintf(file, "printf(\"hello\");");
        fprintf(file, "}\n");
        fclose(file);
        system("gcc -o C:\123.exe C:\123.c");  /* �sĶ�� */
        system("C:\123.exe");  /* ���楦 */
        printf("\n");
    }
    return 0;
}
