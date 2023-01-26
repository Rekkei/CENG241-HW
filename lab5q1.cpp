#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class  Course{
	private:
		int mtG,hwG,finG;
		double mtW,hwW,finW;
		string name,letterGrade;
	public:
		void setGrade(int cmtG,int chwG,int cfinG){mtG=cmtG;hwG=chwG;finG=cfinG;}
		void getGrade(){cout<<right<<mtG<<setw(15)<<hwG<<setw(15)<<finG<<setw(15);}
		void setName(string cname){name=cname;}
		void getName(){cout<<endl<<name<<setw(15-name.size());}
		void getLGrade(){cout<<letterGrade;}
		void calculate();
		Course(){
			mtW=0.30;
			hwW=0.20;
			finW=0.50;
		}
		Course(double cmtW,double chwW,double cfinW){
			mtW=cmtW;
			hwW=chwW;
			finW=cfinW;
		}
		
};

void Course::calculate(){
	int sum;
	double a,b,c;
	a=mtG*mtW;
	b=hwG*hwW;
	c=finG*finW;
	sum=a+b+c;
	if(sum<=100 && sum>=90)
		letterGrade="AA";
	else if(sum<89 && sum>=85)
		letterGrade="BA";
	else if(sum<84 && sum>=80)
		letterGrade="BB";
	else if(sum<=79 && sum>=70)
		letterGrade="CB";
	else if(sum<=69 && sum>=60)
		letterGrade="CC";
	else if(sum<=59 && sum>=50)
		letterGrade="DC";
	else if(sum<=49 && sum>=40)
		letterGrade="DD";
	else
		letterGrade="Fail";
	
}

int main(){
	Course c1;
	string name;
	int cg1,cg2,cg3;
	double cw1,cw2,cw3;
	cout<<"Enter weights for second course:";
	cin>>cw1>>cw2>>cw3;
	Course c2(cw1,cw2,cw3);
	cout<<"Enter first course name:";
	cin>>name;
	c1.setName(name);
	cout<<"Enter first course grades:";
	cin>>cg1>>cg2>>cg3;
	c1.setGrade(cg1,cg2,cg3);
	c1.calculate();
	cout<<"Enter second course name:";
	cin>>name;
	c2.setName(name);
	cout<<"Enter second course grades:";
	cin>>cg1>>cg2>>cg3;
	c2.setGrade(cg1,cg2,cg3);
	c2.calculate();
	cout<<endl<<"Course"<<setw(13)<<"Midterm"<<setw(13)<<"Homework"<<setw(13)<<"Final"<<setw(15)<<"Letter";
	c1.getName();
	c1.getGrade();
	c1.getLGrade();
	c2.getName();
	c2.getGrade();
	c2.getLGrade();
}
