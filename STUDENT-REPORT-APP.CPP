//***************************************************************
//           COMPUTER SCIENCE PROJECT FOR CLASS XII
//					FOR THE ACADEMIC YEAR 2013-2014.
//
//   			DEVELOPERS: SARTHAK SAHU & SARANSH PAWAR.
//***************************************************************

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<dos.h>

//***************************************************************
//                   CLASS USED IN PROJECT
//***************************************************************

class student
{
	int rollno;
	char name[50];
	int p_marks, c_marks, m_marks, e_marks, cs_marks;
	float per;
	char grade;
	void calculate();	//function to calculate grade
public:
	void getdata();	//function to accept data from user
	void showdata();	//function to show data on screen
	void show_tabular();  //function to show tabular data on screen
	int retrollno();      //Function to return roll no
	char retgrade();      // Function to return grade
}; //class ends here


void student::calculate()
{
	per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(per>=90)
		grade='A';
	else if(per>=80)
		grade='B';
	else if(per>=70)
		grade='C';
	else if(per>=60)
		grade='D';
	else if(per>=33)
		grade='E';
	else
		grade='F';
}

void student::getdata()
{
	cout<<"\nEnter The roll number of student ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student ";
	gets(name);
	cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>e_marks;
	cout<<"\nEnter The marks in computer science out of 100 : ";
	cin>>cs_marks;
	calculate();
}

void student::showdata()
{
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in Physics : "<<p_marks;
	cout<<"\nMarks in Chemistry : "<<c_marks;
	cout<<"\nMarks in Maths : "<<m_marks;
	cout<<"\nMarks in English : "<<e_marks;
	cout<<"\nMarks in Computer Science :"<<cs_marks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
}

void student::show_tabular()
{
	cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)<<e_marks<<setw(4)<<cs_marks<<setw(6)<<per<<setw(6)<<" "<<grade<<endl;
}

int  student::retrollno()
{
	return rollno;
}

char student::retgrade()
{
	return grade;
}
//***************************************************************
//    	global declaration
//****************************************************************
student st;
ofstream outFile;
ifstream inFile;
int passlen;
char password[20]="vishalsahu5";

