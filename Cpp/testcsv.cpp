#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Transactions
{
	public:
		int amount[1000];
		string date[1000],time[1000];
};



class sent:public Transactions
{
	public:
		string receiver[1000];
}sending_obj;



class received:public Transactions
{
	public:
		string sender[1000];
}receiving_obj;




int main(){  
   int menu=0; 
   while (menu!=5){
	   cout<<"Menu :-\n1.Search by date\n2.search by name"
		   <<"\n3.search by amount greater than specified"
	       <<"\n4.search by amount less than specified\n5.Exit.\nEnter the choice: ";
	   cin>>menu;
	
	   fstream fin;
	   fin.open("Transactions.csv", ios::in);
	   string line,entry;
	   int j=0,m=0;
	    if (fin.is_open()){
	      string data,a;
	      while(getline(fin, data))
		  { 
		  	 data=data+",";
	         //cout <<"Data is:   " <<data << "\n";
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
			 if (dataarray[3]!=" Amount" && dataarray[3]!=""){
			 	if(stoi(dataarray[3])<0){
			 	sending_obj.amount[j]=stoi(dataarray[3]);
			 	sending_obj.date[j]=dataarray[0];
			 	sending_obj.time[j]=dataarray[1];
			 	sending_obj.receiver[j]=dataarray[2];
			 	j+=1;
			 }
			 else{
			 	receiving_obj.amount[m]=stoi(dataarray[3]);
			 	receiving_obj.date[m]=dataarray[0];
			 	receiving_obj.time[m]=dataarray[1];
			 	receiving_obj.sender[m]=dataarray[2];
				m+=1;
			 }
			 n+=1;
			}
	      } 
		}
	   fin.close();
	   
	   
	   switch(menu)
		{
		   	
			      
			case 1:
			   {
			   	string day,month,year,date;
			   	int i=0,option;
			   	cout<<"\n\nEnter an option: \n1.Detail of money sent\n2.Detail of money received\nEnter option: ";
			   	cin>>option;
			   	cout<<"Enter the Date of the month: ";
			   	cin>>day;
			   	cout<<"Enter the Month number (ex-oct, nov, dec): ";
			   	cin>>month;
			   	month[0] = toupper(month[0]);
			   	cout<<"Enter the Year (ex- 2021,2022): ";
			   	cin>>year;
			   	date=" "+day+" "+month+" "+year+" ";
			   	
			   	
			   	cout<<"The requested date: "<<date;
			   	
			   	
			   	cout<<"\n\nThe required details: ";
			   		switch (option)
					   {			
			   			case 1:{
			   				while(sending_obj.date[i]!=""){
						   		if (sending_obj.date[i]==date){
						   			cout<<"\nDate:"<< sending_obj.date[i];
					         		cout<<"\nTime:"<<sending_obj.time[i];
					         		cout<<"\nReciever: "<<sending_obj.receiver[i];
					         		cout<<"\nAmount: "<<sending_obj.amount[i]<<"\n\n";
				         			}
				         		i+=1;}
							break;
						   	}
						
						case 2:{
							while(receiving_obj.date[i]!=""){
						   		if (receiving_obj.date[i]==date){
						   			cout<<"\nDate:"<< receiving_obj.date[i];
					         		cout<<"\nTime:"<<receiving_obj.time[i];
					         		cout<<"\nSender: "<<receiving_obj.sender[i];
					         		cout<<"\nAmount: "<<receiving_obj.amount[i]<<"\n\n";
					         		}
					         	i+=1;
					         }
							break;
							}
					}
					break;
				}
				
				
					
		   	case 2:
			   {
			   	string day,month,year,date,name="";
			   	int i=0,option;
			   	cout<<"\n\nEnter an option: \n1.Detail of money sent\n2.Detail of money received\nEnter option: ";
			   	cin>>option;
			   	cout<<"Enter the Name of the Sender/Receiver: ";
			   	cin>>name;
			   	name="  "+name+"  ";
			   	switch(option){
			   		case 1:{
			   			while(sending_obj.receiver[i]!="")
				   		{
				   			if (sending_obj.receiver[i].find(name))
							{
				   				cout<<"\nDate:"<< sending_obj.date[i];
				         		cout<<"\nTime:"<<sending_obj.time[i];
				         		cout<<"\nSender: "<<sending_obj.receiver[i];
				         		cout<<"\nAmount: "<<sending_obj.amount[i]<<"\n\n";
			         		}
			         		i+=1;
				    	}	
						break;
					   }
					case 2:{
						while(receiving_obj.sender[i]!="")
				   		{
				   			if (receiving_obj.sender[i].find(name))
							{	
				   				cout<<"\nDate:"<< receiving_obj.date[i];
				         		cout<<"\nTime:"<<receiving_obj.time[i];
				         		cout<<"\nSender: "<<receiving_obj.sender[i];
				         		cout<<"\nAmount: "<<receiving_obj.amount[i]<<"\n\n";
			         		}
			         		i+=1;
				    	}	
						break;
					}
			   	}
				break;
			}
			
			
		   	case 3:
			   {
			   	string day,month,year,date;
			   	int i=0,option,amt;
			   	cout<<"\n\nEnter an option: \n1.Detail of money sent\n2.Detail of money received\nEnter option: ";
			   	cin>>option;
			   	cout<<"Enter the Amount to be compared: ";
			   	cin>>amt;
			   	switch(option){
			   		case 1:{
			   			amt=amt*(-1);
  						cout<<"The Amounts in Transactions: "<<endl;
  						ofstream MyFile("EntryRequest(option 3_1).txt");
  						MyFile << "search by amount greater than specified\n\n";
  						for (int i = 0; i < 999; i++){
							if (sending_obj.amount[i]<=amt && sending_obj.amount[i]!=0){
								cout<<"\nDate:"<< sending_obj.date[i];
				         		cout<<"\nTime:"<<sending_obj.time[i];
				         		cout<<"\nSender: "<<sending_obj.receiver[i];
				         		cout<<"\nAmount: "<<sending_obj.amount[i]<<"\n\n";
				         		MyFile << sending_obj.date[i];
   								MyFile << sending_obj.time[i];
   								MyFile << sending_obj.receiver[i];
   								MyFile << sending_obj.amount[i];
   								MyFile <<"\n\n";
						   		}
							}
				break;
				MyFile.close();
			   }
			   case 2:{
			   		  	cout<<"The Amounts in Transactions: "<<endl;
			   		  	ofstream MyFile("EntryRequest(option 3_2).txt");
			   		  	MyFile << "search by amount greater than specified\n\n";
  						for (int i = 0; i < 999; i++){
							if (receiving_obj.amount[i]>=amt && receiving_obj.amount[i]!=0){
								cout<<"\nDate:"<< receiving_obj.date[i];
				         		cout<<"\nTime:"<<receiving_obj.time[i];
				         		cout<<"\nSender: "<<receiving_obj.sender[i];
				         		cout<<"\nAmount: "<<receiving_obj.amount[i]<<"\n\n";
				         		MyFile << receiving_obj.date[i];
   								MyFile << receiving_obj.time[i];
   								MyFile << receiving_obj.sender[i];
   								MyFile << receiving_obj.amount[i];
   								MyFile <<"\n\n";
						   		}
							}
				break;
				MyFile.close();
			   }
			   }
			   break;
			   }
			   
			   
			   
		   	case 4:
			   {
			   	string day,month,year,date;
			   	int i=0,option,amt;
			   	cout<<"\n\nEnter an option: \n1.Detail of money sent\n2.Detail of money received\nEnter option: ";
			   	cin>>option;
			   	cout<<"Enter the Amount to be compared: ";
			   	cin>>amt;
			   	switch(option){
			   		case 1:{
			   			amt=amt*(-1);
  						cout<<"The Amounts in Transactions: "<<endl;
  						ofstream MyFile("EntryRequest(option 4_1).txt");
  						MyFile << "search by amount less than specified\n\n";
  						for (int i = 0; i < 999; i++){
							if (sending_obj.amount[i]>=amt && sending_obj.amount[i]!=0){
								cout<<"\nDate:"<< sending_obj.date[i];
				         		cout<<"\nTime:"<<sending_obj.time[i];
				         		cout<<"\nSender: "<<sending_obj.receiver[i];
				         		cout<<"\nAmount: "<<sending_obj.amount[i]<<"\n\n";
				         		MyFile << sending_obj.date[i];
   								MyFile << sending_obj.time[i];
   								MyFile << sending_obj.receiver[i];
   								MyFile << sending_obj.amount[i];
   								MyFile <<"\n\n";
						   		}
							}
							MyFile.close();
			   }
			   case 2:{
  						cout<<"The Amounts in Transactions: "<<endl;
  						ofstream MyFile("EntryRequest(option 4_2).txt");
  						MyFile << "search by amount less than specified\n\n";
  						for (int i = 0; i < 999; i++){
							if (receiving_obj.amount[i]<=amt && receiving_obj.amount[i]!=0){
								cout<<"\nDate:"<< receiving_obj.date[i];
				         		cout<<"\nTime:"<<receiving_obj.time[i];
				         		cout<<"\nSender: "<<receiving_obj.sender[i];
				         		cout<<"\nAmount: "<<receiving_obj.amount[i]<<"\n\n";
   								MyFile << receiving_obj.date[i];
   								MyFile << receiving_obj.time[i];
   								MyFile << receiving_obj.sender[i];
   								MyFile << receiving_obj.amount[i];
   								MyFile <<"\n\n";
						   		}
							}
				break;
				MyFile.close();  
			   }
			   }
				break;
			   }
			   
			   
			   
			case 5:
			{
				menu=5;
				break;
			}
			default:
			{
				cout<<"\n\nthe menu:\n\n"<<menu<<endl;
				cout<<"Enter a correct input\n";
				break;
			}	
  		}
  		}
	}	
   //ofstream MyFile("EntryRequest.txt");
   //MyFile << entry;
   //MyFile.close();          //for Required entry	


