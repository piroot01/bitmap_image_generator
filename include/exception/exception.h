#ifndef EXCEPTION_INCLUDED
#define EXCEPTION_INCLUDED


#include <exception>
#include <string>
#include <cstdint>


/**
* @class Exception
* @brief Base class for all exceptions
*/
class Exception : public std::exception
{
public:

    /**
    * @brief Default constructor
    * @param message
    * @parame code
    */
    Exception(const std::string& message, uint32_t code = 0);

    /**
    * @brief Default constructor
    * @param message
    * @param argument
    * @parame code
    */
    Exception(const std::string& message, const std::string& argument, uint32_t code = 0);

    /**
    * @brief Default constructor
    * @param message
    * @param nested stores a clone
    * @parame code
    */
    Exception(const std::string& message, const Exception& nested, uint32_t code = 0);

    /**
    * @brief Destructor
    */
    ~Exception() noexcept;

    /**
    * @brief Copy constructor
    */
    Exception(const Exception& exception);

    /**
    * @brief Copy assign constructor
    */
    Exception& operator=(const Exception& exception);
    
    /**
    * @brief name
    * @return const chat* static string describing the class
    */
    virtual const char* name() const noexcept;

    /**
    * @brief className
    * @return const char* name of the exception class
    */
    virtual const char* className() const noexcept;

    /**
    * @brief what
    * @return const chat* same as name(), mades for compatabiliry with std::except
    */
    virtual const char* what() const noexcept;

    /**
    * @brief nested
    * @return Exception*raw pointer to the nested exception
    */
    const Exception* nested() const;

    /**
    * @brief message
    * @return const std::string& the name of the message
    */
    const std::string& message() const;

    /**
    * @brief code
    * @return uint32_t the code of the exception
    */
    uint32_t code() const;

    /**
    * @brief displayText
    * @return std::string returns the exception name and the message
    */
    std::string displayText() const;

    /**
    * @brief clone
    * @return Exception* raw pointer to exact copy of the exception
    */
    virtual Exception* clone() const;

    /**
    * @brief rethrow
    * @detail rethrows this exception
    * @return void
    */
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
DECLARE_EXCEPTION(InvalidArgumentException, LogicException)



#endif
