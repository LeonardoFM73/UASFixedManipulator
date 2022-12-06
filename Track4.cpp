
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


void gethome();
void hijau();
void biru();
void kuning();
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
            
            gethome();
            Sleep(3000);
            merah();

        }

        cout << endl;
        result = (*MyCloseAPI)();
        programResult = 1;
    }

    FreeLibrary(commandLayer_handle);
    return programResult;
}

void gethome(){
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
