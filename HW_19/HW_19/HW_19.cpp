#include <iostream>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;


//1. ������ � ���������� ������ ������, � ����� ���� ������.
// �������� �� ����� ������� � ���������� ����������(���� ��������� ������� � ������).
//int main()
//{
//	setlocale(LC_ALL, "russian");
//	char str[50];
//	char symbol;
//	int count = 0;
//
//	cout << "\n������� ������ -> ";
//	cin.getline(str, 50);
//
//	cout << "������� ������ -> ";
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
//	cout << "����� ���-�� ����������: " << count << "\n";
//}

//3. ���������� ������� ����� ����� �� �������� �����������.
//int main() 
//{
//	setlocale(LC_ALL, "russian");
//	char sentence[200];
//
//	//Hello my name is Vlad. ����� = 3
//
//	cout << "\n������� ����������� �� ����. ����� -> ";
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
//	cout << "\n������� ����� ����� = " << avgLetters << "\n";
//}

//5. ���������, ������� ��� ����������� ����� ���������� � ������ ������.
//int main()
//{
//	setlocale(LC_ALL, "russian");
//	char sentence[200];
//	char word[200];
//	
//	cout << "\n������� ����������� �� ����. ����� -> ";
//	cin.getline(sentence, 200);
//
//	cout << "\n������� ����� �� ����. ����� -> ";
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
//	cout << "����� ���������� -> " << count << "\n";
//	
//}

//2. �������� ���������, �������������� ���������� ����, � ����� ������� � ��������� ���� � ������, �������� �������������.
// ������������� �������� ���������� ������ ����������, ���� � ������ ��������.������, ��� ����� �������(� ����� �� � ����� ����) ����� ���� ����� ������ �������!����� ������ ������ ���� �� ���������� �����.������ ������ ��������� :
//����� �������� � ������ ������ � 38, �� ��� :
//���� � 6
//������� ���� - 12
//��������� ���� - 21
//������ ���������� - 2
//���� � 0
//������ �������� � 3
//int main()
//{
//	setlocale(LC_ALL, "russian");
//	char sentence[200];
//
//	cout << "\n������� ����������� �� ����. ����� -> ";
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
//	cout << "����� �������� � ������ ������ � " << Count << ", �� ��� :\n";
//	cout << "���� � " << wordCount << "\n";
//	cout << "������� ���� - " << glasniCount << "\n";
//	cout << "��������� ���� - " << soglasniCount << "\n";
//	cout << "������ ���������� - " << znakiCount << "\n";
//	cout << "���� � " << numberCount << "\n";
//	cout << "������ �������� � " << otherCount << "\n";
//}

//8. �������� ���������, ������� ���������� ������ ��������� �����.
//int main()
//{
//	setlocale(LC_ALL, "russian");
//
//	int count;
//
//	cout << "������ ������� ����� ������? -> ";
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
//	cout << "��������������� ������: " << password << "\n";
//}
