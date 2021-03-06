
// 可以将输入的单词或者数字给保存到word中
int getword(char *word, int lim)
{
	int c;
	char *w = word;

	// 跳过之前的空白字符
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

#define BUFSIZE	100
#define NKEYS	(sizeof(keytab) / sizeof(keytab[0]))

char buf[BUFSIZE];	// 用于ungetch函数的缓冲区
int bufp = 0;	// buf中下一个空闲的位置

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp > BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
