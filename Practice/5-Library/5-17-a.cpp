#include <iostream>
#include <memory>
#include <cstring>

std::size_t string_length(const char* s) {
    std::size_t n = 0;
    while (*s != '\0') {
        ++s;
        ++n;
    }
    return n;
}

std::unique_ptr<char[]> string_copy(const char* s) {
    std::size_t n = string_length(s);
    std::unique_ptr<char[]> result(new char[n + 1]);
    std::strcpy(result.get(), s);
    return result;
}

std::unique_ptr<char[]> string_duplicate(const char* s) {
    return string_copy(s);
}

std::unique_ptr<char[]> string_concatenate(const char* first, const char* second) {
    std::size_t first_len = string_length(first);
    std::size_t second_len = string_length(second);
    std::unique_ptr<char[]> result(new char[first_len + second_len + 1]);
    std::strcpy(result.get(), first);
    std::strcpy(result.get() + first_len, second);
    return result;
}

int main() {
    auto s = string_concatenate("Hello, ", "World!");
    auto t = string_duplicate(s.get());
    std::cout << t.get() << '\n';
}