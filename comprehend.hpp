
#include<vector>
#include<type_traits>
#include<utility>

using std::vector;
using std::is_same;

template<class T>
struct is_vector{static bool const value = false;};

template<class T, class A>
struct is_vector<vector<T, A>>{static bool const value = true;};

vector<int> range(int start, int end, int step = 1){
    vector<int> rv(end - start);
    for(int i = 0; i < end - start; i++)
        rv[i] = step * i + start;
    return rv;
}

vector<int> range(int end){
    return range(0, end);
}

#define Comp4(expression, var, set, condition) [&set](){\
    static_assert(is_vector<decltype(set)>::value, "Domain is not a vector!");\
    std::vector<decltype(set)::value_type> rv;\
    for(auto var : set){\
        static_assert(is_same<bool, decltype(condition)>::value, "condition does not evaluate to a boolean");\
        if(condition){\
            static_assert(is_same<decltype(set)::value_type, decltype(expression)>::value, "expression is not same type as domain");\
            rv.push_back(expression);\
        }\
    }\
    return rv;\
}()

#define Comp3(expression, var, set) [&set](){\
    static_assert(is_vector<decltype(set)>::value, "Domain is not a vector!");\
    std::vector<decltype(set)::value_type> rv;\
    for(auto var : set){\
        static_assert(is_same<decltype(set)::value_type, decltype(expression)>::value, "expression is not same type as domain");\
        rv.push_back(expression);\
    }\
    return rv;\
}()

#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define Comp(...) GET_MACRO(__VA_ARGS__, Comp4, Comp3)(__VA_ARGS__)