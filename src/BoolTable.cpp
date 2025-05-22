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
    table.clear();
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
void Bool_Table::Kvine_Mak_Klaski()
{
    vector<vector<int>> temp_one_kit;
    vector<vector<vector<int>>> temp_var_kit;
    vector<vector<int>> block;
    vector<int> qvar;
    vector<vector<int>> comparison_kit;
    vector<vector<int>> first_kit;
    vector<vector<int>> first_temp_kit;
    vector<vector<int>> temp_kit;
    vector<vector<int>> temp_var_kit2;
    vector<vector<int>> f_result;
    for (vector kit: kit_table)
    {
        if (kit.back() == 0)
            continue;
        kit.pop_back();
        temp_one_kit.push_back(kit);
    }

    kit_table.clear();
    for (int d = 0; d < quantity_variable + 1; d++)
    {

        for (vector kit: temp_one_kit)
        {
            int second_var = 0;
            for (int i : kit)
                if (i == 1)
                    second_var++;

            if (second_var == d)
                block.push_back(kit);
        }

        if (block.size() != 0)
            temp_var_kit.push_back(block);

        block.clear();
    }

    for (int block = 0; block + 1< temp_var_kit.size(); block++)
    {
        for (int kit = 0; kit < temp_var_kit[block].size(); kit++)
        {
            for (int second_kit = 0; second_kit < temp_var_kit[block + 1].size(); ++second_kit) //2
            {
                for (int i = 0; i < temp_var_kit[block][kit].size(); ++i)
                {
                    if (temp_var_kit[block][kit][i] != temp_var_kit[block + 1][second_kit][i])
                        qvar.push_back(i);
                }
                if (qvar.size() == 1)
                {
                    first_kit.push_back(temp_var_kit[block][kit]);
                    first_kit.push_back(temp_var_kit[block + 1][second_kit]);
                    vector<int> copy = temp_var_kit[block][kit];
                    copy[qvar[0]] = 2;
                    comparison_kit.push_back(copy);
                }
                qvar.clear();
            }
        }
    }

    for (vector block: temp_var_kit)
        for (vector kit: block)
            first_temp_kit.push_back(kit);
    temp_var_kit.clear();

    sort(first_kit.begin(), first_kit.end());
    first_kit.erase(unique(first_kit.begin(), first_kit.end()), first_kit.end());

    for (vector kit: first_temp_kit)
    {
        int var = 0;
        for (vector kit2: first_kit)
        {
            if (kit == kit2)
                var++;
        }
        if (var == 0)
            temp_kit.push_back(kit);
    }
    temp_one_kit.clear();
    first_kit.clear();
    first_temp_kit.clear();
    qvar.clear();

    for (vector kit: comparison_kit)
    {
        vector<vector<int>> copy;
        int var = 0;
        for (int element: kit)
        {
            if (element == 2)
                break;
            var++;
        }

        bool flag = false;
        for (int i : qvar)
            if (i == var)
                flag = true;
        if (flag)
            continue;
        qvar.push_back(var);

        for (vector kit2 : comparison_kit)
        {
            if (kit2[var] == 2)
                copy.push_back(kit2);
        }
        if (!copy.empty())
            temp_var_kit.push_back(copy);
    }
    qvar.clear();
    for (vector block: temp_var_kit)
    {
        vector<int> copy;
        for (vector kit: block)
        {
            for (vector kit2: block)
            {
                for (int i = 0; i < kit.size(); i++)
                {
                    if (kit[i] != kit2[i])
                        qvar.push_back(i);
                }
                if (qvar.size() == 1)
                {
                    vector<int> copy = kit;
                    copy[qvar[0]] = 2;
                    f_result.push_back(copy);
                    temp_one_kit.push_back(kit);
                    temp_one_kit.push_back(kit2);
                }
                qvar.clear();
            }
        }
    }
    sort(f_result.begin(), f_result.end());
    f_result.erase(unique(f_result.begin(), f_result.end()), f_result.end());

    sort(temp_one_kit.begin(), temp_one_kit.end());
    temp_one_kit.erase(unique(temp_one_kit.begin(), temp_one_kit.end()), temp_one_kit.end());

    for (vector block : temp_var_kit)
        for (vector kit : block)
            temp_var_kit2.push_back(kit);

    for (vector kit : temp_var_kit2)
    {
        int var = 0;
        for (vector kit2 : temp_one_kit)
        {
            if (kit == kit2)
                var++;
        }
        if (var == 0)
            f_result.push_back(kit);
    }

    for (vector kit : temp_kit)
        f_result.push_back(kit);
    int it = 0;
    for (vector kit : f_result)
    {
        int var = 0;
        for (int i : kit)
        {
            if (i == 0)
                cout <<"-X"<<var + 1<<" ";
            else if (i == 1)
                cout <<"X"<<var + 1<<" ";
            var++;
        }
        it++;
        if (it != f_result.size())
            cout << "V ";
    }
}

