class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;
};

class LRUCache
{

    int cap;
    int sz;
    Node *first = new Node();
    Node *last = new Node();
    map<int, Node *> mp;

    void makeRecent(Node *t)
    {
        if (t->prev != NULL && t->next != NULL)
        {
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }

        t->prev = first;
        t->next = first->next;
        t->next->prev = t;
        first->next = t;
        return;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        sz = 0;
        first->val = -1;
        last->val = -1;
        first->next = last;
        last->prev = first;
    }

    int get(int key)
    {
        Node *t = mp[key];
        if (t == NULL)
        {
            return -1;
        }

        makeRecent(t);

        return t->val;
    }

    void put(int key, int value)
    {

        Node *t = mp[key];

        if (t != NULL)
        {
            t->val = value;

            makeRecent(t);
            return;
        }
        if (sz == cap)
        {
            mp[last->prev->key] = NULL;
            last->prev = last->prev->prev;
            last->prev->next = last;
        }
        else
        {
            sz++;
        }
        mp[key] = new Node();
        t = mp[key];
        t->key = key;
        t->val = value;

        makeRecent(t);
        return;
    }
};