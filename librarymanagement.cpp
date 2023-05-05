#include <bits/stdc++.h>
using namespace std;
class book
{
public:
 int book_id;
 char author[20];
 char name[20];
 void getdata()
 {
 cout << "Enter book id :- ";
 cin >> book_id;
 cin.ignore();
 cout << "Enter name of the author :- ";
 cin.getline(author, 20);
 cout << "Enter name of the book :- ";
 cin.getline(name, 20);
 }
 void showdata()
 {
 cout << "Book id :- " << book_id << endl;
 cout << "Author name :- " << author << endl;
 cout << "Book name :- " << name << endl;
 }
 void add_record()
 {
 fstream file;
 file.open("Books.txt", ios::app);
 book b1;
 b1.getdata();
 file.write((const char *)&b1, sizeof(b1));
 file.close();
 }
 void print()
{
 fstream file;
 file.open("Books.txt", ios::in);
 book b1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 b1.showdata();
 cout << endl;
 }
 file.close();
 }
 void printit()
 {
 int todel;
 cout << "Enter the book id of the book to print the record of :- ";
 cin >> todel;
 fstream file;
 file.open("Books.txt", ios::in);
 book b1;
 bool check = 1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 if (file)
 {
 if (b1.book_id == todel)
 {
 check = 0;
 b1.showdata();
 }
 }
}
 if (check)
 cout << "Record not listed..\n";
 file.close();
 }
 void Deletee()
 {
 int todel;
 cout << "Enter the book id of the book to delete the record of :- ";
 cin >> todel;
 fstream file;
 file.open("Books.txt", ios::in);
 fstream tfile;
 tfile.open("temp.txt", ios::app);
 book b1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 if (file)
 {
 if (b1.book_id == todel)
 continue;
 else
 tfile.write((char *)&b1, sizeof(b1));
 }
 }
 tfile.close();
 file.close();
 remove("Books.txt");
 rename("temp.txt", "Books.txt");
 }
