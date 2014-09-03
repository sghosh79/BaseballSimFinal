//
//  main.cpp
//  BaseballSimCPP
//
//


#include <time.h>
#include <ctime>
#include <random>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>


using namespace std;

int awayOuts = 0;
int homeOuts = 0;

int basesEmptyAway = 1;
int firstBaseAway = 0;
int firstBaseSecondBaseAway = 0;
int firstBaseThirdBaseAway = 0;
int basesLoadedAway = 0;
int secondBaseAway = 0;
int secondBaseThirdBaseAway = 0;
int thirdBaseAway = 0;

double walkRangeMaxAway;
double strikeoutRangeMaxAway;
double groundoutRangeMaxAway;
double flyoutRangeMaxAway;
double singleRangeMaxAway;
double doubleRangeMaxAway;
double tripleRangeMaxAway;
double homerunRangeMaxAway;

double walkPercentAway;
double strikeoutPercentAway;
double groundoutPercentAway;
double flyoutPercentAway;
double singlePercentAway;
double doublePercentAway;
double triplePercentAway;
double homerunPercentAway;

int awayTeamScore = 0;
int homeTeamScore = 0;

int counterAway = 1;
int counterHome = 1;

int counterAwayTwo = 1;

double r() {
    
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
    double value = dis(gen);
    double c = dis(gen);
    cout << "r value is " << value << endl;
    cout << "c value is " << c << endl;
    
    return 0;
}

double c;

class Batter{
public:
    string name;
    double obp, slug, avg, strikeoutRate, walkRate, flyoutRate, groundoutRate, avgPitchesPerAB, homerunRate, singleRate, doubleRate, tripleRate;
    
};


