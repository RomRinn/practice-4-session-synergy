#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "data_structures.hpp"

TEST(SimpleQueueTest, PushPopPreservesInsertionOrder) {
    SimpleQueue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    EXPECT_EQ(queue.size(), 3U);
    EXPECT_EQ(queue.pop(), 10);
    EXPECT_EQ(queue.pop(), 20);
    EXPECT_EQ(queue.pop(), 30);
    EXPECT_TRUE(queue.empty());
}

TEST(SimpleQueueTest, PopFromEmptyQueueThrowsException) {
    SimpleQueue<int> queue;

    EXPECT_THROW(queue.pop(), std::out_of_range);
}

TEST(SimpleHeapTest, PushPopReturnsValuesInAscendingOrder) {
    SimpleHeap<int> heap;

    heap.push(7);
    heap.push(3);
    heap.push(5);
    heap.push(1);

    EXPECT_EQ(heap.size(), 4U);
    EXPECT_EQ(heap.pop(), 1);
    EXPECT_EQ(heap.pop(), 3);
    EXPECT_EQ(heap.pop(), 5);
    EXPECT_EQ(heap.pop(), 7);
    EXPECT_TRUE(heap.empty());
}

TEST(SimpleHeapTest, PopFromEmptyHeapThrowsException) {
    SimpleHeap<int> heap;

    EXPECT_THROW(heap.pop(), std::out_of_range);
}

TEST(BinarySearchTreeTest, PushAndSearchWorkCorrectly) {
    BinarySearchTree<int> tree;

    tree.push(8);
    tree.push(3);
    tree.push(10);
    tree.push(1);
    tree.push(6);

    EXPECT_TRUE(tree.search(8));
    EXPECT_TRUE(tree.search(6));
    EXPECT_FALSE(tree.search(100));
}

TEST(BinarySearchTreeTest, PopRemovesExistingValue) {
    BinarySearchTree<int> tree;

    tree.push(8);
    tree.push(3);
    tree.push(10);
    tree.push(1);
    tree.push(6);

    EXPECT_TRUE(tree.pop(3));
    EXPECT_FALSE(tree.search(3));
    EXPECT_TRUE(tree.search(1));
    EXPECT_TRUE(tree.search(6));
}

TEST(BinarySearchTreeTest, InorderReturnsSortedValues) {
    BinarySearchTree<int> tree;

    tree.push(8);
    tree.push(3);
    tree.push(10);
    tree.push(1);
    tree.push(6);

    const std::vector<int> expected{1, 3, 6, 8, 10};
    EXPECT_EQ(tree.inorder(), expected);
}
