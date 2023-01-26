#include<iostream>
using namespace std;

class UpDownNumbers{
	private:
		int start;
		int length;
		int	*numbers;
	public:
		UpDownNumbers(int start,int length){
			this->numbers=new int(length);
			this->start=start;
			this->length=length;
		}
		UpDownNumbers(UpDownNumbers &s){
			length=s.length;
			numbers=new int(length);
		}
		~UpDownNumbers(){
			delete[] numbers;
		}
		void generate(){
			numbers[0]=start;
			for(int i=1;i<length;i++){
				if(numbers[i-1]%2==0){
					numbers[i]=(numbers[i-1]/2)+5;	
				}
				else{
					numbers[i]=(numbers[i-1]*3)-1;
				}
			}
		}
		void print(){
			for(int i=0;i<length;i++){
				cout<<numbers[i]<<" ";
			}
			cout<<endl;
		}
		void setStart(int start){
			this->start=start;	
		}
		int getStart(){return start;}
		int getLength(){return length;}
		
};
 
int main(){
	int start,lenght;
	cout<<"Enter length and start for Object A: ";
	cin>>lenght>>start;
	UpDownNumbers c1(start,lenght);
	c1.generate();
	cout<<"Object A (start:"<<c1.getStart()<<" length:"<<c1.getLength()<<")"<<endl;
	c1.print();
	cout<<"Enter new start for Object B: ";
	cin>>start;
	UpDownNumbers c2=c1;
	
	c2.setStart(start);
	c2.generate();
	cout<<"b.start is now "<<c2.getStart()<<endl;
	cout<<"Object A (start:"<<c1.getStart()<<" length:"<<c1.getLength()<<")"<<endl;
	c1.print();
	cout<<"Object B (start:"<<c2.getStart()<<" length:"<<c2.getLength()<<")"<<endl;
	c2.print();	
		
	return 0;
}
