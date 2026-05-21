#pragma once

#include <cstddef>
#include <functional>
#include <memory>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>

// Учебная очередь FIFO: первый добавленный элемент извлекается первым.
template <typename T>
class SimpleQueue {
public:
    void push(const T& value) {
        data_.push(value);
    }

    T pop() {
        if (data_.empty()) {
            throw std::out_of_range("Queue is empty");
        }

        T value = data_.front();
        data_.pop();
        return value;
    }

    bool empty() const {
        return data_.empty();
    }

    std::size_t size() const {
        return data_.size();
    }

private:
    std::queue<T> data_;
};

// Учебная минимальная куча: при извлечении возвращается наименьший элемент.
template <typename T>
class SimpleHeap {
public:
    void push(const T& value) {
        data_.push(value);
    }

    T pop() {
        if (data_.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        T value = data_.top();
        data_.pop();
        return value;
    }

    bool empty() const {
        return data_.empty();
    }

    std::size_t size() const {
        return data_.size();
    }

private:
    std::priority_queue<T, std::vector<T>, std::greater<T>> data_;
};

// Учебное бинарное дерево поиска.
// push(value) — добавление значения;
// search(value) — поиск значения;
// pop(value) — удаление найденного значения.
template <typename T>
class BinarySearchTree {
private:
    struct Node {
        explicit Node(const T& node_value) : value(node_value) {}

        T value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };

public:
    void push(const T& value) {
        insert(root_, value);
    }

    bool search(const T& value) const {
        return contains(root_.get(), value);
    }

    bool pop(const T& value) {
        return erase(root_, value);
    }

    std::vector<T> inorder() const {
        std::vector<T> result;
        fill_inorder(root_.get(), result);
        return result;
    }

private:
    std::unique_ptr<Node> root_;

    static void insert(std::unique_ptr<Node>& node, const T& value) {
        if (!node) {
            node = std::make_unique<Node>(value);
            return;
        }

        if (value < node->value) {
            insert(node->left, value);
        } else if (node->value < value) {
            insert(node->right, value);
        }
        // Повторяющиеся значения в учебной реализации не добавляются.
    }

    static bool contains(const Node* node, const T& value) {
        if (!node) {
            return false;
        }

        if (value == node->value) {
            return true;
        }

        if (value < node->value) {
            return contains(node->left.get(), value);
        }

        return contains(node->right.get(), value);
    }

    static bool erase(std::unique_ptr<Node>& node, const T& value) {
        if (!node) {
            return false;
        }

        if (value < node->value) {
            return erase(node->left, value);
        }

        if (node->value < value) {
            return erase(node->right, value);
        }

        if (!node->left) {
            node = std::move(node->right);
            return true;
        }

        if (!node->right) {
            node = std::move(node->left);
            return true;
        }

        Node* successor = node->right.get();
        while (successor->left) {
            successor = successor->left.get();
        }

        node->value = successor->value;
        erase(node->right, successor->value);
        return true;
    }

    static void fill_inorder(const Node* node, std::vector<T>& result) {
        if (!node) {
            return;
        }

        fill_inorder(node->left.get(), result);
        result.push_back(node->value);
        fill_inorder(node->right.get(), result);
    }
};
