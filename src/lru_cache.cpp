#include "lru_cache.h"
#include <stdexcept>

using namespace std;
using namespace __gnu_cxx;

template <class K, class V>
lrucache::LruCache::LruCache(size_t maxSlot) {
    this->maxSizeLit = maxSlot;
}

template <class K, class V>
void lrucache::LruCache::add(const K& key, const V& v) {
    // check if exceeds limit
    if (currentSize == maxSizeLimit) {
        throw runtime_error("current size equals limit size");
    }

    // check if already exists 
    InternalMapIterator mapIter = internalMap.find(key);
    if (internalMap.end() != mapIter) {
        throw runtime_error("key exist in current cache, key:" + key);
    }

    // insert to list
    internalList.push_back(v);
    
    // get last list iterator
    InternalListIterator listIter = internalList.end();
    --listIter;

    // insert it to map
    internalMap.insert(key, listIter);

    // increase size
    ++currentSize;
}

template <class K, class V>
void lrucache::LruCache::delete(const K& key) {
    // check if already exists 
    InternalMapIterator mapIter = internalMap.find(key);
    if (internalMap.end() == mapIter) {
        throw runtime_error("key not exist in current cache, key:" + key);
    }

    // delete it in list
    InternalListIterator listIter = mapIter->second;
    internalList.erase(listIter);
    internalMap.erase(key);

    --currentSize;
}

template <class K, class V>
V* lrucache::get(const K& key) {
    InternalMapIterator mapIter = internalMap.find(key);
    if (internalMap.end() != mapIter) {
        InternalListIterator listIter = mapIter->second;

        V& result = (*listIter)->getValue();

        internalList.push_back(*listIter);
        internalList.erase(listIter);

        return &result;
    } else {
        return NULL;
    }
}

template <class K, class V>
size_t size() {
    return currentSize;
}

template <class K, class V>
size_t maxSize() {
    return maxSizeLimit;
}