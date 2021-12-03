/* Paul Cabrera
this program give the user the opportunity to type a text 
and then allow him to chose how he wants to  read it*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



void menu(int&option,string text,int loc,int locc);
void read1(string& text);
void read2(string& text,int loc);   //func prot
void read3(string& text,int loc,int locc);
void read4(string& text);
void read5(string& text);

void write(string& text);

int main(int argc, char** argv) {
	
	int option=0;
	string text;
	int optionn;
	int loc;
	int locc;
	

	
	
		write(text);
		
		int pp;
 
 while(pp!=1)
 {
	menu(option,text,loc,locc);
	
	cout << endl << "press 2 to select another option or 1 to exit" << endl;
			 cin >> pp;
}



	
	
	return 0;
}



void menu(int&option,string text,int loc,int locc)
{
	
 
 	cout << endl <<  "\:::::MENU::::::/" << endl;
	 cout <<"1) READ FROM THE BEGINNING OF THE FILE"<<endl;
	 cout <<"2) READ FROM ANY SPECIFIC LOCATION TO THE END OF THE FILE"<<endl;
	 cout <<"3) READ FROM ANY SPECIFIC LOCATION  TO ANY SPECIFIC LOCATION "<<endl;
	 cout <<"4) READ IN REVERSE ORDER  ";
	 cin >> option;
	 
	 cout << endl;
	 
	 if(option==1)
	 {
	 	read1(text);
	 }
	  	else if(option==2)
		  {
		  	read2(text,loc);
		  }
		  
		   else if(option==3)
		   {
		   	read3(text,loc,locc);
		   }
		   
		    else if(option==4)
		    {
		    	 option=0;
		    	cout << "1) READ FROM THE END TO THE BEGINNING\n";
		    	cout << "2) READ FROM POSITION 50 TO 20\n";
		    	cin >> option;
		    	
		    	 if(option==1)
		    	 {
		    	 	 read4(text);
				 } else if (option==2)
				 {
				 	 read5(text);
				 	
				 }
			}
			
			 
			 
	
 }
 		
	 


void write(string& text)
{
	ofstream myfile;
	myfile.open("data.txt",ios::out);
	if(myfile.fail())
	{
		cout<<"Cant find the file\n";
		
	}
	
	
	 cout << "TYPE THE INFO FOR THE FILE: \n" <<endl;
	 getline(cin,text); 
	 
	  myfile << text;
	  
	   myfile.close();
	 
}


void read1(string& text)
{
ifstream myfile;
	myfile.open("data.txt",ios::in);
	if(myfile.fail())
	{
		cout<<"Cant find the file\n";
		
	}
	

		myfile.seekg(0,ios::beg);
 
	
getline(myfile,text);
cout << text;
		
	myfile.close();
		
}

void read2(string& text,int loc)
{
	
	ifstream myfile;
	myfile.open("data.txt",ios::in);
	if(myfile.fail())
	{
		cout<<"Cant find the file\n";
		
	}
	
	cout << "Enter beginning position\n";
	cin >> loc;
	

	
	 myfile.seekg(loc);
	 
	 getline(myfile,text);
	  
	  cout << text;
	
		
	
	myfile.close();
	

}

void read3(string& text,int loc,int locc)
{
	
		ifstream myfile;
	myfile.open("data.txt",ios::in);
	if(myfile.fail())
	{
		cout<<"Cant find the file\n";
		
	}
	
	
	 
	 
	
	cout << "Enter beginning position\n";
	cin >> loc;
		
	cout << "Enter the final position\n";
	cin >> locc;
	

	
	
	for(int i=loc;i<=locc;i++)
{
	cout << text[i];
}
	myfile.close();
	
	
}

void read4(string& text)
{
	
		ifstream myfile;
	myfile.open("data.txt",ios::in);
	if(myfile.fail())
	{
		cout<<"Cant find the file\n";
		
	}
	

			myfile.seekg(0,ios::end);
 	int finalp= myfile.tellg();	
	for(int i=finalp;i>=0;i--)
	{
		cout << text[i];
	}
	
		myfile.close();
	
	
}
void read5(string& text)

{

		ifstream myfile;
	myfile.open("data.txt",ios::in);
	if(myfile.fail())
	{
		cout<<"Cant find the file\n";
		
	} 
	
			myfile.seekg(49,ios::beg);
	int fifty;
	fifty=myfile.tellg();

	myfile.seekg(19,ios::beg);
	int twenty;
	twenty=myfile.tellg();	

		for(int i=fifty;i>=twenty;i--)
		{
			cout << text[i];
		}
		
		
	myfile.close();
	 
	 
	
}
