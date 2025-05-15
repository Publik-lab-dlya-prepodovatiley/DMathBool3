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
void Bool_Table::Print_table(vector<int> res)
{
    if (res.size() != 0)
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << "x" << res[i] + 1 << " ";
        }
    }
    else
    {
        for (int i = 0; i < quantity_variable; i++)
        {
            cout << "x" << i+1 << " ";
        }
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
int Bool_Table::Truth_result()
{
    int result = 0;
    int comparisons = static_cast<int>(kit_table.size());
    int block = 1;

    for (int i = 0; i < quantity_variable; i++)
    {
        comparisons /= 2;
        bool logicError = false;
        cout<<endl;
        for (int d = 0; d < block; d++)
        {
            int tempit = comparisons;
            for (int j = 0; j < comparisons; j++)
            {
                int iterationa = j + comparisons * d * 2;
                int iterationb = tempit + comparisons * d * 2;
                if (kit_table[iterationa].back() != kit_table[iterationb].back())
                {
                    cout << endl <<"syt x"<< i+1 << endl;
                    syvar.push_back(i);

                    for (int k = 0; k < kit_table[iterationa].size(); k++)
                        cout << kit_table[iterationa][k];
                    cout << " != ";
                    for (int k = 0; k < kit_table[iterationb].size(); k++)
                        cout << kit_table[iterationb][k];

                    logicError = true;
                    result++;
                    break;
                }

                cout<<endl;
                for (int k = 0; k < kit_table[iterationa].size(); k++)
                    cout << kit_table[iterationa][k];
                cout << " == ";
                for (int k = 0; k < kit_table[iterationb].size(); k++)
                    cout << kit_table[iterationb][k];
                tempit++;
            }

            if (logicError){break;}
        }
        block *= 2;
    }
    cout << endl << "result syt: "<<result << endl;
    return result;
}
void Bool_Table::Random_Func()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < kit_table.size(); i++)
    {
        int func_value = rand() % 2;
        kit_table[i].push_back(func_value);
    }

    cout << "Random function f(x) assigned to each row.\n";
}
void Bool_Table::true_function(vector<vector<int>> temp_kit, vector<int> syvar)
{
    for (int i = 0; i < kit_table.size(); i++)
    {
        for (int j = 0; j < temp_kit.size(); j++)
        {
            int boolfunc = 0;
            for (int k = 0; k < syvar.size(); k++)
            {
                if (kit_table[i][k] == temp_kit[j][syvar[k]])
                    boolfunc++;
            }
            if (boolfunc == syvar.size())
            {
                kit_table[i].push_back(temp_kit[j].back());
                break;
            }
        }
    }
}
