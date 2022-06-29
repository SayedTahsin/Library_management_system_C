
void Admin(int x) // Admin Menu
{
    Student st[4]; //array of object
    Book bk[5];    // array of object
    if (x == 1) //! ALL student
    {
        system("cls");

        ifstream file;
        file.open("Student_info.txt", ios::binary | ios::app);
        cout << "\n\t" << left << setw(10) << "ID" << left << setw(30) << "Name" << left << setw(5) << "\tNumber Of Book\n\n";
        while (file.read(reinterpret_cast<char *>(&st[0]), sizeof(Student)))  // diplaying all std info running an loop in the studenti_info.txt file
        {
            st[0].report();
        }
        file.close();
        cout << endl;
        system("pause");
    }
    if (x == 2) //! Specifiq Student
    {
        system("cls");
        ifstream file;
        file.open("Student_info.txt", ios::binary | ios::in);
        int id;
        cout << "\n\tEnter student ID: ";
        cin >> id;
        system("cls");
        int f=0;
        while (file.read(reinterpret_cast<char *>(&st[1]), sizeof(Student))) //looping throung studein_info.txt file
        {
            if (id == st[1].return_id()) //cecking if given id is in the file or not
            {
                f=1;
                st[1].show_info();
                cout << "\n\tIssued Book: \n";
                st[1].ShowBOOk();
            }
        }
        if(!f)
        {
            cout<<"Incorrect info\n";
        }
        cout << endl;
        system("pause");
    }
    if (x == 3) //! modify
    {
        system("cls");
        fstream file;
        file.open("Student_info.txt", ios::binary | ios::in | ios::out);
        int id;
        cout << "\n\tEnter Student ID: ";
        cin >> id;
        cin.ignore();
        system("cls");
        int f=0;
        while (file.read(reinterpret_cast<char *>(&st[2]), sizeof(Student)))
        {
            if (st[2].return_id() == id)
            {
                f=1;
                st[2].modify();
                int pos = (-1) * static_cast<int>(sizeof(Student));
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<char *>(&st[2]), sizeof(Student)); //overwrittng info for given id
            }
        }
        file.close();
        if(!f)
        {
            cout<<"incorrect Info\n";
            system("pause");
        }

    }
    if (x == 4) //! delete
    {
        system("cls");
        ofstream f;
        ifstream file;
        cout << "\n\tStudent\'s ID: ";
        int id;
        cin >> id;
        file.open("Student_info.txt", ios::binary);
        f.open("temp.txt", ios::binary | ios::app);
        file.seekg(0, ios::beg);
        int flag=0;
        while (file.read(reinterpret_cast<char *>(&st[3]), sizeof(Student)))
        {
            if (st[3].return_id() != id)
                f.write(reinterpret_cast<char *>(&st[3]), sizeof(Student));
            else flag=1;
        }
        file.close();
        f.close();
        remove("Student_info.txt");
        rename("temp.txt", "Student_info.txt");
        if(flag)
            cout << "\n\tInformation Deleted...\n\n";
        else cout<<"Incorrect Info\n\n";
        system("pause");
    }
    if (x == 5) //! create book
    {
        system("cls");

        ofstream file;
        file.open("BOOK_info.txt", ios::binary | ios::app);
        bk[0].create_book_record();
        file.write(reinterpret_cast<char *>(&bk[0]), sizeof(Book));
        file.close();
    }
    if (x == 6) //! display book
    {

        system("cls");
        ifstream file;
        file.open("BOOK_info.txt", ios::binary | ios::app);
        cout << "\n\t" << left << setw(10) << "Book No" << left << setw(30) << "Book Name" << left << setw(30) << "Book Aurthor" << endl;
        while (file.read(reinterpret_cast<char *>(&bk[1]), sizeof(Book)))
        {
            bk[1].report();
        }

        file.close();
        cout << endl;
        system("pause");
    }
    if (x == 7) //! display Specific book
    {
        system("cls");
        ifstream file;
        file.open("BOOK_info.txt", ios::binary | ios::app);
        cout << "\n\tEnter Book No: ";
        int no;
        cin >> no;
        int ff=0;
        while (file.read(reinterpret_cast<char *>(&bk[2]), sizeof(Book)))
        {
            if (no == bk[2].retBookNo())
            {
                ff=1;
                bk[2].showBook();
            }
        }
        if(!ff){
            cout<<"incorrect Info\n";
            system("pause");
        }
        file.close();
    }
    if (x == 8) //! modify book
    {
        system("cls");
        fstream file;

        int no;
        file.open("Book_info.txt", ios::binary | ios::in | ios::out);
        cout << "\n\tEnter Book No.: ";
        cin >> no;
        cin.ignore();
        int ff=0;
        while (file.read(reinterpret_cast<char *>(&bk[3]), sizeof(Book)))
        {

            if (bk[3].retBookNo() == no)
            {
                ff=1;
                bk[3].modify();
                int pos = (-1) * static_cast<int>(sizeof(Book));
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<char *>(&bk[3]), sizeof(Book));
            }
        }
        if(!ff){
            cout<<"incorrect info\n\n";
            system("pause");
        }
        file.close();
    }
    if (x == 9) //! delete book
    {
        system("cls");
        ofstream f;
        ifstream file;
        cout << "\n\tBOOK No.: ";
        int no;
        cin >> no;
        int ff=0;
        file.open("Book_info.txt", ios::binary | ios::app);
        f.open("temp.txt", ios::binary | ios::app);
        file.seekg(0, ios::beg);
        while (file.read(reinterpret_cast<char *>(&bk[4]), sizeof(Book)))
        {
            if (bk[4].retBookNo() != no)
                f.write(reinterpret_cast<char *>(&bk[4]), sizeof(Book));
                else ff=1;
        }
        file.close();
        f.close();
        remove("Book_info.txt");
        rename("temp.txt", "Book_info.txt");
        if(!ff){
            cout<<"incorrect info\n";
        }else cout << "     Information Deleted...\n\n";

        system("pause");
    }
    if (x == 10) //! create librarian
    {
        LibraryManagement lm;
        lm.Register(2);
    }
    if (x == 11) //! format
    {
        system("cls");
        fstream file("Student_info.txt", ios::binary | ios::out);
        file.close();
        file.open("BOOK_info.txt", ios::binary | ios::out);
        file.close();
        cout << "\n\n\n\t\t!!!FORMATTED!!!\n\n";
        system("pause");
    }
}
