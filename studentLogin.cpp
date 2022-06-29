bool LibraryManagement::login(int x)
{
    if (x == 1)
    {
        system("cls");
        Student st;
        ifstream file;
        file.open("Student_info.txt", ios::binary | ios::in);
        int id, pin;
        cout << "\n\tEnter student ID: ";
        cin >> id;
        cout << "\n\tEnter pin: ";
        cin >> pin;
        system("cls");
        while (file.read(reinterpret_cast<char *>(&st), sizeof(Student)))
        {
            if (id == st.return_id() && pin == st.return_pin())
            {
                return 1;
            }
        }
    }
    if (x == 2)
    {
        system("cls");
        Librarian lb;
        ifstream file;
        file.open("Lib_info.txt", ios::binary | ios::in);
        int id, pin;
        cout << "\n\tEnter Librarian ID: ";
        cin >> id;
        cout << "\n\tEnter pin: ";
        cin >> pin;
        system("cls");
        while (file.read(reinterpret_cast<char *>(&lb), sizeof(Librarian)))
        {
            if (id == lb.return_id() && pin == lb.return_pin())
            {
                return 1;
            }
        }
    }
    return 0;
}