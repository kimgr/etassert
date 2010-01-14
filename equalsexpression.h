#ifndef INCLUDED_EQUALSEXPRESSION_H
#define INCLUDED_EQUALSEXPRESSION_H

#include "expressionoperators.h"

template< typename ExpectedType >
struct EqualsExpression : ExpressionOperators< EqualsExpression<ExpectedType> >
{
	EqualsExpression(const ExpectedType& expected)
		: m_expected(expected)
	{
	}

	template<typename ActualType>
	bool operator()(const ActualType& actual) const
	{
		return (m_expected == actual);
	}

	ExpectedType m_expected;
};

template< typename ExpectedType >
EqualsExpression<ExpectedType> Equals(const ExpectedType& expected)
{
	return EqualsExpression<ExpectedType>(expected);
}

EqualsExpression<std::string> Equals(const char* expected)
{
	return EqualsExpression<std::string>(expected);
}

#endif INCLUDED_EQUALSEXPRESSION_H