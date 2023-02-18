#include <iostream>

using namespace std;
class Integer{
    unsigned val;
    public: Integer(unsigned val){this->val = val;
} Integer(){};
unsigned func(){
    int sum = 0;
    unsigned dubl = val;
    while(dubl!=0){
       sum++;
       dubl/=10;
      
    }
    return sum;
}
unsigned revers(){
    int ans = val;
    string str = "";
    while(ans!=0){
        str+=to_string(ans%10);
        ans/=10;
    }
    return stoi(str);
}
/*bool& operator==(const Integer& a, const Integer& b){
    if(a.val == b.val)
    return true;
    else return false;*/

bool polindrom(){
    int ans = revers();
    if(ans == val)
    return true;
    else return false;
    
}
bool isJust(){
    int k = 0;
    for(int i = 1;i<=val/2;i++){
    if(val%i== 0){
    k++;}}
    
    if(k<3)
    return true;
    else return false;
}
bool isSover(){
    int sum = 0;
    int i;
    for(i = 0;i<=val/2;i++){
    if(val%i == 0){
    sum=sum+i;}}
    if(sum<val)
    return true;
    else return false;
}
};
class Aray{
   int *a;
    int i ;
    int sizeo;
    public:
   Aray(int size){
       a = new int[size];i = 0;sizeo= size;
   }
   void add(int value){
       if(i>=sizeo)
       cout<<"Array is over"<<endl;
       else{
       a[i] = value;
       i++;}}
   void print(){
       for(int j = 0;j<i;j++)
           cout<<a[j]<<" ";
           
       cout<<endl;
   }
};
int main()
{
    //cout<<"Hello World";
//Integer val(12);
//cout<<"is just = "<<val.isJust()<<", is sover = ";//<<endl;
//cout<<"Count of number = "<<val.func()<<", revers string = "<<val.revers()<<", is this polindrom "<<val.polindrom()<<endl;
//cout<<val.isJust()<<" isSover"<<val.sover();
 Aray ar(3);
 ar.add(1);
 ar.print();
 ar.add(6);
 ar.print();
 ar.add(7);
 ar.print();
 ar.add(9);
    return 0;
}
