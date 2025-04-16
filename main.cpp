#include <iostream>
#include <vector>
#include <memory> // Для использования smart pointers

// Базовый класс
class Animal
{
public:
    virtual void speak() const
    {
        std::cout << "Animal speaks" << std::endl;
    }
    virtual ~Animal() {} // Виртуальный деструктор
};

// Производный класс 1
class Dog : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Woof!" << std::endl;
    }
};

// Производный класс 2
class Cat : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Meow!" << std::endl;
    }
};

int main()
{
    // Создаем вектор указателей на базовый класс
    std::vector<std::unique_ptr<Animal>> animals;

    // Добавляем объекты производных классов
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    // Вызываем метод speak для каждого животного
    for (const auto &animal : animals)
    {
        animal->speak();
    }

    return 0;
}
