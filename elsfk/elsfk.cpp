#include <windows.h>
//windows.h�ļ��а���Ӧ�ó�����������������ͺ����ݽṹ�Ķ���
#include <time.h>
//����SetTimer()��KillTimer()�ȹ��ڶ�ʱ���ĺ���
#include <stdlib.h>


#define CELL 15             // �����񡿵ı߳�(pix)  
#define W  20             // ��Ϸ����(12�������񡿱߳�,8��������������"��һ��"����)
#define H  26             // ��Ϸ����(26�������񡿱߳�)
#define MS_NEWBLOCK WM_USER+1  // ��ϢID�������µġ����顿
#define MS_DRAW  WM_USER+2  // ��ϢID�������������顿
#define MS_NEXTBLOCK WM_USER+3 //��ϢID��������ʾ��һ��������˹���顿��״




//------------------------���ں�����˵��------------------------
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


//---------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR  szCmdLine,

    int  iCmdShow)


{

    static
        char AppName[] = "ToyBrick";           //��������
    HWND  hwnd;
    MSG   msg;       //��Ϣ�ṹ
    WNDCLASSEX wndclass;      //������

    int   iScreenWide;                    //����һ�����ͱ�����ȡ�ô��ڵĿ��  


    wndclass.cbSize = sizeof(wndclass);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;//��������



    //CS_HREDRAW ��Redraws the entire window if a movement or size 

    //             adjustment changes the width of the client area.

    //CS_VREDRAW ��Redraws the entire window if a movement or size

    //             adjustment changes the height of the client area.  


    wndclass.lpfnWndProc = WndProc;        //���ڴ�����ΪWndProc
    wndclass.cbClsExtra = 0;         //����������չ
    wndclass.cbWndExtra = 0;         //����ʵ������չ  
    wndclass.hInstance = hInstance;                            //��ǰʵ�����
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);     //Ĭ��ͼ��
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);          //��ͷ���
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //����Ϊ��ɫ
    wndclass.lpszMenuName = NULL;         //�������޲˵�
    wndclass.lpszClassName = AppName;           //����Ϊ"ToyBrick"
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


    //----------------------------------�������ע��-----------------------------------------



    if (!RegisterClassEx(&wndclass))          //���ע��ʧ���򷢳���������������FALSE
    {
        MessageBeep(0);

        return FALSE;
    }



    // ��ȡ��ʾ���ֱ��ʵ�XֵiScreenWide�������򴰿�������Ļ����
    iScreenWide = GetSystemMetrics(SM_CXFULLSCREEN);


    hwnd = CreateWindow(
        AppName,                    //��������

        "�����������",    //����ʵ���ı�����
        WS_MINIMIZEBOX | WS_SYSMENU, //���ڵķ��
        iScreenWide / 2 - W*CELL / 2,     //�������ϽǺ�����(X)
        CELL,                       //�������Ͻ�������(Y)
        W*CELL,             //���ڵĿ�
        H*CELL,                     //���ڵĸ�
        NULL,                       //�����޸����� 
        NULL,      //���������˵�
        hInstance,     //�����˴��ڵ�Ӧ�ó���ĵ�ǰ���
        NULL                        //��ʹ�ø�ֵ
        );

    if (!hwnd) return FALSE;

    //��ʾ����
    ShowWindow(hwnd, iCmdShow);

    //�����û���
    UpdateWindow(hwnd);
    MessageBox(hwnd, " ��ʼ��Ϸ\n\n OH YEAH", "��ʼ", MB_OK);
    SendMessage(hwnd, MS_NEWBLOCK, 0, 0);


    SetTimer(hwnd, 1, 100, NULL);



    //��Ϣѭ��

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    //��Ϣѭ��������������ֹʱ����Ϣ����ϵͳ

    return msg.wParam;
}


// ����DrawRact: ���������Ρ�----- (��)
// ����: �豸��������͡������Ρ����Ľ�����
void DrawRect(HDC hdc, int l, int t, int r, int b) {
    MoveToEx(hdc, l, t, NULL);   //������ƶ���(l,t)
    LineTo(hdc, r, t);
    LineTo(hdc, r, b);
    LineTo(hdc, l, b);
    LineTo(hdc, l, t);
}




// ����DrawCell: ��������-----(��ɫ��)
// ����: �豸��������͡����񡿵��Ľ�����
void DrawCell(HDC hdc, int l, int t, int r, int b) {
    HBRUSH hbrush;


    hbrush = CreateSolidBrush(RGB(255, 0, 0));    // ��ɫ��ˢ
    SelectObject(hdc, hbrush);
    Rectangle(hdc, l, t, r, b);
    DeleteObject(hbrush);




}