void walk(double param){
    
    cout << "c value is " <<param << endl;
    
    if(basesEmptyAway == 1) {
        basesEmptyAway = 0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
    
    else if(firstBaseAway == 1) {
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
    
    else if(firstBaseSecondBaseAway == 1) {
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
    
    else if(firstBaseThirdBaseAway == 1) {
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
    
    else if(basesLoadedAway == 1) {
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
        awayTeamScore += 1;}
    
    
    else if(secondBaseAway == 1) {
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
    
    else if(secondBaseThirdBaseAway == 1) {
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
    
    else if(thirdBaseAway == 1) {
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
    
    counterAwayTwo++;
    
    cout << "walk" <<endl <<endl;
}

void awayStrikeout (double param){
    
    cout << "c value is " <<param << endl;
    
    awayOuts +=1;
    cout << "Strikeout" <<endl <<endl;
    counterAwayTwo++;
    
    if (awayOuts %3 ==0 && awayOuts >0 ){
        {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
    
}


void flyout(double param){
    
    if(basesEmptyAway ==1){
        
        cout <<"c value is "<< param <<endl;
        
        
        basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
        awayOuts+=1;
        
        counterAwayTwo++;
        
        cout<<"flyout"<<endl <<endl;
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    if(firstBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        if(param >= 0 && param <=.25){
            //runner tags up
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        else{
            // runner doesn't tag up
            basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        
        awayOuts ++;
        
        counterAwayTwo++;
        
        cout<<"flyout"<<endl <<endl;
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    
    else if(firstBaseSecondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if(param >= 0 && param <=.9){
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        else if (param > .9 && param <= .95){
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0;}
        else {
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        
        awayOuts ++;
        
        counterAwayTwo++;
        
        cout<<"flyout"<<endl <<endl;
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    
    else if(firstBaseThirdBaseAway == 1) { //a run scoring or tagging up is dependent on the number of outs, i.e. two outs doesn't matter what runners do
        
        cout <<"c value is "<< param <<endl;
        
        
        if(param >= 0 && param <=.6){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        
        else if(param > .6 && param <= .9){
            {basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
                //make sure outs are incrementing correctly
                if(awayOuts % 3 != 2) {awayTeamScore ++;}
            }
        }
        
        else{
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0;}
        awayOuts +=1;
        
        counterAwayTwo++;
        
        cout<<"flyout"<<endl <<endl;
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
    }
    
    
    else if(basesLoadedAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if(param >=0 && param <=.25)
            
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            
            if(awayOuts % 3 != 2) {awayTeamScore += 1;}
            else {awayTeamScore += 0;}
        }
        
        else if(param > .25 &&  param <= .5)
        {basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0;
            
            if(awayOuts % 3 != 2) {awayTeamScore += 1;}
            else{awayTeamScore += 0;}}
        
        else if(param > .5 && param <= .75)
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;  if(awayOuts % 3 != 2) {awayTeamScore += 1;} else{awayTeamScore +=0;}}
        
        else {
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
        
        awayOuts+=1;
        
        counterAwayTwo++;
        
        cout<<"flyout"<<endl <<endl;
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
    }
    
    
    else if(secondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if(param >= 0 && param <=.77){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        else {
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;
        }
        awayOuts +=1;
        
        counterAwayTwo++;
        
        cout<<"flyout"<<endl <<endl;
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    
    else if(secondBaseThirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        
        if(param >=0 && param <=.19){
            {   basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;}
            
            if(awayOuts % 3 != 2) {awayTeamScore ++;}
        }
        
        else if(param >.19 && param <=.38){
            {   basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            
            if(awayOuts % 3 != 2) {awayTeamScore ++;}
        }
        
        
        else{
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0;
        }
        awayOuts +=1;
        
        
        counterAwayTwo++;
        
        cout<<"flyout"<<endl <<endl;
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    
    else if(thirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        
        if (param >= 0 && param <= .38){
            basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            if(awayOuts % 3 != 2) {awayTeamScore += 1;}
            
        }
        
        
        else {
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;}
        
        awayOuts +=1;
        
        counterAwayTwo++;
        
        cout<<"flyout"<<endl <<endl;
        
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    
}



void groundout(double param){
    
    if(basesEmptyAway ==1){
        
        cout <<"c value is "<< param <<endl;
        
        basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
        awayOuts+=1;
        
        counterAwayTwo++;
        cout <<"groundout"<<endl <<endl ;
        
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
    }
    
    
    else if(firstBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        if (param >= 0 && param <= .4){
            
            //runner advances, guy at first thrown out
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayOuts += 1;
            
            counterAwayTwo++;
            cout <<"groundout"<<endl <<endl ;
            
            
            if (awayOuts %3 ==0 && awayOuts >0 ){
                {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
                cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
            
        }
        else if (param > .4 && param <= .8)
            //runner at second is thrown out, runner safe at first
        {     basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayOuts += 1;
            
            counterAwayTwo++;
            cout <<"groundout"<<endl <<endl ;
            
            
            if (awayOuts %3 ==0 && awayOuts >0 ){
                {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
                cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
            
        }
        
        else
            //double play
        {     basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            if( (awayOuts % 3) == 2)
            {awayOuts += 1;
            }
            else{
                awayOuts += 2;
            }
            cout <<"double play" <<endl;
            
            counterAwayTwo++;
            
            
            if (awayOuts %3 ==0 && awayOuts >0 ){
                {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
                cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        }
        
        
    }
    
    
    else if(firstBaseSecondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if (param >= 0 && param <= .3){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayOuts +=1;
        }
        
        else if (param > .3 && param <= .55){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0; awayOuts +=1;
        }
        
        else if (param > .55 && param <= .75){
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            awayOuts += 1;
        }
        
        else
            //double play
        {   if(param > .75 && param <= .85)
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;}
            
        else if(param > .85 && param <= .95)
        { basesEmptyAway = 0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            
        else
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            
            
            if( (awayOuts % 3) == 2)
            {awayOuts += 1;
            }
            else{
                awayOuts += 2;
            }
            
            cout <<"double play" <<endl;
            
        }
        
        counterAwayTwo++;
        cout <<"groundout"<<endl <<endl ;
        
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    else if(firstBaseThirdBaseAway == 1) { //a run scoring or tagging up is dependent on the number of outs, i.e. two outs doesn't matter what runners do
        
        cout <<"c value is "<< param <<endl;
        
        
        if (param >=0 && param <= .58){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            
            awayOuts +=1;
        }
        
        else if (param > .58 && param <= .7)
            
        {basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            //make sure outs are incrementing correctly
            
            awayOuts +=1;
            
            if (awayOuts % 3 == 0 || awayOuts % 3 == 1)
            {awayTeamScore +=1;}
        }
        
        else if (param > .7 && param <= .95)
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0;
            awayOuts +=1;}
        
        else
            //double play
        {   if(param > .95 && param <= .975)
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;}
            
            if(param > .975)
            { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
                
                if( (awayOuts % 3) == 0)
                {awayTeamScore += 1;
                }
            }
            
            if( (awayOuts % 3) == 2)
            {awayOuts += 1;
            }
            else{cout <<"double play" <<endl;
                awayOuts += 2;
            }
        } //else double play bracket closed here
        
        
        counterAwayTwo++;
        cout <<"groundout"<<endl <<endl ;
        
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
        
    }
    
    
    else if(basesLoadedAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if (param >=0 && param <= .3){
            //runner at second tagged out at third
            { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
                
                awayOuts+=1;
                
                if(awayOuts % 3 != 2)
                { awayTeamScore += 1;
                }
            }
        }
        
        else if (param > .3 && param <= .6){
            //batter tagged out at first
            {basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0; if(awayOuts % 3 != 2) {awayTeamScore += 1;}
            }
            awayOuts+=1;}
        
        else if (param > .6  && param <= .9){ //runner at first tagged out at second
            { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;  if(awayOuts % 3 != 2) {awayTeamScore += 1;}
            }
            awayOuts+=1;}
        
        else if (param >.9 && param <= .95)
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;         awayOuts+=1; } //runner at third is tagged out
        else
            //double play
        {   if(param > .95 && param <= .97) //runner at third base scores, while players tagged out going to first and second, runner at third safe
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;}
            
        else if(param > .97 && param <= .98) //runner at third base scores, while players tagged out going to second and third, batter running to first is safe
        { basesEmptyAway = 0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            
        else //runner at third base scores, while players tagged out going to first and third, runner going to second is safe
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            
            if( (awayOuts % 3) == 0)
            {awayTeamScore += 1;
            }
            
            if( (awayOuts % 3) == 2)
            {awayOuts += 1;
            }
            
            else{cout <<"double play" <<endl;
                awayOuts += 2;
            }
        }
        
        counterAwayTwo++;
        cout <<"groundout"<<endl <<endl ;
        
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    
    else if(secondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if (param >= 0 && param <= .68){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        
        else {
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;}
        
        awayOuts +=1;
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
        
        counterAwayTwo++;
        cout <<"groundout"<<endl <<endl ;
        
        
        
    }
    
    
    else if(secondBaseThirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        if (param >= 0 && param <= .3){
            
            {   basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1; if(awayOuts % 3 != 2) {awayTeamScore += 1;}
            }
        }
        
        else {
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0;}
        
        awayOuts +=1;
        
        counterAwayTwo++;
        cout <<"groundout"<<endl <<endl ;
        
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    
    else if(thirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        if (param >= 0 && param <= .38){
            
            {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
                if(awayOuts % 3 != 2) {awayTeamScore += 1;}
            }
        }
        
        else
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;}
        awayOuts +=1;
        
        counterAwayTwo++;
        cout <<"groundout"<<endl <<endl ;
        
        
        if (awayOuts %3 ==0 && awayOuts >0 ){
            {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
            cout << "End of Inning Number " << awayOuts/3 << endl << endl;}
        
    }
    
    
    
    
}

void single(double param){
    
    if(basesEmptyAway == 1) {
        cout <<"c value is "<< param <<endl;
        
        
        basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; }
    
    else if(firstBaseAway == 1) {
        
        if (param >= 0 && param <= .48){
            cout <<"Case 1"<<endl;
            cout << "Param is " << param <<endl;
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
        }
        else if (param >.48 && param <= .97) {
            cout << "Case 2" <<endl;
            cout << "Param is " << param <<endl;
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        else
        {   cout << "Case 3" << endl;
            cout << "Param is " << param << endl;
            basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            awayTeamScore +=1;}
    }
    
    
    else if(firstBaseSecondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        if (param >= 0 && param <= .05){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        else if (param > .05 && param<= .55){
            
            {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=1;}}
        else
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=1;}
    }
    
    
    else if(firstBaseThirdBaseAway == 1) { //a run scoring or tagging up is dependent on the number of outs, i.e. two outs doesn't matter what runners do
        
        cout <<"c value is "<< param <<endl;
        
        if (param >= 0 && param <= .5){
            
            { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=1;}}
        
        else if (param > .5 && param <= .55)
        {basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=2;}
        
        else
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=1;}
        
    }
    
    
    else if(basesLoadedAway == 1) {
        
        cout << "c value is " << param <<endl;
        
        if (param >= 0 && param <= .4)
            
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 1; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;  awayTeamScore += 2;}
        else if (param > .4 && param <= .45)
        {basesEmptyAway = 0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;  awayTeamScore += 3;}
        else if (param > .45 && param <=.85)
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;  awayTeamScore += 2;}
        else
        {basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;  awayTeamScore += 1;}
        
    }
    
    
    else if(secondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if (param >= 0 && param <= .38){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        else
        {basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;awayTeamScore += 1;}
        
    }
    
    else if(secondBaseThirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if (param >= 0 && param <= .63){
            
            {   basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore += 2;}}
        
        else
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 1; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore += 1;}
    }
    
    
    else if(thirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        basesEmptyAway =0; firstBaseAway = 1; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore += 1;}
    
    counterAwayTwo ++;
    cout << "single"<<endl <<endl;
    
}

void doublehit(double param) {
    
    if(basesEmptyAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
    }
    
    else if(firstBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if (param >= 0 && param <= .82){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0;}
        else {
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=1;}
        
    }
    
    else if(firstBaseSecondBaseAway == 1) {
        
        cout << "c value is " << param <<endl;
        
        if (param >= 0 && param <= .01)
            
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 1; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;}
        
        else if (param > .01 && param <= .77){
            {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0; awayTeamScore +=1;}}
        else
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=2;}
        
    }
    
    else if(firstBaseThirdBaseAway == 1) { //a run scoring or tagging up is dependent on the number of outs, i.e. two outs doesn't matter what runners do
        
        
        cout << "c value is " << param <<endl;;
        
        if (param >= 0 && param <= .75){
            
            { basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0; awayTeamScore +=1;}}
        else {
            {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
                //make sure outs are incrementing correctly
                awayTeamScore +=2;}}
    }
    
    else if(basesLoadedAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        if (param >= 0 && param <= .37)
            
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            
            {awayTeamScore += 3;}
        }
        
        else
        {basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0; {awayTeamScore += 2;}
        }
    }
    
    else if(secondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        if (param >= 0 && param <= .05){
            
            basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0;}
        else
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;awayTeamScore += 1;}
    }
    
    else if(secondBaseThirdBaseAway == 1) {
        
        
        cout <<"c value is "<< param <<endl;
        
        if (param >= 0 && param<= .9){
            
            {   basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore += 2;}}
        else
        {basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 1; thirdBaseAway = 0; awayTeamScore += 1;}
    }
    
    else if(thirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 1; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
            awayTeamScore += 1;}}
    
    
    counterAwayTwo++;
    cout << "double"<<endl <<endl;
    
}

void triple(double param){
    if(basesEmptyAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;}
    
    else if(firstBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1; awayTeamScore +=1; }
    
    else if(firstBaseSecondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1; awayTeamScore +=2;}
    
    else if(firstBaseThirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        { basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1; awayTeamScore +=2;}
    }
    
    else if(basesLoadedAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        { basesEmptyAway = 0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;  awayTeamScore += 3;}
    }
    
    else if(secondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;awayTeamScore += 1;}
    }
    
    else if(secondBaseThirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        {   basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1; awayTeamScore += 2;}}
    
    else if(thirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        {basesEmptyAway =0; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 1;
            awayTeamScore += 1;}}
    
    counterAwayTwo++;
    cout <<"triple"<<endl <<endl;
    
    
}

void homerun(double param){
    
    if(basesEmptyAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
        awayTeamScore +=1;}
    
    
    else if(firstBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=2; }
    
    
    else if(firstBaseSecondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        { basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=3;}}
    
    
    else if(firstBaseThirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        { basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore +=3;} }
    
    
    else if(basesLoadedAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        { basesEmptyAway = 1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore += 4;}}
    
    
    else if(secondBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore+= 2;} }
    
    
    else if(secondBaseThirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;awayTeamScore += 3;} }
    
    else if(thirdBaseAway == 1) {
        
        cout <<"c value is "<< param <<endl;
        
        
        {basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0; awayTeamScore += 2;} }
    
    counterAwayTwo++;
    
    cout<<"Home Run"<<endl <<endl;
    
}

int main(int argc, const char * argv[]) {
    
    for(int i = 1; i<=1000;i++){
        
        do{
            
            // r(); //generates a random number between 0 and 1
            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> dis(0, 1);
            auto value = dis(gen);
            auto c = dis(gen);
            cout << "r value is " << value << endl;
            cout << "initial c value is " << c << endl;
            
            cout << "counterAwayTwo is " << counterAwayTwo <<endl;
            
            
            if (counterAwayTwo % 9 ==1){
                
                //D Jennings
                
                walkPercentAway = .08561; strikeoutPercentAway = .12957; groundoutPercentAway = .31265; flyoutPercentAway = .26384; singlePercentAway = .15093; doublePercentAway = .04157; triplePercentAway = .00148; homerunPercentAway = .01435;}
            
            //K Keiermeyer
            else if (counterAwayTwo % 9 ==2){
                
                walkPercentAway = .07573; strikeoutPercentAway = .13261; groundoutPercentAway = .2950; flyoutPercentAway = .25106; singlePercentAway = .15363; doublePercentAway = .05680; triplePercentAway = .00974; homerunPercentAway = .02543;}
            
            //B Zobrist
            
            else if (counterAwayTwo % 9 == 3){
                
                walkPercentAway = .08837; strikeoutPercentAway = .11108; groundoutPercentAway = .30113; flyoutPercentAway = .29668; singlePercentAway = .15113; doublePercentAway = .03674; triplePercentAway = .00158; homerunPercentAway = .0133;}
            
            
            else if (counterAwayTwo % 9 == 4){ //E Longoria
                
                walkPercentAway = .07634; strikeoutPercentAway = .12975; groundoutPercentAway = .29558; flyoutPercentAway = .27885; singlePercentAway = .16636; doublePercentAway = .03272; triplePercentAway = .00136; homerunPercentAway = .01905;}
            
            
            else if (counterAwayTwo % 9 == 5){
                //J Loney
                
                walkPercentAway = .052; strikeoutPercentAway = .218; groundoutPercentAway = .32; flyoutPercentAway = .253; singlePercentAway = .14; doublePercentAway = .037; triplePercentAway = .001; homerunPercentAway = .035;}
            
            else if (counterAwayTwo % 9 == 6){ //D Navarro
                
                walkPercentAway = .057; strikeoutPercentAway = .194; groundoutPercentAway = .325; flyoutPercentAway = .259; singlePercentAway = .172; doublePercentAway = .036; triplePercentAway = .001; homerunPercentAway = .018;}
            
            else if (counterAwayTwo % 9 == 7){ //E Kratz
                
                walkPercentAway = .044; strikeoutPercentAway = .179; groundoutPercentAway = .355; flyoutPercentAway = .271; singlePercentAway = .147; doublePercentAway = .026; triplePercentAway = .001; homerunPercentAway = .038;}
            
            else if (counterAwayTwo % 9 == 8) {//S Tolleson
                
                walkPercentAway = .05; strikeoutPercentAway = .189; groundoutPercentAway = .328; flyoutPercentAway = .248; singlePercentAway = .151; doublePercentAway = .051; triplePercentAway = .001; homerunPercentAway = .02;}
            
            else if (counterAwayTwo % 9 == 9) { //A Gose
                
                walkPercentAway = .117; strikeoutPercentAway = .198; groundoutPercentAway = .274; flyoutPercentAway = .232; singlePercentAway = .151; doublePercentAway = .043; triplePercentAway = .001; homerunPercentAway = .039;}
            
            double walkRangeMaxAway = walkPercentAway;
            double strikeoutRangeMaxAway = strikeoutPercentAway + walkRangeMaxAway;
            double groundoutRangeMaxAway = groundoutPercentAway + strikeoutRangeMaxAway;
            double flyoutRangeMaxAway = flyoutPercentAway + groundoutRangeMaxAway;
            double singleRangeMaxAway = singlePercentAway + flyoutRangeMaxAway;
            double doubleRangeMaxAway = doublePercentAway + singleRangeMaxAway;
            double tripleRangeMaxAway = triplePercentAway + doubleRangeMaxAway;
            double homerunRangeMaxAway = homerunPercentAway + tripleRangeMaxAway;
            
            if (value >= 0 && value <= walkRangeMaxAway ){
                walk(c);}
            else if (value > walkRangeMaxAway && value <= strikeoutRangeMaxAway ){
                awayStrikeout(c);}
            else if (value > strikeoutRangeMaxAway && value <= groundoutRangeMaxAway ){
                groundout(c);}
            else if (value > groundoutRangeMaxAway && value <= flyoutRangeMaxAway ){
                flyout(c);}
            else if (value > flyoutRangeMaxAway && value <= singleRangeMaxAway ){
                single(c);}
            else if (value > singleRangeMaxAway && value <=doubleRangeMaxAway ){
                doublehit(c);}
            else if (value > doubleRangeMaxAway && value <= tripleRangeMaxAway ){
                triple(c);}
            else if (value > tripleRangeMaxAway && value <= homerunRangeMaxAway ){
                homerun(c);}
            
            
            cout << "awayTeamScore is " << awayTeamScore << endl;
            
            cout << "Number of Outs is " << awayOuts << endl;
            
            
            
            if(basesEmptyAway == 1){
                cout << "Bases are empty"<<endl;}
            else if(firstBaseAway == 1){
                cout << "Runner on first base" << endl << endl;}
            else if(firstBaseSecondBaseAway == 1){
                cout << "Runners on first and second base" << endl << endl;}
            else if(firstBaseThirdBaseAway == 1){
                cout << "Runners on first and third base" << endl << endl;}
            else if(basesLoadedAway == 1){
                cout << "Bases are loaded"<<endl << endl;}
            else if(secondBaseAway == 1){
                cout << "Runner on second base"<< endl << endl;}
            else if(secondBaseThirdBaseAway == 1){
                cout << "Runners on second and third base"<< endl << endl;}
            else if(thirdBaseAway){
                cout << "Runner on third base"<<endl << endl;}
            
            
            
            
        } while(awayOuts!=15);
        
        cout << "Stop" << endl;
        cout << "Final score of Game " << i <<" is " <<awayTeamScore << endl << endl;
        
        cout << "New Game" << endl << endl;
        
        ofstream myfile;
        myfile.open ("/Users/user/Desktop/example.txt", ios::out | ios::app | ios::binary);
        
        myfile << endl << awayTeamScore;
        myfile.close();
        
        awayOuts = 0;
        
        basesEmptyAway =1; firstBaseAway = 0; firstBaseSecondBaseAway = 0; firstBaseThirdBaseAway = 0; basesLoadedAway = 0; secondBaseAway = 0; secondBaseThirdBaseAway = 0; thirdBaseAway = 0;
        
        awayTeamScore  = 0;
        
        
    }
    
}