#ifndef INCLUDED_EXPRESSION_ASSERT_H
#define INCLUDED_EXPRESSION_ASSERT_H

// Named expression_assert.h to avoid colliding with CRT's assert.h

struct Assert
{
	template< typename ActualType, typename ExpectedExpression>
	static void That(const ActualType& actual, const ExpectedExpression& evaluate)
	{
		if (evaluate(actual))
			Report("Succeeded");
		else
			Report("Failed");
	}

	template< typename ActualType, typename ExpectedExpression>
	static void That(const ActualCapture<ActualType>& actual, const ExpectedExpression& evaluate)
	{
		if (evaluate(actual.value))
			Report(actual.expression, "Succeeded");
		else
			Report(actual.expression, "Failed");
	}

private:
	static void Report(const std::string& status)
	{
		std::cout << status << std::endl;
	}

	static void Report(const std::string& actualExpression, const std::string& status)
	{
		std::cout << "Evaluation of '" << actualExpression << "' " << status << std::endl;
	}
};

#endif INCLUDED_EXPRESSION_ASSERT_H
