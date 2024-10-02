#include <stdio.h>

int main() {
    char startChar = 'a';
    int totalLines = 2;
    int charsPerLine = 13;
    int i, j;

    for (i = 0; i < totalLines; i++) {
        for (j = 0; j < charsPerLine; j++) {
            printf("%c", startChar + i * charsPerLine + j);
        }
        printf("\n");
    }

    return 0;
}
/*
main:
    pushq   %rbp                        # ����ɵĻ�ַָ��
    movq    %rsp, %rbp                   # �����µĻ�ַָ��
    movb    $97, -1(%rbp)                # startChar = 'a' (ASCII 97)
    movl    $2, -4(%rbp)                 # totalLines = 2
    movl    $13, -8(%rbp)                # charsPerLine = 13
    movl    $0, -12(%rbp)                # i = 0

.L2:
    cmpl    -4(%rbp), -12(%rbp)           # �Ƚ� i �� totalLines
    jge     .L4                           # ��� i >= totalLines����ת�� END
    movl    $0, -16(%rbp)                 # j = 0

.L5:
    cmpl    -8(%rbp), -16(%rbp)           # �Ƚ� j �� charsPerLine
    jge     .L3                           # ��� j >= charsPerLine����ת�� PRINT_NEWLINE
    movzbl  -1(%rbp), %eax                # ���� startChar �� %eax
    movl    -12(%rbp), %edx                # ���� i �� %edx
    imull   $13, %edx, %eax                # ���� i * charsPerLine
    addl    -16(%rbp), %eax                 # ���� j
    addb    $0, %al                        # ȷ��Ϊ�ַ�
    movzbl  %al, %edi                      # ���ַ����ݸ� printf
    movl    $0, %esi                        # �޸�ʽ����
    call    printf                          # ���� printf ����
    addl    $1, -16(%rbp)                   # j++
    jmp     .L5                             # �����ڲ�ѭ��

.L3:
    movl    $10, %edi                       # '\n' �ַ�
    movl    $0, %esi                        # �޸�ʽ����
    call    printf                           # ���� printf �������
    addl    $1, -12(%rbp)                    # i++
    jmp     .L2                              # �������ѭ��

.L4:
    movl    $0, %eax                         # ����ֵ 0
    popq    %rbp                             # �ָ��ɵĻ�ַָ��
    ret                                       # ����
*/