#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

/* �.�. � ���������� � ��� ��������� ������ 1 � 0, ��� � ��� �������� ������������ ������������� � ������������������ �� 1 � 0. ����� ����� ������������� �������� ����-
��� � ������� ������� �� �������, ������������ ����� �������������� � ���������������� ����� ��� ������� ������� ����� �����, � ����� �������. � � ��������� ����������-
�� ������� �������� - ������� �������, ������������ ���, ����� ��� (����� �� 1 � 0) ������������� ���������� �����/�������. �������� ����� � ������������� ��� 1000001,
� ��� � ������� �������. �� ���������� �� �����, �� ����� ����� ���� �����������.

� ������ ���������, ���������� � ������� �/��� � ��������� ���� ���� ���������.
����� �������� ��������� ��������� ���������� ASCII (American standard code for information interchange). �� �����, ���� ������ ������ ����� ���� ���������. ������
���������, ���������� � ��������� �������� �����-�� ����������. ��� ������� ������� �� ��������� ������:

1. ����������� ������� (�� 32 �����)
   ��� �� ����� ������, �� ������ ������� � ���������� ��� ������ �� �����, �� �� �� ������. ��� ����� ������� ��� Esc, Delete, Backslashend, �������� �����������...

2. ������� ������� (������� �� ����������)
   �������� ����� � ��������� ��� ������ �������, ��� ���� ������ ����. ������� ������� ���� ����� ���� ���� � ����������� �� ���������! � ��������� ������� ����������-
   �� ����������� �� ���� ���������� � ����� �� �� ����� ����, ������� ���� � �� �� ��������� ������� ������������ ��������� � ������ ���������� � ����������.

   ��� �������� �������:
   ������� ��� ����������� �������, ������� "������, ���!". �������, � ������������ �� ����� ���������� ��������� ������ �����/������ �������� � ������������������ �� 1
   � 0, ���������� ������� ��� �� 1 � 0. � � ����� ���� �� ����������� � ������. � ���� �� ���� �����, ��������� � ��������, ��������� ������� � ������ ���������, � ��-
   ����� ������ ���������, �� ������ ��������� ���� ������������������ �� 1 � 0 ����������� � ����� � ������������ �� ����� ����������. � � �� ��������� ����� �������-
   ����������� �� 1 � 0 ����� ��������������� ������ �������, ������ "���� �������". ������ ���?

   ���� ���������� char ����� ��������� ����� 255 ��������, ������� ���� ���� ��������� ������� �� 0 �� 255, ���� �� -128 �� +127 (���� ������������). � ���������� char
   ������� ����� 1 ���� (�� ����. ��������� ��������� ��� �������� 2-� �������� ����������� ���������). � �.�. � ��� ����� 255 �������� � ����� ���������, � ������� ��
   ������ ��������� ������� (� �������, � ���������), ����, ������ ��������� ������ ��������� ���� 255 ����� ������ ��������, ����������� ��� ���������� ������/�������
   � ������ ����������. ����, ��������� ��� � ���������� - ������� �������� � ��������������� �� �������� �����. �� ���������� 1 � 0, � ������ ��������� �� ������������
   ��-������, � ����������� �� ���� ����� � ��� ����������� ���������.

   ���� ���������:
   ������� ������� ��������� �� Windows ��� Windows-1251. ���� ������������ ��� �����, �������� �� ����������, �� ��� �� ������ ��������� ����� �������� � ��� �������-
   ���, � ������� �����. ��������� ��������� �������� ��������� ��������� � ����� ������������� ����� ����, ��������, �������� ������. ���� ����������, �� ����� �����-
   ������ ��������� ����� ��������� ���������� ���������� ������������������ �� 1 � 0. ����� ��������� ���������: ANSI, UTF-8, ������������ ���������... �� ���������
   ������ 8 ���������: �� IOS ��������� Macintosh, KOI8-R - ���� �� ����������� ������� ���������, ������������ ������������ �������� ��������, ����� OEM 855 (������)
   � OEM 866 (�����) ���������, ��������� � ��� �� OS DOS. � ������� ���� ���� ���� ���������, �� �������� ��� ��� ����� � �������.


   ����� � ��� ��� ��������, ��� ����� ������������ ���������. � ������������ ������� ����� ���� ���������, � ��� � ����������, ������� �� ����� (�������� � ��� �� ���-
   ���), ����� ������ ���������. � ����� �� ��� ��������� ������� (��������� ������) ��� �������� ���� ���������, � ������� �� ��������� ����� ���� ��������� ���������
   ������, ����, � ��� ��� ��������� ������: � ������������ �������, � ������, � ���� � �������!
   (!) ��������� ������ ��� ��������� � ���������� � �S Windows ��������� �� MS DOS.


   ��� ���������� ������������ ���������, ���� ��������� ������������:

   1. �� ����� ��� ������ ��������� � ������ ��� ����������: ��������� ���� ��� -> (��� ���������� �������, � ������ ���������, ��������� ���� � ������� ��������� � ��-
   ��������...), ������� ������ ���������.
   �� ��� ������� ���� �����, ����� ��� ����� ���� �������� ������� � ������ ���������, ������� ������������ ������ ���������. ��� � ����� ���� ������ � ������ �������-
   ��� ��������� �����, � � ����� ������ ������������ ��������� ����������� �� �����.

   2. ���������� ��� ����� ���������� ������������ � ������. � ��� ���� ��� ������: ���� � �����. ����� �� ������ � ���������� �������, ������� ����������� �� � �������-
   ����������� �� 1 � 0, � ������ �� ���� ��� (� ������� ��������� cin) �������� � ������, ������� �������� ��� ��� ��������. ������ ����� � ����. */


