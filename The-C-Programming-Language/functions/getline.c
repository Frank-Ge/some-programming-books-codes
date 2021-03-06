#include <stdio.h>

// getline:将输入的一行字符存储到s中，每行的最大值为lim
// 返回该行的字符数。
int getline(char s[], int lim)
{
	int c, i; // c暂时存储输入的值。i记录该行文本的个数

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}
