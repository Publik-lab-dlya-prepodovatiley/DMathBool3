#include <iostream>
#include "include/BoolTable.h"

int main()
{
    int var;
    cin >> var;
    Bool_Table table(var);
    table.Table_Result();
    table.Bool_Fanc();
    table.Print_table(table.syvar);
    Bool_Table truetable(table.Truth_result(table.kit_table));
    truetable.Table_Result();
    cout << endl << "true table:"<<endl;
    truetable.Truth_result(table.kit_table);
    truetable.Print_table(table.syvar);

}
