#define UNICODE
#include "KinovaTypes.h"
#include <iostream>
#include <windows.h>
#include "CommunicationLayer.h"
#include "CommandLayer.h"
#include <conio.h>

using namespace std;

HINSTANCE commandLayer_handle;
int(*MyInitAPI)();
int(*MyCloseAPI)();
int(*MySendBasicTrajectory)(TrajectoryPoint command);
int(*MyGetDevices)(KinovaDevice devices[MAX_KINOVA_DEVICE], int &result);
int(*MySetActiveDevice)(KinovaDevice device);
int(*MyMoveHome)();
int(*MyInitFingers)();
int(*MyGetCartesianCommand)(CartesianPosition &);


void hijau();

int main(){
    CartesianPosition currentCommand;
    int programResult = 0;

    commandLayer_handle = LoadLibraryA("CommandLayerWindows.dll");

    MyInitAPI = (int(*)()) GetProcAddress(commandLayer_handle, "InitAPI");
    MyCloseAPI = (int(*)()) GetProcAddress(commandLayer_handle, "CloseAPI");
    MyMoveHome = (int(*)()) GetProcAddress(commandLayer_handle, "MoveHome");
    MyInitFingers = (int(*)()) GetProcAddress(commandLayer_handle, "InitFingers");
    MyGetDevices = (int(*)(KinovaDevice devices[MAX_KINOVA_DEVICE],
                           int &result)) GetProcAddress(commandLayer_handle, "GetDevices");
    MySetActiveDevice = (int(*)(KinovaDevice devices)) GetProcAddress(commandLayer_handle,
                                                                      "SetActiveDevice");
    MySendBasicTrajectory = (int(*)(TrajectoryPoint)) GetProcAddress(commandLayer_handle,
                                                                     "SendBasicTrajectory");
    MyGetCartesianCommand = (int(*)(CartesianPosition &)) GetProcAddress(commandLayer_handle,
                                                                         "GetCartesianCommand");

    if ((MyInitAPI == NULL) || (MyCloseAPI == NULL) || (MySendBasicTrajectory == NULL) ||
        (MyGetDevices == NULL) || (MySetActiveDevice == NULL) || (MyGetCartesianCommand == NULL) ||
        (MyMoveHome == NULL) || (MyInitFingers == NULL)){

        cout << "init error/n";
        programResult = 0;
    }
    else{

        cout << "initialization complete" << endl;

        int result = (*MyInitAPI)();
        CartesianPosition currentCommand;
        KinovaDevice list[MAX_KINOVA_DEVICE];
        int devicesCount = MyGetDevices(list, result);

        for (int i = 0; i < devicesCount; i++) {
            cout << "robot found: " << list[i].SerialNumber << endl;
            MySetActiveDevice(list[i]);

            MyInitFingers();
            TrajectoryPoint pointToSend;
            pointToSend.InitStruct();

            pointToSend.Position.Type = CARTESIAN_POSITION;
            
			hijau();
			
        }

        cout << endl;
        result = (*MyCloseAPI)();
        programResult = 1;
    }

    FreeLibrary(commandLayer_handle);
    return programResult;
}

