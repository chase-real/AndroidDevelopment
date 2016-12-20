//
//  ADB.cpp
//  PlayPin
//
//  Created by Chase Tillar on 12/19/16.
//  Copyright © 2016 Chase Tillar. All rights reserved.
//

#include <iostream>

using namespace std;

string setup(void);

void ADB() {
    
    int command;
    string adblocation,apks, apkdata, sd, sysdata, backup (" backup"), ppchoice;
    
    adblocation=setup();
    
    cout<<"List of supported ADB commands:"<<endl<<endl;
    cout<<" 1. List connected devices"<<endl;
    cout<<" 2. Enter bootloader"<<endl;
    cout<<" 3. Enter recovery"<<endl;
    cout<<" 4. Create bugreport"<<endl;
    cout<<" 5. Create ADB backup"<<endl;
    cout<<" 6. Push file or directory to device"<<endl;
    cout<<" 7. Pull file or directory from device"<<endl;
    cout<<" 8. View device logcat"<<endl;
    cout<<" 9. Install package on device"<<endl;
    cout<<"10. Unintall package from device"<<endl;

    cout<<endl;
    cout<<"Enter selection here: ";
    cin>>command;
    
    switch(command) {
            
        //executing 'devices' ADB command
        case 1:system((adblocation+" devices").c_str());break;
        
        //executing 'root' ADB command, a must for loading bootloader, then 'reboot [bootloader]'
        case 2: cout<<"Booting into bootloader..."<<endl;
                system((adblocation+" root").c_str());
                system((adblocation+" reboot [bootloader]").c_str());
                cout<<"Done!"<<endl;break;
        
        //executing 'root' ADB command, a must for loading recovery, then reboot [recovery]'
        case 3: cout<<"Booting into recovery..."<<endl;
                system((adblocation+" root").c_str() );
                system((adblocation+" reboot [recovery]").c_str());
                cout<<"Done!"<<endl;break;
        
        //executing 'bugreport' ADB command
        case 4: cout<<"Creating device bug report..."<<endl;
                system((adblocation+" bugreport").c_str());
                cout<<"Done!";break;
            
        //getting information on what to backup, executing ADB 'backup' command
        case 5: cout<<"Tell CommandDroid what you would like to backup (answer with 'yes' or 'no'):"<<endl<<endl;
                cout<<"Backup .apks? ";
                cin>>apks;
                if (apks=="yes") backup=(backup+" [-apk]");
                cout<<"Backup .apk data? ";
                cin>>apkdata;
                if (apkdata=="yes") backup=(backup+" [-obb]");
                cout<<"Backup SD card contents? ";
                cin>>sd;
                if (sd=="yes") backup=(backup+" [-shared]");
                cout<<"Backup system applications? ";
                cin>>sysdata;
                if (sysdata=="yes") backup=(backup+" [-system]");
                cout<<endl;
                cout<<"Backing up device..."<<endl;
                system((adblocation+backup).c_str());
                cout<<"Done!"<<endl<<endl;break;
            
        //getting location of file/directory to be pushed to device,executing ADB 'push' command
        case 6: cout<<"Are you pushing a local or remote file/directory to device? ";
                cin>>ppchoice;
                if (ppchoice=="local") ppchoice=(" push <"+ppchoice+">");
                if (ppchoice=="remote") ppchoice=(" push <"+ppchoice+">");
                system((adblocation+ppchoice).c_str());break;
        
        //getting location of file/directory to be pulled from device,executing ADB 'pull' command
        case 7: cout<<"Are you pulling a local or remote file/directory from device? ";
            cin>>ppchoice;
            if (ppchoice=="local") ppchoice=(" pull <"+ppchoice+">");
            if (ppchoice=="remote") ppchoice=(" pull <"+ppchoice+">");
            system((adblocation+ppchoice).c_str());break;

    }
}
