# -*- coding:utf-8 -*-
# 词法分析模块

#保留字表
reserved = ["void", "int", "float", "double", "else", "if", "do", "while", "break", "for"]
# 其余符号
reserve = 5         #保留字
ID = 6              #标识符
INT = 7             #整数
LT = 8              # <
LE = 9              # <=
EQ = 10             # =
EE = 11             # ==
NE = 12             # !=
GT = 13             # >
GE = 14             # >=
ADD = 15            # +
SUB = 16            # -
MUL = 17            # *
SC = 18             # ;
DIV = 19            # /
MCOMMENT = 20       # /*
COMMENT = 21        # //
LBRACKET = 22       # (
RBRACKET = 23       # )
LBRACE = 24         # {
RBRACE = 25         # }
PLUS = 26           # ++
MINUS = 27          # --
SHIFT_RIGHT = 28    # >>
SHIFT_LEFT = 29     # <<
AND = 30            # &&
OR = 31             # ||
NOT = 32            # !

#输出的二元式数组
scanner_output = []
#错误类型
error = -1


# 二元式类
class Binary(object):
    def __init__(self, code, token):
        """
        初始化
        :param code: 字符编码
        :param token: 字符的值
        """
        self.code = code
        self.token = token


def scanner(line):
    """
    词法分析程序
    :param line: 输入的字符串
    :return: 二元式数组scanner_output;错误类型error
    """
    global error
    scanner_output = []
    line = line.replace('\n', '')
    line = line.replace(';', '')
    tokens = line.split(' ')
    j = 0
    while j != len(tokens):
        # 判断是否为标识符
        if tokens[j][0].isalpha() and tokens[j].isalnum():
            #判断是否为保留字
            if tokens[j] in reserved:
                reserved_binary = Binary(reserve, tokens[j])
                scanner_output.append(reserved_binary)
            else:
                identifier = Binary(ID, tokens[j])
                scanner_output.append(identifier)
            j += 1
        # 判断是否为整数
        elif tokens[j].isdigit():
            integer = Binary(INT, tokens[j])
            scanner_output.append(integer)
            j += 1
        elif tokens[j] == '>':
            gt = Binary(GT, tokens[j])
            scanner_output.append(gt)
            j += 1
        elif tokens[j] == '>=':
            ge = Binary(GE, tokens[j])
            scanner_output.append(ge)
            j += 1
        elif tokens[j] == '<':
            lt = Binary(LT, tokens[j])
            scanner_output.append(lt)
            j += 1
        elif tokens[j] == '<=':
            le = Binary(LE, tokens[j])
            scanner_output.append(le)
            j += 1
        elif tokens[j] == '=':
            eq = Binary(EQ, tokens[j])
            scanner_output.append(eq)
            j += 1
        elif tokens[j] == '==':
            ee = Binary(EE, tokens[j])
            scanner_output.append(ee)
            j += 1
        elif tokens[j] == '+':
            add = Binary(ADD, tokens[j])
            scanner_output.append(add)
            j += 1
        elif tokens[j] == '++':
            plus = Binary(PLUS, tokens[j])
            scanner_output.append(plus)
            j += 1
        elif tokens[j] == '-':
            sub = Binary(SUB, tokens[j])
            scanner_output.append(sub)
            j += 1
        elif tokens[j] == '--':
            minus = Binary(MINUS, tokens[j])
            scanner_output.append(minus)
            j += 1
        elif tokens[j] == '*':
            mul = Binary(MUL, tokens[j])
            scanner_output.append(mul)
            j += 1
        elif tokens[j] == '/':
            if tokens[j+1] == '0':
                print('除数不能为0\n')
                error = 1
                break
            div = Binary(DIV, tokens[j])
            scanner_output.append(div)
            j += 1
        elif tokens[j].startswith('/'):
            if tokens[j][1] == '/':
                comment = Binary(COMMENT, tokens[j])
                scanner_output.append(comment)
                j += 1
            elif tokens[j][1] == '*':
                flag = 0
                for k in range(i+1, len(lines)):
                    if '*/' in lines[k]:
                        flag = 1
                        i = k
                        break
                if flag:
                    mcomment = Binary(MCOMMENT, tokens[j])
                    scanner_output.append(mcomment)
                    j += 1
                else:
                    print("不完整的注释\n")
                    error = 2
                    break
            else:
                print('注释缺少/\n')
                error = 3
                break
        elif tokens[j] == '{':
            lbrace = Binary(LBRACE, tokens[j])
            scanner_output.append(lbrace)
            j += 1
        elif tokens[j] == '}':
            rbrace = Binary(RBRACE, tokens[j])
            scanner_output.append(rbrace)
            j += 1
        elif tokens[j].startswith('('):
            bracket_complete = 0
            lbracket = Binary(LBRACKET, tokens[j])
            scanner_output.append(lbracket)
            j += 1
            for n in range(j+1, len(tokens)):
                if ')' in tokens[n]:
                    bracket_complete = 1
                    break
            if not bracket_complete:
                print('找不到匹配的右括号\n')
                error = 4
                break
        elif tokens[j] == ')':
            rbracket = Binary(RBRACKET, tokens[j])
            scanner_output.append(rbracket)
            j += 1
        elif tokens[j] == '&&':
            and_binary = Binary(AND, tokens[j])
            scanner_output.append(and_binary)
            j += 1
        elif tokens[j] == '||':
            or_binary = Binary(OR, tokens[j])
            scanner_output.append(or_binary)
            j += 1
        elif tokens[j] == '!':
            not_binary = Binary(NOT, tokens[j])
            scanner_output.append(not_binary)
            j += 1
        elif tokens[j] == '!=':
            ne = Binary(NE, tokens[j])
            scanner_output.append(ne)
            j += 1
        else:
            print('%s无法被识别\n' % tokens[j])
            j += 1
    return scanner_output, error


if __name__ == '__main__':
    with open('src.txt', 'r', encoding='utf-8') as srcfile:
        lines = srcfile.readlines()
    scanner(lines)
    for i in range(len(scanner_output)):
        print("%s %s" % (scanner_output[i].code, scanner_output[i].token))






