class User{ //parent class to Student class & librarian class
public:
    int id,pin;
    char name[50];

    int return_id()
    {
        return id;
    }
    int return_pin()
    {
        return pin;
    }
};
