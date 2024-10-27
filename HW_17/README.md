## Код программы
```
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	string theme, word;

	while (true)
	{
		cout << "\n===================================\n";
		cout << "Для выхода из программы (q)\n";
		cout << "Введите тему слова -> ";
		getline(cin, theme);

		if (theme == "q")
		{
			break;
		}

		cout << "Введите слово -> ";
		getline(cin, word);

		string fileName = theme + ".txt";

		ofstream file(fileName, ios::app);
		if (file.is_open())
		{
			file << word << ", ";
			cout << "Слово добавлено.\n";
		}
		else
		{
			cout << " Ошибка!";
		}
	}
}
```


## Файлы которые сохраняются

![{E3CF5D7C-FD96-4613-BABE-81A7DE3E8BD0}](https://github.com/user-attachments/assets/78fbf93a-566f-43af-adf7-1997e4f4c79a)
