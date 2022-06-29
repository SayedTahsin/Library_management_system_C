class Book
{
    int bookNo;
    char bookName[50], aurthor[50];

public:
    void create_book_record()
    {
        system("cls");
        cout << endl;
        cout << "\tEnter Book No    : ";
        cin >> bookNo;
        cin.ignore();
        cout << "\tEnter Book Name  : ";
        cin.getline(bookName, 50);
        cout << "\tEnter Writer Name: ";
        cin.getline(aurthor, 50);

        cout << "\n\tInformation updated...\n\n";
        system("pause");
    }
    void showBook()
    {
        system("cls");
        cout << "\n\tBook Number  : " << bookNo;
        cout << "\n\tBook Name    : " << bookName;
        cout << "\n\tBook Writer  : " << aurthor;

        cout << endl
             << endl;
        system("pause");
    }
    int retBookNo()
    {
        return bookNo;
    }
    void report() //poly
    {
        cout << "\t" << left << setw(10) << bookNo << left << setw(30) << bookName << left << setw(30) << aurthor << endl;
    }
    void modify() //poly
    {
        system("cls");
        cout << "\n\tBook Number  : ";
        cout << bookNo << endl;
        cout << "\n\tBook Name    : ";
        cin.getline(bookName, 50);
        cout << "\n\tBook Writer  : ";
        cin.getline(aurthor, 50);
        cout << "\n\tInformation Updated...\n\n";
        system("pause");
    }
    void Show_name()
    {
        cout << bookName << endl;
    }
};
