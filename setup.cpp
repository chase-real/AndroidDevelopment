//
//  setup.cpp
//  PlayPin
//
//  Created by Chase Tillar on 12/20/16.
//  Copyright © 2016 Chase Tillar. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "boolean.h"

//delaring functions used in subprogram
void devices(void);

using namespace std;

string setup() {
    
    string adblocation;
    
    cout<<"Before you begin using CommandDroid!, please answer one simple question for setup."<<endl<<endl;
    
    cout<<endl;
    cout<<"CommandDroid! needs the location of your ADB folder"<<endl<<endl;
    cout<<"Please enter the path to your ADB folder: ";
    
    cin>>adblocation;
    
    cout<<endl;
    cout<<"Great, setup is complete!"<<endl<<endl;
    
    return adblocation;
    
}
