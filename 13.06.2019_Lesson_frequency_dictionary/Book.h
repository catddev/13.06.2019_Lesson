﻿#pragma once
#include<string>
#include<iostream>
using namespace std;

class Book {
	string author;
	string title;
	string publish;
	int number;
public:
	Book();
	Book(string author, string title, string publish, int number);
	string getAuthor()const;//const для дальнейшего применения стандартных функций, чтобы значение не изменялось
	string getYear()const;
	string getTitle()const;//когда по ссылке передаем, конст убираем
	int getNumber()const;

	friend ostream& operator<<(ostream& os, Book obj);
	friend istream& operator>>(istream& is, Book& obj);
};
//предикатор


//функтор
//class setBook {
//public:
//	bool operator()(const Book& obj1, const Book& obj2) const {//predicator
//		return(obj1.getAuthor() < obj2.getAuthor());//по алфавиту
//	}
//};