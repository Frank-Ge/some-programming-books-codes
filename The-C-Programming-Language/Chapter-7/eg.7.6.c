#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[])
{
	FILE *fp;
	char *prog = argv[0];

	if (argc == 1)
		filecopy(stdin, stdout);
	else
	{
		while (--argc > 0)
		{
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				
				getchar();
				getchar();
				exit(1);
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}

	if (ferror(stdout))
	{
		fprintf(stderr, "%s: error writing stdout\n", prog);

		getchar();
		getchar();
		exit(2);
	}

	getchar();
	getchar();
	exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
