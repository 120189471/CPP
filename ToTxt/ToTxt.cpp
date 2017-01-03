/* 读文件,并进行分割,

读TotNumTradeReports字段，生成文件体指针数组

文件头：
文件体：
文件尾：

定义一个结构体
*/
#include <fstream>
using std::fstream;
using std::ios;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include<vector>
using std::vector;

#include<deque>
using std::deque;

#include <map>
using std::map;

#include <iomanip>
using std::setw;

#include <ios>
using std::left;

#include "File.cpp"
#include "GetFileBody.cpp"
#include "FileBody.cpp"


void GetFileBody(string  file_path, int code, map<string, FileBody> &mfb, vector<string> v_nametable)
{
    string first_line;

    fstream once_txt(file_path, ios::in);

    getline(once_txt, first_line);

    for (int i = 0; i != code; i++)
    {
        FileBody fb;
        fb.SecurityID = v_nametable[i];
        
        //单条记录, 填写对象

        getline(once_txt, mfb[fb.SecurityID].MDStreamID, '|');
        getline(once_txt, mfb[fb.SecurityID].SecurityID, '|');
        getline(once_txt, mfb[fb.SecurityID].Symbol, '|');
        getline(once_txt, mfb[fb.SecurityID].TradeVolume, '|');
        getline(once_txt, mfb[fb.SecurityID].TotalValueTraded, '|');
        getline(once_txt, mfb[fb.SecurityID].PreClosePx, '|');
        getline(once_txt, mfb[fb.SecurityID].OpenPrice, '|');
        getline(once_txt, mfb[fb.SecurityID].HighPrice, '|');
        getline(once_txt, mfb[fb.SecurityID].LowPrice, '|');
        getline(once_txt, mfb[fb.SecurityID].TradePrice, '|');
        getline(once_txt, mfb[fb.SecurityID].ClosePx, '|');

        if (fb.MDStreamID != "MD001")
        {
            getline(once_txt, mfb[fb.SecurityID].BuyPrice1, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyVolume1, '|');
            getline(once_txt, mfb[fb.SecurityID].SellPrice1, '|');
            getline(once_txt, mfb[fb.SecurityID].SellVolume1, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyPrice2, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyVolume2, '|');
            getline(once_txt, mfb[fb.SecurityID].SellPrice2, '|');
            getline(once_txt, mfb[fb.SecurityID].SellVolume2, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyPrice3, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyVolume3, '|');
            getline(once_txt, mfb[fb.SecurityID].SellPrice3, '|');
            getline(once_txt, mfb[fb.SecurityID].SellVolume3, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyPrice4, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyVolume4, '|');
            getline(once_txt, mfb[fb.SecurityID].SellPrice4, '|');
            getline(once_txt, mfb[fb.SecurityID].SellVolume4, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyPrice5, '|');
            getline(once_txt, mfb[fb.SecurityID].BuyVolume5, '|');
            getline(once_txt, mfb[fb.SecurityID].SellPrice5, '|');
            getline(once_txt, mfb[fb.SecurityID].SellVolume5, '|');
            if (fb.MDStreamID == "MD004")
            {
                getline(once_txt, mfb[fb.SecurityID].PreCloseIOPV, '|');
                getline(once_txt, mfb[fb.SecurityID].IOPV, '|');
            }
            else
                ;
        }
        else
            ;
        getline(once_txt, mfb[fb.SecurityID].TradingPhaseCode, '|');
        getline(once_txt, mfb[fb.SecurityID].Timestamp, '\n');

       
    }

    once_txt.close();
    // return vfb;
}


void GetFileHead(string  file_path, FileHead &fh)
{
    fstream once_txt(file_path, ios::in);
    getline(once_txt, fh.BeginString, '|');
    getline(once_txt, fh.Version, '|');
    getline(once_txt, fh.BodyLength, '|');
    getline(once_txt, fh.TotNumTradeReports, '|');
    getline(once_txt, fh.MDReportID, '|');
    getline(once_txt, fh.SenderCompID, '|');
    getline(once_txt, fh.MDTime, '|');
    getline(once_txt, fh.MDUpdateType, '|');
    getline(once_txt, fh.MDSesStatus);
    once_txt.close();

}

