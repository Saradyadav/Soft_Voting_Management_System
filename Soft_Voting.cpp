#include<iostream>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;
class Person
{
public:

       char inputid[50];
       char namevoter[100];
       int age;
       char gender[2];
       void setdata()
       {
             cout<<endl<<"                             Enter Your Details ";
                cout<<"*********************************************************************\n\n";
                cout<<endl<<"                             Voter ID           : ";
                cin >> inputid;
                cout<<endl<<"                             Name               : ";
                scanf(" ");
                gets(namevoter);
                cout<<endl<<"                             Age                : ";
                cin >> age;
                cout<<endl<<"                             Gender (M/F)       : ";
                cin >> gender;
       }
};

int main()
{
    int NumCan,isfound,i,j,NumPer,Vote,max1=0,max2=0,t=0,check=0,age=0;
    vector<int>VoteFor;
    Person p1[10000];
    char CanName[10][1000],id[100][1000],ch;
    char pass[50];
    cout<<endl<<"                              Soft Voting System                  "<< endl;
    cout<<"                     _________________________________________                   "<< endl;
    cout<<endl<<"                        :::::::::: ADMIN PANEL ::::::::::" << endl;
    cout<<endl<<"================================================================================="<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl<< "    Number of Candidate: ";
    cin>>NumCan;
    if(NumCan>1)
    {
         for(i=0; i<=NumCan; i++)
        {
            if(i==0)
            {
            //cout<<"    Candidate-"<<" Name: ";
            gets(CanName[i]);
            }
            else
            {
            cout<<"    Candidate-"<<" Name: ";
            gets(CanName[i]);
            for(int j=1;j<=10;j++)
            VoteFor.push_back(0);
            }
        }
        cout<< "    Number of Persons: ";
        cin>>NumPer;
        cout <<endl<< "  Thank You Admin! we are going to start our election with " <<NumPer<<" Persons and "<<NumCan<<" Candidates."<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"================================================================================="<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"                            Enter The Password: ";
        cin>>pass;
        while(strcmp(pass,"mypass")!=0)
        {
          cout<< endl;
              cout<<endl<<"                            Wrong Password! Try Again."<<endl;
              cout<<endl;
              cout<<"                       Enter The Correct Password: ";
          cin>>pass;
          cout<<endl;
        }
        //system("CLS");
        for(i=1; i<=NumPer; i++)
            {
                cout<<endl<<"                              Soft Voting System                   "<< endl;
                cout<<"                     _________________________________________                   "<< endl;
                cout<<endl<<"                        :::::::::: VOTING PANEL ::::::::::" << endl;
                cout<<endl<<"                                   Person - "<<i<<endl;
                cout<<endl<<"================================================================================="<<endl;
                cout<<endl;
                cout<<endl;
                FILE *filepointer;
                char datatoberead[50];
                filepointer = fopen("ID.txt","r");
                p1[i].setdata();
                strcat(p1[i].inputid,"\n");
                int c=0;
                while(fgets(datatoberead,50,filepointer)!=NULL)
                {
                    c++;
                    if(strcmp(p1[i].inputid,datatoberead)==0)
                    {
                        cout << "                                    Data found!" << endl;
                        FILE *filepointer2;
                        char datatoberead2[50];
                        filepointer2 = fopen("Name.txt","r");
                        int d=0;
                        while(fgets(datatoberead2,50,filepointer2)!=NULL)
                        {
                            d++;
                            if(c==d)
                            {
                                cout<<endl<<endl<<"    Name: "<<datatoberead2<<endl;
                                cout<<"    ID: "<<p1[i].inputid<<endl;
                            }

                        }
                        fclose(filepointer2);
                        fclose(filepointer);
                        break;
                    }
                    else
                    {
                    cout << "Sorry ID Not Found! or you type wrong ID. Please Try Again."<< endl;
                    t++;
                    break;
                    }
                }
                cout<<endl<<"                  ==========================================="<<endl;
                cout<<endl;
                cout<<endl;
                 if(p1[i].age<18)
                 {
                    cout<<"\nSorry! You are not eligible for cost the vote ................Thank You"<<endl;
                 }
               if(p1[i].age>=18)
               {


                for(j=1; j<=NumCan; j++)
                {
                    cout<<"                              Press "<<j<<" For "<<CanName[j]<<endl;
                }
                cout<<endl;
                cout<<endl<<"                  ==========================================="<<endl;
                cout<<endl<<"    Now, Please Put Your Vote: ";
                ch=getch();
                Vote=ch-48;
                cout<<"(Hidden)";
                //cin>>Vote;

                FILE *filepointer3;
                char datatobewrite[50];
                strcpy(datatobewrite,p1[i].inputid);
                filepointer3 = fopen("VoteDoneBy.txt","a");
                if ( strlen (  datatobewrite  ) > 0 )
                {
                    fputs(datatobewrite, filepointer3) ;
                }

                fclose(filepointer3) ;

                FILE *filepointer4;
                char datatobewrite2[50];
                strcpy(datatobewrite2,p1[i].inputid);
                strcat(datatobewrite2,CanName[Vote]);
                strcat(datatobewrite2,"\n");
                filepointer4 = fopen("VoteDetails.txt","a");
                if ( strlen (  datatobewrite2  ) > 0 )
                {
                    fputs(datatobewrite2, filepointer4) ;
                }

                fclose(filepointer4) ;

                for(j=1; j<=NumCan; j++)
                {
                    if(Vote==j)
                    {
                        VoteFor[j]++;
                        break;
                    }
                }
                cout<<endl;
                cout<<endl;
                cout<<endl<<"                  Thanks"<<id[i]<<" For Your Vote.(Press Enter for Next)"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"================================================================================="<<endl;
                getch();
                check=1;
               }
            //    system("CLS");
            }
          //  system("CLS");

            if(check)
            {
            cout<<endl<<"                               Soft Voting System                    "<< endl;
            cout<<"                     _________________________________________                   "<< endl;
            cout<<endl<<"                        :::::::::: RESULT PANEL ::::::::::" << endl;
            cout<<endl<<"================================================================================="<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"                            Enter The Password: ";
            cin>>pass;
            while(strcmp(pass,"mypass")!=0)
            {
              cout<< endl;
              cout<<endl<<"                            Wrong Password! Try Again."<<endl;
              cout<<endl;
              cout<<"                       Enter The Correct Password: ";
              cin>>pass;
              cout<<endl;
            }
            cout<<endl;
            cout<<endl;
            cout<<endl<<"                  ==========================================="<<endl;
            cout<<endl;
            cout<<endl;
            for(j=1; j<=NumCan; j++)
            {
                cout<<"                              "<<CanName[j]<<" Get "<<VoteFor[j]<<" Vote."<<endl;
            }
            cout<<endl;
            cout<<endl;
            cout<<endl<<"                  ==========================================="<<endl;
            max1=0;
            max2=0;
            for(j=1; j<=NumCan; j++)
            {
                if(max1<VoteFor[j])
                {
                    max1=VoteFor[j];
                }
            }
            int g=0;
            for(j=1; j<=NumCan; j++)
            {
                if(max1==VoteFor[j]&&g==0)
                {
                    j++;
                    g=1;
                }
                if(max2<VoteFor[j])
                {
                    max2=VoteFor[j];
                }
            }
            for(j=1; j<=NumCan; j++)
            {
                if(max1==VoteFor[j])
                {

                    if(max1==max2)
                    {
                           cout<<endl;
                           cout<<endl<<"Candidate "<<CanName[j]<<" and "<<CanName[j+1]<<"Got equal votes So it's tie"<< endl;
                           break;
                    }

                    cout<<endl;
                    cout<<endl<<"           Congratulations "<<CanName[j]<<". You are Elected "<< endl;
                    break;
                }
            }
            cout<<endl;
            cout<<endl;
            cout<<"================================================================================="<<endl;
            check=0;
            }


        }
        else
    {
        cout<<endl<<"Sorry! Number of Candidate must be more than one person."<<endl;
    }
    getch();
}
