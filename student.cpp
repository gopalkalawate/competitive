#include<bits/stdc++.h>
using namespace std;
vector <pair<string,int>> electives;
void display(vector <string> &subjects,vector <string> &grade){
    cout<<"here are your 3 coumpulsary subjects\n";
        subjects.push_back("oops");
        subjects.push_back("os");
        subjects.push_back("ds");

        cout<<"enter the grades in the following subjects\n";
        for(int i=0;i<3;i++){
            cout<<subjects[i]<<" ";
            cin>>grade[i];
        }

       cout<<"here is a list of electives\n";

       for(auto it : electives){
        cout<<it.first<<" ";
       }

        cout<<"enter the 2 elective subjects\n";
        string tmp;
       cout<<"first elective";cin>>tmp;
       subjects.push_back(tmp);
       cout<<"second elective";cin>>tmp;
       subjects.push_back(tmp);
}



 

 void setelect(vector <pair<string,int>> &electives){
    electives.push_back({"s1",3});
            electives.push_back({"s2",4});
            electives.push_back({"s3",3});
            electives.push_back({"s4",3});
            electives.push_back({"s5",4});
            electives.push_back({"s6",3});
            electives.push_back({"s7",3});
            electives.push_back({"s8",4});
            electives.push_back({"s9",3});
            electives.push_back({"s10",3});
            electives.push_back({"s11",4});
            electives.push_back({"s12",3});
            electives.push_back({"s13",3});
            electives.push_back({"s14",4});
            electives.push_back({"s15",3});
            electives.push_back({"s16",3});
            electives.push_back({"s17",4});
            electives.push_back({"s18",3});
            electives.push_back({"s19",3});
            electives.push_back({"s20",4});
 }

class DataclassSubjects{
    map <int,vector <string>> m;
   
    public:
        
        DataclassSubjects(){
            m[3]={"ap","as","cp","evs","coms","cso","itw"};
            m[4] = {"edc","eee","mi","oops","dsa","os","mg","ae","ds","dp"};

            

        }

        const vector<pair<string, int>>& getElectives() const {
        return electives;
    }

};


struct firstSemData : DataclassSubjects
{
    string name;
    string rollno;
    string subjects[5];
    string grade[5];
    firstSemData(){
        cout<<"enter your name and roll no\n";
        cin>>name>>rollno;

        cout<<"here are your 5 compulsary subjects\n";
        subjects[0] = "as";
        subjects[1]="edc";
        subjects[2] = "eee";
        subjects[3] = "cp";
        subjects[4] = "evs";

        for(int i=0;i<5;i++){
            cout<<subjects[i]<<" ";
            cin>>grade[i];
        }
    }
};

struct SecondSemData : private firstSemData
{
    string subjects[5];
    string grade[5];
    SecondSemData(){
        cout<<"here are your 5 compulsary subjects\n";
        subjects[0] = "mg";
        subjects[1]="ae";
        subjects[2] = "ds";
        subjects[3] = "ap";
        subjects[4] = "coms";

        for(int i=0;i<5;i++){
            cout<<subjects[i]<<" ";
            cin>>grade[i];
        }
    }
};

struct ThirdSemData : private SecondSemData
{
    string subjects[5];
    string grade[5];
    ThirdSemData(){
        cout<<"here are your 5 compulsary subjects\n";
        subjects[0] = "oops";
        subjects[1]="mi";
        subjects[2] = "cso";
        subjects[3] = "dsa";
        subjects[4] = "itw";

        for(int i=0;i<5;i++){
            cout<<subjects[i]<<" ";
            cin>>grade[i];
        }
    }
};

struct FouthSemData : private ThirdSemData
{
    string subjects[5];
    string grade[5];
    FouthSemData(){
        cout<<"here are your 5 compulsary subjects\n";
        subjects[0] = "os";
        subjects[1]="dsa";
        subjects[2] = "dp";
        subjects[3] = "cp";
        subjects[4] = "evs";
        cout<<"enter the grades in the following subjects\n";
        for(int i=0;i<5;i++){
            cout<<subjects[i]<<" ";
            cin>>grade[i];
        }
    }
};

struct FifthSemData : private FouthSemData {
    string subjects[5];
    string grade[5];
    FifthSemData() {
        cout << "here are your 3 coumpulsary subjects\n";
        subjects[0] = "oops";
        subjects[1] = "os";
        subjects[2] = "ds";

        cout << "enter the grades in the following subjects\n";
        for (int i = 0; i < 3; i++) {
            cout << subjects[i] << " ";
            cin >> grade[i];
        }

        cout << "here is a list of electives\n";

        for (auto it : electives) {
            cout << it.first << " ";
        }

        cout << "enter the 2 elective subjects\n";

        cout << "first elective";
        cin >> subjects[3];
        cout << "second elective";
        cin >> subjects[4];
    }
};

struct SixthSemData : private FifthSemData
{
   vector <string> subjects;
   vector <string> grade;
    SixthSemData(){
        printf("problem is here in sixth\n");
        display(subjects,grade);
    }
};

struct SeventhSemData : private SixthSemData
{
    vector <string> subjects;
   vector <string> grade;
    SeventhSemData(){
        display(subjects,grade);
    }
};

struct EighthSemData : private SeventhSemData
{
    vector <string> subjects;
   vector <string> grade;
   
    EighthSemData(){
        display(subjects,grade);
    }
};

struct student : private EighthSemData
{
   
    float cg;
    public : 

        student(){
            
            cg = 0;
        }
};




int main(){
    setelect(electives);
    student s1;
}

// enter your name and roll no
// GOPAL
// BT22CSE085
// here are your 5 compulsary subjects
// as AA
// edc AAA
// eee AA
// cp AA
// evs AA
// here are your 5 compulsary subjects
// mg AA
// ae AA
// ds AA
// ap A
// coms AA
// here are your 5 compulsary subjects
// oops AA
// mi AA
// cso AA
// dsa AAA
// itw AA
// here are your 5 compulsary subjects
// enter the grades in the following subjects
// os AAA
// dsa AA
// dp AA
// cp AA
// evs AA
// here are your 3 coumpulsary subjects
// enter the grades in the following subjects
// oops AA
// os AA
// ds AA
// here is a list of electives
// s1 s2 s3 s4 s5 s6 s7 s8 s9 s10 s11 s12 s13 s14 s15 s16 s17 s18 s19 s20 enter the 2 elective subjects
// first electives1
// second electives2
// problem is here in sixth
// here are your 3 coumpulsary subjects
// enter the grades in the following subjects
// oops AA
//os AA
//ds AA

//enter your two elective subjects
//s1
//s2

//enter your grade in s2 : AA
//enter your grade in s15 : AB