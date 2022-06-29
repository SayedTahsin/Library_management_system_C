void bookissue()
{
    system("cls");
    int id, bkn, pin;
    cout << "\n\tEnter Student ID: ";
    cin >> id;
    cout << "\n\tEnter Pin: ";
    cin >> pin;
    int f=0;
    Student st;
    fstream file("Student_info.txt", ios::binary | ios::in);
    system("cls");
    while (file.read((char *)&st, sizeof(Student)))
    {
        if (st.return_id() == id && st.return_pin() == pin)
        {
            f=1;
            st.show_info();
        }
    }
    file.close();
    if(!f)
    {
        cout<<"incorrect info";
        system("pause");
        return;
    }
    cout << endl;
    Book bk;
    cout << "\tBook List: \n";
    file.open("Book_info.txt", ios::binary | ios::in);
    cout << "\t" << left << setw(10) << "Book No" << left << setw(30) << "Book Name" << left << setw(30) << "Writer" << endl;
    while (file.read((char *)&bk, sizeof(Book)))
    {
        bk.report();
    }
    file.close();
    while(1)
    {
        file.open("Book_info.txt", ios::binary | ios::in);
        cout << "\n\tEnter Book No to Issue(Enter 0 to Back): ";
        cin >> bkn;
        f=0;
        while (file.read((char *)&bk, sizeof(Book)))
        {
            if(bk.retBookNo()==bkn)
            {
                f=1;
                break;
            }
        }
        file.close();
        if(bkn==0)return;
        if(f==0)
            cout<<"Wrong input.";
        else break;
    }
    file.open("Student_info.txt", ios::binary | ios::out | ios::in);
    while (file.read((char *)&st, sizeof(Student)))
    {
        if (st.return_id() == id)
        {
            int pos = (-1) * static_cast<int>(sizeof(Student));
            file.seekp(pos, ios::cur);
            st.issue(bkn);
            file.write((char *)&st, sizeof(Student));
        }
    }
    file.close();
    cout<<"Book Issued...\n";
    system("pause");
}
