#include <ostream>
#include <iostream>
#include <string>
#include <list>

using namespace std;

int mm_score(string k, string g, int &b, int &w)
{

    
    if(k.size()==g.size())
    {
        int i=0;
        int j=0;
        int gSize = g.size(); 
        int kSize = k.size(); 

        for(i=0;i<k.size();i++)
        {
            for(j=i;j<g.size();j++)
            {
                if(k[i]==g[j] && i!=j)
                {
                    w++;
                }
            }
            if(k[i]==g[i])
            {
                b++;
            }
        }
        std::cout << "Return 1"<<" "<<"b = "<<b<<" " <<"w = "<< w <<std::endl;
        return 1;
    }
    else{
        return 0;
    }
    
}
///**
int main()
{
    int b=0, w=0;
    string k="abc";
    string g="axx";
    mm_score( k,  g,  b, w);
    return 0;
}
//*/