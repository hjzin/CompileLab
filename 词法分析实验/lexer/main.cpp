#include <iostream>
#include "stdio.h"
#include "lexer.h"
using namespace std;
int main() {
    FILE *fp;
    int ch;
    if((fp =fopen("src.txt","r") )== NULL)
    {
        printf("打开文件失败\n");
        exit(-1);
    } else {
        freopen("output.txt", "w", stdout);
        ch = fgetc(fp);
        while (1)
        {
            if(ch == -1)
                break;
            scanner(fp,ch);
            ch = fgetc(fp);
        }
        fclose(fp);
        fclose(stdout);
    }
    return 0;
}