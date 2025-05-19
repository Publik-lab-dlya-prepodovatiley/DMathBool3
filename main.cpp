#include <iostream>
#include "include/BoolTable.h"

enum class Mode {MANUAL = 1, RANDOM = 2};

int main()
{

    cout << endl << "Enter var: ";
    int var;
    cin >> var;
    Bool_Table table(var);
    table.Table_Result();
    cout << endl << "Do you want to fill the function manually or randomly?"<<endl;
    cout << "1 - manual  ||  2 - randomly" << endl;
    int mode;
    do
    {
        cin>>mode;
        if (mode == static_cast<int>(Mode::MANUAL))
            table.Bool_Fanc();
        if (mode == static_cast<int>(Mode::RANDOM))
            table.Random_Func();

    }while (mode == 1 || mode == 2);

    table.Print_table(table.syvar);
    Bool_Table truetable(table.Truth_result());
    truetable.Table_Result();
    cout << endl << "true table:"<<endl;
    truetable.true_function(table.kit_table, table.syvar);
    truetable.Print_table(table.syvar);

    cin.get();
    return 0;
}
