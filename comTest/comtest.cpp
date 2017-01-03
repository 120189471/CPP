#include <windows.h>
#include <stdio.h>
#import ".\VBUtil.dll" no_namespace

int main()
{
    CoInitialize(NULL);
    CLSID clsid;
    HRESULT hr = CLSIDFromProgID(OLESTR("myCom.GetRes"), &clsid);
    IGetRes *ptr;
    hr = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER,__uuidof(IGetRes), (LPVOID*)&ptr);
    ptr->Hello();
    CoUninitialize();
}