int main()
{
    FileHead fh;
    string file_path = "D://remote//mktdt00.txt";
    
    fstream txt(file_path, ios::in);
    if (!txt)
    {
        cerr << "文件不存在!" << endl;
    }

    /*
    txt.seekg(0)>> fh.BeginString;
    txt.seekg(7)>> fh.Version;
    txt.seekg(16)>> fh.BodyLength;
    txt.seekg(27)>> fh.TotNumTradeReports;
    txt.seekg(49) >> fh.MDTime;
    */
    //while(!txt.eof())
    //第一字段判断
    //文件头行 
    getline(txt, fh.BeginString, '|');

    getline(txt, fh.Version, '|');
    getline(txt, fh.BodyLength, '|');
    getline(txt, fh.TotNumTradeReports, '|');
    getline(txt, fh.MDReportID, '|');
    getline(txt, fh.SenderCompID, '|');
    getline(txt, fh.MDTime, '|');
    getline(txt, fh.MDUpdateType, '|');
    getline(txt, fh.MDSesStatus);

    /*
    //头行字段输出
    cout << "\n---------输出1---------" << endl;
    cout << fh.BeginString << "\n"
        << fh.Version << "\n"
        << fh.BodyLength << "\n"
        << fh.TotNumTradeReports << "\n"
        << fh.MDTime << "\n"
        << endl;;
    //txt.seekg(0);
    //for (i = 0;i=100)
    cout << "\n---------输出1结束---------" << endl;
    */

    //商品个数
    const int code_name = atoi(fh.TotNumTradeReports.c_str());
    //定义需要申请的内存长度
    size_t memory_space = atoi(fh.BodyLength.c_str());
    /*
    //开辟码表空间,这个有问题
    //deque<FileBody> *name_table = new deque<FileBody>[memory_space];
    */
    
    //定义索引
    
    //先用vector定义。
    vector<FileBody> vfb;
    map<string,FileBody> mfb;
    //码表文件
    vector<string> v_nametable;

    //vbf = name_talbe;

    for (int i = 0; i != code_name; i++)
    {
        FileBody fb;
        //填写每条记录
        getline(txt, fb.MDStreamID, '|');
        getline(txt, fb.SecurityID, '|');
        getline(txt, fb.Symbol, '|');
        getline(txt, fb.TradeVolume, '|');
        getline(txt, fb.TotalValueTraded, '|');
        getline(txt, fb.PreClosePx, '|');
        getline(txt, fb.OpenPrice, '|');
        getline(txt, fb.HighPrice, '|');
        getline(txt, fb.LowPrice, '|');
        getline(txt, fb.TradePrice, '|');
        getline(txt, fb.ClosePx, '|');

        if (fb.MDStreamID != "MD001")
        {
            getline(txt, fb.BuyPrice1, '|');
            getline(txt, fb.BuyVolume1, '|');
            getline(txt, fb.SellPrice1, '|');
            getline(txt, fb.SellVolume1, '|');
            getline(txt, fb.BuyPrice2, '|');
            getline(txt, fb.BuyVolume2, '|');
            getline(txt, fb.SellPrice2, '|');
            getline(txt, fb.SellVolume2, '|');
            getline(txt, fb.BuyPrice3, '|');
            getline(txt, fb.BuyVolume3, '|');
            getline(txt, fb.SellPrice3, '|');
            getline(txt, fb.SellVolume3, '|');
            getline(txt, fb.BuyPrice4, '|');
            getline(txt, fb.BuyVolume4, '|');
            getline(txt, fb.SellPrice4, '|');
            getline(txt, fb.SellVolume4, '|');
            getline(txt, fb.BuyPrice5, '|');
            getline(txt, fb.BuyVolume5, '|');
            getline(txt, fb.SellPrice5, '|');
            getline(txt, fb.SellVolume5, '|');
            if (fb.MDStreamID == "MD004")
            {
                getline(txt, fb.PreCloseIOPV, '|');
                getline(txt, fb.IOPV, '|');
            }
            else
                ;
        }
        else
            ;
        
        getline(txt, fb.TradingPhaseCode, '|');
        getline(txt, fb.Timestamp, '\n');

        //name_talbe[i] = fb;   //错误
        //vfb.push_back(fb);
        v_nametable.push_back(fb.SecurityID);
        mfb.insert({ fb.SecurityID, fb });
        
        
    }

    txt.close();
    /*
    cout << "vector定长: " << sizeof vfb<< endl;

    cout << "-----------输出code--------------" << endl;
    //for(int i=0;i!=1;i++)
    {
        FileBody f;
        f = vfb[1];
        //cout<<f.MDStreamID<<"\t"<<f.SecurityID<<"\t"<<f.Symbol<<"\t"<<endl;
        cout << f.BuyPrice1 << " " << f.BuyVolume1 << endl;
    }
    */

    //定时器
    //在制定时间读，先写体
    string code = "000001";
    
    while (true)
    {
        GetFileHead(file_path, fh);
        GetFileBody(file_path, code_name, mfb,v_nametable);
        
        cout << "------------------快照显示-----------------" << endl;
        cout << setw(23) << left << fh.MDTime
            << setw(8) << left << mfb[code].SecurityID
            << setw(10) << left << mfb[code].Symbol
            << setw(18) << left << mfb[code].TradeVolume
            << setw(18) << left << mfb[code].TotalValueTraded
            << endl;
    }
    //delete[]name_talbe;

    system("PAUSE");
    return 0;
};

