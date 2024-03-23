#include<iostream>
#include<math.h>
#include<cmath>
#include<algorithm>
using namespace std;


//Constants
float R = 0.08314;//Gas Constant
float Pt = 1;//total pressure
float Rh = 0.6;
float z=0.0025;//film thickness


//Calculating pressure from Antoine Equation
float get_pressure(float T){
    float P;
    float x = 13.8573-(5160.2/T);

    P=pow(2.718,x);

    return P;
}

//Calculating Diffusivity
float get_diffusivity(float T){
    float D;
    D=pow(T,1.5)*4.985*pow(10,-9);
    return D;
}

//calculating Flux Na
float get_flux(float D, float P1, float P2, float T){
    float ans;
    ans = D*Pt/(R*T*z)*log(((Pt-P2)/(Pt-P1)));
    return ans;
}

int main(){
    //DECLARING VARIABLES
    float Ta; //temperature air
    float Tb; //temperature of watr
    float PA2;//Pa2bar, vapour pressure at point 2
    float PA1;// PA1 bar, vapour pressure at point 1
    float Dab;//diffusivity of water 
    float Na;
    //taking input from user

    cout<<"Enter the value of Temperature of air"<<endl;
    cin>>Ta;

    cout<<"Enter the value of Temperature of water"<<endl;
    cin>>Tb;

    //Calculating PA2 and PA1 and Dab
    PA1=Rh*get_pressure(Ta);
    PA2=get_pressure(Tb);
    Dab=get_diffusivity((Ta+Tb)/2);


    //printing diffusivity and pressures
    cout<<"Dab= "<<Dab<<" PA1= "<<PA1<<" PA2= "<<PA2<<endl;

    //Calculating Flux
    Na=get_flux(Dab,PA1,PA2,Tb);
    

    cout<<"Printing the value of flux at this temp "<<Na<<""<<endl;

    return 0;
}

