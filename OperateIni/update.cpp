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
        cout << "�����ļ��ļ�������,���������ļ���ʽ" << endl;
        return 0;
    }
    return 1;
}


//1.1*  ������װĿ¼������Ŀ¼
int UpDate::FindFolder(string g_path)
{
    char buffer[_MAX_PATH];
     _getcwd(buffer, _MAX_PATH);

    int len = strlen(buffer);
    if (buffer[len - 1] != '\\')
    {
        //�����ڱ仯
        strcat(buffer, "\\");
        
    }


    _finddata_t fileinfo;
    _findfirst(buffer, &fileinfo);
    /*
    do
    {
        //�ж��ļ��������ļ���
        if (fileinfo.attrib&_A_SUBDIR)
        {

        }
    }
    while ();
    */

    return 0;

}
