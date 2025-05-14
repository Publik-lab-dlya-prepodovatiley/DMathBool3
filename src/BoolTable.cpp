#include "../include/BoolTable.h"

void Bool_Table::Table_Result()
{
    int row_result = static_cast<int>(pow(2, quantity_variable));
    int iter = 1;
    for (int i = 0; i < quantity_variable; i++)
    {
        vector<int> col;
        row_result /= 2;
        for (int d = 0; d < iter ;d++ )
        {
            for (int j = 0; j < row_result; j++)
            {
                col.push_back(0);
            }
            for (int j = 0; j < row_result; j++)
            {
                col.push_back(1);
            }
        }
        table.push_back(col);
        iter *= 2;
    }
    for (int c = 0; c < rows; c++)
    {
        vector<int> temp_kit;
        for (int j = 0; j < quantity_variable; j++)
        {
            temp_kit.push_back(table[j][c]);
        }
        kit_table.push_back(temp_kit);
    }
}
void Bool_Table::Bool_Fanc()
{
    for (int i = 0; i < kit_table.size(); i++)
    {
        bool logicError;
        do
        {
            logicError = false;
            int boolfunc;
            cout << " Enter function: ";
            for (int j = 0; j < quantity_variable; j++)
            {
                cout << kit_table[i][j];
            }
            cin >> boolfunc;
            if (boolfunc == 0 || boolfunc == 1)
                kit_table[i].push_back(boolfunc);
            else
            {
                cout << "Error" << endl;
                logicError = true;
            }
        }
        while (logicError);
    }
}
void Bool_Table::Print_table()
{
    for (int i = 0; i < quantity_variable; i++)
    {
        cout << "x" << i+1 << " ";
    }
    cout << endl;
    for (int i = 0; i < kit_table.size(); i++)
    {
        for (int j = 0; j < kit_table[i].size(); j++)
        {
            cout << kit_table[i][j] << "  ";
        }
        cout << endl;
    }
}
void Bool_Table::Truth_result()
{
    int result = 0;
    int syc = kit_table.size();
    int syc2 = 1;
    for (int i = 0; i < quantity_variable; i++)
    {
        syc /= 2;
        for (int d = 0; d < syc2; d++)
        {
            for (int j = 0; j < syc; j++)
            {
                if (kit_table[i].back() != kit_table[syc++].back())
                {
                    cout << "Error x"<< i+1 << endl;
                }
            }
        }
        syc2 *= 2;
    }
}