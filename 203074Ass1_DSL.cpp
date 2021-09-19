/*
 * MARKS.cpp
 *
 *  Created on: 
 *  Author: thawatchai yango SE COMP B
 *  Roll No:203074 BATCH E
 *  Assignment 1
 *  Problem Statement
 *  write c++ program to sore marks scored for first test of subject 'Data Structure and alogorithms'
 *  for N student. Compute
 *  1.the average score of cass
 *  2.highest score and lowest score of class
 *  3.marks scored y most of students
 *  4.list of students wh were absent for the test
 */

#include <iostream>
using namespace std;

class Test
{
    int dsa[30],i,j,n,sum,cnt[50],k,rn[30]; //data members
    float av;
public:
    Test()  //default constructor
    {
        i=j=n=0;
        av=sum=k=0;
    }
    void getdata(); //member functions
    void show();
    void avg();
    void Ab_stud();
    void HS_LS();
    void MS_score();
}; //end of class declaration

//Function name: getdata()
//return type: void
//Parameter :Nil
// To accept information of test.

void Test::getdata()
{
	cout<<"\n:::::::::::::::::::WELCOME TO DSA MARK SCORED DATA :::::::::::::::::::::\n\n";
    cout<<"\n\t\tHOW MANY STUDENTS IN (SE COMP DIV B):: ";
    cin>>n;
    cout<<"\n\t------------------------------------------------------";
    cout<<"\n\t ENTER THE MARKS SCORED FOR FIRST TEST OF SUBJECT DSA  ";
    cout<<"\n\t------------------------------------------------------";
    cout<<"\n\nSTDENT WHO REMAINS ABSENT FOR THE TEST PLEASE ENTER ( -1 ) FOR THEM ::";
    cout<<"\n                     -------------------------------------         ";
    for(i=0;i<n;i++)
    {
     cout<<"\nENTER THE MARKS OF ROLL NUMBER :: "<<i+1<<" : ";
     cin>>dsa[i];
    }
}

void Test::MS_score()
{
    for(i=0;i<50;i++)
    {
        cnt[i]=0;
    }
    for(i=0;i<50;i++)
    {
        for(j=0;j<n;j++)
        {
            if(dsa[j]==i)
            {
                cnt[i]=cnt[i]+1;
            }
        }
    }
    /*cout<<"\n\nCount of marks..\n\n";
    for(i=0;i<50;i++)
    {
        cout<<"\t"<<cnt[i];
    }*/
    cout<<"\n\n MARK SCORED BY MOST OF THE STUDENT IN TEST ARE :: \n";
    
    k=0;
    j=0;
        int max=cnt[j];
    for(i=0;i<50;i++)
    {
     if(cnt[i]>=max)
     {
         max=cnt[i];
         k=i;
     }
    }
    cout<<"\n\n MAXIMUM MARKS  "<<k<<" SCORED BY "<<max <<" STUDENTS...\n";
    for(i=0;i<n;i++)
    {
        if(dsa[i]==k)
        {
            rn[j]=i;
            j++;
        }
    }
    cout<<"\n\n STUDENTS ROLL NUMBER ARE AS FOLLOWS..\n\n";
    for(i=0;i<j;i++)
    {
        cout<<"\t"<<rn[i]+1;
    }
}

void Test::show()
{
    cout<<"\n\nFIRST TEST MARKS OF SUBJECT DSA ARE AS FOLLOWS...\n";
    cout<<"\n*********************************\n";
    cout<<"|  Roll No\t"<<"|"<<" DSA Marks     |";
    cout<<"\n*********************************\n";
    for(i=0;i<n;i++)
    {
        cout<<"|\t"<<i+1<<"\t|\t"<<dsa[i]<<"\t|\n";
    }
    cout<<"---------------------------------\n";
}

void Test::avg()
{
    int p=0;
    cout<<"\nAVERAGE SCORE OF THE CLASS = > ";
    for(i=0;i<n;i++)
    {
        if(dsa[i]!=-1)
        {
            sum=sum+dsa[i];
            p++;
        }

    }
    av=sum/p;
    cout<<av;
}

void Test::Ab_stud()
{
    int cnt=0;
    cout<<"\n\n*************TOTAL NUMBER OF STUDENT ABSENT FOR DSA TEST************\n";
    cout<<"\nRoll No\t Marks\n";
    for(i=0;i<n;i++)
    {
        if(dsa[i]==-1)
        {
            cout<<i+1<<"\tABSENT\n";
            cnt++;
        }
    }
    cout<<"\n\tTOTAL_ABSENT_STUDENT :=: "<<cnt;
}

void Test::HS_LS()
{
    int min=0;
    int max=0,rno=0,i=0;
    cout<<"\n\n--------------------------------------------------------------------\n";
    cout<<"\n\n HIGHEST SCORE OF THE CLASS FOR DSA SUBJECT ARE AS FOLLOWS..\n";
    max=dsa[i];
    for(i=0;i<n;i++)
    {
        if(dsa[i]==-1)
        {

        }
        else if(dsa[i]>=max)
        {
            max=dsa[i];
            rno=i;
        }
    }
    cout<<"\n\tDSA HIGHEST SCORE :: "<<"Roll No :: "<<rno+1<<" Marks :: "<<max;
    cout<<"\n\n LOWEST SCORE OF THE CLASS FOR DSA SUBJECT ARE AS FOLLOWS..\n";
    rno=0;
    min=dsa[j];
    for(j=0;j<n;j++)
    {
        if(dsa[j]==-1)
        {

        }
        else if(dsa[j]<=min)
        {
         min=dsa[j];
         rno=j;
        }
    }
    cout<<"\n\tDSA LOWEST SCORE :: "<<"Roll No :: "<<rno+1<<" Marks :: "<<min;
}

int main()
{
    Test T;
    T.getdata();
    T.show();
    T.avg();
    T.Ab_stud();
    T.HS_LS();
    T.MS_score();
    cout << "\n\n\n---------------------------!!!Good Bye!!!---------------------------" << endl;
    return 0;
}
