#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int year;
    int pages;

public:
    // Конструкторы
    Book() : author(""), title(""), publisher(""), year(0), pages(0) {}
    
    Book(const string& a, const string& t, const string& p, int y, int pg) 
        : author(a), title(t), publisher(p), year(y), pages(pg) {}
    
    // Конструктор копирования
    Book(const Book& other) 
        : author(other.author), title(other.title), 
          publisher(other.publisher), year(other.year), pages(other.pages) {}
    
    // Оператор присваивания
    Book& operator=(const Book& other) {
        if (this != &other) {
            author = other.author;
            title = other.title;
            publisher = other.publisher;
            year = other.year;
            pages = other.pages;
        }
        return *this;
    }
    
    // Геттеры
    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    string getPublisher() const { return publisher; }
    int getYear() const { return year; }
    int getPages() const { return pages; }
    
    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Автор: " << book.author 
           << ", Название: " << book.title 
           << ", Издательство: " << book.publisher 
           << ", Год: " << book.year 
           << ", Страниц: " << book.pages;
        return os;
    }
    
    // Функторы для сортировки
    struct SortByAuthor {
        bool operator()(const Book& a, const Book& b) const {
            return a.getAuthor() < b.getAuthor();
        }
    };
    
    struct SortByTitle {
        bool operator()(const Book& a, const Book& b) const {
            return a.getTitle() < b.getTitle();
        }
    };
};

int main() {
    vector<Book> booksVector;
    deque<Book> booksDeque;
    
    // Чтение из файла
    ifstream input("input.txt");
    if (input.is_open()) {
        string author, title, publisher;
        int year, pages;
        
        while (getline(input, author) && 
               getline(input, title) && 
               getline(input, publisher) && 
               input >> year >> pages) {
            input.ignore(); // Пропустить символ новой строки
            booksVector.emplace_back(author, title, publisher, year, pages);
        }
        input.close();
    }
    
    // Вывод исходного контейнера
    ofstream output("output.txt");
    output << "Исходный контейнер (vector):\n";
    for (const auto& book : booksVector) {
        output << book << "\n";
    }
    
    // Сортировка по ФИО автора (вариант 13)
    sort(booksVector.begin(), booksVector.end(), Book::SortByAuthor());
    
    // Вывод отсортированного контейнера
    output << "\nКонтейнер после сортировки по автору:\n";
    for (const auto& book : booksVector) {
        output << book << "\n";
    }
    
    // Копирование в deque
    copy(booksVector.begin(), booksVector.end(), back_inserter(booksDeque));
    
    // Вывод скопированного контейнера
    output << "\nКонтейнер после копирования в deque:\n";
    for (const auto& book : booksDeque) {
        output << book << "\n";
    }
    
    output.close();
    
    return 0;
}
