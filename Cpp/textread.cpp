#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){   
   
   fstream fout;
   fout.open("Transactions.csv", ios::out | ios::app);
   fout <<"Date"<< ", "	<< "Time" << ", "<< "Reciever / Sender" << ", "<< "Amount" << "\n";  //for csv
   
   fstream file;
   file.open("email_data.txt",ios::in); //for text
   
   if (file.is_open()){
      string data,a;
      while(getline(file, data))
	  { //read data from file object and put it into string.
         cout <<data<<"\n";
	  { //read data from file object and put it into string.
	  	 data=data+",";
         cout << data << "\n"; //print the data of the string
		 	string  first="",letter,dataarray[10];
			int i,len,n=0;
			letter=data[0];
			len=data.size();
			for(i=0;i<=len;i++)
			{
				if (letter!=",")
				{
					first=first+letter;
					letter=data[i+1];
				}
				else
				{
					dataarray[n]=first;
					first="";
					n+=1;
					letter=data[i+1];
				}
			}
		 fout << dataarray[0] << ", "
			<< dataarray[1] << ", "
			<< dataarray[2] << ", "
			<< dataarray[3] << ", "
			<< "\n";
		 cout<<"\nDate:"<< dataarray[0];
         cout<<"\nTime:"<<dataarray[1];
         cout<<"\nReciever\sender: "<<dataarray[2];
         cout<<"\nAmount: "<<dataarray[3];
      } 
	}
	file.close();
	}
}

