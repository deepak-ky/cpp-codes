template<typename T>
class myvector
{
    int cs;
    int ms;
    T *arr;
public:
    myvector(){
        cs=0;
        ms=1;
        arr=new T[ms];
    }
    void push_back(T d)
    {
        if(cs==ms)
        {
            T *oldarr=arr;
            arr=new T[2*ms];
            ms=2*ms;
            for(int i=0;i<cs;i++)
            {
                arr[i]=oldarr[i];
            }
            delete [] oldarr;
        }
        arr[cs]=d;
        cs++;
    }
    void pop_back()
    {
        cs--;
    }
    T front()
    {
        return arr[0];
    }
    int back()
    {
        return arr[cs-1];
    }
    T empty()
    {
        return cs==0;
    }
    int capacity()
    {
        return ms;
    }
    T at(int i)
    {
        return arr[i];
    }
    T operator[](const int i)
    {
        return arr[i];
    }
    int size()
    {
        return cs;
    }
};
