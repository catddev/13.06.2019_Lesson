#include "Book.h"

Book::Book()
{
	author = "";
	title = "";
	publish = "";
	number = 0;
}

Book::Book(string author, string title, string publish, int number)
{
	this->author = author;
	this->title = title;
	this->publish = publish;
	this->number = number;
}

string Book::getAuthor() const
{
	return author;
}

string Book::getYear() const
{
	return publish;
}

bool Book::operator<(const Book & obj) const
{
	return(this-> publish > obj.publish);//> не ошибка, а чтобы сет выводил по наименьшей цене
}

ostream & operator<<(ostream & os, Book obj)
{
	os << obj.author << " " << obj.title << " " << obj.publish << " " << obj.number;
	return os;
}

istream & operator>>(istream & is, Book & obj)
{
	getline(is, obj.author, '#');
	getline(is, obj.title, '#');
	getline(is, obj.publish, '#');
	is >> obj.number;
	return is;
}