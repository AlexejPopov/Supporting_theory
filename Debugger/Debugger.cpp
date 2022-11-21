#include <iostream>
#include <locale.h>
using namespace std;

/* ���������� ��� ���� ������, �� ����� ���������� � �� ����� ����������. ������ ����� ����������, ����� ��������� � ������������ ������ ��������� ��� �� ������� ������� � ������.
�� ����� ���������� � ������� �������� ����������������� �����, �������� �� ��������� ������� �� 0. � ����� ���������� ����� ���� ����� ������� - ��������, ������� ��������� ���-
������� ��� ���������� � ����� ��������� � ��� ��� ���� ������ ������� ��� �� ����������. �������� ��������� ��� ��� ���������� ��������� ���������� ��� ���������� � ���������,
�����������, ���������, �� ���� � ��� �� ��������.
� ��������� ���� 2 ������:
  I * ������ �� ����� - ���������� ��������� ������� �� �������� (��� ��� ������ ����������)
      ���.������� F10 ��� Debug -> Step Over (��� � ������� (�������)).
      ������� ������, ��������� �� �����. ������ ��������� ���������� ��������� ������ ����������. �� �������� ���������, �� ����� �������� �� ����� ����������� ����������, ��
      ��������� �� ������� ������, ��������� ��� � �������� ���� � ���������� ��������� ������ ��� ���������� (int 4 �����, double 8 ����, ����. 16 ����), ���������� �����������
      16 ���� � ������.�������, ������.������� �������� ������ � ����� ������ ����� �� ������� � ���� ��������� � ��� �����������. ������� ��� ���������� � � � ����� ��������, ��
      ���� �� ����� � ���� ��������, �� ����� ��� ��� ��� ��������������� ��� ���� ���������. � ��� ��� ��� �������, ��� ������� �� ����� ����������� ������, ������� �� � �������
      ���������� int, float, char, double... (�������� ���������� ��� ������ �� ��������� ������ ������� ������).
      ����� ��������� ������� | Autos | Locals | Watch 1 |
      Watch 1 ��������� �������� � ��� �����-�� ����������, ������ � ������� �� ��� �� ���������� ����� ����� �����.
      Locals ���������� ��� �������, ������� �������/����� ������� � ����� ������� ���������. �� ������ ������ ���, ��� ������� � ����� ������� main.
      Autos (�������) ���������� ����� ������� �������� � ��� �������, �� ������� ����� ������ �������.
      F10 ���������� ������ ������� ����.
      � Locals � ���� ��������� ����������, ������ ���������� ������ ��� ���, ���� ��� ����� �����. ����� � ����������� ���-�� �������, �� ����� �������� (��� ����� �� �� ����������
      ����������). ������ F10, ������� ������������ � ���������� ����������, ��� ��� F10 � � ������� ��� ��������� ���������� �, �����������, � Locals � � � � ��������� ������� ����
      � ���������� � �� �������� � �������. ������� ����� ����������, ��� ���� �������� ��������, �.�. �������� ������� (int A = 0, B = 0;) �� �� ��������! � ��� ���������, ��� ���
      F10 � �� ��� ����� � ������� ������ (������� ����� �: ), �� ������, �����, ��� � ������� � ��������� ������ ���� ����������! ��� ��� F10, ��� � � 0 ��������, �������� ������
      ������! �������� ����� ������ � ������ ������ ��� ���� ��������� � ������� ��� ������ - ������� �� ����!
      ��� ����� ������ ���������?
      � ������� Value �� ����� ������ �������� ����������, ������� ���� � ������ ����� ��������. �������� ��������� �������������� � ������� ��� ������� ���� ��������� ���� �� ��������
      ��������� ����� ������, ������ �� �� ��������.
      SHIFT+F5 - ����� �� ���������.

    * ���������� �������� ���������� ������. �� ������ ����� ������ ������� � ���������� �� � ������ ������, ��������� ��� �������, ������� �������� ������������. ������ ������� �
      ������� ����� �������� ��� � � � � �������� ����� ����� � ������� (��� ������ ��������� � � �).
      (!) ��� ����������� ��������� ���� �������������, �� ���������� ���������� ����������� �����, ��������, ������� ����� ���������� �� ����� ��-�� �������� setlocale. � ������
      ������� ��� ����������� ������� ����� �� ������� �������� ������������ ��������. ��� �� � ����� ������ ������?

 II * ������ ��������� � �������� F5. ��� ����� �� ������ ��������� ��� � Ctrl+F5, �� ��� ���� �������� ��������. ���� ���-�� ������ �� ���, �� ��������� ��������. ���� ��� ������� �
      ���������� ����������� ����� �� �������� � �������� �� ����, �� ������ ������ � �������, �������� ��������� ���������� ���������, �������� � ����� ������� � ���������� ��� �
      ��������� ������� � �� ������ ���������� ��� �� ��������� � ��� ���� �� ���!
      (!) �������� ���������� ��������, ��� �������� ������� �������������� � �������� ������� ����� � �������� ����, �.�. ��� ������ ��������� � ����� ������ ������ ���������.

      ��� ��� �� ����� ��� �������? ����� ��� ������ ��� �������� �� ������, �� ����� ������� ����� �������� ���������� � ���.������. ��������, �� ������ ������� �� ���� � ���������
      ������������, ���������� inf (������������), �.�. � double ����� ������� �� ���� �������, �����, ����� ������, �������������, �� ������ ��� �� �����. � ��� �� ����� ����� �����
      �������� ������������. ������������� ��� �� ���������! ��� ����� ��������� ����� ��������. � ������ ��� ������� ��������� ������������ � ���������� ������ � ���.������/�������.
      �� ������ ����� ��������, ��������� ��������� �� F5 � ���������� ����������� � ����� �������� � ���.������ �����������. � ������ ���������� ���������� ����� ������� � ������!
      ����� �������� �������� F9 ��� ��� ������, ��� �������� ������ ��� �� �������� ������ �� �� ����� ��� ��� ������ ���� ��� ������ ������. �� ����� ������� ������� ������. ������-
      ������� �� ����� ��������, ������ � ��������� �� ����� ���������� ��������, ������� F10 � ����� ���������� �������� ������� �� ��������. � ����� ����� ������ F5 � ����� ���������
      ��������� ������, ������� � ���� ����� �������� �� ����� (��� �� ��������� ����� ��������). � ����� �� ����� ��� ������ � ����� �� �������, ��� ������ F5 ����� ��������� �� �����
      ���������� ��� ����� ������ F10 ��� ���������� ��������� �� �������� � �.�. �.�. ������� ���������� ���������, ���������� � ������ ������� � ������ ��������� �������, � ����� � F10
      ����� ���������� ������� �� �������� ���� ���-�� �����������������, ���������� �������� ����������, ����� ������ F5 � ���������� ���������� ��������� � ������� ������, �� � �������!
      ������ ����� �������� ����� ����� ��� � ���������.

      �� ��� ���� ��������������� � ������ � double �� ������ ��� � ������ ����� B==0, ��� ����� ���������� ����� ����� ��������. ��� ����� �����, ������� �� ����� ������ �������. �.�.
      �� ������ ��� ��������� ��������, � ������ �����, ����� �����-�� ������� ���������, ���-�� ����� �� ���.
      ������ ����� ��������, ������� �� ��� ����, ��� -> Conditions (��� ������� ����� ������ �� �������� � ��� �������� �������). �������� ��� ������� ������ B==0 � ������� ���� ���������.
      ���� � �� ����� ����� ����, �� ��� ���������� ��� ����, � ���� � ����� ����� ����, ����� �������� ��������� � ��������� ��� � ������� �� �������������. ��������� � �������� ����� ��-
      ���� F5 ����� ��������� ��������� ����������.
      (!) ���� ��������� ��������� ��� �������, �� � ������� ��������, �� ������� ������� � ��� �� �����.
      (!) ������ ����� �������� ������� �������� � ����������������� ����, ����� �� ������� ���� ���������, ����� �� ��� ���.

      ����� �������� ����� �������� �� ������ ���������, �� � ����. �������� �� ��������� ��������, ���������� ��� ���� ��������, ��� �� � ��� �����, ��� �� ���������, � ������ ������ ������
      F5 � ���� ������ ��������� ���� ������ ��� �� � ��� �� ������. �������� ��������� ��� ������ ��� ���������� � ����� ��������� �� ��� ��� ���� �������� � ������� �������������� ������
      ���������, �������� ��� ������������ �� � ������ ������, �������� �������� ���� ���������� � ��, ��� � ��� ��� ��������. ���������� ����������� ���� ����.
      ���� � ���� ���������� �� ����������� ���� ��������� (�������� ���� �������� ����� �����), ������ � ������� F10 � �� ����� ����� ���������. � ������� ���� ������� i, �� ��������� ����-
      ���� �����. � ���� ���������� �� ���������, ��� ����� � ���� � ���.���������� �������� �������� ����������, �������� ����� � ���������� � ��� �������� (���� ��� ������ �� ������� � ���
      ����� ����������. ����� ��� ����� ����������� ����-������ ��� ����� ������ ������� �� ��������� ���������� (������ ���� ��� �� ����� �����). � ���� ������� ����������� �������� ��� ���-
      �����, ����� ������� ����� 5. ���� F10, ����� F10 � ��� ���� �� ��� ��� ���� i ����� ����� 5. � ����� �����, �� ����� � ��� �������� �� �����, � � ����� ���������� ������� �������� ������.
      ����� 5 �������� � ���� ���������. � ���� �� 150 ��� ��� ������, �� ��� ����� ��������. ���� ��� ����� ������� �����-�� ���������� ��� � ����� ��������, � ��� ��� ����������� � � �������,
      �������� ������ �������� � �������� � ������ ��� ��� ��������� �� �������. ��� ���������� �������� ����� ����� ��������, ����� ������������ �� ������ � ������ �����-�� ��������� ��������,
      �� � ������ ����� �� �����-�� �������. � ������ ����� �������� ����� ������� �� ����� � ����� ������� ����� (���� i==5) � ������� ����� ��������, ������� ������� ��� ����, ����� ������� i
      ����� 5 ����� ���������� ����� ��������. ������, �������� ��������� ������ �� F5 � ����, ��� ���� ���������� ����, ������� �� ����� ��������, � ������ �� ���� ��� i ����� ����� 5, � ��
      ����� ������� � ��� �����-�� ������� �������� (��������� �������) � ��� ������� ���������� ��� ��� ��������� � ��������� ����� ����� ��� ������ ������������ �� �����-�� ������ ���� � �.�.
      � ����� ��� ��� ������� F5 � ��������� ����������� �� ����� ���� ���� �� ����� �� F10.

      ���� ��� ���� ������������ ������ � ���������� - �� ����� �� �������� ��������� ���������, � ����� ���������� ��� �� �������� ���� �������� ���������.
      ���������� ���� �� switch, �.�. ��� ���������� ���� �� ����� ������ ���������, �� �� ����� ��� �� �����������, ���������� ��. ��� ��� ������� ��������,
      ����������� ��� ������ �� �����, ���������� ��� ��������� ���������/����, ������ ���. */

