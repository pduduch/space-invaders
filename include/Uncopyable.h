#ifndef UNCOPYABLE_H_
#define UNCOPYABLE_H_

class Uncopyable
{
protected:
    Uncopyable();
    ~Uncopyable();

private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

#endif // UNCOPYABLE_H_