//dix.20160630 l03
//���� ��ʾ�ͻ��������˺�
/*���� ��
//  a:int���ݳ�Ա,��ʾ�˻����
    
//  b.���캯�������ܳ�ʼ����������ʼ���˻���
        ������Ч�ԣ�>=0,��������Ϊ0��
        ��ʾ������Ч��
    c.��Ա���� credit ��һ�ʽ����ӵ���ǰ�����
    b.��Ա����debit���˻���ȡǮ����֤�������£�����������������䲢��ӡ��Debit amount exceeded account balance.��
    c.��Ա����getBalance����������
    d.��д���Գ��򣬴���2��Account���󣬲�����Account��ĳ�Ա����
*/


class Account{
public:
    Account();
    Account(int);       //���캯��

    int credit(int);    //��ӽ��
    void debit(int);     //ȡǮ
    int getBalance();   //���ص�ǰ�����
private:
    int balance;        //�������

};

