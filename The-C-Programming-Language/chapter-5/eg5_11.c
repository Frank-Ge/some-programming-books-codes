#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 	5000
#define MAXSIZE		100
char *lineptr[MAXLINES];

int getline(char s[], int lim);
int readlines(char *lineptr[], int MAXLINESs);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
void swap(void *v[], int i, int j);

int main(int argc, char *argv[])
{
	int nlines = 0;
	int numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if (( nlines = readlines(lineptr, MAXLINES)) > 0)
	{
		qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : (int (*)(char *, char *))strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}


// getline:将输入的一行字符存储到s中，每行的最大值为lim
// 返回该行的字符数。
int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

// 读取输入的文本，以EOF结束。
// 将读取的文本记录在字符串数组指针lineptr[]中，
// 每行为一个字符串数组，最大行数为MAXLINESs
// 返回文本的行数。如果输入错误，或者大于最大行数，返回-1
int readlines(char *lineptr[], int maxlines)
{
	char *p;
	int n = 0; // 记录文本的行数
	int len = 0; // 记录每行字符的个数
	char line[MAXSIZE];

	while ((len = getline(line, MAXSIZE))> 0)
	{
		if (n >= maxlines || (p = (char *)malloc(len)) == NULL)
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[n++] = p;
		}
	}

	return n;
}

// writelines:输出字符串指针数组中的字符串内容。
// nlines为字符串指针数组中字符串指针的个数
void writelines(char *lineptr[], int nlines)
{
	int n = 0;
	while (n < nlines)
	{
		printf("%s\n", lineptr[n]);
		n++;
	}
}

// 快速排序：对字符串指针数组按照字符串的字典顺序排序
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;

	if (left >= right)
		return;

	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1, comp);
	qsort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 > v2)
		return 1;
	else if (v1 < v2)
		return -1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
