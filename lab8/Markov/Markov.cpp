#include <vector>

template<typename ValueClass>
struct Elements
{
    ValueClass before;
    ValueClass after;
};

template<typename ValueClass>
//ValueClass& first - аргумент над яким виконуватимуться операції
void MarkovAlgorithm(ValueClass& first, std::vector<Elements<ValueClass>>& v)
{
    unsigned i = 0;
    while (i < v.size())
    {
        int isFind = first.find(v[i].before); // пошук підрядка v[i].before у first
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
        else // якщо підрядок не знайдено то переходим до наступного елементу v
        {
            ++i;
        }
    }
}



// Вона шукає кожен v[i].before в first і замінює його на v[i].after, враховуючи спеціальний випадок, коли останній символ v[i].after є @.

