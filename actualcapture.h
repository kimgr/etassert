#ifndef INCLUDED_ACTUALCAPTURE_H
#define INCLUDED_ACTUALCAPTURE_H

template< typename ActualType >
struct ActualCapture
{
	ActualCapture(const ActualType& actualValue, const char* actualExpression)
		: value(actualValue)
		, expression(actualExpression)
	{
	}

	const ActualType& value;
	const char* expression;
};

template< typename ActualType >
ActualCapture<ActualType> CaptureActual(const ActualType& actualValue, const char* actualExpression)
{
	return ActualCapture<ActualType>(actualValue, actualExpression);
}

#define ACTUAL(expr) CaptureActual(expr, #expr)

#endif INCLUDED_ACTUALCAPTURE_H