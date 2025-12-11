#include "searchable_bag.hpp"

class set
{
    private:
        searchable_bag& bag;

        set();
        set(const set& copy);

        set& operator=(const set& other);
    public:
        set(searchable_bag& s_bag);
        ~set();

        bool has(int value) const;
        void insert (int);
        void insert (int *, int);
        void print() const;
        void clear();

        const searchable_bag& get_bag();
};