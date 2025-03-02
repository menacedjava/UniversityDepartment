#include <iostream>
#include <vector>
using namespace std;


class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void showInfo() {
        cout << "Ism: " << name << ", Yosh: " << age << endl;
    }
};


class Student : public Person {
private:
    int studentID;
public:
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}
    void showInfo() override {
        cout << "👨‍🎓 Student -> Ism: " << name << ", Yosh: " << age << ", ID: " << studentID << endl;
    }
};


class Professor : public Person {
private:
    string subject;
public:
    Professor(string n, int a, string sub) : Person(n, a), subject(sub) {}
    void showInfo() override {
        cout << "👨‍🏫 Professor -> Ism: " << name << ", Yosh: " << age << ", Fan: " << subject << endl;
    }
};


class Course {
private:
    string courseName;
    string instructor;
public:
    Course(string c, string i) : courseName(c), instructor(i) {}
    void showInfo() {
        cout << "📚 Kurs: " << courseName << ", O'qituvchi: " << instructor << endl;
    }
};


class University {
private:
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;
public:
    void addStudent() {
        string name;
        int age, id;
        cout << "Student ismini kiriting: ";
        cin >> name;
        cout << "Yoshini kiriting: ";
        cin >> age;
        cout << "ID kiriting: ";
        cin >> id;
        students.push_back(Student(name, age, id));
        cout << "Student qo'shildi!\n";
    }

    void addProfessor() {
        string name, subject;
        int age;
        cout << "Professor ismini kiriting: ";
        cin >> name;
        cout << "Yoshini kiriting: ";
        cin >> age;
        cout << "Fanini kiriting: ";
        cin >> subject;
        professors.push_back(Professor(name, age, subject));
        cout << "Professor qo'shildi!\n";
    }

    void addCourse() {
        string courseName, instructor;
        cout << "Kurs nomini kiriting: ";
        cin >> courseName;
        cout << "O'qituvchi ismini kiriting: ";
        cin >> instructor;
        courses.push_back(Course(courseName, instructor));
        cout << "Kurs qo'shildi!\n";
    }

    void showAllStudents() {
        cout << "\n📌 Universitetdagi studentlar:\n";
        for (Student &s : students) {
            s.showInfo();
        }
    }

    void showAllProfessors() {
        cout << "\n📌 Universitetdagi professorlar:\n";
        for (Professor &p : professors) {
            p.showInfo();
        }
    }

    void showAllCourses() {
        cout << "\n📌 Universitetdagi kurslar:\n";
        for (Course &c : courses) {
            c.showInfo();
        }
    }
};

int main() {
    University uni;
    int choice;

    do {
        cout << "\n====  UNIVERSITET TIZIMI ====\n";
        cout << "1. Student qo'shish\n";
        cout << "2. Professor qo'shish\n";
        cout << "3. Kurs qo'shish\n";
        cout << "4. Barcha studentlarni ko'rish\n";
        cout << "5. Barcha professorlarni ko'rish\n";
        cout << "6. Barcha kurslarni ko'rish\n";
        cout << "0. Chiqish\n";
        cout << "Tanlovingiz: ";
        cin >> choice;

        switch (choice) {
            case 1:
                uni.addStudent();
                break;
            case 2:
                uni.addProfessor();
                break;
            case 3:
                uni.addCourse();
                break;
            case 4:
                uni.showAllStudents();
                break;
            case 5:
                uni.showAllProfessors();
                break;
            case 6:
                uni.showAllCourses();
                break;
            case 0:
                cout << "Dasturdan chiqilmoqda...\n";
                break;
            default:
                cout << "❌ Xato tanlov! Qaytadan kiriting.\n";
        }
    } while (choice != 0);

    return 0;
}
