#include "exception/exception.h"

Exception::Exception(int code) :
    _pNested(0), _code(code)
{
}


Exception::Exception(const std::string& message, uint32_t code) :
    _message(message), _pNested(0), _code(code)
{
}


Exception::Exception(const std::string& message, const std::string& argument, uint32_t code) :
    _message(message), _pNested(0), _code(code)
{
	if (!argument.empty())
	{
		_message.append(": ");
		_message.append(argument);
	}
}


Exception::Exception(const std::string& message, const Exception& nested, uint32_t code) :
    _message(message), _pNested(nested.clone()), _code(code)
{
}


Exception::~Exception() noexcept
{
	delete _pNested;
}


Exception::Exception(const Exception& exception):
	std::exception(exception),
	_message(exception._message),
	_code(exception._code)
{
	_pNested = exception._pNested ? exception._pNested->clone() : 0;
}


Exception& Exception::operator=(const Exception& exception)
{
	if (&exception != this)
	{
		Exception* newPNested = exception._pNested ? exception._pNested->clone() : 0;
		delete _pNested;
		_message = exception._message;
		_pNested = newPNested;
		_code = exception._code;
	}
	return *this;
}


const char* Exception::name() const noexcept
{
	return "Exception";
}


const char* Exception::className() const noexcept
{
	return typeid(*this).name();
}


const char* Exception::what() const noexcept
{
	return name();
}


std::string Exception::displayText() const
{
	std::string text = name();
	if (!_message.empty())
	{
		text.append(": ");
		text.append(_message);
	}
	return text;
}


void Exception::extendedMessage(const std::string& argument)
{
	if (!argument.empty())
	{
		if (!_message.empty()) _message.append(": ");
		_message.append(argument);
	}
}


Exception* Exception::clone() const
{
	return new Exception(*this);
}


void Exception::rethrow() const
{
	throw *this;
}


IMPLEMENT_EXCEPTION(LogicException, Exception, "Logic exception")
IMPLEMENT_EXCEPTION(RangeException, LogicException, "Out of range")
IMPLEMENT_EXCEPTION(BadCastException, Exception, "Bad cast")
IMPLEMENT_EXCEPTION(InvalidArgumentException, LogicException, "Invalid argument")
