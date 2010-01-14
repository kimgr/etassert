#ifndef INCLUDED_NOTEXPRESSION_H
#define INCLUDED_NOTEXPRESSION_H

#include "expressionoperators_fwd.h"

template< typename Expression >
struct NotExpression : ExpressionOperators< NotExpression<Expression> >
{
	NotExpression(const Expression& expression)
		: expression(expression)
	{
	}

	template<typename ActualType>
	bool operator()(const ActualType& actual) const
	{
		return !expression(actual);
	}

	Expression expression;
};

#endif INCLUDED_NOTEXPRESSION_H