#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define	MAXWORD	100

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


typedef struct
{
	//int count;
	char *word;
	int count;
} key;

// 里面的单词应该按照字母表上升的顺序排列
key keytab[]= {
	{"do", 0},
	{"for", 0},
	{"void", 0},
	{"while", 0}
};

//key keytab[] = {
//	{0, "for"},
//	{0, "while"},
//	{0, "do"},
//	{0, "void"}
//};

int getword(char *, int);
int binsearch(char *, key *, int);

int main()
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n <NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);

	//printf("%d\n", binsearch("while", keytab, 4));
	//printf("%d\n", strcmp("do", "while"));
	
	return 0;
}

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

int binsearch(char *word, key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}
