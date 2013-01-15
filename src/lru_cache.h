#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <list>
#include <tr1/memory>
#include <ext/hash_map>

namespace lrucache {

template <class V>
class LruNode {
public:
    LruNode(V& v): val(&v) {};
    V& getValue();
private:
    V* val;
};

template <class K, class V>
class LruCache {
public:
    LruCache(size_t maxCacheSlot);

    void add(const K& key, const V& val);
    V* get(const K& key);
    void delete(const K& key);

    size_t size();
    size_t maxSize();
private:
    typedef std::tr1::shared_ptr<LruNode<V> > LruNodePtr;
    typedef std::list<LruNodePtr> InternalList;
    typedef InternalList::iterator InternalListIterator;
    typedef __gnu_cxx::hash_map<K, InternalListIterator> InternalMap;
    typedef InternalMap::iterator InternalMapIterator;
    
    InternalMap internalMap;
    InternalList internalList; 
    size_t maxSizeLimit;
    size_t currentSize;
};

} //namespace

#endif