//�����Ϸ����ķ������а���"��Ϸ�ռ�"��"��ʾ��һ�������顿�ռ�"
//�˺���������Cover�����С��������豸�������
void DrawGamePlace(HDC hdc) {

    int i, j;
    HPEN hpen1, hpen2;
    hpen1 = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
    hpen2 = CreatePen(PS_DASHDOTDOT, 3, RGB(0, 0, 255));



    //���Ʒָ���
    SelectObject(hdc, hpen2);
    MoveToEx(hdc, (W - 8)*CELL, 0, NULL);
    LineTo(hdc, (W - 8)*CELL, H*CELL);



    //������Ϸ���򷽸���(��ɫ)
    SelectObject(hdc, hpen1);

    for (i = 1; i<H - 1; i++)

        for (j = 1; j <= W - 8; j++)
            DrawRect(hdc, (j - 1)*CELL, (i - 1)*CELL, j*CELL, i*CELL);



    //����"��ʾ��һ��"����ķ�����

    for (i = 5; i<9; i++)                             // 5��i��

        for (j = W - 5; j<W - 1; j++)                     // 15��j��
            DrawRect(hdc, (j - 1)*CELL, (i - 1)*CELL, j*CELL, i*CELL);


    DeleteObject(hpen2);
    DeleteObject(hpen1);


}


// ����DrawBlock: ����Ϸ�г��ֵġ�����˹���顿
// ����: �豸��������͡�����˹���顿���ĸ�����������Ϸ�����е�λ��
// ÿ��������˹���顿���ĸ�����������ֲ�ͬ����״
void DrawBlock(HDC hdc, int block[4][2]) {

    int i;

    for (i = 0; i<4; i++)
        DrawCell(hdc, (block[0] - 1)*CELL, (block[1] - 1)*CELL, //....
        block[0] * CELL, block[1] * CELL);


}


// ����Cover: ���ԭ��λ�õġ�����˹���顿
// ����: �豸��������ʹ�����ġ�����˹���顿
//����(1) ���������˹���顿���ڸá�����˹���顿��ÿ�������񡿴���һ�������εİ׿�
//    (2) ���»�����Ϸ����ķ���


void Cover(HDC hdc, int org[4][2]) {

    int i;
    HBRUSH hbrush;

    //���»�����Ϸ����
    DrawGamePlace(hdc);


    hbrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
    SelectObject(hdc, hbrush);

    for (i = 0; i<4; i++)
        Rectangle(hdc, (org[0] - 1)*CELL, (org[1] - 1)*CELL, //.....
        org[0] * CELL, org[1] * CELL);
    DeleteObject(hbrush);


}


//-------------------���ڹ��̺���WndProc-----------------------------


