#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
	protected:
	    string brandName;
	    int modelYear;
	    int price;
	
	public:
	    Car(){
	        brandName="";
	        modelYear=0;
	        price=0;
	    }
	    
	    Car(string brandName,int modelYear,int price){
	        this->brandName=brandName;
	        this->modelYear=modelYear;
	        this->price=price;
	    }
	    
	    void setBrandName(string brandName){this->brandName=brandName;}
	    string getBrandName(){return brandName;}
	    void setModelYear(int modelYear){this->modelYear=modelYear;}
	    int getModelYear(){return modelYear;}
	    void setPrice(int price){this->price = price;}
	    int getPrice(){return price;}
};

class ElectricCar:public Car{
	protected:
	    int numberOfBatteries;
	    int electricCost;
	public:
	    ElectricCar():Car(){
	        numberOfBatteries=0;
	        electricCost=0;
	    }

	    ElectricCar(string brandName,int modelYear,int price,int numberOfBatteries,int electricCost){
	    	this->brandName=brandName;
	    	this->modelYear=modelYear;
	    	this->price=price;
	        this->numberOfBatteries=numberOfBatteries;
	        this->electricCost=electricCost;
	    }
	
	    ElectricCar(const ElectricCar& other){
	    	this->brandName=other.brandName;
	    	this->modelYear=other.modelYear;
	    	this->price=price;
	        this->numberOfBatteries=other.numberOfBatteries;
	        this->electricCost=other.electricCost;
	    }

	    void setNumberOfBatteries(int numberOfBatteries){this->numberOfBatteries=numberOfBatteries;}
	    int getNumberOfBatteries(){return numberOfBatteries;}
	    void setElectricCost(int electricCost){this->electricCost = electricCost;}
	    int getElectricCost() { return electricCost; }
	
	    friend ostream& operator<<(ostream& out,const ElectricCar& a) {
	        out<<" 1-Brand name:"<<a.brandName<<endl;
	        out<<" 2-Model year:"<<a.modelYear<<endl;
	        out<<" 3-Price:"<<a.price<<endl;
	        out<<" 4-Number of batteries:"<<a.numberOfBatteries<<endl;
	        out<<" 5-Electric cost:"<<a.electricCost<<endl;
	        return out;
    	}
};

class GasolineCar:public Car{
	protected:
	    int engineVolume;
	    int fuelCost;
	
	public:
	    GasolineCar(){
	        fuelCost=0;
	    }
	
	    GasolineCar(string brandName,int modelYear,int price,int engineVolume,int fuelCost){
	    	this->brandName=brandName;
	    	this->modelYear=modelYear;
	    	this->price=price;
	        this->engineVolume=engineVolume;
	        this->fuelCost=fuelCost;
	    }
	
	    GasolineCar(const GasolineCar& other){
	    	this->brandName=other.brandName;
	    	this->modelYear=other.modelYear;
	    	this->price=price;
	        this->engineVolume=other.engineVolume;
	        this->fuelCost=other.fuelCost;
	    }

	    void setEngineVolume(int engineVolume){this->engineVolume=engineVolume;}
	    int getEngineVolume(){return engineVolume;}
	    void setFuelCost(int fuelCost){this->fuelCost=fuelCost;}
	    int getFuelCost(){return fuelCost;}
	
	    friend ostream& operator<<(ostream& out,const GasolineCar& a) {
	        out<<" 1-Brand name:"<<a.brandName<<endl;
	        out<<" 2-Model year:"<<a.modelYear<<endl;
	        out<<" 3-Price:"<<a.price<<endl;
	        out<<" 4-Engine volume:"<<a.engineVolume << endl;
	        out<<" 5-Fuel cost:"<<a.fuelCost <<endl;
	        return out;
    	}
};

class HybridCar:public ElectricCar,public GasolineCar{
	public:
		HybridCar():ElectricCar(),GasolineCar(){}
		HybridCar(const HybridCar& other) : ElectricCar(other), GasolineCar(other){}
	    friend ostream& operator<<(ostream& out, const HybridCar& a){
	    	out <<" 1-Brand name:"<<a.ElectricCar::brandName<<endl;
	        out <<" 2-Model year:"<<a.ElectricCar::modelYear<<endl;
	        out <<" 3-Price:"<<a.ElectricCar::price<<endl;
	        out <<" 4-Number of batteries:"<< a.ElectricCar::numberOfBatteries<<endl;
	        out <<" 5-Electric cost:"<<a.ElectricCar::electricCost<<endl;
	        out <<" 6-Engine volume:"<<a.GasolineCar::engineVolume<<endl;
	        out <<" 7-Fuel cost:"<<a.GasolineCar::fuelCost<<endl;
	        return out;
    	}	
};

