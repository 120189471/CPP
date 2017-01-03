#include <windows.h>
//windows.h文件中包含应用程序中所需的数据类型和数据结构的定义
#include <time.h>
//包含SetTimer()、KillTimer()等关于定时器的函数
#include <stdlib.h>


#define CELL 15             // 【方格】的边长(pix)  
#define W  20             // 游戏区宽(12个【方格】边长,8个格子用来绘制"下一个"方块)
#define H  26             // 游戏区高(26个【方格】边长)
#define MS_NEWBLOCK WM_USER+1  // 消息ID，产生新的【方块】
#define MS_DRAW  WM_USER+2  // 消息ID，用来画【方块】
#define MS_NEXTBLOCK WM_USER+3 //消息ID，用来显示下一个【俄罗斯方块】形状




//------------------------窗口函数的说明------------------------
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


//---------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR  szCmdLine,

    int  iCmdShow)


{

    static
        char AppName[] = "ToyBrick";           //窗口类名
    HWND  hwnd;
    MSG   msg;       //消息结构
    WNDCLASSEX wndclass;      //窗口类

    int   iScreenWide;                    //定义一个整型变量来取得窗口的宽度  


    wndclass.cbSize = sizeof(wndclass);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;//窗口类型



    //CS_HREDRAW ：Redraws the entire window if a movement or size 

    //             adjustment changes the width of the client area.

    //CS_VREDRAW ：Redraws the entire window if a movement or size

    //             adjustment changes the height of the client area.  


    wndclass.lpfnWndProc = WndProc;        //窗口处理函数为WndProc
    wndclass.cbClsExtra = 0;         //窗口类无扩展
    wndclass.cbWndExtra = 0;         //窗口实例无扩展  
    wndclass.hInstance = hInstance;                            //当前实例句柄
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);     //默认图标
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);          //箭头光标
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //背景为黑色
    wndclass.lpszMenuName = NULL;         //窗口中无菜单
    wndclass.lpszClassName = AppName;           //类名为"ToyBrick"
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


    //----------------------------------窗口类的注册-----------------------------------------



    if (!RegisterClassEx(&wndclass))          //如果注册失败则发出警报声音，返回FALSE
    {
        MessageBeep(0);

        return FALSE;
    }



    // 获取显示器分辨率的X值iScreenWide，将程序窗口置于屏幕中央
    iScreenWide = GetSystemMetrics(SM_CXFULLSCREEN);


    hwnd = CreateWindow(
        AppName,                    //窗口类名

        "四面楚歌制作",    //窗口实例的标题名
        WS_MINIMIZEBOX | WS_SYSMENU, //窗口的风格
        iScreenWide / 2 - W*CELL / 2,     //窗口左上角横坐标(X)
        CELL,                       //窗口左上角纵坐标(Y)
        W*CELL,             //窗口的宽
        H*CELL,                     //窗口的高
        NULL,                       //窗口无父窗口 
        NULL,      //窗口无主菜单
        hInstance,     //创建此窗口的应用程序的当前句柄
        NULL                        //不使用该值
        );

    if (!hwnd) return FALSE;

    //显示窗口
    ShowWindow(hwnd, iCmdShow);

    //绘制用户区
    UpdateWindow(hwnd);
    MessageBox(hwnd, " 开始游戏\n\n OH YEAH", "开始", MB_OK);
    SendMessage(hwnd, MS_NEWBLOCK, 0, 0);


    SetTimer(hwnd, 1, 100, NULL);



    //消息循环

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    //消息循环结束即程序终止时将消息返回系统

    return msg.wParam;
}


// 函数DrawRact: 画【正方形】----- (□)
// 参数: 设备环境句柄和【正方形】的四角坐标
void DrawRect(HDC hdc, int l, int t, int r, int b) {
    MoveToEx(hdc, l, t, NULL);   //将光标移动到(l,t)
    LineTo(hdc, r, t);
    LineTo(hdc, r, b);
    LineTo(hdc, l, b);
    LineTo(hdc, l, t);
}




