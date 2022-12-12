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


void biru();

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
            
            biru();

        }

        cout << endl;
        result = (*MyCloseAPI)();
        programResult = 1;
    }

    FreeLibrary(commandLayer_handle);
    return programResult;
}


void biru(){
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

			pointToSend.Position.CartesianPosition.X = 0.45051;
			pointToSend.Position.CartesianPosition.Y = 0.0896356;
			pointToSend.Position.CartesianPosition.Z = 0.0264554;
			pointToSend.Position.CartesianPosition.ThetaX = 3.11772;
			pointToSend.Position.CartesianPosition.ThetaY = 0.104079;
			pointToSend.Position.CartesianPosition.ThetaZ = 1.84796;
			pointToSend.Position.Fingers.Finger1 = 1524;
			pointToSend.Position.Fingers.Finger2 = 1608;
			pointToSend.Position.Fingers.Finger3 = 930;
			MySendBasicTrajectory(pointToSend);
			
			pointToSend.Position.CartesianPosition.X = 0.450345;
			pointToSend.Position.CartesianPosition.Y = 0.0816106;
			pointToSend.Position.CartesianPosition.Z = 0.0193227;
			pointToSend.Position.CartesianPosition.ThetaX = 3.11702;
			pointToSend.Position.CartesianPosition.ThetaY = 0.104397;
			pointToSend.Position.CartesianPosition.ThetaZ = 1.84824;
			pointToSend.Position.Fingers.Finger1 = 5388;
			pointToSend.Position.Fingers.Finger2 = 5424;
			pointToSend.Position.Fingers.Finger3 = 930;
			MySendBasicTrajectory(pointToSend);
			
			pointToSend.Position.CartesianPosition.X = 0.44864;
			pointToSend.Position.CartesianPosition.Y = 0.0803617;
			pointToSend.Position.CartesianPosition.Z = 0.484118;
			pointToSend.Position.CartesianPosition.ThetaX = 3.11553;
			pointToSend.Position.CartesianPosition.ThetaY = 0.104596;
			pointToSend.Position.CartesianPosition.ThetaZ = 1.84909;
			pointToSend.Position.Fingers.Finger1 = 5388;
			pointToSend.Position.Fingers.Finger2 = 5424;
			pointToSend.Position.Fingers.Finger3 = 930;
			MySendBasicTrajectory(pointToSend);
			
			pointToSend.Position.CartesianPosition.X = -0.387903;
			pointToSend.Position.CartesianPosition.Y = 0.426023;
			pointToSend.Position.CartesianPosition.Z = 0.454487;
			pointToSend.Position.CartesianPosition.ThetaX = -3.03843;
			pointToSend.Position.CartesianPosition.ThetaY = -0.0344454;
			pointToSend.Position.CartesianPosition.ThetaZ = -0.272341;
			pointToSend.Position.Fingers.Finger1 = 5388;
			pointToSend.Position.Fingers.Finger2 = 5424;
			pointToSend.Position.Fingers.Finger3 = 930;
			MySendBasicTrajectory(pointToSend);
			
			pointToSend.Position.CartesianPosition.X = -0.374227;
			pointToSend.Position.CartesianPosition.Y = 0.411169;
			pointToSend.Position.CartesianPosition.Z = 0.133625;
			pointToSend.Position.CartesianPosition.ThetaX = -3.03852;
			pointToSend.Position.CartesianPosition.ThetaY = -0.0348587;
			pointToSend.Position.CartesianPosition.ThetaZ = -0.27326;
			pointToSend.Position.Fingers.Finger1 = 5388;
			pointToSend.Position.Fingers.Finger2 = 5424;
			pointToSend.Position.Fingers.Finger3 = 930;
			MySendBasicTrajectory(pointToSend);
			
			pointToSend.Position.CartesianPosition.X = -0.374213;
			pointToSend.Position.CartesianPosition.Y = 0.410841;
			pointToSend.Position.CartesianPosition.Z = 0.10278;
			pointToSend.Position.CartesianPosition.ThetaX = -3.03854;
			pointToSend.Position.CartesianPosition.ThetaY = -0.0348978;
			pointToSend.Position.CartesianPosition.ThetaZ = -0.273638;
			pointToSend.Position.Fingers.Finger1 = 6;
			pointToSend.Position.Fingers.Finger2 = 0;
			pointToSend.Position.Fingers.Finger3 = 930;
			MySendBasicTrajectory(pointToSend);

}