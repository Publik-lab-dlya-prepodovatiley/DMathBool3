#include <iostream>
#include "include/BoolTable.h"
#include <chrono>

using namespace std::chrono;
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
    cin>>mode;
    auto start = high_resolution_clock::now();
    if (mode == static_cast<int>(Mode::MANUAL))
        table.Bool_Fanc();
    else
        table.Random_Func();

    table.Print_table(table.syvar);

    Bool_Table truetable(table.Truth_result());
    truetable.Table_Result();
    cout << endl << "true table:"<<endl;
    truetable.true_function(table.kit_table, table.syvar);
    truetable.Print_table(table.syvar);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " ms\n";

    cin.get();
    return 0;
}
