#ifndef CRUD_H
#define CRUD_H

#include <vector>
#include <memory>

template <typename T>
class CRUD {
private:
    std::vector<T> items;

public:
    CRUD(std::vector<T>& items) : items(items) {}

    void crear(const T& item) {
        items.push_back(item);
    }

    T leer(size_t id) const {
        return items.at(id);
    }

    std::vector<T> leerTodos() const {
        return items;
    }
};

#endif // CRUD_H