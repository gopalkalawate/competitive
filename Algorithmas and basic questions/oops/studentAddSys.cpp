#include<bits/stdc++.h>
using namespace std;

class student{
    string name;
    int rollno;
    string branch;

    public:

        static int count;

        student(){
            cout<<"Enter the details of a new Student 1)NAME,ROLL,BRANCH\n";
            cin>>name>>rollno>>branch;
            count++;
            cout<<count<<endl;
        }

        ~student(){
            cout<<"student data is removed\n";
            cout<<name<<" "<<rollno<<" "<<branch<<'\n';
            count--;
            cout<<count<<endl;
        }

};

int student :: count = 0;

int main(){
    int k = 1;
    list <student> data;
    while(k){
        cout<<"1->add student \n 2->remove student \n 0->stop process\n";
        cin>>k;
        
        if(k==1){
            student s1;
            data.push_back(s1);
            s1.count++;
        }
        
        if(k==2){
            
            //data.front().~student();
            cout<<data.front().count<<" ";
        }
    }

    cout<<student::count<<endl;
}
      