#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    Animal() {};
    virtual void bark(){};
};

class Wolf : public Animal
{
public:
    Wolf(string m_word) : m_word(m_word) {};
    void bark()
    {
        cout << m_word << endl;
    }

private:
    string m_word;
};

class Lion : public Animal
{
public:
    Lion(string m_word) : m_word(m_word) {};
    void bark()
    {
        cout << m_word << endl;
    }

private:
    string m_word;
};

class Dog : public Animal
{
public:
    Dog(string m_word) : m_word(m_word) {};
    void bark()
    {
        cout << m_word << endl;
    }

private:
    string m_word;
};

void print(Animal *animal)
{
    animal->bark();
}

int main()
{
    Lion lion1("asddd");

    Lion* lion = new Lion("asd");

    print(lion);

    print(&lion1);
    return 0;
}
