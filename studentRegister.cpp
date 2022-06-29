
void LibraryManagement::Register(int x)
{
    if (x == 1)
    {
        system("cls");
        Student st;
        ofstream file;
        file.open("Student_info.txt", ios::binary | ios::app);
        st.create_account();
        file.write(reinterpret_cast<char *>(&st), sizeof(Student));
        file.close();
    }
    if(x==2){
     system("cls");
        Librarian lb;
        ofstream file;
        file.open("Lib_info.txt", ios::binary | ios::app);
        lb.create_account();
        file.write(reinterpret_cast<char *>(&lb), sizeof(Librarian));
        file.close();
    }
}