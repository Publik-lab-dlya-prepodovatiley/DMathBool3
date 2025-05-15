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
    Bool_Table truetable(table.Truth_result());
    truetable.Table_Result();
    truetable.Print_table(table.syvar);

}
