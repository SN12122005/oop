#include <iostream>
using namespace std;

class Publication
{
	string title;
	float price;
public:
	void input_p()
	{
		cout<<"Enter the title of book: "<<endl;
		cin>>title;
		cout<<"Enter the price of book: "<<endl;
		cin>>price;
	}
	void display_p()
	{
		cout<<"\nTitle: "<<title<<"\nPrice: "<<price;
	}
};
class Book:public Publication
{
	int page_no;
public:
	void input()
	{
		cout<<"Enter page number: "<<endl;
		cin>>page_no;
		try
		{
			if(page_no==0)
			{
				throw page_no;
			}
		}
		catch(int)
		{
			cout<<"Page number is not equal to zero...."<<endl;
		}
	}
	void display()
	{
		cout<<"\nPage number: "<<page_no;
	}
};
class Tape:public Publication
{
	int time;
public:
	void input()
	{
		cout<<"Enter the time: "<<endl;
		cin>>time;
	}
	void display()
	{
		cout<<"\nTime: "<<time;
	}
};
int main()
{
	Book b;
	Tape t;

	int ch;
	do{
		cout<<"\nMenu\n1:Enter book datails.\n2:Enter tape details.\n3:diaplay book details.\n4:diaplay tape details.\n5:Exit.";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			b.input_p();
			b.input();
			break;
		case 2:
			t.input_p();
			t.input();
			break;
		case 3:
			cout<<"Book details:";
			b.display_p();
			b.display();
			break;
		case 4:
			cout<<"Tape details:";
			t.display_p();
			t.display();
			break;
		case 5:
			break;
		default:
			cout<<"Pleae try again..!";
		}
	}while(ch!=5);
	return 0;
}
