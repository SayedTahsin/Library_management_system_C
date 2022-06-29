void Deposit()
{
    system("cls");
    cout<<"\n\tEnter Student ID: ";
    int id,bkn,pin;
    cin>>id;
    cout<<"\n\tEnter Pin: ";
    cin>>pin;
    Student st;
    int f=0;
    fstream file("Student_info.txt",ios::binary|ios::in);

    while(file.read((char*)&st,sizeof(Student)))
    {
        if(id==st.return_id() && pin==st.return_pin())
        {
            f=1;
            st.show_info();
            st.ShowBOOk();
        }
    }
    if(!f){
        cout<<"incorrect info";
        system("pause");
        return;
    }

    file.close();


    cout<<"\n\tEnter Book No to Deposit(Enter 0 to Back): ";
    cin>>bkn;
    if(bkn==0)return;
    f=0;
    file.open("Student_info.txt",ios::binary|ios::in|ios::out);
    while(file.read((char*)&st,sizeof(Student)))
    {
        if(id==st.return_id())
        {
           f= st.Depos(bkn);
            int pos=(-1)*static_cast<int>(sizeof(Student));
            file.seekp(pos,ios::cur);
            file.write(reinterpret_cast<char*>(&st),sizeof(Student));
        }
    }
    file.close();
    if(f){
    cout<<"\n\tDeposit complete...\n\n";
    system("pause");
    }
}
