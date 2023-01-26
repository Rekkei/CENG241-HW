#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>
using namespace std;

class Villager{
	protected:
		int health;
		int attackP;
	public:
		Villager(){
			health=20;
			attackP=0;
		}
		
		void setHealth(int b){
			health=b;
		}
		int getHealth(){return health;}
		int	attack(Villager &a){return 0;}
};

class Archer:public Villager{

	protected:
		int arrows;
	public:
	
		Archer(){
			health=60;
			attackP=40;
			arrows=5;
		}
		int attack(Villager &c){
			if(c.getHealth()<=0){
				cout<<"Current Heal:"<<c.getHealth()<<endl;
				return -1;
			}
			else if(arrows==0){
				return -2;
			}
			else{
				int rattack=((rand()%attackP)+1);
				arrows--;
				c.setHealth(c.getHealth()-rattack);	
				return rattack;
			}
		}
		int attack(Archer &d){
			if(d.getHealth()<=0){
				cout<<"Current Heal:"<<d.getHealth()<<endl;
				return -1;
			}
			else if(arrows==0){
				return -2;
			}
			else{
				int rattack=((rand()%attackP)+1);
				arrows--;
				d.setHealth(d.getHealth()-rattack);	
				return rattack;
			}
		}
		int getNrofArrows(){return arrows;}
};

int main(){
	srand(time(0));
	string cname1,cname2,attack;
	int k=1,cnumber1,cnumber2;
	Villager villager[5];
	Archer archer[5];
	while(cnumber1!=cnumber2){
		cout<<"Enter command "<<k<<":";
		cin>>cname1;
		cin>>cnumber1;
		cin>>attack;
		cin>>cname2;
		cin>>cnumber2;
		if(cname1==cname2 && cnumber1==cnumber2){
			break;
		}
		if(cname1=="Villager"){
			cout<<cname1<<cnumber1<<" can't attack!"<<endl;
		}
		else{
			
			if(cname2=="Villager"){
				
				if(archer[cnumber1].attack(villager[cnumber2])==-1){
					cout<<cname2<<cnumber2<<" dead!"<<endl;
				}
				else if(archer[cnumber1].attack(villager[cnumber2])==-2){
					cout<<cname1<<cnumber1<<" is out of arrows"<<endl;
				}
				else{
					cout<<cname1<<cnumber1<<" made "<<archer[cnumber1].attack(villager[cnumber2])<<" damage to "<<cname2<<cnumber2<<endl;
				}
					
			}
			else{
				
				if(archer[cnumber1].attack(archer[cnumber2])==-1){
					cout<<cname2<<cnumber2<<" dead!"<<endl;
				}
				else if(archer[cnumber1].attack(archer[cnumber2])==-2){
					cout<<cname1<<cnumber1<<" is out of arrows"<<endl;
				}
				else{
					cout<<cname1<<cnumber1<<" made "<<archer[cnumber1].attack(archer[cnumber2])<<" to "<<cname2<<cnumber2<<endl;
				}
					
			}
			
		}	
		k++;
	}
	return 0;
}
