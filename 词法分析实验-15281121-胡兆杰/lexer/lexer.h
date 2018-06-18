//
// Created by 胡兆杰 on 2018/4/12.
//

#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

//保留字表
extern char reserved[13][13];

/* 其余符号 */
#define ID 6        //标识符
#define INT 7       //整数
#define LT 8        // <
#define LE 9        // <=
#define EQ 10       // =
#define EE 11       // ==
#define NE 12       // <>
#define GT 13       // >
#define GE 14       // >=
#define ADD 15      // +
#define SUB 16      // -
#define STAR 17     // *
#define COLON 18    // :
#define CE 19       // :=
#define SC 20       // ;
#define DIV 21      // /
#define FSS 22      // /*
#define DFS 23      // //
#define LBRACKET 24 // (
#define RBRACKET 25 // )
#define LBRACE 26   // {
#define RBRACE 27   // }
extern char token[30]; //字符数组
extern int lookup(char s[]); //查保留字表
extern void out(int id, char s[]);//输出字符
extern void report_error();//报错
extern void scanner(FILE *fp, int ch); //词法分析
extern void convert_to_lower(char s[30]);//将大写字母转换为小写
#endif //LEXER_LEXER_H
