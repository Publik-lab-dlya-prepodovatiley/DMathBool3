#ifndef BOOLTABLE_H
#define BOOLTABLE_H
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

class Bool_Table
{
protected:
    int quantity_variable;
    int rows = static_cast<int>(pow(2, quantity_variable));
    int cols = quantity_variable;

public:
    vector<vector<int>> table;
    vector<vector<int>> kit_table;
    vector<int> syvar;
    void Table_Result();
    void Bool_Fanc();
    void Print_table(vector<int>);
    int Truth_result();



    Bool_Table(int qv)
     : quantity_variable(qv){}
};



#endif //BOOLTABLE_H