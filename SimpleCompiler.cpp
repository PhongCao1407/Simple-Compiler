#include <string>
#include <stack>
#include <unordered_map>
#include <list>
#include <tuple>
#include <any>

#include <iostream>

using namespace std;

class Interpreter
{
public:
    stack<int> stack;
    void run_code(list<tuple<string, string> > instructions, list<int> numbers)
    {

        for (tuple<string, string> each_step : instructions)
        {
            string instruction = get<0>(each_step);
            string argument = get<1>(each_step);

            if (instruction == "LOAD_VALUE")
            {
                auto l_front = numbers.begin();

                advance(l_front, stoi(argument));

                int number = *l_front;

                LOAD_VALUE(number);
            }
            else if (instruction == "ADD_TWO_VALUES")
            {
                ADD_TWO_VALUES();
            }
            else if (instruction == "PRINT_ANSWER")
            {
                PRINT_ANSWER();
            }
        }
    }

private:
    void LOAD_VALUE(int number)
    {
        stack.push(number);
    }

    void PRINT_ANSWER()
    {
        int answer = stack.top();
        stack.pop();

        cout << answer << endl;
    }

    void ADD_TWO_VALUES()
    {
        int firstNum = stack.top();
        stack.pop();
        int secondNum = stack.top();
        stack.pop();

        int total = firstNum + secondNum;
        stack.push(total);
    }
};