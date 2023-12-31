#include <iostream>

using namespace std;

class classname{
    public:  
    std::string name;
    int age;
    float id;
    bool con;
    std::string BC;

    classname(){}
    classname(std::string name,int age,float id){
        this->name = name;
        this->age = age;
        this->id = id;
    }
    classname(std::string name,int age,float id,bool con){
        if (con == true) {  
            cout << "Constructor with parameters called"<<endl;
            this->name = name;
            this->age = age;
            this->id = id;
            } else {
                cout << "Error in Constructor call"<< endl;
                }
    }
    classname(std::string name,int age,float id,bool con,std::string BC){
        if (con == true) {  
            cout << "Constructor with parameters called"<<endl;
            this->name = name;
            this->age = age;
            this->id = id;
            this->BC=BC;
            } else {
                cout << "Error in Constructor call"<< endl;
                }
    }
    

    void eat(){
        cout << "I am eating." << endl;  //calling the function to print a message
    }
    void sleep(){
        cout << "Zzz... I'm sleeping." << endl;
    }
    void run(){
        cout << "I am running..." << endl;
    }

    
};

class student{
   private:
   std:: string name;
   int id;
   int age;
   float gpa;
   char grade;

   
   public:
   student(){}
   void setname(std::string name){
    this -> name = name;
   }
   void setid(int id){
    this -> id = id;
    }
    void setgpa(float gpa){
        if ((gpa >=0.0) && (gpa <=4.0)){
            this -> gpa = gpa;
            if (gpa==4.0)
            grade='A';
            else if (gpa>=3.5)
            grade='B';
            else if (gpa>=2.5)
            grade='C';
            else if (gpa>=1.5)
            grade='D';
            else
            grade='F';
            }else{
                cout << "Invalid GPA entered! Please enter a value between 0.0 and 4.0." << endl;
                }
                }
   string getname(){
    return name;
   }  
   float getgpa(){
    return gpa;
   }
   int getid(){
    return id;
    }
    char getgrade() {
        return grade;
        }

                void getinfo() {
                    cout << "Name : "<< name <<endl;
                    cout << "ID : " << id << "\n";
                    cout << "Age : " << age << "\n";
                    cout << "GPA : " << gpa << "\t Grade : " <<grade<<"\n\n" ;
                    }

        void displayStudent() {
            cout << "Name: " << name << ", ID: " << id << ", Age: " << age << ", GPA: " <<
            gpa << ", Grade: " << grade << endl;
            }
            
};

int main(){
classname cls;
cout<<"enter name"<<endl;
cin>>cls.name;
cout<<"Enter your age:"<<endl;
cin>>cls.age;
cout<<"Enter your ID number:"<<endl;
cin>>cls.id;
cout<<cls.name<<"\n"<<cls.age<<"\n"<<cls.id<<endl;
classname cls2("okita",5,6.9);
cout<<cls2.name<<"\n"<<cls2.age<<"\n"<<cls2.id<<endl;
classname cls3("Sougo",5,6.9,true);
cout<<cls3.name<<"\n"<<cls3.age<<"\n"<<cls3.id<<"\n"<<cls3.con<<endl;
classname cls4("Votka",5,6.9,true,"Black");
cout<<cls4.name<<"\n"<<cls4.age<<"\n"<<cls4.id<<"\n"<<cls4.con<<"\n"<<cls4.BC<<endl;

cls.eat();      
cls.sleep();  
cls.run();     
string name;
int id;
float gpa;
         student s;
         cout<<"Enter student name"<<endl;
            cin>>name;
          cout<<"ENter ID"<<endl;
          cin>>id;
          cout<<"Enter GPA"<<endl;
          cin>>gpa;
          s.setname(name);
          s.setid(id);
          s.setgpa(gpa);
          s.getinfo();
          s.getgpa();
            s.getgrade();
            s.getid();
            s.getname();
            s.displayStudent();

         

}