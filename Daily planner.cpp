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
	cout << "��� ������ ������������� ����������� ���������� ����������:" << endl << "\t��� ������ ������� ������� ����� \"��������\", ����� ������� ���� � ���� ��.��.����" << endl << "\t��� ��������� ������� ������� ����� \"���������\", ����� ������� ���� � ���� ��.��.����" << endl << "\t��� �������� ���� ���������� ������� ������� ����� \"�������\"" << endl << endl << "������� �������: ";
	while (true)
	{
		Day d;
		if (other != "")
			cout << "��� ������ ������� ������� ����� \"��������\", ����� ������� ���� � ���� ��.��.����" << endl << "��� ��������� ������� ������� ����� \"���������\", ����� ������� ���� � ���� ��.��.����" << endl << "��� �������� ���� ���������� ������� ������� ����� \"�������\"" << endl << endl << "������� �������: ";
		
		getline(cin, other);

		if (other == "��������" || other == "��������" || other == "������" || other == "������")
		{
			cout << "������� ����: ";
			string aa = "";
			getline(cin, aa);
			other = aa;
			cout << "������� �����: ";
			getline(cin, aa);
			other += "." + aa; cout << "������� ���: ";
			getline(cin, aa);
			other += "." + aa;
			d.id = other;
			cout << "������� �������: ";
			getline(cin, other);
			d.text = other;

			fn.open("Notes.txt", fstream::in | fstream::app | fstream::out);
			if (fn.is_open())
			{
				fn << d << "\n";
				fn.close();
				system("cls");
				cout << "\a\t������ ������� �������!\n" << endl;
				system("pause");
			}
			else
				cout << "\a\t��������� ������!!!" << endl;
		}
		if (other == "���������" || other == "���������")
		{
			string aa = "";
			cout << "\t��� ����� ��� �������?(��/���): ";
			getline(cin, other);
			if (other == "��" || other == "��")
			{
				d.id = "���";
				goto link;
			}
			cout << "������� ����: ";
			getline(cin, aa);
			other = aa;
			cout << "������� �����: ";
			getline(cin, aa);
			other += "." + aa; cout << "������� ���: ";
			getline(cin, aa);
			other += "." + aa;
			d.id = other;
		link:
			system("cls");
			cout << "\t���� �������:\n" << endl;
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
					if (d.id == "���" || d.id == "���")
						cout << temp.id << "\a " << temp.text << "\n";
				}
				if (d.id == "���" || d.id == "���")
					system("pause");
				
				fn.close();
			}
			else
				cout << "\a\t��������� ������!!!" << endl;
		}
		if (other == "�������" || other == "�������")
		{
			cout << "\t�����?(��/���): ";
			getline(cin, other);
			if (other == "��" || other == "��")
			{
				ofstream of;
				of.open("Notes.txt");
				of << "";
				of.close();
				system("cls");
				cout << "\a\t������ ������� �������!\n\n\n" << endl;
				system("pause");
			}
		}
		if (other == "�������" || other == "�������")
		{
			fn.close();
			break;
		}
		system("cls");
	}
	if (other == "�������" || other == "�������")
		system("cls");
}