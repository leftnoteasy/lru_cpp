#ifndef _LRU_CACHE_H
#define _LRU_CACHE_H

#include <list>
#include <tr1/memory>
#include <ext/hash_map>

namespace lrucache {

template <class V>
class LruNode {
public:
    LruNode(V& v): val(&v) {};
    V& getValue() { return *val; };
private:
    V* val;
};

template <class K, class V>
class LruCache {
public:
    LruCache(size_t maxCacheSlot);

    void add(const K& key, const V& val);
    V* get(const K& key);
    void remove(const K& key);

    size_t size();
    size_t maxSize();
private:
    typedef std::tr1::shared_ptr<LruNode<V> > LruNodePtr;
    typedef std::list<LruNodePtr> InternalList;
    typedef __gnu_cxx::hash_map<K, typename InternalList::iterator> InternalMap;
    
    InternalMap internalMap;
    InternalList internalList; 
    size_t maxSizeLimit;
    size_t currentSize;
};

} //namespace

#endif