// 函数DrawCell: 画【方格】-----(红色■)
// 参数: 设备环境句柄和【方格】的四角坐标
void DrawCell(HDC hdc, int l, int t, int r, int b) {
    HBRUSH hbrush;


    hbrush = CreateSolidBrush(RGB(255, 0, 0));    // 红色画刷
    SelectObject(hdc, hbrush);
    Rectangle(hdc, l, t, r, b);
    DeleteObject(hbrush);




}


//绘出游戏区域的方格，其中包括"游戏空间"和"显示下一个【方块】空间"
//此函数包含在Cover函数中。参数：设备环境句柄
void DrawGamePlace(HDC hdc) {

    int i, j;
    HPEN hpen1, hpen2;
    hpen1 = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
    hpen2 = CreatePen(PS_DASHDOTDOT, 3, RGB(0, 0, 255));



    //绘制分割线
    SelectObject(hdc, hpen2);
    MoveToEx(hdc, (W - 8)*CELL, 0, NULL);
    LineTo(hdc, (W - 8)*CELL, H*CELL);



    //绘制游戏区域方格线(绿色)
    SelectObject(hdc, hpen1);

    for (i = 1; i<H - 1; i++)

        for (j = 1; j <= W - 8; j++)
            DrawRect(hdc, (j - 1)*CELL, (i - 1)*CELL, j*CELL, i*CELL);



    //绘制"显示下一个"区域的方格线

    for (i = 5; i<9; i++)                             // 5≤i≤

        for (j = W - 5; j<W - 1; j++)                     // 15≤j≤
            DrawRect(hdc, (j - 1)*CELL, (i - 1)*CELL, j*CELL, i*CELL);


    DeleteObject(hpen2);
    DeleteObject(hpen1);


}


// 函数DrawBlock: 画游戏中出现的【俄罗斯方块】
// 参数: 设备环境句柄和【俄罗斯方块】中四个【方格】在游戏区域中的位置
// 每个【俄罗斯方块】由四个【方格】组成种不同的形状
void DrawBlock(HDC hdc, int block[4][2]) {

    int i;

    for (i = 0; i<4; i++)
        DrawCell(hdc, (block[0] - 1)*CELL, (block[1] - 1)*CELL, //....
        block[0] * CELL, block[1] * CELL);


}


// 函数Cover: 清除原来位置的【俄罗斯方块】
// 参数: 设备环境句柄和待清除的【俄罗斯方块】
//作用(1) 清除【俄罗斯方块】即在该【俄罗斯方块】的每个【方格】处画一个正方形的白块
//    (2) 重新绘制游戏区域的方格


void Cover(HDC hdc, int org[4][2]) {

    int i;
    HBRUSH hbrush;

    //重新绘制游戏区域
    DrawGamePlace(hdc);


    hbrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
    SelectObject(hdc, hbrush);

    for (i = 0; i<4; i++)
        Rectangle(hdc, (org[0] - 1)*CELL, (org[1] - 1)*CELL, //.....
        org[0] * CELL, org[1] * CELL);
    DeleteObject(hbrush);


}


//-------------------窗口过程函数WndProc-----------------------------


