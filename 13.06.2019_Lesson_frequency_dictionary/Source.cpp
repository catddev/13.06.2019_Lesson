#include<string>
#include<cstring>
#include<string.h>
#include<map>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<set>
#include<vector>

using namespace std;


int main() {
	//ifstream in_file("dict.txt");
	//map<string, int> d;

	//string s;
	//while (!in_file.eof()) {
	//	in_file >> s;//first<string>
	//	d[s]++;//second<int> ++
	//}
	//for_each(d.begin(), d.end(), [](pair<string, int> el) {//for MAP always use template class (PAIR<type, type>) with name El, т.кю мэп содержит 2 значения
	//	cout << el.first << " " << el.second << endl;
	//});

	//1.	Программа проверки правильности слов в текстовом файле.
	//Проверка правильности осуществляется с помощью частотного словаря.
	//Для реализации частотного словаря использовать класс map<string, int>(Ключом является строка, значение – частота повторения слова).
	//Частотный словарь формируется на основе некоторого текстового документа, который считается орфографически правильным.
	//(Этот файл открывается, каждое слово читается и сохраняется в vector<string>(или list<string> или deque<string>).
	//Затем все слова переводятся в нижний регистр и переносятся в частотный словарь map<string, int>, который сохраняется в файл.)
	//При проверке текста указывается имя файла, содержащего текст для проверки.
	//Программа открывает этот файл, и, извлекая из него слова, осуществляет их поиск в частотном словаре.
	//Если слово в словаре не найдено, то пользователю предлагается или заменить это слово на другое(вводит пользователь) или добавить слово в частотный словарь.
	//Проверяемый файл должен сохраняться с изменениями, которые внес в него пользователь.
	//В реализации программы приветствуется наличие удобного пользовательского интерфейса(приложение консольное),
	//а также наличие самостоятельно разработанных для решения поставленной задачи классов.



	//Написать программу учета книг в библиотеке.Сведения о книгах : ФИО автора, название, год издания, количество экземпляров.Обеспечить :
	//		Добавление книг
	//		Удаление книг
	//		Вывод сведений о книгах по фамилиям авторов
	//		Вывод сведений о книгах по указанному году издания
	//	Использовать контейнерный класс multimap

	//use set or map//photo

	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream read_file("read.txt");
	
	vector<string> v;
	set<string> sd;

	string str;
	while (!read_file.eof()) {
		read_file >> str;
		//str=_tolower(str);//?
		//_strlwr_(str);
		//d.insert(pair<string, int>(s,1)); //for multimap
		sd.insert(str);
		
	}
	for_each(sd.begin(), sd.end(), [](string el) {
		cout << el << endl;
	});

	ifstream text_file("check_text.txt");
	while (!text_file.eof()) {
		text_file >> str;
		v.push_back(str);
	}



	int choice;

	for (auto it = v.begin(); it != v.end(); it++)
	{
		auto fit = sd.find(*it);
		if (fit != sd.end())
			continue;
		else {

			int choice;
			cout << "Enter 1 to change this word" << endl;
			cout << "Enter 2 to add this word into the dictionary" << endl;
			cin >> choice;
			
			switch (choice) {
			case 1:
			{
				string tmp = *it;
				string str;
				cout << "Enter new word" << endl;
				cin >> str;
				replace(v.begin(), v.end(), tmp, str);
			}
			break;
			case 2:
			{
				sd.insert(*it);

			}
			break;
			}

		}

	}

	for_each(v.begin(), v.end(), [](string el) {
		cout << el << endl;
	});

	cout << endl << "DICTIONARY" << endl;
	for_each(sd.begin(), sd.end(), [](string el) {
		cout << el << endl;
	});

	system("pause");
	return 0;
}