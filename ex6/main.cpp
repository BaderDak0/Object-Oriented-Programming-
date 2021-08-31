#include "math.h"
int main(int argc, char const *argv[])
{
  
    //  list<int> li;
    // li.insert(4);
    // li.insert(5);
    // li.insert(6);
    // li.insert(7);
    // li.insert(8);
    // cout<<li<<endl;
    math<int> m;
    m.insert(15);
    m.insert(6);
    m.insert(16);
    m.insert(4);
    m.insert(9);
    cout<<m<<endl;
    //cout<<m.mean()<<endl;
    m.sort(0);
    cout<<m<<endl;
    // try
    // {
    //     cout<<li[2]<<endl;
    //     li[2]=99;
    //     cout<<li<<endl;
    // }
    // catch(const char* error )
    // {
    //     cerr << error << '\n';
    // }
    
    list<const char *> lc;
    lc.insert("adam");
    lc.insert("jaber");
    lc.insert("bader");
    lc.insert("daka");
    cout<<lc<<endl;
    
    return 0;
}
