#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

typedef struct Student
{
    string name;
    string sex;
    double score;
}Student;

Student s[100];

bool cmp(Student A,Student B)
{
    if(A.score!=B.score)
      return A.score>B.score;
    if(A.score==B.score)
        return A.name<B.name;
}

int main()
{
    int number=0;
    double sco_all=0.0;
    double ave_all=0.0;
    
    int male_num=0;
    double sco_male=0.0;
    double ave_male=0.0;

    int fe_num=0;
    double sco_fe=0.0;
    double ave_fe=0.0;

    string s1;

    ifstream in("score.csv");
    getline(in,s1);
    while(getline(in,s1))
    {
        stringstream ss;
        ss<<s;
        ss>>s[number].name;
        ss>>s[number].sex;

        if(s[number].sex[0]='M')
        {
            male_num++;
        }
        else
            fe_num++;

        ss>>s[number].score;
       
        if(s[number].sex[0]=='M')
        {
            sco_male+=s[number].score;
            sco_all+=s[number].score;
        }
        else
        {
            sco_fe+=s[number].score;
            sco_all+=s[number].score;
        }
        
        number++;
    }

    ave_all=sco_all/number;
    ave_male=sco_male/male_num;
    ave_fe=sco_fe/fe_num;

    sort(s,s+number,cmp);

    cout<<"the average of the students is: "<<ave_all<<endl;
    cout<<"the average of the male is: "<<ave_male<<endl;
    cout<<"the average of the female is: "<<ave_fe<<endl;

    cout<<"\t\t#name,"<<"\t\t#sex,"<<"\t\t#score"<<endl;
    
    for(int i=0;i<number;i++)
    {
        cout<<"\t\t"<<s[i].name<<"\t\t"<<s[i].sex<<"\t\t"<<s[i].score<<endl;
    }


   return 0;
}   
