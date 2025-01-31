#include <iostream>
using namespace std;
class student
{
public:
    string stu_name;
    char stu_grade;

public:
    void get_data(string name, char grade)
    {
        stu_name = name;
        stu_grade = grade;
    }
    void display_data()
    {
        cout << "Student name is : " << stu_name << endl;
        cout << "Student grade is : " << stu_grade << endl;
    }
};
int main()
{
    student s, s1;
    s1.get_data(" Nand kishor ", 'A');
    s1.display_data();
    s.stu_name = " Binod";
    s.stu_grade = 'B';
    cout << "student name is : " << s.stu_name << endl;
    cout << "student grade is : " << s.stu_grade << endl;
}
