#include <iostream>
#include <stdio.h>
#include <string.h>
#include "RoboteqDevice.h"
#include "ErrorCodes.h"
#include "Constants.h"

using namespace std;

int main(int argc, char *argv[])
{
    sting response = "";

    RoboteqDevice device;

    int status = device.Connect("/dev/ttyS0);

    .
    if(status != RQ_SUCCESS)
    {
        cout << "Error connection to device: " << status << "." << endl;
        return 1;
    }

    cout << " - SetConfig(_DINA, 1, 1_ ...");


    // Check to see if connection was a success
    if ((status = device.SetConfig(_DINA, 1, 1)) != RQ_SUCCESS)
    {
        cout << "failed " << status << endl;
    }
    else 
    {
        cout << "succeeded" << endl;
    }

    sleepms(10);

    int result;

    cout << "- GetConfig(_DINA, 1)...";

    if ((status = device.GetConfig(_DINA, 1, 1)) != RQ_SUCCESS)
    {
        cout << "failed " << status << endl;
    }
    else 
    {
        cout << "returned" << result << endl;
    }

    // Wait 10ms before another command sent
    sleepms(10);

    cout << " - GetValue(_ANAIN, 1)... ";
    
    if ((status = device.GetValue(_ANAIN, 1, result)) != RQ_SUCCESS)
    {
        cout << "failed " << status << endl;
    }
    else 
    {
        cout << "returned" << result << endl;
    }

    sleepms(10);

    cout << "- SetCommand(_GO, 1, 1)...";

    if ((status = device.SetCommand(_GO, 1, 1)) != RQ_SUCCESS)
    {
        cout << "failed " << status << endl;
    }
    else 
    {
        cout << "succeeded" << endl;
    }
    return 0;
}
