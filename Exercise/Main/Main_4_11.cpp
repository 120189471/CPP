int main_4_11(){
    bool                flag;
    char                cval;
    short               sval;
    unsigned short      usval;
    int                 ival;
    unsigned int        uival;
    long                lval;
    unsigned long       ulval;
    float               fval;
    double              dval=0.0;
    /*
    3.1415926L + 'a';                   //a->int->double
    dval + ival;                        //int->double
    dval + fval;                        //float->double
    ival = dval;                        //dval->int,ȥ��С����
    flag = dval;                        //dval=0��"false":"true"
    cval + fval;                        //char->int->float;
    sval + cval;                        //short->int;char->int 
    cval + lval;                        //char->long;
    ival + ulval;                       //int->unsigned long
    usval + ival;                       //����ռ�ռ��С
    uival + lval;                       //����ռ�ռ��С
    */

    int ia[10];
    int* iaPtr = ia;                    //����ת����ָ��

    return 0;
}