class Student : public User  //inherited from use class
{
    int token;
    int book_List[100];

public:
    void create_account() //polimorphism
    {
        system("cls");
        cout << "\n\tStudent ID   : ";
        cin >> id;
        cin.ignore();
        cout << "\n\tStudent Name : ";
        cin.getline(name, 50);
        cout << "\n\tpin : ";
        cin >> pin;
        cout << endl;
        token = 0;
        book_List[token] = 0;
        cout << "\tAccount Created...\n\n\t";
        system("pause");
    }
    void report() //polimorphism
    {
        cout << "\t" << left << setw(10) << id << left << setw(30) << name << left << setw(5) << "\t" << token << endl;
    }
    void show_info()
    {
        system("cls");
        cout << endl;
        cout << "\tStudent\'s ID           : " << id << endl;
        cout << "\tStudent\'s Name         : " << name << endl;
        cout << "\tNumber of Book\'s issued: " << token << endl;
    }
    void ShowBOOk()
    {
        Book bk;
         cout << "\t" << left << setw(10) << "Book No" << left << setw(30) << "Book Name" << left << setw(30) << "Writer" << endl;

        for (int i = 0; i < token; i++)
        {
            ifstream file("BOOK_info.txt", ios::binary);
            file.seekg(0, ios::beg);

            while (file.read((char *)&bk, sizeof(Book)))
            {
                if (book_List[i] == bk.retBookNo())
                {

                    bk.report();
                    file.close();
                    break;
                }
            }
        }
    }
    void modify() //poly
    {
        system("cls");
        cout << "\n\tStudent ID: " << id << endl;
        cout << "\tModify Student\'s name: ";
        cin.getline(name, 50);
        cout << "\n\tInformation updated...\n\n";
        system("pause");
    }
    void issue(int bkn)
    {
        book_List[token] = bkn;
        token++;
    }
    int Depos(int bkn)
    {
        int f=0;
        for (int i = 0; i < token; i++)
        {
            if(book_List[i]==bkn)
            {
                bkn=i;
                f=1;
                break;
            }

        }
        if(f)
        {
            for(int i=bkn; i<token-1; i++)
            {
                book_List[i] = book_List[i + 1];
            }
            token--;
            return 1;
        }
        else
        {
            cout<<"book Id doesn't Exist in your List.\n";
            system("pause");
            return 0;
        }
    }
};