LRESULT CALLBACK WndProc(HWND  hwnd,
    UINT  iMsg,
    WPARAM wParam,
    LPARAM lParam) {

    int   i, j, k, lines, r;

    static
        int top, sel, flag;

    static
        int cells[W - 6][H];                           // 控制游戏区域的【方格矩阵】

    static
        int org[4][2], block[4][2], org2[4][2];       // 【方块】
    HDC   hdc;
    HPEN  hpen;
    PAINTSTRUCT ps;



    switch (iMsg) {

    case WM_CREATE:

        //当一个应用程序使用函数CreateWindow或CreateWindowEx来创建一个窗口时，

        //系统将发送该消息给此新建窗口过程。该消息将在创建窗口之后，显示窗口

        //之前发送该消息，该消息将在CreateWindow或CreateWindowEx函数返回之前发送。


        top = H - 1;

        // 将第一列和最后一列【方格】置，控制【方块】不超出游戏区域

        for (i = 0; i<H; i++) {
            cells[0] = 1;
            cells[W - 7] = 1;
        }



        // 将最底下一行【方格】置，控制【方块】不超出游戏区域

        for (i = 0; i<W - 6; i++)
            cells[H - 1] = 1;



        // 其他【方格】置，游戏方块只能在这里移动

        for (i = 1; i <= W - 8; i++)

            for (j = 0; j<H - 1; j++)
                cells[j] = 0;





        return 0;



    case MS_NEWBLOCK:


        flag = 0;         // flag表示【方块】旋转了几次



        for (i = top; i<H - 1; i++) {
            lines = 0;



            // 循环语句检查是否有某一行全部被【方格】都填满

            for (j = 1; j <= W - 7; j++)

                if (!cells[j]) {
                lines = 1;

                break;
                }



            // 若该行被填满，则将上一行的填充状态复制到该行，依此类推

            // 即从该行开始，所有的【方格】都下移一行

            if (!lines) {
                for (j = 1; j<W - 7; j++)

                    for (k = i; k >= top; k--)
                        cells[j][k] = cells[j][k - 1];
                top++;



                //该函数把指定窗口用户区域内的矩形加入到该窗口的更新区域之外

                //使该矩形无效。这个无效的矩形，连同更新区域中的其他区域，在收到下

                //一条WM_PAINT消息时将被重画。无效区一直积累在更新区域之中，直到

                //下一条WM_PAINT消息发生时对该区域进行处理。
                InvalidateRect(hwnd, NULL, TRUE);
            }
        }



        // 产生随机数～，分别代表【方块】的种形状
        srand((unsigned)time(NULL));
        sel = rand() % 7;



        //【方块】形状初始化

        //【方块】的形状由其每个【方格】的位置决定

        // 游戏区宽W=20，block[?][0]=4/5/6/7，block[?][1]=0/1/2

        // 这样【方块】初始位置在游戏区域的最顶部的中央

        switch (sel) {

        case 0:

            // ▓▓

            // ▓▓
            org[0][0] = block[0][0] = 5; org[0][1] = block[0][1] = 0;
            org[1][0] = block[1][0] = 6; org[1][1] = block[1][1] = 0;
            org[2][0] = block[2][0] = 5; org[2][1] = block[2][1] = 1;
            org[3][0] = block[3][0] = 6; org[3][1] = block[3][1] = 1;

            for (i = 0; i<4; i++) {
                org2[0] = org[0] + 11;
                org2[1] = org[1] + 5;
            }



            break;



        case 1:

            //▓▓▓▓
            org[0][0] = block[0][0] = 4; org[0][1] = block[0][1] = 0;
            org[1][0] = block[1][0] = 5; org[1][1] = block[1][1] = 0;
            org[2][0] = block[2][0] = 6; org[2][1] = block[2][1] = 0;
            org[3][0] = block[3][0] = 7; org[3][1] = block[3][1] = 0;

            for (i = 0; i<4; i++) {
                org2[0] = org[0] + 11;
                org2[1] = org[1] + 5;
            }



            break;





        case 2:

            //▓

            //▓▓

            //  ▓
            org[0][0] = block[0][0] = 5; org[0][1] = block[0][1] = 0;
            org[1][0] = block[1][0] = 5; org[1][1] = block[1][1] = 1;
            org[2][0] = block[2][0] = 6; org[2][1] = block[2][1] = 1;
            org[3][0] = block[3][0] = 6; org[3][1] = block[3][1] = 2;

            for (i = 0; i<4; i++) {
                org2[0] = org[0] + 11;
                org2[1] = org[1] + 5;
            }



            break;



        case 3:

            //  ▓

            //▓▓

            //▓
            org[0][0] = block[0][0] = 6; org[0][1] = block[0][1] = 0;
            org[1][0] = block[1][0] = 6; org[1][1] = block[1][1] = 1;
            org[2][0] = block[2][0] = 5; org[2][1] = block[2][1] = 1;
            org[3][0] = block[3][0] = 5; org[3][1] = block[3][1] = 2;

            for (i = 0; i<4; i++) {
                org2[0] = org[0] + 11;
                org2[1] = org[1] + 5;
            }



            break;



        case 4:

            //▓

            //▓

            //▓▓
            org[0][0] = block[0][0] = 5; org[0][1] = block[0][1] = 0;
            org[1][0] = block[1][0] = 5; org[1][1] = block[1][1] = 1;
            org[2][0] = block[2][0] = 5; org[2][1] = block[2][1] = 2;
            org[3][0] = block[3][0] = 6; org[3][1] = block[3][1] = 2;

            for (i = 0; i<4; i++) {
                org2[0] = org[0] + 11;
                org2[1] = org[1] + 5;
            }



            break;



        case 5:

            //  ▓

            //  ▓

            //▓▓
            org[0][0] = block[0][0] = 5; org[0][1] = block[0][1] = 0;
            org[1][0] = block[1][0] = 5; org[1][1] = block[1][1] = 1;
            org[2][0] = block[2][0] = 5; org[2][1] = block[2][1] = 2;
            org[3][0] = block[3][0] = 4; org[3][1] = block[3][1] = 2;

            for (i = 0; i<4; i++) {
                org2[0] = org[0] + 11;
                org2[1] = org[1] + 5;
            }



            break;

        case 6:

            //  ▓

            //▓▓▓
            org[0][0] = block[0][0] = 5; org[0][1] = block[0][1] = 0;
            org[1][0] = block[1][0] = 4; org[1][1] = block[1][1] = 1;
            org[2][0] = block[2][0] = 5; org[2][1] = block[2][1] = 1;
            org[3][0] = block[3][0] = 6; org[3][1] = block[3][1] = 1;

            for (i = 0; i<4; i++) {
                org2[0] = org[0] + 11;
                org2[1] = org[1] + 5;
            }


            SendMessage(hwnd, MS_NEXTBLOCK, 0, 0);

            break;



        default:


            SendMessage(hwnd, MS_NEWBLOCK, 0, 0);
            SendMessage(hwnd, MS_NEXTBLOCK, 0, 0);

            break;
        }



        return 0;



    case WM_TIMER:



        // 每个时间节拍【方块】自动下移一行

        for (i = 0; i<4; i++)
            block[1]++;



        // 检查【方块】下移是否被档住，即判断下移后新位置是否有【方格】

        for (i = 0; i<4; i++)

            if (cells[block[0]][block[1]]) {
            SendMessage(hwnd, MS_NEXTBLOCK, 0, 0);



            for (i = 0; i<4; i++)
                cells[org[0]][org[1]] = 1;



            if (top>org[0][1] - 2)
                top = org[0][1] - 2;



            if (top<1) {
                KillTimer(hwnd, 1);
                MessageBox(hwnd, "游戏结束,即将退出!\n    四面楚歌", "退出", MB_OK);
                PostQuitMessage(0);
            }


            SendMessage(hwnd, MS_NEWBLOCK, 0, 0);

            return 0;
            }


        SendMessage(hwnd, MS_DRAW, 0, 0);



        return 0;



        // 响应键盘控制

    case WM_KEYDOWN:
        r = 0;

        switch ((int)wParam) {

        case VK_LEFT:

            for (i = 0; i<4; i++)
                block[0]--;

            break;



        case VK_RIGHT:

            for (i = 0; i<4; i++)
                block[0]++;

            break;

        case VK_DOWN:

            for (i = 0; i<4; i++)
                block[1]++;

            break;



            // 按[向上键]，【方块】顺时针旋转

            //【方块】的旋转不是真正的旋转，而是根据不同的【方块】形状和该【方块】旋转过的

            // 次数来移动其中的一个或几个【方格】，从而达到旋转的效果。这样做很复杂，算法

            // 不够理想，但是能够保持【方块】旋转时的重心比较稳定。



        case VK_UP:
            r = 1;
            flag++;                         //【方块】旋转加



            switch (sel)                     // sel代表当前【方块】的形状
            {

            case 0: break;



            case 1:
                flag = flag % 2;

                for (i = 0; i<4; i++) {
                    block[(flag + 1) % 2] = org[2][(flag + 1) % 2];
                    block[flag] = org[2][flag] - 2 + i;
                }

                break;



            case 2:
                flag = flag % 2;

                if (flag) {
                    block[0][1] += 2; block[3][0] -= 2;
                }

                else {
                    block[0][1] -= 2; block[3][0] += 2;
                }

                break;



            case 3:
                flag = flag % 2;

                if (flag) {
                    block[0][1] += 2; block[3][0] += 2;
                }

                else {
                    block[0][1] -= 2; block[3][0] -= 2;
                }

                break;



            case 4:
                flag = flag % 4;

                switch (flag) {

                case 0:
                    block[2][0] += 2; block[3][0] += 2;
                    block[2][1] += 1; block[3][1] += 1;

                    break;

                case 1:
                    block[2][0] += 1; block[3][0] += 1;
                    block[2][1] -= 2; block[3][1] -= 2;

                    break;

                case 2:
                    block[2][0] -= 2; block[3][0] -= 2;
                    block[2][1] -= 1; block[3][1] -= 1;

                    break;

                case 3:
                    block[2][0] -= 1; block[3][0] -= 1;
                    block[2][1] += 2; block[3][1] += 2;

                    break;
                }

                break;



            case 5:
                flag = flag % 4;

                switch (flag) {

                case 0:
                    block[2][0] += 1; block[3][0] += 1;
                    block[2][1] += 2; block[3][1] += 2;

                    break;

                case 1:
                    block[2][0] += 2; block[3][0] += 2;
                    block[2][1] -= 1; block[3][1] -= 1;

                    break;

                case 2:
                    block[2][0] -= 1; block[3][0] -= 1;
                    block[2][1] -= 2; block[3][1] -= 2;

                    break;

                case 3:
                    block[2][0] -= 2; block[3][0] -= 2;
                    block[2][1] += 1; block[3][1] += 1;

                    break;
                }

                break;



            case 6:
                flag = flag % 4;

                switch (flag) {

                case 0:
                    block[0][0]++; block[0][1]--;
                    block[1][0]--; block[1][1]--;
                    block[3][0]++; block[3][1]++;

                    break;

                case 1:
                    block[1][0]++; block[1][1]++; break;

                case 2:
                    block[0][0]--; block[0][1]++; break;

                case 3:
                    block[3][0]--; block[3][1]--; break;
                }

                break;
            }

            break;
        }



        // 判断【方块】旋转后新位置是否有【方格】，若有，则旋转取消

        for (i = 0; i<4; i++)

            if (cells[block[0]][block[1]]) {

            if (r) flag += 3;

            for (i = 0; i<4; i++)

                for (j = 0; j<2; j++)
                    block[j] = org[j];

            return 0;
            }
        SendMessage(hwnd, MS_DRAW, 0, 0);;

        return 0;



        // 清楚当前【方块】，并在显示“下一个方块”处绘制下一个【方块】

    case MS_NEXTBLOCK:


        hdc = GetDC(hwnd);
        Cover(hdc, org2);
        //   DrawBlock(hdc,org2);





        return 0;



        // 清除当前【方块】，并在新的位置重新绘制【方块】

    case MS_DRAW:


        hdc = GetDC(hwnd);
        Cover(hdc, org);


        DrawBlock(hdc, org2);



        for (i = 0; i<4; i++)

            for (j = 0; j<2; j++)
                org[j] = block[j];


        DrawBlock(hdc, block);
        ReleaseDC(hwnd, hdc);



        return 0;



        // 按照【方格矩阵】重绘游戏区域的【方格】

    case WM_PAINT:


        hdc = BeginPaint(hwnd, &ps);
        DrawGamePlace(hdc);
        TextOut(hdc, 15 * CELL, 12 * CELL, "Score", lstrlen("Score"));
        TextOut(hdc, 15 * CELL, 13 * CELL, "i", lstrlen("i"));
        TextOut(hdc, 15 * CELL, 15 * CELL, "Level", lstrlen("Level"));
        TextOut(hdc, 15 * CELL - 5, 19 * CELL, "四面楚歌", lstrlen("四面楚歌"));
        hpen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
        SelectObject(hdc, hpen);

        for (i = top; i<H - 1; i++)

            for (j = 1; j <= W - 8; j++)

                if (cells[j])
                    DrawCell(hdc, (j - 1)*CELL, (i - 1)*CELL, j*CELL, i*CELL);


        DeleteObject(hpen);
        EndPaint(hwnd, &ps);

        return 0;



    case WM_DESTROY:
        KillTimer(hwnd, 1);
        PostQuitMessage(0);

        return 0;
    }



    return DefWindowProc(hwnd, iMsg, wParam, lParam);


}