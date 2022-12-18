#include <iostream>                                                             
                                                                                
using namespace std;                                                            
                                                                                                                                                                                                                
int sequence_length = 1;                                                        
float longest_descending_sequence[10001];                                        
int l,p,t;                                                                      
                                                                                
int check(float k)                                                              
{                                                                               
    l = 0;                                                                      
    p = sequence_length+1;                                                      
    while (l!=p-1)                                                              
    {                                                                           
        t = (l+p)/2;                                                            

        if (k<longest_descending_sequence[t-1])                                 
        {                                                                       
            l=t;                                                                
        }                                                                       
        else                                                                    
        {                                                                       
            p = t;                                                              
        }                                                                       
    }                                                                           
    return p;                                                                   
}                                                                               
                                                                                
int main()                                                                      
{ 
    int n;                                                                              
    float times[300001];                                                          
    ios_base::sync_with_stdio(false);                                           
    cin >> n;                                                                   

    for (int i = 0;i<n;i++)                                                     
    {                                                                           
        cin >> times[i];                                                        
    }                                                                           

    longest_descending_sequence[0] = times[0];                                  

    for(int i = 1;i<n;i++)                                                      
    {                                                                           

        if (times[i]<longest_descending_sequence[sequence_length-1])            
        {                                                                       
            sequence_length+=1;                                                 
            longest_descending_sequence[sequence_length-1] = times[i];          
        }                                                                       
        else                                                                    
        {                                                                       

            longest_descending_sequence[check(times[i])-1] = times[i];          
        }                                                                       
                                                                                
    }
    cout << sequence_length*100;                                                
}