int main()
{
    /*
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ��������� ������� �������� - Set Console Output Code Page ������, ��� ��� ������ � �������� ���� ��������� ������ �������� ������� � ������������ � ����� ����������
    1251. SetConsoleOutputCP �������� ������ �� ����� ��������, � SetConsoleCP �������� �� ����. ����� ���������� ���-�� ����, ���� ������ �������������� �� �����. */

    system("chcp 1251");                          // ��������� ������� �������� 1251 ���������� ����� �������, � �� ����, � �� �����.
    system("cls");                                // (!) ��� ������� �� ����� ������� � ������� ��������, ������� ��� ����� � ���� �������� ������������ ������� ������!

    /*
    setlocale(LC_ALL, "rus");                       // � ����� Windows � ������ ��� ������ ������ �� �����!
    */
    cout << "������, ���!" << endl;
    char Symbol = '+';                              // char ����� ������� �� 0 �� 255 ��� �� -128 �� +127 (� ������ ��������� �� 0 �� 127)
    cout << "������� ������: "; cin >> Symbol;
    cout << "������: " << Symbol << endl;
    /* ����� '�' �� �������, �.�. ����� �� � ������� �������� ����� '�', ����� '�' � 866 ��������� ����� ��� 153, ��������� ��� ����� � �������� ��� � ������� 10011001.
    ����� ���� ��� �� �������� � Symbol. A char �������� � ������ 1 ����, ���������� ��� ������������ ��������, �.�. 1 ���� = 8 ��� (8 �����, 8 �������� � �����), � ��-
    �� �� ������� ���� 8 �������� � �������, ��������������� ����� '�'. � �����, ����� �� ������� ������� cout � ������� �� ����� ���������� ���������� Symbol, �������
    cout ����� �� ������ ���������� ���������� Symbol (��� 10011001) � ���������� � �������, � ������� ��� ������������������ �������� � ����������� � ������������ �
    ��� �� 866 ���������� � ����� '�'.

    � ��� ���� ���������, �� �������, � ������ ���� ��������� (��������� ������) ������������ ���� ������. ������� �������� if else. */

    if (Symbol != '�')cout << "It's not SCH!" << endl;
    else cout << "��� ����� �!" << endl;
    cout << "������: " << Symbol << endl;

    /* ���� ��������� ����� '�' ������������ �� ��� '�', �.�. ���� ��������� � ������ �������� � ��������� UTF-8, � � ���� ��������� ����� '�' ����������� ������ �����-
    ��� ��� 10101000. �.�. � �������, � ������ ���������� ������ ���������, �� �������� ������ ������. ��� �� ��� ������? �������������� ��������� ��� �����, � �������
    �������� ���� ��������� (�������), � ���, ����� ��������� ������������ � ����� ���������, ������� ��������. ����� ������ �������� ����� ����� ��� ��������� (Symbol
    != '�'), � '�', ����������� ������ ����� ���������, � � Symbol, ������� �� ����� � ���������� ���� ���������� ���������. ������� ���.

    ������� ������� setlocale(LC_ALL, "rus"); � ����� ������ "������, ���!", � ����� '�' �� �����. ������ ���� ��� ����������, �.�. ������� setlocale �� ������ �������
    ��������, ���� ����� ����� ������, ��� ����������� � ������, ������� ����� ������ ��� �����.����, ����������, ������� �����, �����,... ��� �������� �������, ��� ��
    ��������� � ������, � ����, ��� ����� ����� ������������ ���������, ������� ������� ��� ������, � �.�. ������� �������� ����� ���-�� ������� ����� ���������� �����-
    �� � ���������� ������, ������� ����� ���-�� �������.
    ��������� ��������� ��� ��� �� ������ ��������� � ����� �������, � �������� ����� "����� �����������". � ������� � ���������� ��������� �� �������� �������� �������
    ���������. ������� �������� ��� �������, � ��� ������ �������, ��� �� � ������ � ��������� ��. ��� ������ ����������, � ��� ������� ���. ������� �������� ���������
    ��� �������, ������� �� ����������� � ������ �������, ������� �� ������, �.�. ��� �������� ��, ��� �� �������� �� ������� ���������������� � ������� ������� ��� ��-
    ��� ��������� (��� ��������� �� ������), � �������, ��� �� ������� �������� ����������������, ������� ����� �� ����� �����������. � �� �����, ��� � Windows �� �����
    ��� ��������, � �� ���� ���. �.�. setlocale(LC_ALL, "rus") �� ���������� ������ ��� ������ ������ �� ����� � ��� ����� ��������� ��� ��� ��������� � ������� �������.
    � � ������� ��� �������� � �� ����, � �� �����!
    (� ���������� ������������ ��� ����� ����� ��������� �������� ������, �.�. ��� ��������, � �� �������. � ��� �������� � ���������� ����������� ��� ������� ����� �
    ����� ����������� ������ ������ ��� ��������� ������� ������ ������� � ���������, � �� ���� ����������. � ���� ����� ��� �� ��������, �� ������� setlocale ��� ���
    ��������. ��� ��� �������� � ��� �������, � �� ����, � �� �����, �.�. ����������� ��� ������� � ������ ������� ���������� � ���� setlocale(LC_ALL, "rus").

    ��� ��� ������� ����� � �������� ������� ����� ���������?

    1. ������������ � ����� �������� �� �����, �������� ��.
    � ������� ���� �������, ��������� �� ������ DOS, ��������, ������� ping (�������� ����������� ����), ����������, ��������� ����, � ����� ������� ��� ����� ���������
    chcp (������� ������� ������� ��������� � �������/��������� ������)
    chcp 1251 (������� ������ ������� ��������� �� 1251)
    ����� �� ������ ������� ������� ���� ��������.

    2. �) ��� OS Windows ���� ����.������� �� OS Windows, ������������� � ����.�����������. �� �������� OS Windows ����� ������� ��������� ������� ���������� ����� ����-
    ������������ �� ����. windows.h. � windows.h ���� ������� ��� ������ � ��������, � ��� ������������� ������ ���������� OS, � �.�. ������� ����� OS, �� ����� �� ��-
    ����������!

    SetConsoleOutputCP(1251); - ������� ������������� ��������� 1251 ��� ������� �� ����� �� ����� ��������� � �������.
    SetConsoleCP(1251); - ������� ������������� ��������� 1251 ��� ������� �� ���� �� ������� (��� ��� ������� ���� �����)

    ���� ��� ����� ������� ��������� ������ �� ����� ��������, �� �� ����� ������������ ���� ������ �������.
    (!) ��������� ����� ������� �����, ��� � � OS Windows, ����� �� ���� ����������� � ������� ����������� OS Windows.

       �) �� �� �������, �� �� ������ ���������� stdlib.h
    system("chcp 1251");
    ������� system ��������� ������������ ������� �������, �� ����� �������, ������� � ������� � �������� � ������ � ��� ��� � DOS � ���� �������� �� ������ 'C'.

    ����� �������(-�) ����� �����?
    ��, ���������� ������� ��� ���������� � ���������, �.�. ����������� ����� ���������� ������ ��� ����� � ������, � ����� ������������ ������ ������������ ����������
    ��-���������!
    � ���� ��� ����� ������� ������ ������� ����� �� �����, � �� ������� ��� � ���������, �� ����� ����� locale.h, �.�. ���� ������� �����-�������������, �� � ��������-
    �� ��� �������� �����, �� � ���� ������� ���� �������.


       ����������: ���� ����� ��� ����������� �����-�� ������ �������, ���������, �������� ��� ��� �����-��, �� ��� �����:

    1. ����� ��� ���� � ����� ������������ ������� (����� �� ����� �� ������ � �����), ����� ����������� ���� � �������.
    2. ����� ��������� ����� � ����� ��������� �������� ��� ��� ����, ����� ������ ��������������� ��������� (���� ��������� ���� � ���������)
    3. ��� 3 �������� ���� ����� ���� ����� �� ������, ����� ���� ��� ��� �������� �����, �� ������������ ���� � ���� ����������� ��� ����!
    4. ������ �� ��������� ���� ������� ����������� ����� ����������, � ������� ���������� ������� ����������!

    (!) ������� � ������� system �������� ������ � OS Windows, �.�. ������ ���� ��� �� OS DOS */
}