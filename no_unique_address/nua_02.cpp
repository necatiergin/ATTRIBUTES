template<typename Key, typename Value, typename Hash, typename Pred, typename Allocator>
class HashMap {
    
public:
    // ...
private:
    [[no_unique_address]] Hash hasher;
    [[no_unique_address]] Pred pred;
    [[no_unique_address]] Allocator alloc;
    Bucket* buckets;
    // ...
};
