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

bool asc(const Book& obj1, const Book& obj2) {
	//return (obj1.getNumber() < obj2.getNumber()); //будет сортировать по кол-ву экземпляров
	return (obj1.getYear() < obj2.getYear()); // чтобы работало по году нужно чтобы в прототипе getYear() было CONST!
}

void remove_by_property(multimap<string, Book>& mb, string prop) {
	string tmp;
	cout << "Enter your property's value" << endl;
	cin.ignore();//!
	getline(cin, tmp, '\n');

	if (prop == "author") {

			for (auto it = mb.begin(); it != mb.end(); it++) {
				if (it->second.getAuthor() == tmp) {
					if (it != mb.end()) {
						mb.erase(it);
						if (!mb.empty())
							it = mb.begin();
						else break;
					}
				}
			}
	}
	else if (prop == "title") {
		for (auto it = mb.begin(); it != mb.end(); it++)
			if (it->second.getTitle() == tmp) {
				if (it != mb.end()) {
					mb.erase(it);
					if (!mb.empty())
						it = mb.begin();
					else break;
				}
			}
	}
	else if (prop == "year") {
		for (auto it = mb.begin(); it != mb.end(); it++)
			if (it->second.getYear() == tmp) {
				if (it != mb.end()) {
					mb.erase(it);
					if (!mb.empty())
						it = mb.begin();
					else break;
				}
			}
	}
}




int main() {
	//ifstream in_file("dict.txt");
	//map<string, int> d;

	//string s;
	//while (!in_file.eof()) {
	//	in_file >> s;//first<string>
	//	d[s]++;//second<int> ++ by [key=s]
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
	//set<string> sd;//better for dictionary than map, as contains only unique values

	//string str;
	//while (!read_file.eof()) {
	//	read_file >> str;
	//	transform(str.begin(), str.end(), str.begin(), tolower);//string to lower!!!
	//	sd.insert(str);//formulate dictionary
	//}
	//for_each(sd.begin(), sd.end(), [](string el) {
	//	cout << el << endl;
	//});
	//cout << endl;

	//ifstream text("check_text.txt");
	//while (!text.eof()) {
	//	text >> str;
	//	v.push_back(str);//vector of the text word by word to check
	//}

	//for (auto it = v.begin(); it != v.end(); it++)
	//{
	//	auto fit = sd.find(*it);//fit - find_iterator, check every value of vector (v[i]=*it)
	//	if (fit != sd.end())
	//		continue;//means it has found this word in the dictionary and it's correct
	//	else {
	//		int choice;
	//		cout << "There is no word \"" << *it << "\" in the dictionary" << endl;// \" to print ""
	//		cout << "Enter 1 to change this word" << endl;
	//		cout << "Enter 2 to add this word to the dictionary" << endl;
	//		cin >> choice;

	//		switch (choice) {
	//		case 1:
	//		{
	//			string tmp = *it;//saving value to the string type
	//			string str;
	//			cout << "Enter new word" << endl;
	//			cin >> str;
	//			replace(v.begin(), v.end(), tmp, str);//replace saved value to the new one through whole vector
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
	//	cout << el << " ";
	//});
	//cout << endl;

	//cout << endl << "DICTIONARY renewed" << endl;
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
	multimap<string, Book> lib;//author is a key
	set<string> bookset;//set of unique multimap's keys!
	string str1;
	int i = 0;

	string author, title, publish;
	int number;
	vector<Book> b1;

	while (!lib_file.eof()) {
		getline(lib_file, author, '#');
		getline(lib_file, title, '#');
		getline(lib_file, publish, '#');
		lib_file >> number;
		lib_file.ignore();
		bookset.insert(author);
		lib.insert(pair<string, Book>(author, Book(author, title, publish, number)));
		b1.push_back(Book(author, title, publish, number));
		
	}
	//cout << endl;
	//for_each(lib.begin(), lib.end(), [](pair<string, Book> p) {
	//	cout << p.second << " " << p.first << endl;
	//});

	while (true) {
		cout << endl << "Enter 1 to remove a book" << endl;
		cout << "Enter 2 to add a book" << endl;
		cout << "Enter 3 to get books by author" << endl;
		cout << "Enter 4 to get books by publishing year" << endl;
		cout << "Enter 5 to print the book list" << endl;
		cout << "Enter 0 to exit" << endl;
		int choice1;
		cin >> choice1;
		if (choice1 == 0)
			break;
		Book yourBook;

		switch (choice1) {
		case 1:
		{
			//cout << "Enter full book description to erase" << endl;
			//cin.ignore();
			////cin >> yourBook;
			///*	auto it = lib.find(yourBook.getAuthor());
			//if (it != lib.end()) {
			//	lib.erase(it);//erasing by book info/author
			//}*/

			//cout << "Enter author" << endl;
			//getline(cin, author, '\n');
			////cin>>year;
			//cout << "Enter book's title" << endl;
			//getline(cin, title, '\n');

			//auto it = lib.find(author);
			//if (it != lib.end()) {
			//	if(it->second.getTitle()==title)//erasing by title
			//	lib.erase(it);
			//}

			//or erase by filter!
			string property;
			cout << "Enter \"author\" to erase by author" << endl;
			cout << "Enter \"title\" to erase by title" << endl;
			cout << "Enter \"year\" to erase by publishing year" << endl;
			cin >> property;

			remove_by_property(lib, property);

			if (!lib.empty()) {
				cout << endl;
				for_each(lib.begin(), lib.end(), [](pair<string, Book> p) {
					cout << p.first << " " << p.second << endl;
				});
			}
			else
				cout << "EMPTY MAP!" << endl;

		}
		break;
		case 2:
		{
			cout << "Enter full book description to add to the library database" << endl;
			cin.ignore();
			cin >> yourBook;
			lib.insert(pair<string, Book>(yourBook.getAuthor(), yourBook));
			bookset.insert(yourBook.getAuthor());// renew set!!
		}
		break;
		case 3:
		{
			cout << "Enter an author" << endl;
			cin.ignore();
			getline(cin, author, '\n');

			for (auto it = bookset.begin(); it != bookset.end(); it++) {//every *it - unique author
				auto ret = lib.equal_range(*it); //*it is a key for multimap.
				//Equal_range sets only 2 ptr - first (when we "first" meet author in the multimap, and "second" when it is last book of the author in the multimap lib
				if (*it == author)//by author
					for (auto mit = ret.first; mit != ret.second; mit++)// mit is iterator for multimap
						cout << mit->second << endl;
			}
		}
		break;
		case 4:
		{
			cout << "Enter publishing year" << endl;
			cin >> publish;
			for (auto it = lib.begin(); it != lib.end(); it++) {
				if (it->second.getYear() == publish)
					cout << it->first << " " << it->second << endl;
			}
		}
		break;
		case 5:
		{
			//cout << "Equal ranges from multimap" << endl;
			
			if (!lib.empty()) {//!!!!!
				cout << endl << "БИБЛИОТЕКА:" << endl;
				for (auto it = bookset.begin(); it != bookset.end(); it++) {
					auto ret = lib.equal_range(*it);
					cout << ret.first->first << endl;
					for (auto mit = ret.first; mit != ret.second; mit++)
						cout << mit->second << endl;
				}
			}
			else
				cout << "EMPTY MAP!" << endl;
		}
		break;
		}
	}

	sort(b1.begin(), b1.end(), asc); //bool asc
	for_each(b1.begin(), b1.end(), [](Book b) {
		cout << b.getAuthor() << " " << b << endl;
	});

	system("pause");
	return 0;
}