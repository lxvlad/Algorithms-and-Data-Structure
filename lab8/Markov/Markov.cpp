#include <vector>

template<typename ValueClass>
struct Elements
{
    ValueClass before;
    ValueClass after;
};

template<typename ValueClass>
void MarkovAlgorithm(ValueClass& first, std::vector<Elements<ValueClass>>& v)
{
    unsigned i = 0;
    while (i < v.size())
    {
        int isFind = first.find(v[i].before);
        if (isFind != -1)
        {
            if (v[i].after[v[i].after.length() - 1] == '@')
            {
                ValueClass last(v[i].after);
                last.erase(last.length() - 1, 1);
                first.replace(isFind, v[i].before.length(), last);
                return;
            }
            first.replace(isFind, v[i].before.length(), v[i].after);
            i = 0;
        }
        else
        {
            ++i;
        }
    }
}
