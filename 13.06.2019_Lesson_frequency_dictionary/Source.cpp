#include<string>
#include<cstring>
#include<string.h>
#include<map>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<set>
#include<queue>
#include<vector>
#include"Book.h"
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
	//cout << endl;

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

	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//ifstream read_file("read.txt");
	//
	//vector<string> v;
	//set<string> sd;

	//string str;
	//while (!read_file.eof()) {
	//	read_file >> str;
	//	transform(str.begin(), str.end(), str.begin(), ::tolower);//string to lower!!!
	//	sd.insert(str);
	//}
	//for_each(sd.begin(), sd.end(), [](string el) {
	//	cout << el << endl;
	//});
	//cout << endl;

	//ifstream text("check_text.txt");
	//while (!text.eof()) {
	//	text >> str;
	//	v.push_back(str);
	//}

	//for (auto it = v.begin(); it != v.end(); it++)
	//{
	//	auto fit = sd.find(*it);//fit - find_iterator
	//	if (fit != sd.end())
	//		continue;
	//	else {
	//		int choice;
	//		cout << "There is no word \"" << *it << "\" in the dictionary" << endl;
	//		cout << "Enter 1 to change this word" << endl;
	//		cout << "Enter 2 to add this word into the dictionary" << endl;
	//		cin >> choice;

	//		switch (choice) {
	//		case 1:
	//		{
	//			string tmp = *it;
	//			string str;
	//			cout << "Enter new word" << endl;
	//			cin >> str;
	//			replace(v.begin(), v.end(), tmp, str);
	//		}
	//		break;
	//		case 2:
	//			sd.insert(*it);
	//		break;
	//		}
	//	}
	//}

	//cout << "TEXT REDACTED" << endl;
	//for_each(v.begin(), v.end(), [](string el) {
	//	cout << el << endl;
	//});

	//cout << endl << "DICTIONARY" << endl;
	//for_each(sd.begin(), sd.end(), [](string el) {
	//	cout << el << endl;
	//});

	//Написать программу учета книг в библиотеке. Сведения о книгах : ФИО автора, название, год издания, количество экземпляров.
	//Обеспечить :
	//		Добавление книг
	//		Удаление книг
	//		Вывод сведений о книгах по фамилиям авторов
	//		Вывод сведений о книгах по указанному году издания
	//	Использовать контейнерный класс multimap


	ifstream lib_file("library.txt");
	multimap<Book, int> lib;
	set<Book> bookset;
	string str1;
	int i = 0;

	string author, title, publish;
	int number;
	while (!lib_file.eof()) {
		getline(lib_file, author, '#');
		getline(lib_file, title, '#');
		getline(lib_file, publish, '#');
		lib_file >> number;
		lib_file.ignore();
		lib.insert(pair<Book, int>(Book(author, title, publish, number), i++));
		bookset.insert(Book(author, title, publish, number));
	}
	cout << endl;
	for_each(lib.begin(), lib.end(), [](pair<Book, int> el) {
		cout << el.first << " " << el.second << endl;
	});

	bool f = true;
	while (f) {
		cout << endl << "Enter 1 to find a book" << endl;
		cout << "Enter 2 to remove a book" << endl;
		cout << "Enter 3 to add a book" << endl;
		cout << "Enter 4 to get books by author" << endl;
		cout << "Enter 5 to get books by publishing year" << endl;
		cout << "Enter 6 to print the library list" << endl;
		cout << "Enter 0 to exit" << endl;
		int choice1;
		cin >> choice1;
		Book yourBook;

		switch (choice1) {
		case 1:
		{
			cin >> yourBook;
			auto it = lib.find(yourBook);
			if (it != lib.end())
				cout << it->first << " " << it->second << endl;
		}
		break;
		case 2:
		{
			cin >> yourBook;
			auto it = lib.find(yourBook);
			if (it != lib.end())
				lib.erase(it);
		}
		break;
		case 3:
		{
			cin.ignore();
			cin >> yourBook;
			lib.insert(pair<Book, int>(yourBook, i++));
		}
		break;
		case 4:
		{
			cout << "Enter author" << endl;
			cin.ignore();
			getline(cin, author, '#');
			for (auto it = lib.begin(); it != lib.end(); it++) {
				if (it->first.getAuthor() == author)
					cout << it->first << " " << it->second << endl;
			}
		}
		break;
		case 5:
		{
			cout << "Enter publishing year" << endl;
			cin >> publish;
			for (auto it = lib.begin(); it != lib.end(); it++) {
				if (it->first.getYear() == publish)
					cout << it->first << " " << it->second << endl;
			}
		}
		break;
		case 6:
		{
			/*for_each(lib.begin(), lib.end(), [](pair<Book, int> el) {
				cout << el.first << " " << el.second << endl;
			});*/

			//cout << "Equal ranges from multimap" << endl;
			cout << endl << "Library" << endl;
			for (auto it = bookset.begin(); it != bookset.end(); it++) {
				auto ret = lib.equal_range(*it);
				cout << ret.first->first << endl;
				for (auto mit = ret.first; mit != ret.second; mit++)
					cout << mit->second << endl;
			}
		}
		break;
		case 0:
			f = false;
			break;
		}
	}



	system("pause");
	return 0;
}