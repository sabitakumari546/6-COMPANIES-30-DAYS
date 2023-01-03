#include<bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<long long>st;
       for(auto token: tokens){
           if(token!="*"&&token!="/"&&token!="+" &&token!="-"){
               int p=stoi(token);
               st.push(p);
           }
           else{
               long long a=st.top();
               st.pop();
             long long b=st.top();
               st.pop();
               if(token=="+"){
              long long c=a+b;
               st.push(c);}
               else  if(token=="-"){
              long long c=b-a;
               st.push(c);}
               else  if(token=="*"){
               long long c=a*b;
               st.push(c);}
               else  if(token=="/"){
              long long c=b/a;
               st.push(c);}
           }
       }
      
       return st.top();
    }
};