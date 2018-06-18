//
// Created by 胡兆杰 on 2018/4/12.
//
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "lexer.h"
char token[30];
char reserved[13][13]={
        "begin", "end", "if", "then", "else", "for", "do", "while", "and", "or", "not","break", "to"
};

/* 查保留字表 */
int lookup(char s[])
{
    for (int i = 0; i < 13; ++i) {
        if(strcmp(reserved[i],s) == 0)
            return i; //如果成功匹配则返回编码
    }
    return -1;//查找不成功
}

/* 将大写字母转换成小写 */
void convert_to_lower(char s[30])
{
    for (int i = 0; i < 30; ++i) {
        if(isupper(s[i]))
            s[i] = static_cast<char>(s[i] + 32);
    }
}
/* 输出单词 */
void out(int id, char s[])
{
    printf("编码\t   字符\t\n");
    printf("%d\t   %s\t\n",id,s);
    printf("**********************\n");
    printf("\n");
}

/* 报告错误 */
void report_error()
{
    printf("该字符无法被识别！\n");
}

/* 词法分析 */
void scanner(FILE *fp,int ch)
{
    //int ch;
    int step = 1;
    int count = 1, c;
    /* 每次扫描述将token数组置空 */
    for (int i = 0; i< 30; i++){
        token[i] = '\0';
    }
    //ch = fgetc(fp);
    token[0] = (char)ch;
    if(isalpha(ch))//如果是字母
    {
        ch = fgetc(fp);
        while (isalnum(ch))
        {
            token[count++] = (char)ch;
            ch = fgetc(fp);
        }
        token[count] = '\0';
        if(ch != -1)
            fseek(fp,-1,1);//如果不是，则将指针回退一个
        //查保留字表
        convert_to_lower(token);
        c = lookup(token);
        if(c == -1)
        {
            //如果没有查到则将该标识符输出
            printf("*******标识符**********\n");
            out(ID,token);
        } else{
            printf("*******保留字**********\n");
            out(c,reserved[c]); //输出保留字
        }
    } else if(isdigit(ch))
        {
            ch = fgetc(fp);
            while (isdigit(ch))
            {
                token[count++] = (char)ch;
                ch = fgetc(fp);
            }
            token[count] = '\0';
            ch = fgetc(fp);
            if(ch != -1)
                fseek(fp,-2,1);
            printf("*******整数**********\n");
            out(INT,token);
        } else{
        switch (ch)
        {
            case '<':
                ch = fgetc(fp);
                if(ch == '=')
                {
                    token[1] = (char)ch;
                    printf("*******<=**********\n");
                    out(LE,token);
                }
                else if (ch == '>')
                {
                    token[1] = (char)ch;
                    printf("*******<>**********\n");
                    out(NE,token);
                }
                else
                {
                    fseek(fp, -1, 1);
                    printf("*******<**********\n");
                    out(LT, token);
                }
                break;
            case '=':
                ch = fgetc(fp);
                if(ch == '=')
                {
                    token[1] = (char)ch;
                    printf("*******==**********\n");
                    out(EE,token);
                } else{
                    fseek(fp,-1,1);
                    printf("*******=**********\n");
                    out(EQ,token);
                }
                break;
            case '>':
                ch = fgetc(fp);
                if(ch == '=')
                {
                    token[1] = (char)ch;
                    printf("*******>=**********\n");
                    out(GE,token);
                } else{
                    fseek(fp,-1,1);
                    printf("*******>**************\n");
                    out(GT,token);
                }
                break;
            case '+':
                printf("***********+**********\n");
                out(ADD,token);
                break;
            case '-':
                printf("*******-**********\n");
                out(SUB,token);
                break;
            case '*':
                printf("--------*---------\n");
                out(STAR,token);
                break;
            case ':':
                ch = fgetc(fp);
                if(ch == '=')
                {
                    token[1] = (char)ch;
                    printf("**********:=**********\n");
                    out(CE,token);
                } else{
                    ch = fgetc(fp);
                    if(ch != -1)
                        fseek(fp,-1,1);
                    out(COLON, token);
                }
                break;
            case '(':
                printf("*******(**************\n");
                out(LBRACKET,token);
                ch = fgetc(fp);
                while (ch != ')')
                {
                    ch = fgetc(fp);
                    step++;
                    if(ch == EOF)
                    {
                        printf("无法找到匹配的括号\n");
                        exit(-2);
                    }
                }
                fseek(fp,-step,1);
                break;
            case ')':
                printf("*******)**************\n");
                out(RBRACKET,token);
                break;
            case ';':
                printf("*******;**********\n");
                out(SC,token);
                break;
            case '/':
                ch = fgetc(fp);
                if(ch == '/') //单行注释
                {
                    token[count++] = (char)ch;
                    ch = fgetc(fp);
                    while (ch != '\n')
                    {
                        token[count++] = (char)ch;
                        ch = fgetc(fp);
                    }
                    fseek(fp,-1,1);
                    printf("******单行注释*********\n");
                    out(DFS,token);
                } else if(ch == '*') //多行注释
                {
                    token[count++] = (char)ch;
                    ch = fgetc(fp);
                    while (ch != '*')
                    {
                        if(ch == EOF)
                        {
                            printf("不完整的注释\n");
                            exit(-3);
                        }
                        token[count++] = (char)ch;
                        ch = fgetc(fp);
                    }
                    token[count++] = (char)ch;
                    if((ch = fgetc(fp)) == '/')
                    {
                        token[count] = (char)ch;
                        printf("******多行注释********\n");
                        out(FSS,token);
                    } else{
                        printf("缺少/\n");
                        exit(-4);
                    }

                } else{
                    if(ch == '0')
                    {
                        printf("除数不能为0！\n");
                        exit(-5);
                    } else{
                        printf("******/*************\n");
                        out(DIV,token);
                    }
                }
                break;
            case ' ':
                break;
            case '{':
                printf("***********{**********\n");
                out(LBRACE,token);
                ch = fgetc(fp);
                while (ch != '}')
                {
                    ch = fgetc(fp);
                    step++;
                    if(ch == EOF)
                    {
                        printf("无法找到匹配的右大括号\n");
                        exit(-6);
                    }
                }
                fseek(fp,-step,1);
                break;
            case '}':
                printf("*******}**************\n");
                out(RBRACE,token);
                break;
            case '\n':
                break;
            default:
                report_error();
                break;
        }
    }
}
