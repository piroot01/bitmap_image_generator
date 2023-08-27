#ifndef EXCEPTION_INCLUDED
#define EXCEPTION_INCLUDED


#include <exception>
#include <string>
#include <cstdint>


class Exception : public std::exception
{
public:
    Exception(const std::string& message, uint32_t code = 0);
    Exception(const std::string& message, const std::string& argumet, uint32_t code = 0);
    Exception(const std::string& message, const Exception& nested, uint32_t code = 0);
    ~Exception() noexcept;
    Exception(const Exception& exception);
    Exception& operator=(const Exception& exception);
    
    virtual const char* name() const noexcept;
    virtual const char* className() const noexcept;
    virtual const char* what() const noexcept;
    const Exception* nested() const;
    const std::string& message() const;
    uint32_t code() const;
    std::string displayText() const;
    virtual Exception* clone() const;
    virtual void rethrow() const;

protected:
    Exception(int code = 0);
    void message(const std::string& message);
    void extendedMessage(const std::string& argumet);

private:
    std::string _message;
    Exception* _pNested;
    uint32_t _code;

};


inline const Exception* Exception::nested() const
{
    return _pNested;
}


inline const std::string& Exception::message() const
{
    return _message;
}


inline void Exception::message(const std::string& message)
{
    _message = message;
}


inline uint32_t Exception::code() const
{
    return _code;
}


#define DECLARE_EXCEPTION_CODE(CLASS, BASE, CODE) \
    class CLASS : public BASE \
    { \
    public: \
        CLASS(uint32_t code = CODE); \
        CLASS(const std::string& message, uint32_t code = CODE); \
        CLASS(const std::string& message, const std::string& argumet, uint32_t code = CODE); \
        CLASS(const std::string& message, const Exception& exception, uint32_t code = CODE); \
        ~CLASS() noexcept; \
        CLASS(const CLASS& exception); \
        CLASS& operator=(const CLASS& exception); \
        const char* name() const noexcept; \
        const char* className() const noexcept; \
        Exception* clone() const; \
        void rethrow() const; \
    };


#define DECLARE_EXCEPTION(CLASS, BASE) \
    DECLARE_EXCEPTION_CODE(CLASS, BASE, 0)


#define IMPLEMENT_EXCEPTION(CLASS, BASE, NAME) \
    CLASS::CLASS(uint32_t code) : BASE(code) \
    { \
    } \
    CLASS::CLASS(const std::string& message, uint32_t code) : BASE(message, code) \
    { \
    } \
    CLASS::CLASS(const std::string& message, const std::string& argumet, uint32_t code) : BASE(message, argumet, code) \
    { \
    } \
    CLASS::CLASS(const std::string& message, const Exception& exception, uint32_t code) : BASE(message, exception, code) \
    { \
    } \
    CLASS::~CLASS() noexcept \
    { \
    } \
    CLASS::CLASS(const CLASS& exception) : BASE(exception) \
    { \
    } \
    CLASS& CLASS::operator=(const CLASS& exception) \
    { \
        BASE::operator=(exception); \
        return *this; \
    } \
    const char* CLASS::name() const noexcept \
    { \
        return NAME; \
    } \
    const char* CLASS::className() const noexcept \
    { \
        return typeid(*this).name(); \
    } \
    Exception* CLASS::clone() const \
    { \
        return new CLASS(*this); \
    } \
    void CLASS::rethrow() const \
    { \
        throw *this; \
    }


DECLARE_EXCEPTION(LogicException, Exception)
DECLARE_EXCEPTION(RangeException, LogicException)
DECLARE_EXCEPTION(BadCastException, Exception)


#endif
