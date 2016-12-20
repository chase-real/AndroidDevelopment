//
//  menu.cpp
//  PlayPin
//
//  Created by Chase Tillar on 12/19/16.
//  Copyright © 2016 Chase Tillar. All rights reserved.
//

#include <iostream>
#include "boolean.h"

using namespace std;

int menu (void) {
    
    int choice;
    
    cout<<"///////////////////////////////////////"<<endl;
    cout<<"       Welcome to CommandDroid!"<<endl<<"         Created by chase.real"<<endl;
    cout<<"///////////////////////////////////////"<<endl<<endl;
    
    cout<<"What would you like to do?"<<endl<<endl;
    
    cout<<"1. ADB commands"<<endl;
    cout<<"2. Help"<<endl;
    cout<<"3. Report bugs"<<endl;
    cout<<"4. Quit"<<endl;
    //cout<<"x. Flash ROM"<<endl;

    
    cout<<"Enter a selection: ";
    cin>>choice;
    cout<<endl;

    return choice;
}
