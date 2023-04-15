#include <iostream>
#include <string>
#include <vector>


enum class types_of_books
{
    litr, tech
};

class Book {
public:
    std::string book_author;
    std::string book_name;
    types_of_books book_type;

    Book(std::string author, std::string name, std::string type) {
        if (author != "" && name != "" && (type == "Техническая" || type == "Художественная")) {
            book_author = author;
            book_name = name;
            if (type == "Техническая") book_type = types_of_books::tech;
            if (type == "Художественная") book_type = types_of_books::litr;
        }
        else std::cout << "Некорректные данные в характеристике книги.\n";
    }

    types_of_books get_type() { return book_type; };

    ~Book() {}
};

void switchfunc(std::vector<Book>& lib) {
    int lit_count = 0; int tech_count = 0;
    for (int i = 0; i < lib.size(); ++i) {
        switch (lib[i].get_type()) {
            case types_of_books::litr:
                lit_count++;
                break;
            case types_of_books::tech:
                tech_count++;
                    }
    };

    std::cout << "Количество художественной литературы:   " << lit_count << "\nКоличество технической литературы:   " << tech_count<< std::endl;
}

void nonswitchfunc(std::vector<Book>& lib) {
    int lit_count = 0; int tech_count = 0;
    for (int i = 0; i < lib.size(); ++i) {
        if (lib[i].book_type == types_of_books::litr) lit_count++;
        if (lib[i].book_type == types_of_books::tech) tech_count++;
    };
    std::cout << "Количество художественной литературы:\n" << lit_count << "\nКоличество технической литературы:\n" << tech_count << std::endl;
}

int main() {

    setlocale(LC_ALL, "ru");
    std::vector<Book> library;

    Book book1("Эдвард Уилсон", "Смысл существования человека", "Техническая");
    Book book2("Юрий Олеша", "Ни дня без строчки", "Художественная");
    for (int i = 0; i < 5; ++i) { library.push_back(book1); };
    for (int i = 0; i < 5; ++i) { library.push_back(book2); };

    for (int i = 0; i < library.size(); ++i) {};
    
    std::cout << "Использование функции с оператором switch:\n";
    switchfunc(library);

    std::cout << "\nИспользование функции без оператора switch:\n";
    nonswitchfunc(library);
    
    return 0;
}