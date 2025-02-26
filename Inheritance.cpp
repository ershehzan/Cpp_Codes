#include <iostream>  
using namespace std; 

// Define a class named 'student'
class student
{
public:
    string stu_name;  // Public member variable to store student name
    char stu_grade;   // Public member variable to store student grade

public:
    // Function to assign values to student name and grade
    void get_data(string name, char grade)
    {
        stu_name = name;
        stu_grade = grade;
    }

    // Function to display student details
    void display_data()
    {
        cout << "Student name is : " << stu_name << endl;
        cout << "Student grade is : " << stu_grade << endl;
    }
};

int main()
{
    student s, s1;  // Create two objects of the 'student' class

    // Using the get_data function to initialize student s1
    s1.get_data("Nand Kishor", 'A');
    s1.display_data();  // Display student s1 details

    // Directly assigning values to object 's' without using get_data function
    s.stu_name = "Binod";
    s.stu_grade = 'B';

    // Display student s details
    cout << "Student name is : " << s.stu_name << endl;
    cout << "Student grade is : " << s.stu_grade << endl;

    return 0;  
}
