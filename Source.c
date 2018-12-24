#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define LETTER 1
#define NOT_THE_LETTER 0
#define MAXLEN 1000
void main(void)
{
	HANDLE hStdout;
	char word[MAXLEN];
	int i = 0;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	char line[MAXLEN]; // строчка из файла
	char types[5][MAXLEN] = {"int","float","double","char","void"};
	FILE *fp;
	char *ptr;
	char *buf;
	fp = fopen("input.txt" , "rt");
	WORD foregroundColor0; // цвет слов
	WORD foregroundColor; // цвет символа
	WORD textAttribute; // атрибут текста - цвет символа и фона
	// Получить стандартный дескриптор
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	// определить цвета символов, разделителей и фона
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE |
	
	SetConsoleTextAttribute(hStdout, foregroundColor0 );
	
	while (!feof(fp))
	{
		ptr = fgets(line, MAXLEN, fp);
		buf = line;
		while (*buf!='\0')
		{
			if (*buf == '=' )
				flag3 = 1;
			buf++;
		}
		while (*ptr != ' ')
		{
		
			word[i] = *ptr;
			ptr++;
			i++;
		}
		word[i++] = '\0';
		if (strcmp(word, types[0]) == 0 || strcmp(word, types[1]) == 0 || strcmp(word, types[2]) == 0 || strcmp(word, types[3]) == 0|| strcmp(word, types[4]) == 0)
			flag1 = 1;
		while (*ptr != '\0')
		{
			if (*ptr == '(')

			{
				flag2 = 1;
				ptr++;
				break;
			}
			else {
			
				ptr++;
				continue;
			}
		}
		if (flag1 == 1 && flag2 == 1 && flag3 == 0)
		{
			textAttribute = foregroundColor0;
			SetConsoleTextAttribute(hStdout, textAttribute);
			printf("%s", line);
		}
		else
		{
			SetConsoleTextAttribute(hStdout, 7);
			printf("%s", line);
		}
		i = 0;
		flag1 = 0;
		flag2 = 0;
		flag3 = 0;
	}	SetConsoleTextAttribute(hStdout, 7);	getchar();}