void hijau(){
			MyInitFingers();
            TrajectoryPoint pointToSend;
            pointToSend.InitStruct();

            pointToSend.Position.Type = CARTESIAN_POSITION;
            
            pointToSend.Position.CartesianPosition.X = 0.452631;
            pointToSend.Position.CartesianPosition.Y = 0.0857984;
            pointToSend.Position.CartesianPosition.Z = 0.395685;
            pointToSend.Position.CartesianPosition.ThetaX = 3.09227;
            pointToSend.Position.CartesianPosition.ThetaY = 0.100668;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.83743;
            pointToSend.Position.Fingers.Finger1 = 1518;
            pointToSend.Position.Fingers.Finger2 = 1602;
            pointToSend.Position.Fingers.Finger3 = 918;
            MySendBasicTrajectory(pointToSend);
            
            pointToSend.Position.CartesianPosition.X = 0.451243;
            pointToSend.Position.CartesianPosition.Y = 0.0901909;
            pointToSend.Position.CartesianPosition.Z = 0.0171862;
            pointToSend.Position.CartesianPosition.ThetaX = 3.11589;
            pointToSend.Position.CartesianPosition.ThetaY = 0.103145;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.84533;
            pointToSend.Position.Fingers.Finger1 = 1518;
            pointToSend.Position.Fingers.Finger2 = 1602;
            pointToSend.Position.Fingers.Finger3 = 918;
            MySendBasicTrajectory(pointToSend);
	
			pointToSend.Position.CartesianPosition.X = 0.451243;
            pointToSend.Position.CartesianPosition.Y = 0.0901909;
            pointToSend.Position.CartesianPosition.Z = 0.0171862;
            pointToSend.Position.CartesianPosition.ThetaX = 3.11589;
            pointToSend.Position.CartesianPosition.ThetaY = 0.103145;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.84533;
            pointToSend.Position.Fingers.Finger1 = 4566;
            pointToSend.Position.Fingers.Finger2 = 4734;
            pointToSend.Position.Fingers.Finger3 = 3966;
            MySendBasicTrajectory(pointToSend);
            
            pointToSend.Position.CartesianPosition.X = 0.451243;
            pointToSend.Position.CartesianPosition.Y = 0.0901909;
            pointToSend.Position.CartesianPosition.Z = 0.412659;
            pointToSend.Position.CartesianPosition.ThetaX = 3.11589;
            pointToSend.Position.CartesianPosition.ThetaY = 0.103145;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.84533;
            pointToSend.Position.Fingers.Finger1 = 4566;
            pointToSend.Position.Fingers.Finger2 = 4734;
            pointToSend.Position.Fingers.Finger3 = 3966;
            MySendBasicTrajectory(pointToSend);
            
            pointToSend.Position.CartesianPosition.X = 0.37539;
            pointToSend.Position.CartesianPosition.Y = 0.362105;
            pointToSend.Position.CartesianPosition.Z = 0.412286;
            pointToSend.Position.CartesianPosition.ThetaX = -3.10778;
            pointToSend.Position.CartesianPosition.ThetaY = 0.101076;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.27614;
            pointToSend.Position.Fingers.Finger1 = 4566;
            pointToSend.Position.Fingers.Finger2 = 4734;
            pointToSend.Position.Fingers.Finger3 = 3966;
            MySendBasicTrajectory(pointToSend);
            
            pointToSend.Position.CartesianPosition.X = 0.37484;
            pointToSend.Position.CartesianPosition.Y = 0.361538;
            pointToSend.Position.CartesianPosition.Z = 0.0916709;
            pointToSend.Position.CartesianPosition.ThetaX = -3.10778;
            pointToSend.Position.CartesianPosition.ThetaY = 0.101076;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.27614;
            pointToSend.Position.Fingers.Finger1 = 4566;
            pointToSend.Position.Fingers.Finger2 = 4734;
            pointToSend.Position.Fingers.Finger3 = 3966;
            MySendBasicTrajectory(pointToSend);
            
            pointToSend.Position.CartesianPosition.X = 0.37484;
            pointToSend.Position.CartesianPosition.Y = 0.361538;
            pointToSend.Position.CartesianPosition.Z = 0.0916709;
            pointToSend.Position.CartesianPosition.ThetaX = -3.10778;
            pointToSend.Position.CartesianPosition.ThetaY = 0.101076;
            pointToSend.Position.CartesianPosition.ThetaZ = 1.27614;
            pointToSend.Position.Fingers.Finger1 = 1518;
            pointToSend.Position.Fingers.Finger2 = 1602;
            pointToSend.Position.Fingers.Finger3 = 918;
            MySendBasicTrajectory(pointToSend);
}