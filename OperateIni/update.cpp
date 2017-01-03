#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ios;

#include <direct.h>
#include <IO.h>
#include "Update.h"



//UpDate::UpDate()
//{
//};

bool UpDate::IsFile(string g_path)
{
    string ConfigFile = "update.ini";
    ConfigFile = g_path + ConfigFile;
    //cout << ConfigFile << endl;

    ifstream config_file(ConfigFile, ios::in);
    if (!config_file)
    {
        cout << "配置文件文件不存在,本次生成文件格式" << endl;
        return 0;
    }
    return 1;
}


//1.1*  遍历安装目录并生成目录
int UpDate::FindFolder(string g_path)
{
    char buffer[_MAX_PATH];
     _getcwd(buffer, _MAX_PATH);

    int len = strlen(buffer);
    if (buffer[len - 1] != '\\')
    {
        //可以在变化
        strcat(buffer, "\\");
        
    }


    _finddata_t fileinfo;
    _findfirst(buffer, &fileinfo);
    /*
    do
    {
        //判断文件属性是文件夹
        if (fileinfo.attrib&_A_SUBDIR)
        {

        }
    }
    while ();
    */

    return 0;

}