//***************************************************************
// 							INITIALIASING FUNCTION
//***************************************************************
void initialising()
{
fstream pass("pass1.dll",ios::in | ios::nocreate);
if(pass==NULL)
{ pass.close();
 fstream pass2("pass1.dll",ios::out|ios::in);
 strcpy(password,"vishalsahu5");
 pass2<<password;
 pass2.close();
 cout<<"password is set to default password.\nrefer to program code for the defualt password";
}
else
{

pass>>password;
pass.close();

}
}
//****************************************************************
// 				  FUNCTION TO CHECK PASSWORD
//****************************************************************
int CheckPass()
{
int trial =0;
cout<<"\nPlease enter password(in a maximum trial of 3 times)\nTrials remaining ="<<(3-trial++)<<endl;
cout<<" => ";
char inputpass[20];
int len=strlen(password);
int i=0;
INPUT:
inputpass[i]=getch();
cout<<'*';
if(inputpass[i]!='\r')
{
	i++;
	goto INPUT;
}
else
inputpass[i]='\0';
if(strcmp(inputpass,password)==0)
{
cout<<"\nlogin success!";
cout<<"\n\npress any key to proceed...";
getch();
return 0;
}
else
{
 if(trial<3)
 {
  clrscr();
  cout<<"Enter Password again.\nTrials remaining="<<(3-trial++)<<endl;
  cout<<" => ";
  i=0;
  goto INPUT;
 }
 else
 {
 cout<<"Login failed! wrong password";
 cout<<"\npress any key to exit...";
 getch();
 return -1;
 }
}
}
//****************************************************************
//      					FUNCTION TO CHANGE PASSWORD
//****************************************************************
void ChangePass()
{
	clrscr();
  char symbol=4;
  int i=0;
  char inputpass[20],newpass[20],confirmpass[20];
  cout<<"\t\tCHANGE PASSWORD WIZARD\n\n";
  cout<<"Enter OLD password\n";
  cout<<"=> ";
  OLD:
  inputpass[i]=getch();
  cout<<'*';
  if(inputpass[i]!='\r')
  {
	i++;
	goto OLD;
  }
  else
  inputpass[i]='\0';
  if(strcmp(password,inputpass)==0)
  {
  NEW:
	clrscr();
	cout<<"\t\tCHANGE PASSWORD WIZARD\n\n";
	cout<<"Now enter NEW password. The password:-\n"<<symbol<<"should be of minimum 8 characters and maximum 20 characters.\n"<<symbol<<"can have both numbers and letters.\n"<<symbol<<"should not have blank spaces and symbols in it.\n\n";
	cout<<"=> ";
	i=0;
	NEW_ENTER:
	newpass[i]=getch();
	cout<<'*';
	if((newpass[i]!='\r') && (newpass[i]!=' ') && (newpass[i]!='\t') && (newpass[i]<=32 || newpass[i]>=47))
	{i++;
	goto NEW_ENTER;}
	else if(newpass[i]='\r' && i<20 && i>6)
	newpass[i]='\0';
	else
	{
	 cout<<"Invalid Password!!! Enter Again\n";
	 goto NEW;
	}
	cout<<"\nCONFIRM NEW password.\n";
	cout<<"=> ";
	i=0;
	CONFIRM_PASS:
	confirmpass[i]=getch();
	cout<<'*';
	if(confirmpass[i]!='\r')
	{
	 i++;
	 goto CONFIRM_PASS;
	}
	else
	{
	 confirmpass[i]='\0';
	}
	if(strcmp(confirmpass,newpass)==0)
	 {
		ofstream passChange("pass1.dll",ios::trunc);
		strcpy(password,newpass);
		passChange<<password;
		cout<<"\n\nPASSWORD HAS CHANGED SUCCESSFULLY!\n";
		passChange.close();
	 }
	 else
	 {
	  cout<<"\n\t\tPASSWORD MISMATCH.\nPASSWORD CHANGE FAIL!!!\n\n";
	 }
  }
	else
	 {
	 cout<<"\n\t\tPASSWORD CHANGE FAIL!!!\n\n";
	 }
	 cout<<"Press any key to exit wizard & go back to main menu...";
	 getch();
}
//****************************************************************
//             FUNCTION TO SELECT WITHOUT PRESSING ENTER
//****************************************************************
char getdigit()
{
int ch;
ch=getch();
if(ch=='1')
return '1';
else if(ch=='2')
return '2';
else if(ch=='3')
return '3';
else if(ch=='4')
return '4';
else if(ch=='5')
return '5';
else if(ch=='6')
return '6';
else if(ch=='7')
return '7';
else if(ch=='8')
return '8';
else if(ch=='9')
return '9';
else
return '-1';
}

//****************************************************************
//    	function to write in file
//****************************************************************
void write_student()
{
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(student));
	outFile.close();
	 cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	getch();
}
//***************************************************************
//    	function to read all records from file
//****************************************************************
void display_all()
{
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORDS \n\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();

	getch();
}
//***************************************************************
//    	function to read specific record from file
//****************************************************************
void display_sp(int n)
{
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	int flag=0;
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retrollno()==n)
		{
			 st.showdata();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord does not exist";

	getch();
}
//***************************************************************
//    	function to modify record of file
//****************************************************************
void modify_student(int n)
{
	int found=0;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}

	while(File.read((char *) &st, sizeof(student)) && found==0)
	{
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
			 int pos=(-1)*sizeof(st);
			 File.seekp(pos,ios::cur);
			 File.write((char *) &st, sizeof(student));
			 cout<<"\n\n\t Record Updated";
			 found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}
