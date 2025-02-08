#include<iostream>
#include<string>
#include<cstring>
using namespace std;
struct Student{
	char name[50];
	int score;
};
Student students[100];
void input(Student* students,int* numStudents);
void display(const Student* students,int* numStudents);
void findHighestscore(const Student* students,int* numStudents);
double Average(const Student* students,int* numStudents);
void search(const Student* students,int* numStudents,const char* searchName);
int main()
{
	int numStudents;
	cout<<"Enter number of students(max 100):";
	cin>>numStudents;
	while(numStudents<1||numStudents>100)
	{
		cout<<"Invalid Number. Please input between 1 and 100.";
		cin>>numStudents;
	}
	input(students,&numStudents);
	display(students,&numStudents);
	findHighestscore(students,&numStudents);
	double average=Average(students,&numStudents);
	cout<<"Average Score:"<<average<<endl;
	char searchName[50];
	cout<<"Enter name of student you want to search:";
	cin>>searchName;
	search(students,&numStudents,searchName);
	return 0;
}
void input(Student* students,int* numStudents)
{
	for(int i=0;i<*numStudents;i++)
	{
		cout<<"Enter name of Student "<<i+1<<" :";
		cin>>students[i].name;
		cout<<"Enter score of Student: "<<i+1<<" :";
		cin>>students[i].score;
		while(students[i].score<0||students[i].score>100)
		{
			cout<<"Invalid Score. PLease enter between 0 and 100"<<endl;
			cin>>students[i].score;
		}
	}
}
void display(const Student* students,int* numStudents)
{
	cout<<"Students and their scores "<<endl;
	for(int i=0;i<*numStudents;i++)
	{
		cout<<"Name: "<<students[i].name<<", Score: "<<students[i].score<<endl;
	}
}
void findHighestscore(const Student* students,int* numStudents)
{
	if(*numStudents==0)
	{
		cout<<"No Students Available."<<endl;
		return;
	}
	int highestscore=students[0].score;
	for(int i=0;i<*numStudents;i++)
	{
		if(students[i].score>highestscore)
		{
			highestscore=students[i].score;
		}
	}
	cout<<"Highest Score:"<<highestscore<<endl;
	cout<<"Student(s) with highest score:";
	for(int i=0;i<*numStudents;i++)
	{
		if(students[i].score==highestscore)
		{
			cout<<students[i].name<<endl;
		}
	}
}
double Average(const Student* students,int* numStudents)
{
	if(*numStudents==0)
	{
		return 0;
	}
	int total=0;
	for(int i=0;i<*numStudents;i++)
	{
		total+=students[i].score;
	}
	double a=double(total)/ *numStudents;
	return a;
}
void search(const Student* students,int *numStudents,const char* searchName)
{
	for(int i=0;i<*numStudents;i++)
	{
		if(strcmp(students[i].name,searchName)==0)
		{
			cout<<"Score of "<<searchName<<" is "<<students[i].score<<endl;
		}
	}
	cout<<searchName<<" not found";
}