void modify()
 {
 int tomod;
 cout << "Enter the book id of the book to modify the record of :- ";
 cin >> tomod;
 fstream file;
 file.open("Books.txt", ios::in);
 fstream tfile;
 tfile.open("temp.txt", ios::app);
 book b1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 if (file)
 {
 if (b1.book_id == tomod)
 {
 b1.getdata();
 tfile.write((char *)&b1, sizeof(b1));
 continue;
 }
 else
 tfile.write((char *)&b1, sizeof(b1));
 }
 }
 tfile.close();
 file.close();
 remove("Books.txt");
 rename("temp.txt", "Books.txt");
 }
};
class student
{
 char name[25];
 int adm_no;
 char classs[100];
 int books;
public:
 void getdata()
 {
 cout << "Enter student name :- ";
 cin.ignore();
 cin.getline(name, 25);
 cout << "Enter admission number of the student :- ";
 cin >> adm_no;
 cout << "Enter class of the student :- ";
 cin.ignore();
 cin.getline(classs, 100);
 cout << "Enter number of books issued to the student :- ";
 fflush(stdin);
 cin >> books;
 }
 void showdata()
 {
 cout << "Name :- " << name << endl;
 cout << "Admission number:- " << adm_no << endl;
 cout << "Class :- " << classs << endl;
 cout << "Number of books issued :- " << books << endl;
 }
 void add_record()
{
 fstream file;
 file.open("Students.txt", ios::app);
 student b1;
 b1.getdata();
 file.write((const char *)&b1, sizeof(b1));
 file.close();
 }
 void print()
 {
 fstream file;
 file.open("Students.txt", ios::in);
 student b1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 b1.showdata();
 cout << endl;
 }
 file.close();
 }
 void printit()
 {
 int todel;
 cout << "Enter the admission number of the student to print the record of :- ";
 cin >> todel;
 fstream file;
 file.open("students.txt", ios::in);
 student b1;
 bool check = 1;
 while (file.read((char *)&b1, sizeof(b1)))
{
 if (file)
 {
 if (b1.adm_no == todel)
 {
 check = 0;
 b1.showdata();
 break;
 }
 }
 }
 if (check)
 cout << "Record not listed..\n";
 file.close();
 }
 void Deletee()
 {
 int todel;
 cout << "Enter the admission number of the student to delete the record of :- ";
 cin >> todel;
 fstream file;
 file.open("Students.txt", ios::in);
 fstream tfile;
 tfile.open("temp.txt", ios::app);
 student b1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 if (file)
 {
 if (b1.adm_no == todel)
continue;
 else
 tfile.write((char *)&b1, sizeof(b1));
 }
 }
 tfile.close();
 file.close();
 remove("Students.txt");
 rename("temp.txt", "Students.txt");
 }
 void modify()
 {
 int tomod;
 cout << "Enter the admission number of the student to modify the record of :- ";
 cin >> tomod;
 fstream file;
 file.open("Students.txt", ios::in);
 fstream tfile;
 tfile.open("temp.txt", ios::app);
 student b1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 if (file)
 {
 if (b1.adm_no == tomod)
 {
 b1.getdata();
 tfile.write((char *)&b1, sizeof(b1));
 continue;
 }
else
 tfile.write((char *)&b1, sizeof(b1));
 }
 }
 tfile.close();
 file.close();
 remove("Students.txt");
 rename("temp.txt", "Students.txt");
 }
 void issue()
 {
 int addm, idd;
 cout << "Enter the addmission number of the student to issue the book to :- ";
 cin >> addm;
 fstream file;
 file.open("Students.txt", ios::in);
 student b1;
 bool check = 1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 if (file)
 {
 if (b1.adm_no == addm)
 {
 if (b1.books > 3)
 {
 cout << "Limit to issue books exceeded ..\nCannot issue more books..\n";
 check = 0;
 return;
 }
 }
}
 }
 cout << "Enter the book id of the book to be issued :- ";
 cin >> idd;
 fstream file2;
 file2.open("Books.txt", ios::in);
 book b2;
 bool check2 = 0;
 while (file2.read((char *)&b2, sizeof(b2)))
 {
 if (b2.book_id == idd)
 {
 check2 = 1;
 break;
 }
 }
 if (!check2)
 cout << "No Book with id " << idd << " present in library" << endl;
 else
 {
 b1.books++;
 fstream newfile;
 string date;
 fflush(stdin);
 cout << "Enter the date on which the book is issued :- ";
 fflush(stdin);
 getline(cin, date);
 newfile.open("issue_record.txt", ios::app);
 newfile << "Student with admission number :- " << b1.adm_no << " issued book with book id :- " << idd << " on date :- " << date;
}
 }
 void deposit()
 {
 int addm, idd;
 cout << "Enter the addmission number of the student to issue the book to :- ";
 cin >> addm;
 fstream file;
 file.open("Students.txt", ios::in);
 student b1;
 bool check = 1;
 while (file.read((char *)&b1, sizeof(b1)))
 {
 if (file)
 {
 if (b1.adm_no == addm)
 {
 b1.books--;
 break;
 }
 }
 }
 cout << "Enter the book id of the book returned :- ";
 cin >> idd;
 string date;
 fflush(stdin);
 cout << "Enter the date on which the book is returned :- ";
 getline(cin, date);
 fstream newfile;
 newfile.open("deposit_record.txt", ios::app);
 fflush(stdin);
newfile << "Student with admission number :- " << b1.adm_no << " returned book with book id :- " << idd << " on date :- " << date;
 }
};
int main()
{
 book b1;
 student s1;
 int choice;
 string username = "admin", pwd = "adminpwd";
 cout << "\t**************" << endl;
 cout << "\t\t WELCOME TO LIBRARY" << endl;
 cout << "\t**************" << endl;
 char c1;
 cout << "Do you want to enter admin portal(Y/N) :- ";
 cin >> c1;
 string uname, pwwd;
label:
 if (c1 == 'Y' || c1 == 'y')
 {
 cout << "Enter username :- ";
 fflush(stdin);
 cin >> uname;
 if (username.compare(uname) != 0)
 {
 cout<<username.compare(uname)<<endl;
 cout << "USERNAME INCORRECT ..Please Reneter \n\n";
 goto label;
 }
 cout << "Enter password :- ";
 fflush(stdin);
cin >> pwwd;
 if (pwwd.compare(pwd) != 0)
 {
 cout << "Password INCORRECT ..Please Re-Enter :- \n\n";
 goto label;
 }
 cout << "Enter 1 to enter book record\nEnter 2 to enter student record\nEnter 3 to print the books file\nEnter 4 to print the student file \nEnter 5 to Modify books file\nEnter 6 to Modify Student File\nEnter 7 to delete book record\nEnter 8 to delete student record\nEnter 9 to print the record of a specific book\nEnter 10 print record the record of a specific student\nEnter any other choice to exit\n";
 do
 {
 cout << "Enter the choice :- ";
 cin >> choice;
 switch (choice)
 {
 case 1:
 b1.add_record();
 break;
 case 2:
 s1.add_record();
 break;
 case 3:
 b1.print();
 break;
 case 4:
 s1.print();
 break;
 case 5:
 b1.modify();
 break;
case 6:
 s1.modify();
 break;
 case 7:
 b1.Deletee();
 break;
 case 8:
 s1.Deletee();
 break;
 case 9:
 b1.printit();
 break;
 case 10:
 s1.printit();
 break;
 }
 } while (choice <= 10 && choice != 0);
 }
 else
 {
 cout << "Enter 1 to issue a book\nEnter 2 to deposit a book\nEnter any other choice to exit\n";
 do
 {
 cout << "Enter your choice :- ";
 cin >> choice;
 switch (choice)
 {
 case 1:
 s1.issue();
break;
 case 2:
 s1.deposit();
 break;
 }
 } while (choice == 1 || choice == 2);
 }
 return 0;
}
