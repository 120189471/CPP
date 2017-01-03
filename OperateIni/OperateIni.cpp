#include <string>

#include <filesystem>

#include <iostream>
using std::cout;
using std::endl;

#include <direct.h>

#include <io.h>

#include "update.h"

//需求一: 路径为绝对路径,需求二:路径为相对路径
const string g_path = "E:\\install\\";

int main()
{
    UpDate ud;
    ud.IsFile(g_path);

    //=============================================================================
    //练习
    int drive;
    cout << "\n当前系统驱动: " << _getdrive() << endl;
    cout << "返回表示当前可用的磁盘驱动器的位掩码" << _getdrives << endl;
    //数据结果是5,对应是E盘.
    //
    //获取当前文件目录
    char buffer[_MAX_PATH];
    _getcwd(buffer, _MAX_PATH);
    cout << "当前路径："<<*buffer << endl;
    
    int len = strlen(buffer);

    if (buffer[len - 1] != '\\')
    {
        strcat(buffer, "\\");
    }
    const buffer = g_path;
 
    long h_file;
    _finddata_t dirtest;
    cout << "buffer: " << buffer;
    if ((h_file = _findfirst(buffer, &dirtest)) != -1)
    {
        do
        {
            if (dirtest.attrib&_A_SUBDIR)
            {
                char test_filename[_MAX_PATH];
                strcpy(test_filename, buffer);
                //strcat(test_filename, dirtest.name);
                cout << "遍历的第一个文件夹" << test_filename << endl;
            }

        }
        while (!_findnext(h_file, &dirtest));
    }


    //=============================================================================

    system("PAUSE");
    return 0;

}

