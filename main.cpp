#include "SimpleCompiler.cpp"

#include <unordered_map>
#include <any>

int main() {

    list<tuple<string, string> > instructions = 
    {make_tuple("LOAD_VALUE", "0"),
    make_tuple("LOAD_VALUE", "1"),
    make_tuple("ADD_TWO_VALUES", ""),
    make_tuple("PRINT_ANSWER", "")
    }; 

    list<int> numbers = {100, 5};

    Interpreter interpreter;
    interpreter.run_code(instructions, numbers);

}