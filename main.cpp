#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<ios>
using namespace std;

class ITEM{
   char name[20];
   float price;
   float weight;
   char brand[20];
   char sno[20];
   int stock;

   char fname[13]="itemdata.txt";
   ofstream ofs;
   ifstream ifs;

 public:
     void fillspacestring(char arr[],int siz){
       string str;
       str=arr;
       for(int i=str.length();i<siz;i++)
        arr[i]=' ';
     }
     template<typename t>
     char* filspace(t num,int siz){
      string str;
      char ch[10];
      int i;
      str=to_string(num);
      int n=str.length();
      strcpy(ch,str.c_str());
      for(i=n;i<siz;i++){
        ch[i]=' ';
      }
        cout<<"\nWeight from templat:-"<<ch;
        return ch;
     }
     void getData(){
                //Taking data From user
     cout<<"Enter Item Details"<<endl;
     fflush(stdin);
     cout<<"Item Name:-";
     gets(name);
     fillspacestring(name,20);
     cout<<endl<<"Item Price:-";
     cin>>price;
     cout<<endl<<"Item Weight(in grams):-";
     cin>>weight;
     cout<<endl<<"Brand Name:-";
     fflush(stdin);
     gets(brand);
     fillspacestring(brand,20);
     cout<<endl<<"Serial Number(S/N):-";
     gets(sno);
     fillspacestring(sno,20);
     cout<<endl<<"Stock:-";
     cin>>stock;
     }
     void storeData(){
      ofstream ofs;
       char *p;
                                 //storing data in a file
      ofs.open(fname,ios::app);
      ofs<<sno<<endl;
      cout<<"Serial no.:-"<<sno<<endl;
      ofs<<name<<endl;
      cout<<"Name:-"<<name<<endl;
      p=filspace<float>(weight,5);
      ofs<<*p<<endl;
      cout<<"Weight:-"<<*p<<endl;
      ofs<<brand<<endl;
      cout<<"Brand:-"<<brand<<endl;
      ofs<<stock<<endl;
      cout<<"Stock:-"<<stock<<endl;
      ofs<<filspace<float>(price,5)<<"/-"<<endl<<endl;
      cout<<"Price:-"<<price<<endl;
      ofs.close();
     }
     void showData(){
     string str;                                  //read data from file
     ifs.open(fname,ios::in);
     cout<<"\nHere is Your storage details\n";
     while(getline(ifs,str)){
     cout<<str<<endl;
     }
    ifs.close();
}
     void searchItem(){
        // char temp[20],ch;
         char s1[20];
            string s3;
              int i=0;                          //search item
      cout<<"Enter serial Number\n";
      gets(s1);
      ifs.open(fname,ios::in);
      bool flag=0;
      while(getline(ifs,s3)){


        //   s2=(string)temp;
        if(!strcmp(s1,s3.c_str())){
            cout<<"\nitem found";
            //getch();
            flag=1;
        }
        if(flag&&i<6){

            if(i==0){
                    strcpy(sno,s3.c_str());         //converting string to char
                cout<<"\nSerial Number(S/N):-   "<<sno;
            }if(i==1){
                strcpy(name,s3.c_str());
                cout<<"\n1.Item Name:-            "<<name;
            }if(i==2){
                   weight=stof(s3);                         //converting string to float
                cout<<"\n2.Weight:-               "<<weight;
            }if(i==3){
                  strcpy(brand,s3.c_str());
                cout<<"\n3.Brand Name:-           "<<brand;
            }if(i==4){
                  stock=stoi(s3);                       //converting sting to int
                cout<<"\n4.Stock:-                "<<stock;
            }if(i==5){
                price=stof(s3);
                cout<<"\n5.Price:-                "<<price;
            }i++;
        }
           if(flag&&i==6)                //to break loop when search is complete
            break;
      }
      if(!flag){
            cout<<endl<<"Item Not found";
        }
      ifs.close();
     }

     void update(){
         int n;
         string s3;
         char s1[20];
            searchItem();
            cout<<"\nEnter serial Number again for Update:-";
             gets(s1);
             ifs.open(fname,ios::in);
            ofs.open(fname,ios::in|ios::binary);
            cout<<endl<<"get ointer position:-"<<ofs.tellp();
          int i=0;
            bool flag=0;
      while(getline(ifs,s3)){


        //   s2=(string)temp;
        cout<<endl<<"get ointer position:-"<<ifs.tellg();
        if(!strcmp(s1,s3.c_str())){
                cout<<endl<<"get ointer position:-"<<ifs.tellg();
            cout<<"\nitem found";
            cout<<endl<<ifs.tellg();
            cout<<"\nwhat you want to update(1-5):-";
            cin>>n;
            //getch();
            flag=1;
        }
        if(flag&&i==n){

            if(n==1){
                    cout<<endl<<"get ointer position:-"<<ifs.tellg();
            ofs.seekp(ifs.tellg(),ios::beg);
            cout<<endl<<"get ointer position:-"<<ofs.tellp();
                cout<<"\nNew name:-";
                fflush(stdin);
                gets(name);
                ofs<<name;
                break;
            }if(n==2){
             cout<<"New weight:-";
             cin>>weight;
            }if(n==3){
              cout<<"New brand name:-";
              gets(brand);
            }if(n==4){
                int temp=stock;
              cout<<"Enter Number of New "<<name<<":-";
              cin>>stock;
              cout<<"New stock is "<<stock+temp;
            }if(n==5){
              cout<<"New Price:-";
              cin>>price;
            }

     }else cout<<"\nWrong input";
      if(flag)
      i++;
      }
      ifs.close();
      ofs.close();

     }
};
int main(){
  ITEM i1;
   i1.getData();
     i1.storeData();
     i1.showData();

     //i1.searchItem();

//     i1.update();
     //i1.searchItem();
     i1.showData();

  return 0;
}
