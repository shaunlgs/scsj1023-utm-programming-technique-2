#include <iostream>
using namespace std;

class Thought
{
    public:
        void message()
        {
            cout << "Some people get lost in thought" << endl;
        }
};

class Advice : public Thought
{
    public:
        void message()
        {
            cout << "Avoid cliches like the plague" << endl;
        }
};

int main()
{
    Thought think;
    Advice cliche;
    think.message();
    cliche.message();
    return 0;
}
