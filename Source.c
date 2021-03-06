#define _CRT_SECURE_NO_WARNINGS
#define YES 1
#define NO 0
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAXLEN 1000
void main(void)
{
	HANDLE hStdout;
	char word[MAXLEN];
	int i = 0;
	int flag1 = 0;//Флаг наличия типа данных в начале строки
	int flag2 = 0;//Флаг наличия круглой скобки в строке
	int flag3 = 0;//Флаг отсутствия оператора приравнивания
	char line[MAXLEN]; //Строка
	char types[5][MAXLEN] = {"int","float","double","char","void"};//Константные типы данных
	FILE *fp;
	char *ptr;
	char *buf;
	fp = fopen("input.txt" , "rt");
	/*Настройка параметров консоли*/
	WORD foregroundColor0; 
	WORD foregroundColor; 
	WORD textAttribute; 
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE |
	SetConsoleTextAttribute(hStdout, foregroundColor0 );
	while (!feof(fp))
	{
		ptr = fgets(line, MAXLEN, fp);
		buf = line;
		while (*buf!='\0')//Проверяем на наличие знаков приравнивания
		{
			if (*buf == '=' )
				flag3 = YES;
			buf++;
		}
		while (*ptr != ' ')//Берем первое слово
		{
		
			word[i] = *ptr;
			ptr++;
			i++;
		}
		word[i++] = '\0';
		/*Проверяем совпадение с типами данных*/
		if (strcmp(word, types[0]) == 0 || strcmp(word, types[1]) == 0 || strcmp(word, types[2]) == 0 || strcmp(word, types[3]) == 0|| strcmp(word, types[4]) == 0)
			flag1 = YES;
		while (*ptr != '\0')//До конца строки ищем круглую скобку
		{
			if (*ptr == '(')

			{
				flag2 = YES;
				ptr++;
				break;
			}
			else {
			
				ptr++;
				continue;
			}
		}
		if (flag1 == YES && flag2 == YES && flag3 == NO)//Если все флаги в правильном положении - подсвечиваем строку
		{
			textAttribute = foregroundColor0;
			SetConsoleTextAttribute(hStdout, textAttribute);
			printf("%s", line);
		}
		else//иначе - выводим стандартно
		{
			SetConsoleTextAttribute(hStdout, 7);
			printf("%s", line);
		}
		/*Обнуляем флаги и счетчики*/
		i = 0;
		flag1 = flag2=flag3= NO;
	}
	/*Восстанавливаем стандартные параметры консоли*/
	SetConsoleTextAttribute(hStdout, 7);
	fclose(fp);//Закрываем файл
	getchar();
}
