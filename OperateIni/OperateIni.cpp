#include <string>

#include <filesystem>

#include <iostream>
using std::cout;
using std::endl;

#include <direct.h>

#include <io.h>

#include "update.h"

//����һ: ·��Ϊ����·��,�����:·��Ϊ���·��
const string g_path = "E:\\install\\";

int main()
{
    UpDate ud;
    ud.IsFile(g_path);

    //=============================================================================
    //��ϰ
    int drive;
    cout << "\n��ǰϵͳ����: " << _getdrive() << endl;
    cout << "���ر�ʾ��ǰ���õĴ�����������λ����" << _getdrives << endl;
    //���ݽ����5,��Ӧ��E��.
    //
    //��ȡ��ǰ�ļ�Ŀ¼
    char buffer[_MAX_PATH];
    _getcwd(buffer, _MAX_PATH);
    cout << "��ǰ·����"<<*buffer << endl;
    
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
                cout << "�����ĵ�һ���ļ���" << test_filename << endl;
            }

        }
        while (!_findnext(h_file, &dirtest));
    }


    //=============================================================================

    system("PAUSE");
    return 0;

}

