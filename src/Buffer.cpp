#include "Buffer.h"

Buffer::Buffer(int capacity) {
    this->capacity = capacity;
    buffer = new char[capacity];
    clear();
}

Buffer::~Buffer() { delete[] buffer; }

int Buffer::length() { return len; }

void Buffer::insert(const char ch) {
    if (pos >= capacity - 2) return;

    for (int i = len; i > pos; i--) {
        buffer[i] = buffer[i - 1];
    }

    buffer[pos] = ch;
    pos++;
    len++;
}

void Buffer::prev() {
    if (pos > 0) pos--;
}

void Buffer::next() {
    if (pos < len - 1) pos++;
}

void Buffer::first() { pos = 0; }

void Buffer::last() { pos = len - 1; }

void Buffer::del() {
    if (pos == 0 || len == 0) return;
    pos--;
    len--;
    for (int i = pos; i < len; i++) buffer[i] = buffer[i + 1];
    buffer[len] = '\x00';
}

void Buffer::del_next() {
    if ((pos == len - 1) || len == 0) return;
    len--;
    for (int i = pos; i < len; i++) {
        buffer[i] = buffer[i + 1];
    }
    buffer[len] = '\x00';
}

void Buffer::clear() {
    memset(&buffer[0], '\x00', sizeof(buffer[0]) * capacity);
    pos = 0;
    len = 0;
}

bool Buffer::empty() { return (len == 0); }

char *Buffer::get() { return buffer; }