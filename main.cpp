#include <iostream>
#include "include/BoolTable.h"

int main()
{
    int var;
    cin >> var;
    Bool_Table table(var);
    table.Table_Result();
    table.Bool_Fanc();
    table.Print_table();
    table.Truth_result();
}
