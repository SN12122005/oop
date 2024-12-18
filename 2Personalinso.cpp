#include <iostream>
#include <string.h>
using namespace std;
class student
{
public:
	int rollno;
    string dob;
	char *name;
    char* blood_group;
    char* Class;
    char* div;
    string contact_address;
    string mobile_no;
    string license_no;
    string adhar_no;
	static int count;
	void getdata()
	{
		name=new char[10];
		blood_group=new char[10];
        Class=new char[10];
        div=new char[10];
        contact_address=new char[100];
		cout<<"Enter the roll no: ";
        cin>>rollno;
        cout<<"Enter the name: ";
        cin>>name;
        cout<<"Enter date of birth: ";
        cin>>dob;
        cout<<"Enter blood group: ";
        cin>>blood_group;
        cout<<"Enter the class: ";
        cin>>Class;
        cout<<"Enter division: ";
        cin>>div;
        cout<<"Enter contact address: ";
        cin>>contact_address;
        cout<<"Mobile No.: +91-";
        cin>>mobile_no;
        cout<<"Driving license No. : ";
        cin>>license_no;
        cout<<"Enter adhar no: ";
        cin>>adhar_no;
		count++;

	}
	inline void display()
	{
		cout<<"\nRollno:-"<<rollno<<"\nName:-"<<name<<"\nDate of Birth:- "<<dob<<"\nBlood Group:- "<<blood_group<<"\nClass:- "<<Class<<"\nDivision:- "<<div<<"\nContact Address:- "<<contact_address<<"\nMobile No.:- +91- "<<mobile_no<<"\nDriving license No.:- "<<license_no<<"\nAdhar No.: "<<adhar_no;
	}
	static void displaycount()
	{
		cout<<"\nTotal student="<<count;
	}
	student()
	{
		rollno=0;
		name=new char[10];
		dob="dd/mm/yyyy";
		blood_group=new char[10];
        Class=new char[10];
        div=new char[10];
        contact_address=new char[100];
        mobile_no="0000000000";
        license_no="0000-0000-0000-0000";
        adhar_no="0000-0000-0000";
	}
	student(student &x)
	{
		this->rollno=x.rollno;
		name=new char[10];
		strcpy(this->name,x.name);
		this->dob=x.dob;
		blood_group=new char[10];
		strcpy(this->blood_group,x.blood_group);
        Class=new char[10];
		strcpy(this->Class,x.Class);
        div=new char[10];
		strcpy(this->div,x.div);
        this->contact_address=x.contact_address;
        this->mobile_no=x.mobile_no;
        this->license_no=x.license_no;
        this->adhar_no=x.adhar_no;
	}
	~student()
	{
		delete name;
		cout<<"object has deleted";
	}
};
int student::count;
int main()
{
	student s[10];
	int ch,c=0,r,flag,i,count;
	char ch1;
	do
	{
		cout<<"\n Menu \n1:ADD RECORD \n2:DISPLAY RECORDS \n3:MODIFY \n4:DELETE\n5:NUMBER OF STUDENTS\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			s[c].getdata();
			c++;
			break;
		case 2:
			for(i=0;i<c;i++)
			{
			  s[i].display();
			}
			break;
		case 3:
			cout<<"Enter the rollno which record you want to modify: ";
			cin>>r;
			flag=0;
			for(i=0;i<c;i++)
			{
				if (s[i].rollno==r)
	          	{
	          		flag=1;
	          		break;
	          	}
			}
	          	if(flag==1){
	          		s[i].getdata();}
	          	else
	          		cout<<"\n Record has not found";
		            break;

		case 4:
			cout<<"Enter the roll no which record you want to delete: ";
			cin>>r;
			flag=0;
			for(i=0;i<c;i++)
			{
				if(s[i].rollno==r)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				for(;i<c;i++)
				{
					s[i].rollno==s[i+1].rollno;
					strcpy(s[i].name,s[i+1].name);

				}
				c--;
				count--;
			}
			else
				cout<<"\n Record HAS NOT FOUND";
			break;
		case 5:
			student::displaycount();
			break;
		default: cout<<"\n WRONG CHOICE";
		cout<<"\n Do you want to cont(y/n): ";
		cin>>ch1;
	    }
	}
	while(ch1='y'||ch1='Y');
	return 0;
}