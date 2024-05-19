#include <iostream>
#include <cstring>
#include <memory>
#include <cctype>

// Duplicate a C-style string.
std::unique_ptr<char[]> string_duplicate(const char* s) {
    std::size_t n = std::strlen(s);
    std::unique_ptr<char[]> result(new char[n + 1]);
    std::strcpy(result.get(), s);
    return result;
}

// Read character data from an input stream and return it.
std::unique_ptr<char[]> source_data() {
    char buffer[1024];
    if (std::cin.getline(buffer, sizeof(buffer))) {
        return string_duplicate(buffer);
    } else {
        return nullptr;
    }
}

// Transform the character data and return the transformed data.
// (Map lowercase to uppercase.)
std::unique_ptr<char[]> transform_data(std::unique_ptr<char[]> s) {
    char* p = s.get();
    while (*p != '\0') {
        if (std::islower(*p)) {
            *p = std::toupper(*p);
        }
        ++p;
    }
    return s;
}

// Write the character data to an output stream and then discard the data.
void sink_data(std::unique_ptr<char[]> s) {
    std::cout << s.get() << '\n';
}

int main() {
    std::unique_ptr<char[]> s;
    while ((s = source_data()) != nullptr) {
        s = transform_data(std::move(s));
        sink_data(std::move(s));
    }
}