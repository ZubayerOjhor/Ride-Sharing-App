#include<iostream>
using namespace std;

class Ride{
public:
int car_base_fare =50;
int motorcycle_base_fare =30;
int bicycle_base_fare =20;

//variables for fare
float distance_fare, duration_fare, total_fare, promo_fare;

float grand_total, online_discount, distance;

//for choosing option;
int vehicle, promo, payment_mode;

public:

//menu for vehicles
void menu()
{
cout<<"1. Car"<<endl;
cout<<"2. Motorcycle"<<endl;
cout<<"3. Bicycle"<<endl;
}

//menu for promos
void menu1()
{
cout<<"\n1. Flat 50 Taka discount"<<endl;
cout<<"2. 20% discount"<<endl;
cout<<"3. 25% discount but max 60 Taka"<<endl;
}

//menu for payment mode
void menu2()
{
cout<<"\n1. Online payment"<<endl;
cout<<"2. Offline payment"<<endl;
}

//function to read input
void input(){
do{
cout<<"Choose the transportation option that you want to use from [1 - 3] = ";
cin>>vehicle;  //reading vehicle type
}while (vehicle < 1 || vehicle > 3);

cout<<"\nEnter the distance to travel(in Kilometers) = ";
cin>>distance; //reading distance

menu1();
do{
cout<<"Choose promo [1 - 3] = ";
cin>>promo;  //reading promo
}while (promo < 1 || promo > 3);

menu2();
do{
cout<<"Choose your payment method [1 or 2] = ";
cin>>payment_mode; //reading payment mode
}while (payment_mode < 1 || payment_mode > 2);
}

//function to do all calculations (distance fare, duration fare,
//total fare, promo fare and grand total

void calculation()
{
//check vehicle type and calculate distance fare, duration fare, total fare
switch (vehicle)
{
//if vehicle is car
case 1:
distance_fare = 25 * distance;
duration_fare = 2 * distance; //duration=(distance/60)*60 minute= distance & duration fare=distance*2
total_fare = car_base_fare + distance_fare + duration_fare;
break;

//if vehicle is motorcycle
case 2:
distance_fare = 15 * distance;
duration_fare = 2 * (distance / 70) * 60;
total_fare = motorcycle_base_fare + distance_fare + duration_fare;
break;

//if vehicle is bicycle
case 3:
distance_fare = 10 * distance;
duration_fare = 2 * distance * 3;
total_fare = bicycle_base_fare + distance_fare + duration_fare;
}

//check promo type and calculate promo fare
switch (promo){
//if promo is flat $50
case 1:
promo_fare = 50;
break;

//if promo is 20%
case 2:
promo_fare = total_fare * 0.2;
break;

//if promo is 25% and max 60
case 3:
//if promo_fare is less than 60
if ((total_fare * 0.25) < 60)
{
promo_fare = total_fare * 0.25;
}

else{
promo_fare = 60;
}
}

//checking payment mode
//if Online
if (payment_mode == 1){
online_discount = promo_fare * 0.1;
}

//if Offline
else
online_discount = 0;

grand_total = total_fare - promo_fare - online_discount;
}

//function to display bill
void display(){
cout<<"\n-----Generated Bill------"<<endl;
cout<<"-------------------------"<<endl;

//checking vehicle type
switch (vehicle){
//if vehicle is car
case 1:
cout<<"Base fare = "<<car_base_fare<< " Taka" <<endl;
cout<<"Distance fare = "<<distance_fare<<" Taka" <<endl;
cout<<"Duration fare = "<<duration_fare<<" Taka" <<endl;
cout<<"Total fare = "<<total_fare<<" Taka" <<endl;
cout<<"Promo fare = "<<promo_fare<<" Taka" <<endl;
cout<<"Online payment discount ="<<online_discount<<" Taka" <<endl;
cout<<"Grand total = "<<grand_total<<" Taka";
break;

//if vehicle is motorcyle
case 2:
cout<<"Base fare = "<< motorcycle_base_fare<<" Taka" <<endl;
cout<<"Distance fare = "<<distance_fare<<" Taka" <<endl;
cout<<"Duration fare = "<<duration_fare<<" Taka" <<endl;
cout<<"Total fare = "<<total_fare<<" Taka" <<endl;
cout<<"Promo fare = "<<promo_fare<<" Taka" <<endl;
cout<<"Online payment discount = "<<online_discount<<endl;
cout<<"Grand total = "<<grand_total<< " Taka";
break;

//if vehicle is bicycle
case 3:
cout<<"Base fare = "<< bicycle_base_fare<<" Taka" <<endl;
cout<<"Distance fare = "<<distance_fare<<" Taka" <<endl;
cout<<"Duration fare = "<<duration_fare<<" Taka" <<endl;
cout<<"Total fare = "<<total_fare<<" Taka" <<endl;
cout<<"Promo fare = "<<promo_fare<<" Taka" <<endl;
cout<<"Online payment discount = "<<online_discount<<" Taka" <<endl;
cout<<"Grand total = "<<grand_total<<" Taka";
}
}
};

//main function
int main()
{
cout<< "                     WELCOME TO CHOLO RIDE-SHARING SERVICE                  "<<endl;
//creating object of Ride class
Ride ride;
cout<< "Available Vehicles For Ride-Sharing Service: "<<endl;
ride.menu();
ride.input();
ride.calculation();
ride.display();

return 0;
}