int main(){
    vector<ElectricCar> electricCars;
    vector<HybridCar> hybridCars;
    vector<GasolineCar> gasolineCars;
    string brandName;
    int modelYear;
    int price;
    int numberOfBatteries;
    int electricCost;
    int engineVolume;
    int fuelCost;
    int totalCost=0;
    int minCost=INT_MAX;
    string minCostBrandName;
	int ch;
    while(true){
    	cout<<"1-Electric Car 2- Hybrid Car 3-Gasoline Car 4-Exit:";
    	cin>>ch;
    	if(ch==4){
    		break;
		}
    	else if(ch==1){
	    	cout<<"Enter brand name: ";
	        cin>>brandName;
	        cout<<"Enter model year: ";
	        cin>>modelYear;
	        cout<<"Enter price: ";
	        cin>>price;
	        cout<<"Enter number of batteries: ";
            cin>>numberOfBatteries;
            cout<<"Enter electric cost: ";
            cin>>electricCost;
            ElectricCar car(brandName,modelYear,price,numberOfBatteries,electricCost);
            electricCars.push_back(car);
		}
		else if(ch==2){
			cout<<"Enter brand name: ";
	        cin>>brandName;
	        cout<<"Enter model year: ";
	        cin>>modelYear;
	        cout<<"Enter price: ";
	        cin>>price;
	        cout<<"Enter number of batteries: ";
            cin>>numberOfBatteries;
            cout<<"Enter electric cost: ";
            cin>>electricCost;
            cout<<"Enter engine volume: ";
            cin>>engineVolume;
            cout<<"Enter fuel cost: ";
            cin>> fuelCost;
            HybridCar car;
			car.ElectricCar::setBrandName(brandName);
			car.ElectricCar::setModelYear(modelYear);
			car.ElectricCar::setPrice(price);
			car.ElectricCar::setNumberOfBatteries(numberOfBatteries);
			car.ElectricCar::setElectricCost(electricCost);
			car.GasolineCar::setEngineVolume(engineVolume);
			car.GasolineCar::setFuelCost(fuelCost);
            hybridCars.push_back(car);
		}
		else if(ch==3){
			cout<<"Enter brand name: ";
	        cin>>brandName;
	        cout<<"Enter model year: ";
	        cin>>modelYear;
	        cout<<"Enter price: ";
	        cin>>price;
	        cout<<"Enter engine volume: ";
            cin>>engineVolume;
            cout<<"Enter fuel cost: ";
            cin>>fuelCost;
            GasolineCar car(brandName,modelYear,price,engineVolume,fuelCost);
            gasolineCars.push_back(car);
		}
	
	}                       
	cout<<"Electric cars: "<<endl;
    for(int i=0;i<electricCars.size();i++){
        cout<<electricCars[i];
        cout<<"Total cost: "<<electricCars[i].getElectricCost()<<endl;
    }
    cout<<"Hybrid cars: "<<endl;
    for (int i=0; i<hybridCars.size();i++){
        cout<<hybridCars[i];
        cout<<"Total cost: "<<hybridCars[i].getElectricCost()+hybridCars[i].getFuelCost()<<endl;
    }
    cout<<"Gasoline cars: "<<endl;
    for (int i=0;i<gasolineCars.size();i++){
        cout<<gasolineCars[i];
        cout<<"Total cost: "<< gasolineCars[i].getFuelCost()<<endl;
    }
    
    for (int i=0;i<electricCars.size();i++){
        if(electricCars[i].getElectricCost()<minCost){
            minCost=electricCars[i].getElectricCost();
            minCostBrandName=electricCars[i].getBrandName();
        }
    }
    for (int i=0;i<hybridCars.size();i++){
        int cost=hybridCars[i].getElectricCost()+hybridCars[i].getFuelCost();
        if (cost<minCost){
            minCost=cost;
            minCostBrandName=static_cast<ElectricCar&>(hybridCars[i]).getBrandName();
        }
    }
    for (int i=0;i<gasolineCars.size();i++){
        if (gasolineCars[i].getFuelCost()<minCost){
            minCost=gasolineCars[i].getFuelCost();
            minCostBrandName=gasolineCars[i].getBrandName();
        }
    }
    cout<<"Minimum cost car: "<<minCostBrandName<<endl;                              
return 0;
}
    
    
	

