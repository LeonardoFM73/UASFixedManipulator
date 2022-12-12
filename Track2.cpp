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


void merah();

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
            
            merah();

        }

        cout << endl;
        result = (*MyCloseAPI)();
        programResult = 1;
    }

    FreeLibrary(commandLayer_handle);
    return programResult;
}


void merah(){
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
	
		pointToSend.Position.CartesianPosition.X = 0.43539;
		pointToSend.Position.CartesianPosition.Y = 0.137755;
		pointToSend.Position.CartesianPosition.Z = 0.0374926;
		pointToSend.Position.CartesianPosition.ThetaX = 1.5556;
		pointToSend.Position.CartesianPosition.ThetaY = 0.0197033;
		pointToSend.Position.CartesianPosition.ThetaZ = -2.92271;
		pointToSend.Position.Fingers.Finger1 = 1518;
		pointToSend.Position.Fingers.Finger2 = 1608;
		pointToSend.Position.Fingers.Finger3 = 924;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.436112;
		pointToSend.Position.CartesianPosition.Y = 0.0614426;
		pointToSend.Position.CartesianPosition.Z = 0.00751556;
		pointToSend.Position.CartesianPosition.ThetaX = 1.63329;
		pointToSend.Position.CartesianPosition.ThetaY = -0.148269;
		pointToSend.Position.CartesianPosition.ThetaZ = -2.91338;
		pointToSend.Position.Fingers.Finger1 = 1518;
		pointToSend.Position.Fingers.Finger2 = 1608;
		pointToSend.Position.Fingers.Finger3 = 924;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.436112;
		pointToSend.Position.CartesianPosition.Y = 0.0614426;
		pointToSend.Position.CartesianPosition.Z = 0.00751556;
		pointToSend.Position.CartesianPosition.ThetaX = 1.63329;
		pointToSend.Position.CartesianPosition.ThetaY = -0.148269;
		pointToSend.Position.CartesianPosition.ThetaZ = -2.91338;
		pointToSend.Position.Fingers.Finger1 = 5286;
		pointToSend.Position.Fingers.Finger2 = 5538;
		pointToSend.Position.Fingers.Finger3 = 924;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.434824;
		pointToSend.Position.CartesianPosition.Y = 0.143366;
		pointToSend.Position.CartesianPosition.Z = 0.485838;
		pointToSend.Position.CartesianPosition.ThetaX = 1.63181;
		pointToSend.Position.CartesianPosition.ThetaY = 0.0534967;
		pointToSend.Position.CartesianPosition.ThetaZ = -2.92843;
		pointToSend.Position.Fingers.Finger1 = 5286;
		pointToSend.Position.Fingers.Finger2 = 5532;
		pointToSend.Position.Fingers.Finger3 = 924;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.0422678;
		pointToSend.Position.CartesianPosition.Y = 0.6612;
		pointToSend.Position.CartesianPosition.Z = 0.373207;
		pointToSend.Position.CartesianPosition.ThetaX = -2.97747;
		pointToSend.Position.CartesianPosition.ThetaY = 0.218948;
		pointToSend.Position.CartesianPosition.ThetaZ = 1.87266;
		pointToSend.Position.Fingers.Finger1 = 5286;
		pointToSend.Position.Fingers.Finger2 = 5532;
		pointToSend.Position.Fingers.Finger3 = 924;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.0423716;
		pointToSend.Position.CartesianPosition.Y = 0.654502;
		pointToSend.Position.CartesianPosition.Z = 0.115133;
		pointToSend.Position.CartesianPosition.ThetaX = -2.97699;
		pointToSend.Position.CartesianPosition.ThetaY = 0.21863;
		pointToSend.Position.CartesianPosition.ThetaZ = 1.86969;
		pointToSend.Position.Fingers.Finger1 = 5286;
		pointToSend.Position.Fingers.Finger2 = 5532;
		pointToSend.Position.Fingers.Finger3 = 924;
		MySendBasicTrajectory(pointToSend);
		
		pointToSend.Position.CartesianPosition.X = 0.0423716;
		pointToSend.Position.CartesianPosition.Y = 0.654502;
		pointToSend.Position.CartesianPosition.Z = 0.115133;
		pointToSend.Position.CartesianPosition.ThetaX = -2.97699;
		pointToSend.Position.CartesianPosition.ThetaY = 0.21863;
		pointToSend.Position.CartesianPosition.ThetaZ = 1.86969;
		pointToSend.Position.Fingers.Finger1 = 6;
		pointToSend.Position.Fingers.Finger2 = 6;
		pointToSend.Position.Fingers.Finger3 = 924;
		MySendBasicTrajectory(pointToSend);

}
