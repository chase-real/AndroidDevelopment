//
//  main.cpp
//  PlayPin
//
//  Created by Chase Tillar on 12/19/16.
//  Copyright © 2016 Chase Tillar. All rights reserved.
//

#include <iostream>
#include "boolean.h"

using namespace std;


//declaring functions
int menu(void);
void ADB(void);
void bugs(void);
void help(void);
void devices(void);
void ROMflash(void);
string setup(void);

int main(int argc, const char * argv[]) {
    
    boolean quit = false;

    int selection;
    
    selection=menu(); //show main menu 
    
    if (selection!=quit) {
        
        switch (selection) {
            case 1: ADB();break; //adb commands option chosen by user, execute function
            case 2: help();break; //help option chosen by user, execute function
            case 3: bugs();break; //CommandDroid bug report option chosen by user, exexcute function 
            case 4: quit=true;break; //quit program option chosen by user, end program
            default:cout<<selection<<" is not a valid selection!"<<endl; //if user inputs other than accepted option, give warning and end program
        }
    }
}

