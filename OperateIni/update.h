
#include <string>
using std::string;

class UpDate
{
public:
    //UpDate();
    //~UpDate();

    //1.�鿴�Ƿ��������ļ�
    //path �������Ŀ¼
    bool IsFile(string g_path);

    //1.1*  ������װĿ¼������Ŀ¼
    int FindFolder(string g_path);

    //1.2*  д�������ļ�
    int WriteConfig(string g_path);

    //2. ����ģ������ļ������Ա�׼Ŀ¼���е���
    int NewFIle(string g_path);

    //3. ����������汾
    int UpNewVersion(string g_path);

    //4. ѡ���Ӧȯ�̣���ִ�в���
    int UpSecuritiesCompany(string g_path);

    //5. ����ȯ��
    int AddSecuritiesCompany(string g_path);

    //6. ����Ҫ����ȯ�̰�������
    int DelSecuritiesCompany(string g_path);

};