LRESULT CALLBACK WndProc(HWND  hwnd,
    UINT  iMsg,
    WPARAM wParam,
    LPARAM lParam) {

    int   i, j, k, lines, r;

    static
        int top, sel, flag;

    static
        int cells[W - 6][H];                           // ������Ϸ����ġ��������

    static
        int org[4][2], block[4][2], org2[4][2];       // �����顿
    HDC   hdc;
    HPEN  hpen;
    PAINTSTRUCT ps;



    switch (iMsg) {

    case WM_CREATE:

        //��һ��Ӧ�ó���ʹ�ú���CreateWindow��CreateWindowEx������һ������ʱ��

        //ϵͳ�����͸���Ϣ�����½����ڹ��̡�����Ϣ���ڴ�������֮����ʾ����

        //֮ǰ���͸���Ϣ������Ϣ����CreateWindow��CreateWindowEx��������֮ǰ���͡�


        top = H - 1;

        // ����һ�к����һ�С������ã����ơ����顿��������Ϸ����

        for (i = 0; i<H; i++) {
            cells[0] = 1;
            cells[W - 7] = 1;
        }



        // �������һ�С������ã����ơ����顿��������Ϸ����

        for (i = 0; i<W - 6; i++)
            cells[H - 1] = 1;



        // �����������ã���Ϸ����ֻ���������ƶ�

        for (i = 1; i <= W - 8; i++)

            for (j = 0; j<H - 1; j++)
                cells[j] = 0;





        return 0;



    case MS_NEWBLOCK:


        flag = 0;         // flag��ʾ�����顿��ת�˼���



        for (i = top; i<H - 1; i++) {
            lines = 0;



            // ѭ��������Ƿ���ĳһ��ȫ���������񡿶�����

            for (j = 1; j <= W - 7; j++)

                if (!cells[j]) {
                lines = 1;

                break;
                }



            // �����б�����������һ�е����״̬���Ƶ����У���������

            // ���Ӹ��п�ʼ�����еġ����񡿶�����һ��

            if (!lines) {
                for (j = 1; j<W - 7; j++)

                    for (k = i; k >= top; k--)
                        cells[j][k] = cells[j][k - 1];
                top++;



                //�ú�����ָ�������û������ڵľ��μ��뵽�ô��ڵĸ�������֮��

                //ʹ�þ�����Ч�������Ч�ľ��Σ���ͬ���������е������������յ���

                //һ��WM_PAINT��Ϣʱ�����ػ�����Ч��һֱ�����ڸ�������֮�У�ֱ��

                //��һ��WM_PAINT��Ϣ����ʱ�Ը�������д���
                InvalidateRect(hwnd, NULL, TRUE);
            }
        }



        // ��������������ֱ�������顿������״
        srand((unsigned)time(NULL));
        sel = rand() % 7;



        //�����顿��״��ʼ��

        //�����顿����״����ÿ�������񡿵�λ�þ���

        // ��Ϸ����W=20��block[?][0]=4/5/6/7��block[?][1]=0/1/2

        // ���������顿��ʼλ������Ϸ��������������

        switch (sel) {

        case 0:

            // ����

            // ����
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

            //��������
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

            //��

            //����

            //  ��
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

            //  ��

            //����

            //��
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

            //��

            //��

            //����
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

            //  ��

            //  ��

            //����
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

            //  ��

            //������
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



        // ÿ��ʱ����ġ����顿�Զ�����һ��

        for (i = 0; i<4; i++)
            block[1]++;



        // ��顾���顿�����Ƿ񱻵�ס�����ж����ƺ���λ���Ƿ��С�����

        for (i = 0; i<4; i++)

            if (cells[block[0]][block[1]]) {
            SendMessage(hwnd, MS_NEXTBLOCK, 0, 0);



            for (i = 0; i<4; i++)
                cells[org[0]][org[1]] = 1;



            if (top>org[0][1] - 2)
                top = org[0][1] - 2;



            if (top<1) {
                KillTimer(hwnd, 1);
                MessageBox(hwnd, "��Ϸ����,�����˳�!\n    �������", "�˳�", MB_OK);
                PostQuitMessage(0);
            }


            SendMessage(hwnd, MS_NEWBLOCK, 0, 0);

            return 0;
            }


        SendMessage(hwnd, MS_DRAW, 0, 0);



        return 0;



        // ��Ӧ���̿���

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



            // ��[���ϼ�]�������顿˳ʱ����ת

            //�����顿����ת������������ת�����Ǹ��ݲ�ͬ�ġ����顿��״�͸á����顿��ת����

            // �������ƶ����е�һ���򼸸������񡿣��Ӷ��ﵽ��ת��Ч�����������ܸ��ӣ��㷨

            // �������룬�����ܹ����֡����顿��תʱ�����ıȽ��ȶ���



        case VK_UP:
            r = 1;
            flag++;                         //�����顿��ת��



            switch (sel)                     // sel����ǰ�����顿����״
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



        // �жϡ����顿��ת����λ���Ƿ��С����񡿣����У�����תȡ��

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



        // �����ǰ�����顿��������ʾ����һ�����顱��������һ�������顿

    case MS_NEXTBLOCK:


        hdc = GetDC(hwnd);
        Cover(hdc, org2);
        //   DrawBlock(hdc,org2);





        return 0;



        // �����ǰ�����顿�������µ�λ�����»��ơ����顿

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



        // ���ա���������ػ���Ϸ����ġ�����

    case WM_PAINT:


        hdc = BeginPaint(hwnd, &ps);
        DrawGamePlace(hdc);
        TextOut(hdc, 15 * CELL, 12 * CELL, "Score", lstrlen("Score"));
        TextOut(hdc, 15 * CELL, 13 * CELL, "i", lstrlen("i"));
        TextOut(hdc, 15 * CELL, 15 * CELL, "Level", lstrlen("Level"));
        TextOut(hdc, 15 * CELL - 5, 19 * CELL, "�������", lstrlen("�������"));
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