#include "KeyValueTable.cpp"

int main()
{
    KeyValueTable<10> table;

    table.AddKeyValue("MathAnalysis", 51);
    table.AddKeyValue("DiscreteMath", 72);
    table.AddKeyValue("Programming", 92);

    cout << "Value of DiscreteMath:" << table.GetValue("DiscreteMath") << endl;
    cout << "Value of non-exist key: " << table.GetValue("dfsofk") << endl;

    table.GetTable();

    table.RemoveKey("MathAnalysis");

    table.GetTable();

    return 0;
}
