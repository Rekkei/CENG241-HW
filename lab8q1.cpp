#include <iostream>
#include <string>

using namespace std;

class Calculator{

	private:
		int length;
		float *numbers = {nullptr};
		
	public:
		Calculator(){
			length = 0;
			numbers = new float(length);
		}
		Calculator(int taken){
			length = taken;
			numbers = new float(length);
		}
		~Calculator(){
			delete [] numbers;
		}
		void setNum(int a,int floor){numbers[floor] = a;}
		int getLength(){return length;}
		Calculator operator+(const Calculator &src){
			Calculator temp;
			if( src.length < length){
				temp.numbers = new float(length);
				temp.length = length;
			}
			else{
				temp.length = src.length;
				temp.numbers = new float(src.length);
			}	
			for(int i = 0; i < temp.length ; i++){
				temp.numbers[i] = src.numbers[i] + numbers[i];
			}
			return temp;
		}
		Calculator operator-(const Calculator &src){
			Calculator temp;
			if( src.length < length){
				temp.numbers = new float(length);
				temp.length = length;
			}
			else{
				temp.length = src.length;
				temp.numbers = new float(src.length);
			}	
			for(int i = 0; i < temp.length ; i++){
				temp.numbers[i] = src.numbers[i] - numbers[i];
			}
			return temp;
		}
		Calculator operator*(const Calculator &src){
			Calculator temp;
			if( src.length < length){
				temp.numbers = new float(length);
				temp.length = length;
			}
			else{
				temp.length = src.length;
				temp.numbers = new float(src.length);
			}	
			for(int i = 0; i < temp.length ; i++){
				temp.numbers[i] = src.numbers[i] * numbers[i];
			}
			return temp;
		}
		Calculator operator/(const Calculator &src){
			Calculator temp;
			if( src.length < length){
				temp.numbers = new float(length);
				temp.length = length;
			}
			else{
				temp.length = src.length;
				temp.numbers = new float(src.length);
			}	
			for(int i = 0; i < temp.length ; i++){
				temp.numbers[i] = src.numbers[i] / numbers[i];
			}
			return temp;
		}
		Calculator operator=(const Calculator &src){
		if (this == &src) 
        		return *this;
        		
   			delete [] numbers;
    		numbers = new float(src.length);
   			for(int i = 0; i < src.length; i++){
   				numbers[i] = src.numbers[i]; 
			   }
   		 	return *this;
		}
		friend ostream& operator<<(ostream &os, const Calculator &src){
			for(int i = 0; i < src.length; i++)
				os <<  src.numbers[i] << " " ;
		return os;
		}
		
		
};

int main(){

	int len1,len2;
	string ch;
	cout << "Input lengths of the first and second number set: ";
	cin >> len1 >> len2;
	Calculator c1(len1), c2(len2);
	
	cout << "First set entered: ";
	for(int i = 0; i < c1.getLength(); i++){
		cin >> len1;
		c1.setNum(len1,i);
	}
	cout << "Second set entered: ";
	for(int i = 0; i < c2.getLength(); i++){
		cin >> len1;
		c2.setNum(len1,i);
	}

	while(ch!="exit"){
		cout << "\nEnter operation: "<<;
		cin >> ch;
		if(ch=="+"){
			cout << c2+c1;
		}
		else if(ch=="-"){
			cout << c2-c1;
		}
		else if(ch=="*"){
			cout << c2*c1;
		}
		else if(ch=="/"){
			cout << c2/c1;
		}
	}
	return 0;
}