//***************************************************************
//    	function to delete record of file
//****************************************************************
void delete_student(int n)
{
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write((char *) &st, sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";

	getch();
}
//***************************************************************
//    	function to display all students grade report
//****************************************************************
void class_result()
{
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"==========================================================\n";
	cout<<"R.No       Name        P   C   M   E   CS    %      Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.show_tabular();
	}
	inFile.close();
	getch();

}
//***************************************************************
// 				FUNCTION TO GENERATE TOPPERs LIST
//***************************************************************
void showtoppers()
{
	char get;
	inFile.open("student.dat", ios::binary);
	if(!inFile)
	{
		cout <<"The File does not exist !"<<endl;
		return;
	}
	else
	cout <<"\n\n\t\tA GRADERS"<<endl;
	cout<<"==========================================================\n";
	cout<<"R.No       Name        P   C   M   E   CS    %      Grade"<<endl;
	cout<<"==========================================================\n";
	{
	 while(inFile.read((char*)&st, sizeof(student)))
	  {
		 get = st.retgrade();
		 if(get == 'A')
			st.show_tabular();
	  }
	}
	inFile.close();
	getch();
	return;
}
//****************************************************************
//						FUNCTION TO GENERATE FAILURES LIST
//****************************************************************
void showfail()
{
	char get;
	inFile.open("student.dat", ios::binary);
	if(!inFile)
	{
		cout <<"The File does not exist !"<<endl;
		return;
	}
	else
	cout <<"\n\n\t\tFAILURES"<<endl;
	cout<<"==========================================================\n";
	cout<<"R.No       Name        P   C   M   E   CS    %      Grade"<<endl;
	cout<<"==========================================================\n";
	{
	 while(inFile.read((char*)&st, sizeof(student)))
	  {
		 get = st.retgrade();
		 if(get == 'F')
			st.show_tabular();
	  }
	}
	inFile.close();
	getch();
	return;
}
//***************************************************************
//    	function to display result menu
//***************************************************************
void result()
{
	char ch;
	int rno;
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Toppers list";
	cout<<"\n\n\t4. Failures list";
	cout<<"\n\n\t5. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice: ";
	ch = getdigit();
	clrscr();
	switch(ch)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
				display_sp(rno); break;
	case '3' :  showtoppers(); break;
	case '4' :  showfail(); break;
	case '5' :	return;
	default:	cout<<"\a";
	}
	clrscr();
	result();
}
//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************
void intro()
{
	cout<<"\n\n\n\t\t   STUDENT";
	cout<<"\n\n\t\t\tREPORT";
	cout<<"\n\n\t\t\t      APP";
	cout<<"\n\n\n\tDEVELOPERS : SARTHAK SAHU & SARANSH PAWAR"<<endl;
	getch();
	clrscr();
	initialising();
	getch();
}
//***************************************************************
//    	ADMIN MENU FUNCTION
//****************************************************************
void entry_menu()
{
	char ch;
	int num;
	clrscr();
		cout<<"\n\n\n\tADMINISTRATOR MENU";
		cout<<"\n\n\t1.CREATE STUDENT RECORD";
		cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
		cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
		cout<<"\n\n\t4.MODIFY STUDENT RECORD";
		cout<<"\n\n\t5.DELETE STUDENT RECORD";
		cout<<"\n\n\t6.CHANGE LOGIN PASSWORD";
		cout<<"\n\n\t7.BACK TO MAIN MENU";
		cout<<"\n\n\tPlease Enter Your Choice: ";
		ch = getdigit();
		clrscr();
		switch(ch)
		{
		case '1':	write_student(); break;
		case '2':	display_all(); break;
		case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
					display_sp(num); break;
		case '4':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
					modify_student(num);break;
		case '5':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
					delete_student(num);break;
		case '6':  ChangePass();
		case '7':  return;
		default:	cout<<"\a";
	}
	entry_menu();
}
//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
main()
{
	char ch;
	cout.setf(ios::fixed|ios::showpoint); //Normal notation & extra decimal even when not needed.
	cout<<setprecision(2);
	clrscr();
	intro();
	clrscr();
	if(CheckPass()==0)
	{
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. RESULT ";
		cout<<"\n\n\t02. ADMINISTRATOR";
		cout<<"\n\n\t03. EXIT ";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		ch = getdigit();
		clrscr();
		switch(ch)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3': exit(0);
			default :cout<<"\a";
		}
	 }while(ch!='3');
	 }
	else
	exit(-1);
}
//***************************************************************
//    			END OF PROGRAM
//***************************************************************
