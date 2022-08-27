#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;



struct Node{
	
	
	int accNum;
	int balnc;
	string name;
	string Lname;
	
	Node *next;
};


struct Data{
		
		Node *head;
		Node *head1;
		int count;
		ofstream wrt;
		ifstream read;

		
			Data(){
				head=NULL;
				head1=NULL;
				count=0;
				
			wrt.open("database.txt",std::ios_base::app);
			read.open("database.txt");
			}
			
			void add(int acNUm,string name,string lastName,int balance){
					
						Node *Nn=new Node;
						Nn->accNum=acNUm;
						Nn->name=name;
						Nn->Lname=lastName;
						Nn->balnc=balance;
						if(!head1){
							Nn->next=head1;
							head1=Nn;
						}
						else{
							Node *curr=head1;
							for(int i=0;i<count;i++){
								curr=curr->next;
							}
							Nn->next=curr->next;
							curr->next=Nn;
							count++;
							
						}
						
						wrt<<Nn->accNum<<"   "<<Nn->name<<"   "<<Nn->Lname<<"    "<<Nn->balnc<<endl;
				
			}
			
			void info(){
				
				count=0;
						
					int acNum;
					while(read>>acNum){
					Node *Nn=new Node;
						Nn->accNum=acNum;
						read>>Nn->name;
						read>>Nn->Lname;
						read>>Nn->balnc;
						if(!head){
							Nn->next=head;
							head=Nn;
						}
						else{
							Node *curr=head;
							for(int i=0;i<count;i++){
								curr=curr->next;
							}
							Nn->next=curr->next;
							curr->next=Nn;
							count++;
							
						}
					}
				
				
				
				
				int opt,id;
				jump:
				cout<<"press 1 for all data 2 for particular data and 3 for return"<<endl;
				cin>>opt;
				if(opt==1){
					
					Node *curr=head;
							while(curr){
								
								cout<<curr->accNum<<"   "<<curr->name<<"   "<<curr->Lname<<"   "<<curr->balnc<<endl;
								curr=curr->next;
							}
					
					
				}
				else if(opt==2){
					
								Node *curr=head;
							cout<<"enter the id of the user"<<endl;
							cin>>id;
							while(curr->accNum!=id){
								curr=curr->next;
							}
								if(curr->accNum==id){
									cout<<curr->accNum<<"   "<<curr->name<<"   "<<curr->Lname<<"   "<<curr->balnc<<endl;
								}
								else{
									cout<<"the ID does not compare"<<endl;
								}
						
				}
			else{
				cout<<"the option is wrong re-enter"<<endl;
							goto jump;
			}
				 
					
			}
			
			
		void update	(){
			
					count=0;
			
						int acNum,id,bal;
					while(read>>acNum){
					Node *Nn=new Node;
						Nn->accNum=acNum;
						read>>Nn->name;
						read>>Nn->Lname;
						read>>Nn->balnc;
						if(!head){
							Nn->next=head;
							head=Nn;
						}
						else{
							Node *curr=head;
							for(int i=0;i<count;i++){
								curr=curr->next;
							}
							Nn->next=curr->next;
							curr->next=Nn;
							count++;
						}
					}
						fopen("database.txt","w");
						ofstream wrt;
						wrt.open("database.txt",std::ios_base::app);
						
						cout<<"enter the id on which updates are to be done"<<endl;
						cin>>id;
						Node *temp=head;
						while(temp->accNum!=id){
							temp=temp->next;
						}
						
						if(temp->accNum==id){
							jump:
							int opt;
							cout<<"1 for Name"<<endl;
							cout<<"2 for Last Name"<<endl;
							cout<<"2 for balance"<<endl;
							cin>>opt;
							if(opt==1){
								cout<<"re-write the name"<<endl;
								cin>>temp->name;
							}
							else if (opt==2){
								cout<<"re-write the last name"<<endl;
								cin>>temp->Lname;
							}
								else if (opt==3){
								cout<<"your current balance is "<<temp->balnc<<endl;
								jump2:
								cout<<"\n\n\n\n\npress 1 to withdraw the money or 2 for depositing money"<<endl;
								cin>>opt;
								if(opt==1){
									cout<<"enter the amount to withdraw"<<endl;
									cin>>bal;
									
									temp->balnc=temp->balnc-bal;
									
								}
								else if(opt==1){
									cout<<"enter the amount to deposit"<<endl;
									cin>>bal;
									
									temp->balnc=temp->balnc+bal;
									
								}
								else{
									
									cout<<"wrong entery retry"<<endl;
									goto jump2;
									
								}
							}
							else{
								cout<<"wrong entery retry"<<endl;
								goto jump;
							}
							
						}
						else{
							cout<<"the id does not exist"<<endl;
						}
						
						Node *curr=head;
						while(curr){
							wrt<<curr->accNum<<"   "<<curr->name<<"   "<<curr->Lname<<"    "<<curr->balnc<<endl;
							curr=curr->next;
						}
				
				
		}
		
		void del(){
			
				count=0;
			
			
			
				int acNum,id;
					while(read>>acNum){
					Node *Nn=new Node;
						Nn->accNum=acNum;
						read>>Nn->name;
						read>>Nn->Lname;
						read>>Nn->balnc;
						if(!head){
							Nn->next=head;
							head=Nn;
						}
						else{
							Node *curr=head;
							for(int i=0;i<count;i++){
								curr=curr->next;
							}
							Nn->next=curr->next;
							curr->next=Nn;
							count++;
						}
					}
					cout<<"enter the id you want to delete"<<endl;
					cin>>id;
					
					
						fopen("database.txt","w");
						ofstream wrt;
						wrt.open("database.txt",std::ios_base::app);
						
						
						Node *temp=head;
						Node *tc=NULL;
						while(temp->accNum!=id){
							tc=temp;
							temp=temp->next;
						}
						if(id==head->accNum){
							
							head=head->next;
							delete temp;
							
						}
						else if(id==temp->accNum){
							tc->next=temp->next;
							delete temp;
						}
						
						Node *curr=head;
						while(curr){
							wrt<<curr->accNum<<"   "<<curr->name<<"   "<<curr->Lname<<"    "<<curr->balnc<<endl;
							curr=curr->next;
						}
						
						
		}
			
			
			
			
			
			
			
			
		
		
};

int main(){
	Data obj;
	int opt,acNum,balnc;
	string name,lname;
	char op='y';
		while(op=='y'){
			
			cout<<"enter 1 to create account"<<endl;
			cout<<"enter 2 for checking information"<<endl;
			cout<<"enter 3 for updating data"<<endl;
			cout<<"enter 4 to delete data"<<endl;
			cout<<"enter 5 to end program"<<endl;
			cin>>opt;
				
				switch(opt){
					
						case 1:
							cout<<"enter account number"<<endl;
							cin>>acNum;
							cout<<"enter name of the person"<<endl;
							cin>>name;
							cout<<"enter last name"<<endl;
							cin>>lname;
							cout<<"enter the deposit amount"<<endl;
							cin>>balnc;
							obj.add(acNum,name,lname,balnc);
						
							break;
							
						case 2:
							system("cls");
							obj.info();
							break;
							
							
							
						case 3:
							system("cls");
							obj.update();
							break;
						
						
						case 4:
							system("cls");
							obj.del();
							break;
						
						case 5:
							system("cls");
							cout<<"Good Bye"<<endl;
							return 0;
							break;
						
							
							default:
								break;
				}
			
			cout<<"do you want to continue"<<endl;
			cin>>op;
			system("cls");
			
			
			
		}

	
	
	
	
}


































