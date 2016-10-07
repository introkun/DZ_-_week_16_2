#include <iostream>
#include "myLib.h"

/*Поиск вхождения слова в текст и проверка, является ли оно отдельностоящим*/
char* searchSeparateWordToStr(char * text, char * posWord, char * wordDst)
{
	while ((posWord = strstr(posWord, wordDst)) != NULL)
	{

		/*Символ стоящий перед словом*/
		char simbolBeforeWord;
		/*Если начало найденного слова совпадает с началом текста -
		присваеват значение '\0' (не буква), если нет - символ стоящий перед словом*/
		simbolBeforeWord = (posWord == text) ? '\0' : *(posWord - 1);

		/*Символ стоящий после слова*/
		char simbolAfterWord;
		simbolAfterWord = *(posWord + strlen(wordDst));

		/*Если символы до или после слова является буквенным продолжает искать вхождения слова в строку*/
		if (simbolAfterWord >= 'A' && simbolAfterWord <= 'Z' || simbolAfterWord >= 'a' && simbolAfterWord <= 'z' ||
			simbolBeforeWord >= 'A' && simbolBeforeWord <= 'Z' || simbolBeforeWord >= 'a' && simbolBeforeWord <= 'z')
		{
			posWord++;
			continue;
		}
		
		else
		{
			return posWord;
		}
	}
	/*Если не находит отдельностоящего слова возвращаем NULL*/
	return NULL;
}

/*Заменяет слова в тексте на новые*/
char * replacingTheWord(char * text, int sizeText, char * wordSRC, char * wordDST)
{
	if (text == nullptr)
	{
		return nullptr;
	}

	/*Позиция совпадения искомого слова в исходном тексте*/
	char * coincidencePoztion;
	coincidencePoztion = searchSeparateWordToStr(text, text, wordDST);

	/*Если нет вхождений - возвращает исходный текст*/
	if (coincidencePoztion == NULL)
	{
		return text;
	}
	
	/*Нультерминация места начала вхождения искомого слова для обозначения 
	конца копируемого текста функцией strcpy_s*/
	*coincidencePoztion = '\0';

	/*Новый массив для измененного текста*/
	char * newText = new char[sizeText];
		
	/*Текущая позиция в исходном тексте*/
	char * positionToSurceText = text;
		
	/*Текущая позиция в измененном тексте*/
	char * pozitionToNewText = newText;
		
	/*Копирует исходный текст в новую строку до точки вхождения заменяемого слова*/
	strcpy_s(newText, sizeText, text);
	do
	{
		/*Вставляет новое слово в новую строку*/
		strcat_s(pozitionToNewText, sizeText, wordSRC);
		
		/*Устанавливает указатель на позицию, следующую за замененным словом
		для продолжения поиска вхождения в строку*/
		positionToSurceText = coincidencePoztion + strlen(wordDST);
			
		/*Поиск следующих вхождений искомого слова в исходной строке*/
		coincidencePoztion = searchSeparateWordToStr(text, positionToSurceText, wordDST);
			
		/*Если есть совпадения устанавливает нуль-терминацию для ограничения копирования текста функцией strcar_s*/
		if (coincidencePoztion != NULL)
		{
			*coincidencePoztion = '\0';
		}
			
		/*Копирует исходный текст начиная с позиции следующей за замененным словом и до нуль-терминации*/
		strcat_s(pozitionToNewText, sizeText, positionToSurceText);

	} while (coincidencePoztion != NULL);

	delete[] text;
	return newText;
	
}
int inputChek(int min, int max)
{
	int input = 1;
	return input;
}

