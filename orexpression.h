#ifndef INCLUDED_OREXPRESSION_H
#define INCLUDED_OREXPRESSION_H

#include "expressionoperators_fwd.h"

template< typename LeftExpression, typename RightExpression >
struct OrExpression : ExpressionOperators< OrExpression<LeftExpression, RightExpression> >
{
	OrExpression(const LeftExpression& left, const RightExpression& right)
		: m_left(left)
		, m_right(right)
	{
	}

	template< typename ActualType >
	bool operator()(const ActualType& actual) const
	{
		return (m_left(actual) || m_right(actual));
	}

	LeftExpression m_left;
	RightExpression m_right;
};

#endif INCLUDED_OREXPRESSION_H