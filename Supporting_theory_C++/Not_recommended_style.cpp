#include <iostream>
#include <cstdlib>
// чем больше макросов, тем дольше препроцессор будет готовить код к компиляции
#define HELLO "Привет, Мир!"
#define FOR for(int i=0;i<size;i++)
#define PUS system("pause");
#define CLS system("cls");
#define ForFor1 for(int i=0;i<row;i++){for (int j=0;j<col;j++){
#define ForFor2(X) for(int i=0;i<row;i++){for (int j=0;j<col;j++){X}cout<<endl;}
#define ЦИКЛ for(int i=0;i<size;i++)
#define ПРИВЕТ cout<<"Привет, Мир!"<<endl;


using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");

    int size = 3;

    FOR                                             // for (int i = 0; i < size; i++) этот заголовок введен в макрос
    {
        cout << HELLO << endl;
    }
        /* + проще писать
           - нужно постоянно помнить параметры ибо они фиксированы, при смене параметров будут проблемы */
    cout << endl;

    FOR(cout << HELLO << endl);
    /* Круглые скобки будут приняты макросом точно также. В этом случае цикл сработает, но лишь потому что там ОДНА команда. Было бы больше команд, то все развалится.
    Раскрылось это так: for (int i = 0; i < size; i++)cout << HELLO << endl */

    PUS                                             // если команда не изменяется!
        CLS
        int row = 5, col = 7, count = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            count++;
            cout << count << "\t";
        }
        cout << endl;
    }
    cout << endl;
    count = 0;

    ForFor1                                         // ужасно!
        count++;
    cout << count << "\t";
}
cout << endl;
    }
    cout << endl;
    count = 0;

    ForFor2(count++; cout << count << "\t";)            // если вкладывать, то хотя бы с параметрами (в виде вызова функции), но параметры должны никак не менияться!

        cout << endl;
    // ТАК НЕЛЬЗЯ!
    ЦИКЛ
    {
        ПРИВЕТ
    }
        /* Это сработает, т.к. препроцессор берет код любых символов, поддерживаемых встроенной кодировкой и преобразует их в 1 и 0 и ищет эту последовательность во всем
        коде. Находит и заменяет. */
}