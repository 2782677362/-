//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��֡��ݹ鼰�����ж���䣨A?B:C��

#include <iostream>
using namespace std;

class Sum {
public:
    Sum()
    {
        _sum += _n;
        _n++;
    }
    static void Init()
    {
        _sum = 0;
        _n = 1;
    }
    static int Ret()
    {
        return _sum;
    }
private:
    static int _sum;
    static int _n;
};

int Sum::_sum = 0;
int Sum::_n = 1;

int main()
{
    int n;
    while (cin >> n)
    {
        Sum::Init();
        Sum* a = new Sum[n];
        cout << Sum::Ret() << endl;
        delete[] a;
    }
    return 0;
}