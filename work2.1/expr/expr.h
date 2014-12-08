#ifndef EXPR_H_INCLUDED
#define EXPR_H_INCLUDED

/* 表达式求值 - expr 为输入的表达式, n 为其长度, 求出表达式的值
 *
 * 假设 expr 只含数字字符和四则运算符号 ('+'、'-'、'*'、'/'),
 * 不含包括空白符在内的其他字符, 并假设 expr 是合法的表达式.
 *
 * 注意：所有运算均应处理为整型运算 (e.g. 3/2=1).
 */
int Eval(const char* const expr, int n);

#endif // EXPR_H_INCLUDED
