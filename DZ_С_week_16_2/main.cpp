#include <iostream>
#include "myLib.h"

int main()
{
	int sizeText = 1024 * 1024;
	/*Исходный текст*/
	char * text = new char[sizeText];
	strcpy_s(text, sizeText, "This season, Jamie and Adam try something they've never done before:"
		"an implosion caused by a vacuum. The tall tale goes that a freight train tank car was being "
		"steam cleaned when a rainstorm let loose. The engineers made the mistake of sealing the "
		"container full of hot steam and headed home. The rain cooled the tank car, the steam condensed "
		"and contracted, and the resulting pressure differential caused the massive steel car to crumple "
		"like a soda can. Is it possible? The MythBusters devote an entire episode and embark on the "
		"biggest logistical operation in their history to find out.");
	/*Искомое слово*/
	char * requiredWord = new char[40];
	/*слово для замены*/
	char * wordForChange = new char[40];
	/*std::cout << "Vvedite text dlia redaktirovanija: " << std::endl;
	gets_s(text, sizeText);*/
	puts(text);
	std::cout << "Vvedite slovo dlia poiska i ego zameni: " << std::endl;
	gets_s(requiredWord, 40);
	std::cout << "Vvedite slovo, na kotoroe bydet proizvoditsia zamena: " << std::endl;
	gets_s(wordForChange, 40);
	text = replacingTheWord(text, sizeText, wordForChange, requiredWord);
	std::cout << text << std::endl;
	return 0;
}