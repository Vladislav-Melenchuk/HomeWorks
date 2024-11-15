#include <iostream>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;


//1. Ввести с клавиатуры строку текста, а затем один символ.
// Показать на экран индексы и количество совпадений(ищем вхождения символа в строку).
//int main()
//{
//	setlocale(LC_ALL, "russian");
//	char str[50];
//	char symbol;
//	int count = 0;
//
//	cout << "\nВведите строку -> ";
//	cin.getline(str, 50);
//
//	cout << "Введите символ -> ";
//	cin >> symbol;
//
//	for (int i = 0; i < strlen(str); i++)
//	{
//		if (str[i] == symbol)
//		{
//			count++;
//		}
//	}
//
//	cout << "Общее кол-во совпадений: " << count << "\n";
//}

//3. Подсчитать среднюю длину слова во введённом предложении.
//int main() 
//{
//	setlocale(LC_ALL, "russian");
//	char sentence[200];
//
//	//Hello my name is Vlad. Ответ = 3
//
//	cout << "\nВведите предложение на англ. языке -> ";
//	cin.getline(sentence, 200);
//
//	int letterCount = 0;
//	int wordCount = 0;
//	bool word = false;
//
//	for (char c : sentence)
//	{
//		if (isalpha(c))
//		{
//			letterCount++;
//			if(!word)
//			{
//				word = true;
//				wordCount++;
//			}
//		}
//		else
//		{
//			word = false;
//		}
//	}
//
//	float avgLetters;
//
//
//	
//
//	avgLetters = letterCount / wordCount;
//
//	cout << "\nСредняя длина слова = " << avgLetters << "\n";
//}

//5. Посчитать, сколько раз определённое слово содержится в строке текста.
//int main()
//{
//	setlocale(LC_ALL, "russian");
//	char sentence[200];
//	char word[200];
//	
//	cout << "\nВведите предложение на англ. языке -> ";
//	cin.getline(sentence, 200);
//
//	cout << "\nВведите слово на англ. языке -> ";
//	cin.getline(word, 200);
//	
//	int count = 0;
//	char* position = strstr(sentence, word);
//	while (position != nullptr)
//	{
//		count++;
//		position = strstr(position + 1, word);
//	}
//
//	cout << "Слово встечается -> " << count << "\n";
//	
//}

//2. Написать программу, подсчитывающую количество слов, а также гласных и согласных букв в строке, введённой пользователем.
// Дополнительно выводить количество знаков пунктуации, цифр и других символов.Учесть, что между словами(а также до и после слов) может быть более одного пробела!Текст строки должен быть на английском языке.Пример вывода программы :
//Всего символов в строке текста – 38, из них :
//Слов – 6
//Гласных букв - 12
//Согласных букв - 21
//Знаков пунктуации - 2
//Цифр – 0
//Других символов – 3
//int main()
//{
//	setlocale(LC_ALL, "russian");
//	char sentence[200];
//
//	cout << "\nВведите предложение на англ. языке -> ";
//	cin.getline(sentence, 200);
//
//	bool word = false;
//	int Count = 0;
//	int wordCount = 0;
//	int glasniCount = 0;
//	int soglasniCount = 0;
//	int znakiCount = 0;
//	int numberCount = 0;
//	int otherCount = 0;
//
//	for (int i = 0; sentence[i] != '\0'; i++)
//	{
//		Count++;
//		char c = sentence[i];
//
//		if (isalpha(c)) {
//
//			if (!word) {
//				word = true;
//				wordCount++;
//			}
//
//			if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' ||
//				c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
//				glasniCount++;
//			}
//			else {
//				soglasniCount++;
//			}
//		}
//		else if (ispunct(c))
//		{
//			znakiCount++;
//		}
//		else if (isdigit(c))
//		{
//			numberCount++;
//		}
//		else if (!isspace(c))
//		{
//			otherCount++;
//		}
//		else
//		{
//			word = false;
//		}
//	}
//
//	cout << "Всего символов в строке текста – " << Count << ", из них :\n";
//	cout << "Слов – " << wordCount << "\n";
//	cout << "Гласных букв - " << glasniCount << "\n";
//	cout << "Согласных букв - " << soglasniCount << "\n";
//	cout << "Знаков пунктуации - " << znakiCount << "\n";
//	cout << "Цифр – " << numberCount << "\n";
//	cout << "Других символов – " << otherCount << "\n";
//}

//8. Напишите программу, которая генерирует пароль указанной длины.
//int main()
//{
//	setlocale(LC_ALL, "russian");
//
//	int count;
//
//	cout << "Какого размера будет пароль? -> ";
//	cin >> count;
//
//	char pass[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@1234567890";
//
//	srand(time(0));
//
//	string password = "";
//
//	for (int i = 0; i < count; i++)
//	{
//		password += pass[rand() % sizeof(pass)];
//	}
//
//	cout << "Сгенерированный пароль: " << password << "\n";
//}
