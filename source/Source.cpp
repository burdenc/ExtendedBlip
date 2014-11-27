#include "CallStack.h"
#include "IStatement.h"
#include "StatementFactory.h"
#include "Vector.h"

void run(void)
{
	Vector<IStatement*> program;
	CallStack::instance().push(); // Create global scope

    while (read_next_token(), next_token_type != END)
    {
		IStatement* statement = StatementFactory::buildNextStatement();
		program.push_back(statement);
		statement->execute();
    }

	CallStack::instance().pop();

	// Clean up
	for (unsigned int i = 0; i < program.size(); i++)
	{
		delete program[i];
	}
}

int main(void)
{
	run();
}