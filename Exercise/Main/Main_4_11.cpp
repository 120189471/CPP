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
    ival = dval;                        //dval->int,去掉小数点
    flag = dval;                        //dval=0？"false":"true"
    cval + fval;                        //char->int->float;
    sval + cval;                        //short->int;char->int 
    cval + lval;                        //char->long;
    ival + ulval;                       //int->unsigned long
    usval + ival;                       //看所占空间大小
    uival + lval;                       //看所占空间大小
    */

    int ia[10];
    int* iaPtr = ia;                    //数组转换成指针

    return 0;
}