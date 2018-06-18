//
// Created by 胡兆杰 on 2018/4/26.
//

#ifndef PARSER_PASRSER_H
#define PARSER_PASRSER_H

extern int current; //当前要分析的字符
extern int istrue;  //判断输入的表达式是否为该文法定义的算数表达式，0代表是，1代表不是
int FE(FILE *fp);   //E的函数
int FEp(FILE *FP);  //E'的函数
int FT(FILE *fp);   //T的函数
int FTp(FILE *fp);  //T'的函数
int FM(FILE *fp);   //M的函数
int FA(FILE *fp);   //A的函数
int FF(FILE *fp);   //F的函数

#endif //PARSER_PASRSER_H
