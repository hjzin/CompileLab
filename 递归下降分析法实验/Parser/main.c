#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int istrue = 0; //0代表正确，1代表错误
int current;

int main() {
    FILE *fp;
    if((fp = fopen("src.txt","r")) == NULL)
    {
        printf("打开文件失败\n");
        exit(-1);
    } else{
        freopen("output.txt", "w", stdout);
        current = fgetc(fp);
        FE(fp);
        if(istrue == 0)
            printf("合法的表达式\n");
        else
            printf("不合法的表达式\n");
    }
    fclose(fp);
    fclose(stdout);
    return 0;
}

int FE(FILE *fp)
{
    int t = 0, ep = 0;

    if (current == 'i' || current == '(')
    {
        //current = fgetc(fp);
        t = FT(fp);
        if( t == 0)
        {
            //current = fgetc(fp);
            ep = FEp(fp);
            if(ep == 0)
            {
                printf("E -> TE'\n");
                istrue = 0;
            } else
            {
                istrue = 1;
            }
        } else{
            istrue = 1;
        }
    } else{
        istrue = 1;
    }
    //current = fgetc(fp);
    if(istrue == 0)
        return 0;
    else
        return 1;
}

int FEp(FILE *fp)
{
    int a = 0, t = 0;
    istrue = 0;
    while (1)
    {
        if(current == '+' || current == '-')
        {
            //current = fgetc(fp);
            a = FA(fp);
            if(a == 0)
            {
                t = FT(fp);
                if(t == 0)
                {
                    printf("E' ->ATE'\n");
                    //current = fgetc(fp);
                } else{
                    istrue = 1;
                    break;
                }
            } else{
                istrue = 1;
                break;
            }
        } else{
            if (current == ')' || current == '#')
            {
                printf("E' -> ε\n");
                istrue = 0;
                break;
            } else{
                istrue = 1;
                break;
            }
        }
    }
    //current = fgetc(fp);
    if(istrue == 0)
        return 0;
    else
        return 1;
}

int FT(FILE *fp)
{
    int f = 0,tp = 0;
    istrue = 0;
    if(current == 'i' || current == '(')
    {
        //current = fgetc(fp);
        f = FF(fp);
        if(f == 0)
        {
            //current = fgetc(fp);
            tp = FTp(fp);
            if(tp == 0)
            {
                printf("T -> FT'\n");
                istrue = 0;
            } else{
                istrue = 1;
            }
        } else{
            istrue = 1;
        }
    } else{
        istrue = 1;
    }
    //current = fgetc(fp);
    if(istrue == 0)
        return 0;
    else
        return 1;
}

int FTp(FILE *fp)
{
    int m = 0, f = 0;
    istrue = 0;
    while (1)
    {
        if(current == '*' || current == '/')
        {
            //current = fgetc(fp);
            m = FM(fp);
            if(m == 0)
            {
                //current = fgetc(fp);
                f = FF(fp);
                if(f == 0)
                {
                    printf("T' -> MFT'\n");
                    //current = fgetc(fp);
                } else{
                    istrue = 1;
                    break;
                }
            } else{
                istrue = 1;
                break;
            }
        } else{
            if (current == ')' || current == '#' || current == '+' || current == '-')
            {
                printf("T' -> ε\n");
                istrue = 0;
                break;
            } else{
                istrue = 1;
                break;
            }
        }
    }
    //current = fgetc(fp);
    if(istrue == 0)
        return 0;
    else
        return 1;
}

int FM(FILE *fp)
{
    istrue = 0;
    if(current == '*')
    {
        printf("M -> *\n");
        istrue = 0;
    } else if (current == '/'){
        printf("M -> /\n");
        istrue = 0;
    } else{
        istrue = 1;
    }
    current = fgetc(fp);
    if(istrue == 0)
        return 0;
    else
        return 1;
}

int FA(FILE *fp)
{
    istrue = 0;
    if(current == '+')
    {
        printf("A -> +\n");
        istrue = 0;
    } else if(current == '-'){
        printf("A -> -\n");
        istrue = 0;
    } else{
        istrue = 1;
    }
    current = fgetc(fp);
    if(istrue == 0)
        return 0;
    else
        return 1;
}

int FF(FILE *fp)
{
    int e = 0;
    istrue = 0;
    if(current == '(')
    {
        current = fgetc(fp);
        e = FE(fp);
        if(e == 0)
        {
            if(current == ')')
            {
                current = fgetc(fp);
                printf("F -> (E)\n");
                istrue = 0;
            } else{
                istrue = 1;
            }
        } else{
            istrue = 1;
        }
    } else{
        if(current == 'i')
        {
            printf("F -> i\n");
            current = fgetc(fp);
            istrue = 0;
        }
        else
            istrue = 1;
    }
    if(istrue == 0)
        return 0;
    else
        return 1;
}