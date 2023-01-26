#include<iostream>
#include<string>
using namespace std;

class CoffeeMachine{
	public:
		CoffeeMachine(){
			coffee=0;
		}
		void addCoffee(int a){
			coffee+=a;
		}
	protected:
		int coffee;
			
			
};

class LatteMachine:public CoffeeMachine{
	private:
		int milk;
	public:
		
		LatteMachine(){
			milk=0;
			coffee=0;
		}
		
		int makeLatte(int c){
			if(coffee>=c && milk>=c){
				coffee-=c;
				milk-=c;
				return 0;
			}
				
			else if(milk<c && coffee>=c){
				return -2;
			}
			
			else 
				return -1;
			
		}
		
		void addMilk(int b){
			milk+=b;
		}
};

class FilterCoffeeMachine:public CoffeeMachine{
	public:
		int makeFilterCoffee(int d){
			if(coffee>=d){
				coffee-=d;
				return 0;
			}
			else{
				return -1;
			}		
		}
};


int main(){
	string chc;
	int chn,cha;
	FilterCoffeeMachine filter;
	LatteMachine latte;
	while(chc!="none"){
		cout<<"Filter or latte?";
		cin>>chc;
		if(chc=="none"){
			break;
		}
		cout<<"How many cups of coffee do you want?";
		cin>>chn;
		
		
		if(chc=="filter"){
			while(filter.makeFilterCoffee(chn)!=0){
				if(filter.makeFilterCoffee(chn)==-1){
					cout<<"Not enough coffee!"<<endl;
					cout<<"Add:";
					cin>>cha;
					filter.addCoffee(cha);		
				}
			}
			cout<<"Enjoy"<<endl;
		}
		
		else if(chc=="latte"){
			while(latte.makeLatte(chn)!=0){
				if(latte.makeLatte(chn)==-1){
					cout<<"Not enough coffee!"<<endl;
					cout<<"Add:";
					cin>>cha;
					latte.addCoffee(cha);
					
				}
				else if(latte.makeLatte(chn)==-2){
					cout<<"Not enough milk"<<endl;
					cout<<"Add:";
					cin>>cha;
					latte.addMilk(cha);	
				}	
			}
			cout<<"Enjoy"<<endl;
		}
	}
	return 0;
}
