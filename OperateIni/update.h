
#include <string>
using std::string;

class UpDate
{
public:
    //UpDate();
    //~UpDate();

    //1.查看是否有配置文件
    //path 打包环境目录
    bool IsFile(string g_path);

    //1.1*  遍历安装目录并生成目录
    int FindFolder(string g_path);

    //1.2*  写入配置文件
    int WriteConfig(string g_path);

    //2. 读主模块更新文件，并对标准目录进行调整
    int NewFIle(string g_path);

    //3. 更新主程序版本
    int UpNewVersion(string g_path);

    //4. 选择对应券商，并执行操作
    int UpSecuritiesCompany(string g_path);

    //5. 新增券商
    int AddSecuritiesCompany(string g_path);

    //6. 不需要更新券商白名单。
    int DelSecuritiesCompany(string g_path);

};

