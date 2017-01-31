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
				throw;
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
		try
		{
			keys = new key[s.size];
		}
		catch(...)
		{
			delete [] data;
			throw;
		}
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
		key* nkeys;
		try
		{
			nkeys = new key[s.size];
		}
		catch(...)
		{
			delete [] ndata;
		}
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
            o <<"key: "<< v.keys[i] <<endl;
            o << v.data[i]<<endl;
        }
        return o;
    }
    map_template<key,example> Add(const key& addkey, const example& addend)
    {
        if(size == 0)
        {
            data[0] = addend;
            keys[0] = addkey;
            size += 1;
            return *this;
        }
        else 
        {
            size += 1;
            example* newdata;
            newdata = new example[size];
            key* newkeys;
			try
			{
				newkeys = new key[size];
			}
			catch(...)
			{
				delete [] newdata;
				throw;
			}
            try
			{
				for(unsigned i =0; i<size-1;i++)
				{
					newdata[i] = data[i];
					newkeys[i] = keys[i];
				}
				newdata[size-1] = addend;
				newkeys[size-1] = addkey;
			}
			catch(...)
			{
				delete [] newdata;
				delete [] newkeys;
				throw;
			}
            delete[] data; delete[] keys;
            data = newdata; keys = newkeys;
            return *this;
        }
    }
    example* Find(key finding)
    {
        for(unsigned i = 0; i<size; i++)
            if (finding == keys[i]) 
				return &data[i];
			
		return NULL;
    }
};
#endif /* _TEMPLATE_H_ */