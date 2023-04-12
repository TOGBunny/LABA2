#include <iostream>
#include <set>

class CharSet {
private:
    std::set<char> set_;
    int size;
public:
    CharSet()
    {
        size = 1;
    }
    // Конструктор, що заповнює множину з рядка
    CharSet(const char* str) {
        for (int i = 0; str[i] != '\0'; ++i) {
            set_.insert(str[i]);
        }
       
    }

    // Перевантажена операція додавання елементу до множини
    CharSet operator+(char c) const {
        CharSet result(*this);
        result.add(c);
        return result;
    }

    // Перевантажена операція перетину множин
    CharSet operator*(const CharSet& other) const {
        CharSet result;
        for (char c : set_) {
            if (other.contains(c)) {
                result.add(c);
            }
        }
        return result;
    }

    // Перевантажена операція приведення до типу int - повертає кількість елементів у множині
    operator int() const {
        return set_.size();
    }

    friend void elementsInList(CharSet &Size);//Ініціалізація дружньої функції в класі

    // Додавання елементу до множини
    void add(char c) {
        set_.insert(c);
    }

    // Перевірка, чи належить елемент множині
    bool contains(char c) const {
        return set_.find(c) != set_.end();
    }

    // Виведення множини на екран
    void print() const {
        for (char c : set_) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
};

void elementsInList(CharSet &Size)//Дружня функція з класом Лаба2, яка перевіряє чи об'єкт пустий
{
    if (Size.set_.size() <= Size.size) //Перевірка чи кількість елементів в множині більше ніж поле int size = 1 
    {
        std::cout << "Fill a list" << std::endl;
    }
    else
        std::cout << "List is already filled" << std::endl;
}

int main() {
    const char* str1 = "hello";
    const char* str2 = "world";
    CharSet str0;
    CharSet charSet1(str1);
    CharSet charSet2(str2);

    elementsInList(str0);

    CharSet charSet3 = charSet1 + 'w';
    charSet3.print();

    CharSet charSet4 = charSet1 * charSet2;
    charSet4.print();

    int size = (int)charSet1;
    std::cout << "Size of charSet1: " << size << std::endl;

    return 0;
}
