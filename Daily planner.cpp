#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Day
{
public:
	string id, text;
};

ostream& operator << (ostream& os, const Day& d)
{
	os << d.id << " " << d.text;
	return os;
}

istream& operator >> (istream& is, Day& d)
{
	char ch;
	is >> d.id;
	d.text = "";
	while (is.get(ch))
	{
		if (ch == '\n')
			break;
		
		d.text += ch;
	}
	return is;
}

int main()
{
	setlocale(LC_ALL, "ru");
	system("chcp 1251 >> null");
	fstream fn;
	string other = "";
	cout << "Для начала использования ежедневника прочитайте инструкцию:" << endl << "\tДля записи заметки введите слово \"Записать\", далее введите дату в виде ДД.ММ.ГГГГ" << endl << "\tДля прочтения заметок введите слово \"Прочитать\", далее введите дату в виде ДД.ММ.ГГГГ" << endl << "\tДля удаления ВСЕХ предыдущих записей введите слово \"Удалить\"" << endl << endl << "Введите команду: ";
	while (true)
	{
		Day d;
		if (other != "")
			cout << "Для записи заметки введите слово \"Записать\", далее введите дату в виде ДД.ММ.ГГГГ" << endl << "Для прочтения заметок введите слово \"Прочитать\", далее введите дату в виде ДД.ММ.ГГГГ" << endl << "Для удаления ВСЕХ предыдущих записей введите слово \"Удалить\"" << endl << endl << "Введите команду: ";
		
		getline(cin, other);

		if (other == "Записать" || other == "записать" || other == "Запись" || other == "запись")
		{
			cout << "Введите день: ";
			string aa = "";
			getline(cin, aa);
			other = aa;
			cout << "Введите месяц: ";
			getline(cin, aa);
			other += "." + aa; cout << "Введите год: ";
			getline(cin, aa);
			other += "." + aa;
			d.id = other;
			cout << "Введите заметку: ";
			getline(cin, other);
			d.text = other;

			fn.open("Notes.txt", fstream::in | fstream::app | fstream::out);
			if (fn.is_open())
			{
				fn << d << "\n";
				fn.close();
				system("cls");
				cout << "\a\tЗапись успешно внесена!\n" << endl;
				system("pause");
			}
			else
				cout << "\a\tПроизошла ошибка!!!" << endl;
		}
		if (other == "Прочитать" || other == "прочитать")
		{
			string aa = "";
			cout << "\tВам нужны ВСЕ заметки?(да/нет): ";
			getline(cin, other);
			if (other == "Да" || other == "да")
			{
				d.id = "Все";
				goto link;
			}
			cout << "Введите день: ";
			getline(cin, aa);
			other = aa;
			cout << "Введите месяц: ";
			getline(cin, aa);
			other += "." + aa; cout << "Введите год: ";
			getline(cin, aa);
			other += "." + aa;
			d.id = other;
		link:
			system("cls");
			cout << "\tВаши заметки:\n" << endl;
			fn.open("Notes.txt", fstream::in | fstream::app | fstream::out);
			if (fn.is_open())
			{
				Day temp;
				while (true)
				{
					fn >> temp;
					if (fn.eof())
						break;
					
					if (d.id == temp.id)
					{
						cout << "\a" << temp.text << "\n\n";
						system("pause");
					}
					if (d.id == "Все" || d.id == "все")
						cout << temp.id << "\a " << temp.text << "\n";
				}
				if (d.id == "Все" || d.id == "все")
					system("pause");
				
				fn.close();
			}
			else
				cout << "\a\tПроизошла ошибка!!!" << endl;
		}
		if (other == "Удалить" || other == "удалить")
		{
			cout << "\tТочно?(да/нет): ";
			getline(cin, other);
			if (other == "да" || other == "Да")
			{
				ofstream of;
				of.open("Notes.txt");
				of << "";
				of.close();
				system("cls");
				cout << "\a\tЗаписи успешно удалены!\n\n\n" << endl;
				system("pause");
			}
		}
		if (other == "Закрыть" || other == "закрыть")
		{
			fn.close();
			break;
		}
		system("cls");
	}
	if (other == "Закрыть" || other == "закрыть")
		system("cls");
}