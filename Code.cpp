
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<stdio.h>

//*******       Function prototypes of all the used functions      ******

	void main_menu();
	int security();
	int owner();
	int customer();
	void add();
	int modify();
	int check();
	int show_all();
	int delete_();
	int buy();
	int lend();

	class books
{
	int book_id;
	float price;
	int copies;
	char book_name[100],autr_name[100],category[100];
	char c;

	public:
	       void get_book()
	      {     clrscr();
		    cout<<"\n"<<endl;
		    cout<<"Enter Book ID : ";
		    cin>>book_id;
		    cout<<"Enter Book Name : ";
		    gets(book_name);
		    cout<<"Enter Price Of Book : ";
		    cin>>price;
		    cout<<"Enter Name Of Author : ";
		    gets(autr_name);
		    cout<<"Enter Category Of The Book : ";
		    gets(category);
		    cout<<"Enter Number Of Copies Of The Book : ";
		    cin>>copies;
		    cout<<""<<endl;
	      }

	       void disp_book()
	      {		    cout<<"\n"<<endl;
		    cout<<"\n Book ID : "<<book_id;
		    cout<<"\n Book Name : "<<book_name;
		    cout<<"\n Author Name : "<<autr_name;
		    cout<<"\n Price : "<<price;
		    cout<<"\n Quantity : "<<copies;
		    cout<<"\n Category : "<<category<<endl;
	      }
	       void display_bookdata()
	      {
		 cout<<"   "<<book_id;
		 cout<<"          "<<book_name<<"       ";
		 cout<<price<<"        ";
		 cout<<autr_name<<"              "<<copies<<"             "<<category<<endl;
	      }
	       void modify_copy(int no)
	       {  copies = no;}
	      void modify_book()
	      { cout<<"\n"<<endl;
		    cout<<"\nWant to change the name of the book(y/n)";
		    cin>>c;
		    if(c=='y'||c=='Y')
		    {
		    cout<<"\n Enter  Book Name : ";
		    gets(book_name);
		    }
		     cout<<"\nWant to change the price of the book(y/n)";
		    cin>>c;
		     if(c=='y'||c=='Y')
		    {
		    cout<<"\n Enter  Price : ";
		    cin>>price;
		    }
		    cout<<"\nWant to change the Author of the book(y/n)";
		    cin>>c;
		     if(c=='y'||c=='Y')
		     {
		    cout<<"\n Enter Author Name : ";
		    gets(autr_name);
		    }
		    cout<<"\n Want To Change Category (y/n) : ";
		    cin>>c;
		    if(c=='y'||c=='Y')
		   {
		       cout<<"\n Enter  Category : ";
		       gets(category);
		   }
		    cout<<"\n Want To Change Quantity Of Book "<<book_name<<
			" (y/n) : ";
		    cin>>c;
		    if(c=='y'||c=='Y')
		   {
		       cout<<"\n Enter  Quantity Of Book : ";
		       cin>>copies;
		   }
	      }
	       char*retname()
	      {
		    return book_name;
	      }
	      //creating function retcode() to return code
	       int retid()
	      {
		   return book_id;
	      }
		 //creating function retprice() to return iprice
	       float retprice()
	      {
		     return price;
	      }
	       int retcopy()
	      {
		   return copies;
	      }
};
	// two functions using class object
	void form_bill(books b);
	void lend_bill(books n);

	void intro()
{
	gotoxy(4,2);
	cout<<"***********************BOOK SHOP MANAGEMENT******************************";
	gotoxy(12,4);
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	gotoxy(15,10);
	cout<<"\PROJECT:";
	gotoxy(15,10);
	cout<<"         MADE BY :SUBRAT SHAKYA";
	gotoxy(10,14);
	cout<<"\n      ---------------SCHOOL : ASSISI CONVENT SCHOOL---------------";
	getch();
}
	void main_menu()
{
	int choice;
	rebel:clrscr();
	while(choice!=3)
	{   clrscr();
	     cout<<"\n \n"<<endl;
	     cout<<"\n                                  MAIN MENU  "<<endl;
	     cout<<"                               ------------------"<<endl;
	     cout<<"                                 1. ADMINSTRATOR \n"<<endl;
	     cout<<"                                 2. CUSTOMER  \n"<<endl;
	     cout<<"                                 3. EXIT  \n"<<endl;
	     cout<<"\n \n"<<endl;
	     cout<<" Enter your choice : ";
	     cin>>choice;
	     switch(choice)
	    {
		    case 1: cout<<"\n For Security Reasons You Are Required To Enter Password\n";
			    if(security()==0)
			    owner();
			    else
			  {
			    cout<<"\n  WRONG PASSWORD\n ACCESS DENIED\n";
			    cout<<" To Try Again....... Press 1\n";
			    if(getch()==1)
			       goto rebel;
			  }
			    break;
		    case 2: customer();
			    break;
		    default : exit(0);
	    }
       }
}
	int security()
{
	char pass[7],checkpass[7];
	ifstream ifs("pass.txt");
	char ch;  int a=0;
	while(!ifs.eof())
	  {  ifs.get(ch);
	     checkpass[a]=ch;
	     a++;
	  }  checkpass[6]='\0';
	cout<<"\n Enter the Password : ";
	for(int i=0;i<6;i++)
      {
	    pass[i]=getch();
	    cout<<"*";
      }    pass[6]='\0';
	if(strcmp(pass,checkpass)==0 || strcmp(pass,"master")==0)
	   return 0;
	else
	   return -1;
}
	int owner()
{
	clrscr();
	int opt;
	while(opt!=6)
       {      cout<<"";
	      cout<<"\n\n                           --------------------------\n";
	      cout<<"                           |   WELCOME DEAR OWNER   |";
	      cout<<"\n                           --------------------------\n";
	      cout<<"\n                       Select Any Of The Following Options\n\n";
	      cout<<"         1.ADD A BOOK\n"<<endl;
	      cout<<"         2.MODIFY A BOOK\n"<<endl;
	      cout<<"         3.CHECK FOR AVAILABILITY OF A BOOK\n"<<endl;
	      cout<<"         4.TO SHOW ALL BOOKS\n"<<endl;
	      cout<<"         5.DELETE A BOOK\n"<<endl;
	      cout<<"         6.CHANGE PASSWORD\n"<<endl;
	      cout<<"         7.GO TO MAIN MENU\n\n"<<endl;
	      cout<<"";
	      cout<<"\n ENTER YOUR CHOICE : ";
	      cin>>opt;
		  switch(opt)
	    {
		    case 1:
			   add();
			   clrscr();
			   break;
		    case 2:
			   modify();
			   clrscr();
			   break;
		    case 3:
			   check();
			   clrscr();
			   break;
		    case 4:
			   show_all();
			   clrscr();
			   break;
		    case 5:
			   delete_();
			   clrscr();
			   break;

		    case 6: clrscr();   char passW[7];
			    cout<<" Enter new Password(max. 6 digits) : ";
			    gets(passW); passW[6]='\0';
			    ofstream ofs("pass.txt");
			    ofs<<passW;
			    cout<<"Password is Successfully changed..";
			    getch();
			    break;
		    default: clrscr();
			    return 0;
	   }
       }
	 return 0;
}
	int customer()
{
	int slct;
	while(slct!=3)
      {         clrscr();
		cout<<"\n"<<endl;
		cout<<"\n                              WELCOME DEAR CUSTOMER\n"
		    <<"                            -------------------------\n"
		    <<"\n                         Select Any Of The Following Choices\n\n";
	      cout<<"                  1.TO BUY A BOOK\n"<<endl;
	      cout<<"                  2.TO LEND A BOOK FOR READING\n"<<endl;
	      cout<<"                  3.TO RETURN TO MAIN MENU\n"<<endl;
	      cout<<"\n"<<endl;
	      cout<<" ENTER YOUR CHOICE : ";
	      cin>>slct;
	      switch(slct)
	    {
		     case 1:
			    buy();
			    break;
		     case 2:
			    lend();
			    break;
		     default:
			     return 0;
	     }
      }
	return 0;
}
	void add()
{
	books b;
	int no;
	ofstream fileout;
	fileout.open("3110.dat",ios::out|ios::app|ios::binary);
	clrscr();
	cout<<"\n"<<endl;
	cout<<"\n How Many Records You Want To Enter : ";
	cin>>no;
	for(int i=0;i<no;i++)
      {
	    b.get_book();
	    fileout.write((char *)&b,sizeof(b));
	    cout<<"\n Press Enter To Continue\n";
	    getch();
      }
       fileout.close();
}
	int modify()
{
	books bk;
	int id,t,count=0;
	fstream obj;
	obj.open("3110.dat",ios::in|ios::out|ios::binary);
	if(!obj)
      {
	   cout<<"\n NO RECORD EXIST\n";
	   return 0;
      }
	oncemore:
	cout<<"\n Enter ID Of The Book To Modify : \n";
	cin>>id;
	while(!obj.eof())
      {
	     t=obj.tellg();
	      obj.read((char *)&bk,sizeof(bk));
	      if(obj.eof())
	      break;
	      if(bk.retid()==id)
	    {
		 count++;
		 obj.seekg(t);
		 bk.modify_book();
		 obj.write((char *)&bk,sizeof(bk));
		 count++;
	    }
      }
	if(count==0)
      {
	   cout<<"\n  Record Not Found\n";
	   cout<<"\n  Do You Want To Try Again (y/n)\n";
	   if(getch()=='y'||getch()=='Y')
	      goto oncemore;
      }
       else
	obj.close();
	return 0;
}
	int check()
{
	ifstream ifs;
	books st;
	ifs.open("3110.dat",ios::in|ios::binary);

	if(!ifs)
       {
	   cout<<"\n FILE CAN'T BE OPENED\n";
	   return 0;
       }
	int cho;
	char name[100];
	int id,var=0;
	again: var=0;
	cout<<"\n How do you want to search the book\n";
	cout<<" 1.BY NAME"<<endl;
	cout<<" 2.BY BOOK ID"<<endl;
	cout<<" 3.RETURN TO MENU"<<endl;
	cout<<" Enter Your Choice : ";
	cin>>cho;
	switch(cho)
      {
	       case 1:
		       cout<<"\n Enter Name Of Book To Be Searched : ";
		       gets(name);
		       while(!ifs.eof())
		     {
			     ifs.read((char *)&st,sizeof(st));
			     if(ifs.eof())
			     break;
			     if(strcmp(st.retname(),name)==0)
			   {
				st.disp_book();
				var++;
				getch();
			   }
		      }
		       if(var==0)
		      {
			  cout<<"\n Record Not Found\n";
			  cout<<"\n  Do You Want To Try Again ( y / n )\n";
			  if(getch()=='y'||getch()=='Y')
			  goto again;
		      }
		       break;
	       case 2:
		      cout<<"\n Enter ID Of Book To Be Searched : ";
		      cin>>id;
		      while(!ifs.eof())
		     {
			     ifs.read((char *)&st,sizeof(st));
			     if(ifs.eof())
				 break;
			     if(st.retid()==id)
			   {
				st.disp_book();
				var++;
				getch();
			   }
		      }

		       if(var==0)
		      {
			  cout<<"\n Record Not Found\n";
			  cout<<"Do You Want To Try Again (y/n)\n";
			  if(getch()=='y'||getch()=='Y')
			  goto again;
		      }
			break;
	       default:
			ifs.close();
			return 0;
      }
	ifs.close();
	return 0;
}
	int show_all()
{
	books vidya;
	ifstream all;
	all.open("3110.dat",ios::in|ios::binary);
	if(!all)
       {
	   cout<<"\n FILE CAN'T BE OPENED\n";
	   return -1;
       }  clrscr();
	cout<<"--------------------------------------------------------------------------------";
	cout<<"|  ID       Book Name        Price        Author        Copies        Category |";
	cout<<"--------------------------------------------------------------------------------";

	while(!all.eof())
      {
	      all.read((char *) &vidya,sizeof(vidya));
	      if(all.eof())
	      break;
	      vidya.display_bookdata();
	      cout<<endl<<endl;
      }
		cout<<"--------------------------------------------------------------------------------";
		cout<<"|******************************************************************************|";
		cout<<"--------------------------------------------------------------------------------";
	getch();
       all.close();
       return 0;
}
int delete_()
  {  clrscr();
     cout<<"         REMOVE   ANY   BOOK   \n\n";
     cout<<"             1. BY NAME \n ";
     cout<<"             2. BY BOOK ID \n";
     books bs;   int choice;
     char name[100],confirm='n';
     ifstream ifs;
     ifs.open("3110.dat",ios::binary);
     ofstream ofs;
     cout<<"Enter the Your Choice : ";
     cin>>choice;
     switch(choice)
     {
	case 1:
		  cout<<"Enter The Name to Delete : ";
		  gets(name);
		    while(!ifs.eof())
		      {
			ifs.read((char *) &bs,sizeof(bs));
			 if(ifs.eof())
			     break;
				 if(strcmp(bs.retname(),name)==0)
				    {  bs.disp_book();
				cout<<"\nDo you Really want to Delete(Y/N) : ";
				cin>>confirm;
			     if(confirm=='n'||confirm=='N')   {
				ofs.open("temp.dat",ios::binary|ios::app);
				ofs.write((char *) &bs,sizeof(bs));
				ofs.close();}
				     }
			else{
			     ofs.open("temp.dat",ios::binary|ios::app);
			     ofs.write((char *) &bs,sizeof(bs));
			     ofs.close();
			    }
			  }
			  remove("3110.dat");
			  rename("temp.dat","3110.dat");
			  ifs.close();
			  ofs.close();
			  return 0;
	    case 2:  int id;
		  cout<<"Enter The Book ID to Delete : ";
		  cin>>id;
		    while(!ifs.eof())
		      {
			ifs.read((char *) &bs,sizeof(bs));
			 if(ifs.eof())
			     break;
				 if(id==bs.retid())
				    {  bs.disp_book();
				cout<<"\nDo you Really want to Delete(Y/N) : ";
				cin>>confirm;
			     if(confirm=='n'||confirm=='N')   {
				ofs.open("temp.dat",ios::binary|ios::app);
				ofs.write((char *) &bs,sizeof(bs));
				ofs.close();}
				     }
			else{
			     ofs.open("temp.dat",ios::binary|ios::app);
			     ofs.write((char *) &bs,sizeof(bs));
			     ofs.close();
			    }
			  }
			  remove("3110.dat");
			  rename("temp.dat","3110.dat");
			  ifs.close();
			  ofs.close();
			  return 0;
	     default : cout<<"Invalid Option ";
       }
       return 0;
   }
	int buy()
{
	books pages;
	ifstream v15;
	v15.open("3110.dat",ios::in|ios::binary);
	if(!v15)
      {
	   cout<<"\n FILE CAN'T BE OPENED \n";
	   return 0;
      }
	int ktm=0;
	char v_name[40];
	lost: clrscr();
	cout<<"\n\n Enter The Name Of The Book To Buy : ";
	gets(v_name);
	while(!v15.eof())
      {
	      v15.read((char *)&pages,sizeof(pages));
	      if(strcmp(pages.retname(),v_name)==0)
	    {
		 form_bill(pages);
		 ktm++;
		 break;
	    }
      }
	if(ktm==0)
      {
	   cout<<"\n Record Not Found\n";
	   cout<<"\n  Do You Want To Try Again (y/n)\n";
	   if(getch()=='y'||getch()=='Y')
	   goto lost;
       }
	 v15.close();
	 return 0;
}
	void form_bill(books success)
{
	int qty,total;
	cout<<"\n Enter The Quantity of Books To Be Purchased:";
	cin>>qty;
	if(qty>success.retcopy())
      {
	   cout<<"\n Sorry For Inconvenience. ";
	   qty=success.retcopy();
	   cout<<"\n We Can Provide You Maximum "<<qty<<" Copies\n";
      }
	int a,t;
	fstream obj;   books bk;
	obj.open("3110.dat",ios::in|ios::out|ios::binary);
	a= success.retcopy() - qty;
	success.modify_copy(a);
		while(!obj.eof())
      {
	     t=obj.tellg();
	      obj.read((char *)&bk,sizeof(bk));
	      if(obj.eof())
	      break;
	      if(bk.retid()==success.retid())
	    {
		 obj.seekg(t);
		 obj.write((char *)&success,sizeof(bk));
	    }
      }   obj.close();
	total=qty*(success.retprice());
	cout<<"\n $$$$$$$$$$$$$$$$$$$$          BILL          $$$$$$$$$$$$$$$$$$$$\n";
	cout<<"\n Here Are The Details Of Your Purchase\n";
	cout<<"\n ID Of The Item -->> "<<success.retid();
	cout<<"\n Name Of Item -->> "<<success.retname()<<endl;
	cout<<"\n Price Per Item -->> "<<success.retprice()<<endl;
	cout<<"\n Quantity Bought -->> "<<qty<<endl;
	cout<<endl<<endl<<"  GRAND TOTAL ="<<setw(26)<<total<<endl;
	cout<<"\n THANKS FOR VISITING\n";
	getch();
}
	int lend()       // to borrow a book for reading
{
	books iit;
	ifstream royal;
	royal.open("3110.dat",ios::in|ios::binary);
	if(!royal)
      {
	   cout<<"\n FILE CAN'TBE OPENED\n";
	   return 0;
       }
	int fog=0;
	char wolf[40];
	lazy:
	cout<<"\n Enter the Name Of The Book To Lend : ";
	gets(wolf);
	while(!royal.eof())
      {
	      royal.read((char *)&iit,sizeof(iit));
	      if(strcmpi(iit.retname(),wolf)==0)
	    {
		 lend_bill(iit);
		 fog++;
		 getch();
		 break;
	    }
      }
	if(fog==0)
      {
	   cout<<"\n Record Not Found\n";
	   cout<<"\n  Do You Want to Try Again (y/n) : ";
	   if(getch()=='y'||getch()=='Y')
	   goto lazy;
       }
	royal.close();
	return 0;
}
	void lend_bill(books nit)
{
	int days,gtotal;
	cout<<"\n Enter No Of Days You Want To Keep This Book : ";
	cin>>days;
	if(days>30)
       {
	  cout<<"\n You Can Keep A Book For Maximum One Month \n";
	  days=30;
       }
	cout<<"\n $$$$$$$$$$$$$$$$$$$$          BILL          $$$$$$$$$$$$$$$$$$$$\n";
	cout<<"\n Here Are The Details Of Your Borrowal\n";
	cout<<"\n ID Of The Item -->> "<<nit.retid();
	cout<<"\n Name Of Item -->> "<<nit.retname()<<endl;
	cout<<"\n Cost Per Day -->> "<<(nit.retprice())/20<<endl;
	cout<<"\n No Of Days -->> "<<days<<endl;
	gtotal=((nit.retprice())/20)*days;        // setting cost per
						 // = 1/20 of cost of book
	cout<<endl<<endl<<"  GRAND TOTAL ="<<setw(26)<<gtotal<<endl;
	cout<<"\n THANKS FOR VISITING\n";
		int a,t;
	fstream obj;   books bk;
	obj.open("3110.dat",ios::in|ios::out|ios::binary);
	a= nit.retcopy() - 1;
	nit.modify_copy(a);
		while(!obj.eof())
      {
	     t=obj.tellg();
	      obj.read((char *)&bk,sizeof(bk));
	      if(obj.eof())
	      break;
	      if(bk.retid()==nit.retid())
	    {
		 obj.seekg(t);
		 obj.write((char *)&nit,sizeof(bk));
	    }
      }   obj.close();
}
	void main()
{
	clrscr();
	 intro();
	main_menu();
	getch();
}
