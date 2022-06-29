class Librarian : public User  //inherited from user class
{

public:
    void create_account()
    {
        system("cls");
        cout << "\n\tLibraian ID   : ";
        cin >> id;
        cin.ignore();
        cout << "\n\tLibrarian Name : ";
        cin.getline(name, 50);
        cout << "\n\tpin : ";
        cin >> pin;
        cout << endl;
        cout << "\tAccount Created...\n\n\t";
        system("pause");
    }
 };
