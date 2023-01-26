#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class NumbersClass
{
private:
    int *numbers;
    int length;

    bool isPrime(int num){
    if (num == 1)
    {
        return false;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

public:
    NumbersClass(){
	    length = 0;
	    numbers = new int[length];
	}

    NumbersClass(int length){
	    this->length = length;
	    numbers = new int[length];
	}

    NumbersClass(NumbersClass &a){
	    length = a.length;
	    numbers = new int[length];
	
	    for (int i = 0; i < length; i++)
	    {
	        numbers[i] = a.numbers[i];
	    }
	}

    ~NumbersClass(){
    	delete[] numbers;
	}

    void setLength(int length){
	    this->length = length;
	    numbers = new int[length];
	}

    void generate(){
	    srand(time(0));
	
	    for (int i = 0; i < length; i++)
	    {
	        numbers[i] = rand() % 1000;
	    }
	}

    void filter(string a){
	    if (a == "prime")
	    {
	        for (int i = 0; i < length; i++)
	        {
	            if (!isPrime(numbers[i]))
	            {
	                numbers[i] = -1;
	            }
	        }
	    }
	
	    else if (a == "nonprime")
	    {
	        for (int i = 0; i < length; i++)
	        {
	            if (isPrime(numbers[i]))
	            {
	                numbers[i] = -1;
	            }
	        }
	    }
	}

    void print(){
	    for (int i = 0; i < length; i++)
	    {
	        if (numbers[i]>0)
	        {
	            cout << numbers[i] << " ";
	        }
	    }
	
	    cout << endl;
	}
};
int main()
{
    int length;

    cout << "Enter length: ";
    cin >> length;

    NumbersClass c1(length);
    c1.generate();

    NumbersClass c2(c1);
    NumbersClass c3(c1);

    c2.filter("prime");
    c3.filter("nonprime");

    cout << "A: ";
    c1.print();

    cout << "B: ";
    c2.print();

    cout << "C: ";
    c3.print();

    return 0;
}