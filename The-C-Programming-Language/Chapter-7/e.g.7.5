#include <stdio.h>

void filecopy(FILE *, FILE *);

// 如果命令行的参数是文件名，则将文件中内容读到stdout（屏幕）
// 否则，将stdin（键盘输入）内容读到stdout。
int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
		{
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				printf("cat: can't open %s\n", *argv);

				getchar();
				getchar();
				return 1;
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}

	getchar();
	getchar();
	return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
