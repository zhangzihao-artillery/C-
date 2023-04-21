#include<bits/stdc++.h>
using namespace std;
#define true 1
#define false 0
string s,t;
/* int next(int n){
    if(n==0)return -1;
    if(n==1)return -2;
   int l=0,r=1;
   while(l+r<n){
    if(s[l]==s[l+r]){
        l++;
    }else{
        l=0;
        r++;
    }
   }
   if(r==n)return -2;
   else return n-r+1;
} */

/* bool kmp(string s, string t){
    int i = 0 ,j = 0;
    while(i<s.size()&&j<t.size()){
        if(s[i]==t[j]){
            i++;
            j++;
        }else{
            i=next(i);
            if(i==-1){
                i=0;
                j++;
            }else if(i==-2){
                i=0;
            }
        }
    }
    if(i == s.size()){
        return true;
    }
    return false;
} */
int* prepare(){
    int* next = new int[s.size()];
    next[0]=-1;
    int r=0;
    int l=-1;
    while(r<s.size()-1){
        if(l==-1||s[l]==s[r]){
            l++;
            r++;
            next[r]=l;
        }else{
            l = next[l];
        }
    }
    return next;
}

/* void testnext(){
    int *next = prepare();
    for(int i=0;i<s.size();i++){
        cout<<next[i];
    }
    cout<<endl;
} */
bool kmp(string s, string t){
    int i = 0 ,j = 0;
    int *next = prepare();
    while((i<s.size()&&j<t.size())||i==-1){
        if(s[i]==t[j]||i==-1){
            i++;
            j++;
        }else{
            i=next[i];
        }
    }
    if(i == s.size()){
        return true;
    }
    return false;
}
int main(){
    cin>>s>>t;
    bool ret = kmp(s,t);
    cout<<ret<<endl;
}