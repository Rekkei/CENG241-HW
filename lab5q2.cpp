#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class  Contact{
	private:
		string name;
		string number;
	public:
		Contact(){
			name="Unknow";
			number="0";
		}
		Contact(string a,string b){
			name=a;
			number=b;
		}
		void print(string c){
			if(c=="Light"){
				cout<<"Name"<<name<<","<<"Number"<<number<<endl;
				
			}
			if(c=="Headers"){
				cout<<"Name"<<name<<endl;
				cout<<"Number"<<number<<endl;
			}
			
		}
		void setName(string cname){name=cname;}
		string getName(){return name;}
		void setNum(string cnum){number=cnum;}
		string getNum(){return number;}
};

class  AdressBook{
	private:
		int nrofcontacts=0;
		Contact contacts[20];
		int search(string e){
			for(int i=0;i<nrofcontacts;i++){
				if(e==contacts[i].getName()){
					return i;
				}	
			}
				return -1;
		}
	public:
		void print(){
			int i;
			cout<<"Name"<<setw(20)<<"Number"<<endl;
			for(i=0;i<nrofcontacts;i++){
				cout<<contacts[i].getName()<<setw(24-contacts[i].getName().size())<<contacts[i].getNum()<<right<<endl;
			}
		}
		bool remove(string d){
			int i=search(d);
			if(search(d)!=-1){
				for(int j=0;j<nrofcontacts;j++){
					contacts[i]=contacts[i+1];	
				}
				nrofcontacts--;
				return true;
			}
				
			else
				return false;
			
		}
		bool add(Contact f){
			int i=search(f.getName());
			if(search(f.getName())==-1){
				contacts[nrofcontacts]=f;
				nrofcontacts++;
				return true;
			}	
			else{
				cout<<"Contact already exist"<<endl;
				return false;	
			}		
		}
		
};

int main(){
	int ch;
	string cname,cnumber;
	AdressBook ab;
	Contact c1;
	do{
		cout<<"1.Display Adress Book\n2.Add New Contact\n3.Remove Contact\n4.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch){
		case 1:
			ab.print();	
			break;
			
		case 2:
			cout<<"Enter name:";
			cin>>cname;
			cout<<"Enter number:";
			cin>>cnumber;
			c1.setName(cname);
			c1.setNum(cnumber);
			if(ab.add(c1)){
				cout<<"Contact added"<<endl;
			}
			break;
		case 3:
			cout<<"Enter name:";
			cin>>cname;
			if(ab.remove(cname)){
				cout<<"Contact removed"<<endl;
			}
			
			break;
		case 4:
			cout<<"Goodbye";
			return 0;	
		}
	}while(true);
	
	
	//return 0;
}