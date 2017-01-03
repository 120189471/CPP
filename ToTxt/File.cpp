#include <string>
using std::string;

struct FileHead
{
    string BeginString;
    string Version;
    string BodyLength;
    string TotNumTradeReports;
    string MDReportID;
    string SenderCompID;
    string MDTime;                    //时间格式:20160930-11:12:32.050
    string MDUpdateType;
    string MDSesStatus;                //市场行情状态
};

