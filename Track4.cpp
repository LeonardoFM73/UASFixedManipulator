
//
// Created by sigit dani perkasa on 18/08/2022.
//
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


void kuning();

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
            
            kuning();

        }

        cout << endl;
        result = (*MyCloseAPI)();
        programResult = 1;
    }

    FreeLibrary(commandLayer_handle);
    return programResult;
}

void kuning(){
	
		MyInitFingers();
    	TrajectoryPoint pointToSend;
        pointToSend.InitStruct();
        pointToSend.Position.Type = CARTESIAN_POSITION;
		pointToSend.Position.CartesianPosition.X = 0.35363;
		
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


		pointToSend.Position.CartesianPosition.Y = -0.0497157;
		pointToSend.Position.CartesianPosition.Z = 0.0112656;
		pointToSend.Position.CartesianPosition.ThetaX = -1.5123;
		pointToSend.Position.CartesianPosition.ThetaY = 0.0407542;
		pointToSend.Position.CartesianPosition.ThetaZ = 0.163204;
		pointToSend.Position.Fingers.Finger1 = 1518;
		pointToSend.Position.Fingers.Finger2 = 1608;
		pointToSend.Position.Fingers.Finger3 = 930;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.353044;
		pointToSend.Position.CartesianPosition.Y = 0.0237976;
		pointToSend.Position.CartesianPosition.Z = 0.0110733;
		pointToSend.Position.CartesianPosition.ThetaX = -1.5917;
		pointToSend.Position.CartesianPosition.ThetaY = 0.238266;
		pointToSend.Position.CartesianPosition.ThetaZ = 0.199122;
		pointToSend.Position.Fingers.Finger1 = 1518;
		pointToSend.Position.Fingers.Finger2 = 1608;
		pointToSend.Position.Fingers.Finger3 = 930;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.353044;
		pointToSend.Position.CartesianPosition.Y = 0.0237976;
		pointToSend.Position.CartesianPosition.Z = 0.0110733;
		pointToSend.Position.CartesianPosition.ThetaX = -1.5917;
		pointToSend.Position.CartesianPosition.ThetaY = 0.238266;
		pointToSend.Position.CartesianPosition.ThetaZ = 0.199122;
		pointToSend.Position.Fingers.Finger1 = 4980;
		pointToSend.Position.Fingers.Finger2 = 5088;
		pointToSend.Position.Fingers.Finger3 = 930;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.352178;
		pointToSend.Position.CartesianPosition.Y = 0.024446;
		pointToSend.Position.CartesianPosition.Z = 0.423909;
		pointToSend.Position.CartesianPosition.ThetaX = -1.59267;
		pointToSend.Position.CartesianPosition.ThetaY = 0.237612;
		pointToSend.Position.CartesianPosition.ThetaZ = 0.199604;
		pointToSend.Position.Fingers.Finger1 = 4980;
		pointToSend.Position.Fingers.Finger2 = 5088;
		pointToSend.Position.Fingers.Finger3 = 930;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.0444487;
		pointToSend.Position.CartesianPosition.Y = 0.419945;
		pointToSend.Position.CartesianPosition.Z = 0.425536;
		pointToSend.Position.CartesianPosition.ThetaX = -3.08127;
		pointToSend.Position.CartesianPosition.ThetaY = 0.0738878;
		pointToSend.Position.CartesianPosition.ThetaZ = -0.979018;
		pointToSend.Position.Fingers.Finger1 = 4980;
		pointToSend.Position.Fingers.Finger2 = 5088;
		pointToSend.Position.Fingers.Finger3 = 930;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.0443247;
		pointToSend.Position.CartesianPosition.Y = 0.419268;
		pointToSend.Position.CartesianPosition.Z = 0.0965513;
		pointToSend.Position.CartesianPosition.ThetaX = -3.08128;
		pointToSend.Position.CartesianPosition.ThetaY = 0.0739173;
		pointToSend.Position.CartesianPosition.ThetaZ = -0.979244;
		pointToSend.Position.Fingers.Finger1 = 4980;
		pointToSend.Position.Fingers.Finger2 = 5088;
		pointToSend.Position.Fingers.Finger3 = 930;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.0443247;
		pointToSend.Position.CartesianPosition.Y = 0.419268;
		pointToSend.Position.CartesianPosition.Z = 0.0965513;
		pointToSend.Position.CartesianPosition.ThetaX = -3.08128;
		pointToSend.Position.CartesianPosition.ThetaY = 0.0739173;
		pointToSend.Position.CartesianPosition.ThetaZ = -0.979244;
		pointToSend.Position.Fingers.Finger1 = 6;
		pointToSend.Position.Fingers.Finger2 = 6;
		pointToSend.Position.Fingers.Finger3 = 930;
		MySendBasicTrajectory(pointToSend);
}