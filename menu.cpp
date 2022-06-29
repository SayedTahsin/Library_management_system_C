int StudentMenu();
int LibrarianMenu();
int menu()
{
    LibraryManagement lm;
    while (1)
    {
        system("cls");
        cout << "User Type\n";
        cout << "1.student\n";
        cout << "2.Librarian\n";
        cout << "3.Exit\n";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            system("cls");
            cout << "1. Login\n";
            cout << "2. register\n";
            cout << "0. backTo main menu\n";
            cin >> ch;
            if (ch == 1)
            {
                if (lm.login(1))
                {
                    StudentMenu();
                }
                else
                {
                    cout << "Incorrect Info\n";
                    system("pause");
                }
            }
            else if (ch == 2)
            {
                lm.Register(1);
            }
            else if (ch == 0)
            {
                continue;
            }
            else
            {
                cout << "incorrect Info\n";
                system("pause");
            }
        }
        else if (ch == 2)
        {
            system("cls");
            cout << "librrian Menu\n";
            cout << "1.Login\n";
            cout << "0.back to mainmenu\n";
            cin >> ch;
            if (ch == 1)
            {
                if (lm.login(2))
                {
                    while (1)
                    {
                        int x = LibrarianMenu();
                        if (x == 0)
                            break;
                        Admin(x);
                    }
                }
                else
                {
                    cout << "Incorrect Info\n";
                    system("pause");
                }
            }
            else if (ch == 0)
            {
                continue;
            }
            else
            {
                cout << "incorrect Info\n";
                system("pause");
            }
        }
        else if (ch == 3)
        {
            system("cls");
            cout<<"Thank You\n";
            exit(1);
        }
        else
        {
            cout << "wrong Input\n";
            system("pause");
        }
    }
}

int StudentMenu()
{

    while (1)
    {
        system("cls");
        cout << "Student Menu\n";
        cout << "1.Book Issue\n";
        cout << "2.Book Return\n";
        cout << "0.Back\n";
        cout<<"Enter Option: ";
        cin.ignore();
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            bookissue();
        }
        else if (ch == 2)
        {
            Deposit();
        }
        else if (ch == 0)
            return 0;
        else
        {
            cout << "wrong Input\n";
            system("pause");
        }
    }
}
int LibrarianMenu()
{
    while (1)
    {
        system("cls");
        cout << "\n\tADMIN PANEL\n";
        cout << "\t------------";
        cout << "\n\t 1. Display All Student's Record.";
        cout << "\n\t 2. Display specific Student's Record.";
        cout << "\n\t 3. Modify Student's Record.";
        cout << "\n\t 4. Delete Student's Record.";
        cout << "\n\t 5. Create Book Record.";
        cout << "\n\t 6. Display Book\'s.";
        cout << "\n\t 7. Display Specific Book\'s.";
        cout << "\n\t 8. Modify Book.";
        cout << "\n\t 9. Delete Book.\n";
        cout << "\n\t 10. create Librarian account.\n";
        cout << "\n\t 11. FORMAT ALL Info.\n";
        cout << "\t_______________________";
        cout << "\n\t 0. Back to Main Menu.\n\n";
        cout << "\tEnter Choice: ";
        int i;
        cin >> i;
        if (i < 0 || i > 11)
        {
            cout << "\n\tInvalid Input\n";
            system("pause");
        }
        else
        {
            return i;
        }
    }
}