int main()
{
    setlocale(LC_ALL, "rus");
    /*
    int A = 0, B = 0;
    cout << "������� ����� �: "; cin >> A;
    cout << "������� ����� � �������� �� ����: "; cin >> B;
    double C = A / B;
    cout << "��������� �= " << C << endl;
    */
    /*
    for (int i = 0; i < 10; i++)
    {
        //if(i==5)cout<<"Yes!"<<endl;
        cout << "i*i= " << i * i << endl;
    }
    */
    int i = 0;
    for (; i < 4; ++i)
    {
        switch (i)
        {
        case 0:cout << "0";
        case 1:cout << "1"; continue;
        case 2:cout << "2"; break;
        default:cout << "D"; break;
        }
        cout << ".";
    }
    /* � �������� 01.1.2.D.
    ���������� ����� 0112.D.
    � �������� ������ ����� ����� 1, �.�. �� ���� ��� continue �� �������� �� switch � �� if else, � �������� ������ �� ����, ����, ��� ��������� �� ������ ��� �� switch, � ��� � �����
    (� �� �����, ������� ��������� ����� switch). �.�. ��� ������ ����� ��������� ������� continue, �� ��������� ��� ���� �� ��� � ����� for � ����� �������� � ��������� ����� � ��������
    �������.
    (!) break ����������� �� ��������� ����������� � ������� ����� �������� (� ����� ������ �� switch), � continue ������� � ���������� ���� �����! */
}