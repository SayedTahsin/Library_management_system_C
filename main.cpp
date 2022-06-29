#include <bits/stdc++.h>
using namespace std;
#include "intro.h"
#include "LibraryManegementClass.h"
#include "Book.h"
#include "User.h"
#include "Student.h"
#include "Librarian.h"
#include "studentLogin.cpp"
#include "studentRegister.cpp"
#include "Admin.cpp"
#include "bookIssue.cpp"
#include "BookDepos.cpp"
#include "menu.cpp"

int main()
{
    system("color 60");
    intro();
    while (1)
    {
         menu();
    }
}
