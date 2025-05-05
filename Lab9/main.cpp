#include <stdio.h>
#include <tuple>

template<typename K, typename V>
class Inregistrare {
public:
    K key;
    V value;
    int index;

    V& Init(K k, int i) {
        key = k;
        index = i;

        return value;
    }

    void Init(K k, V v, int i) {
        key = k;
        value = v;
        index = i;
    }
};

template<typename K, typename V>
class Iterator {
public:
    Inregistrare<K, V>* values;
    int index;

    Iterator(Inregistrare<K, V>* v, int i) : values(v), index(i) {}

    Iterator<K, V>& operator++() {
        index++;
        return *this;
    }

    bool operator!=(Iterator<K, V>& other) {
        return index != other.index;
    }

    auto operator*() {
        return values[index];
    }
};

template<typename K, typename V>
class Map {
private:
    Inregistrare<K, V>* values;
    int size, count;

    void Resize() {
        size *= 2;

        Inregistrare<K, V>* temp = new Inregistrare<K, V>[size];
        for (int i = 0; i < count; i++)
            temp[i] = values[i];
        delete[] values;
        values = temp;
    }

    bool Find(const K& key) {
        for (int i = 0; i < count; i++)
            if (key == values[i].key)
                return true;

        return false;
    }

public:
    Map() {
        values = new Inregistrare<K, V>[2];
        size = 2;
        count = 0;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < count; i++)
            if (key == values[i].key)
                return values[i].value;
        
        if (count == size)
            Resize();

        return values[count].Init(key, count++);
    }

    Iterator<K, V> begin() {
        return Iterator<K, V>(values, 0);
    }

    Iterator<K, V> end() {
        return Iterator<K, V>(values, count);
    }

    void Set(K key, V value) {
        if (count == size)
            Resize();

        values[count].Init(key, value, count++);
    }

    bool Get(const K& key, V& value) {
        for(int i = 0; i < count; i++)
            if (key == values[i].key) {
                value = values[i].value;
                return true;
            }

        return false;
    }

    int Count() {
        return count;
    }

    void Clear() {
        delete[] values;

        values = new Inregistrare<K, V>[2];
        size = 2;
        count = 0;
    }

    bool Delete(const K& key) {
        for(int i = 0; i < count; i++)
            if (key == values[i].key) {
                while (i < count - 1)
                    values[i] = values[i + 1], i++;
                count--;
                return true;
            }

        return false;
    }

    bool Includes(const Map<K, V>& map) {
        for (auto [k, v, i] : map)
            if (!Find(k))
                return false;

        return true;
    }
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    //m.Delete(10);

    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
