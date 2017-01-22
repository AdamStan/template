#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_
//BEZ add, find...
#include <iostream>
#include <string>

using namespace std;

template<typename key, class example> class map_template
{
    example *data;
    key *keys;
    unsigned int size;
public:
    class index_out_of_range{};
    map_template ()
    {
        size = 0;
        data = new example[1];
        data[size] = example(); 
        try
        {
            keys = new key[1];
            keys[size] = key();
        }
	catch(...)
	{
            delete [] data;
	}
    }
    ~map_template ()
    {
        delete [] data;
        delete [] keys;
    }
    map_template (const map_template<key,example> & s)
    {
        data = new example[s.size];
        keys = new key[s.size];
        size = s.size;
        for (unsigned i = 0; i < size; i++)
        {
            data[i] = s.data[i];
            keys[i] = s.keys[i];
        }
    }
    map_template<key,example>& operator= (const map_template<key,example>& s) 
    {
        if (this == &s)
            return *this;
        example* ndata = new example[s.size];
        key* nkeys = new key[s.size];
        for(unsigned int i = 0; i<s.size;i++)
        {
            ndata[i] = s.data[i];
            nkeys[i] = s.keys[i];
        }
        if (size!=0) 
        {
            delete [] data;
            delete [] keys;
        }
        size = s.size;
        data = ndata;
        keys = nkeys;
        return *this;
    }
    friend ostream& operator<< (ostream& o, const map_template<key,example>& v) 
    {
        for (unsigned i = 0; i < v.size;i++)
        {
           //if (v.keys[i] == 0) break;
            o <<"key: "<< v.keys[i] <<endl;
            o << v.data[i]<<endl;
        }
        return o;
    }
    map_template<key,example> Add(key addkey, example addend)
    {
        if(size == 0)
        {
            data[0] = addend;
            keys[0] = addkey;
            size +=1;
            return *this;
        }
        else 
        {
            size += 1;
            example* newdata;
            newdata = new example[size];
            key* newkeys;
            newkeys = new key[size];
            
            for(unsigned i =0; i<size-1;i++)
            {
                newdata[i] = data[i];
                newkeys[i] = keys[i];
            }
            delete[] data; delete[] keys;
            data = newdata; keys = newkeys;
            data[size-1] = addend; 
            keys[size-1] = addkey;
            return *this;
        }
    }
    example* Find(key finding) //ponoć tak to ma być
    {
        unsigned int i = 0;
        for( ; i<size; i++)
            if (finding == keys[i])
            {
                break;
            }
        if(i == size) i=0;
        return &data[i];
    }
};
#endif /* _TEMPLATE_H_ */