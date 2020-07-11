#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;

    while(cin>>a>>b)
    {
        int count=0;
        bool flagCount = false;

        for(int i=a; i<=b; i++)
        {
            set<char> st;
            string s = to_string(i);
            bool flag = true;
            count=0;

            for(int j = 0; j<s.size(); j++)
            {
                if(s[j]=='4' || s[j]=='7') st.insert(s[j]);
                else
                {
                    flag = false;
                    break;
                }
            }

            if((st.size()==1 || st.size()==2) && flag==true){cout<<s<<" "; count++; flagCount=true;}
        }
        if(count==0 && flagCount==false) cout<<"-1";
        cout<<endl;
    }
}
