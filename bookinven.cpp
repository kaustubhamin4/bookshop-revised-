/* book shop 
3154152 kaustubh amin
*/
#include <iostream>
#include<stdlib.h>
using namespace std;
#define max 50

class books
{

public :
	int aval_stock;
     int book_id;
    char *title,*author,*publ;
    float price;
    books();
   void add();
   void display();


};

books::books()
{

    /*book_id=0;
    title[0]='\0';
    author[0]='\0';
    publ[0]='\0';

    price=0.0;
*/

       author = new char[30];
        title = new char[30];
        publ = new char[30];
}

void books::add()
{
    cout<<"enter book id :\t";
    cin>>book_id;
    cout<<"\n";
    cout<<"title of the book :\t";
    cin>>title;
    cout<<"\n";
    cout<<" name of author :\t";
    cin>>author;
    cout<<"\n";
    cout<<"name of publisher :\t";
    cin>>publ;
    cout<<"\n";
    cout<<"price of the book :\t";
    cin>>price;
    cout<<"\n";




}

void books::display()
{
   cout<<"book id :\t";
    cout<<book_id;
    cout<<"\n";
    cout<<"title of the book :\t";
    cout<<title;
    cout<<"\n";
    cout<<" name of author :\t";
    cout<<author;
    cout<<"\n";
    cout<<"name of publisher :\t";
    cout<<publ;
    cout<<"\n";
    cout<<"price of the book :\t";
    cout<<price;
    cout<<"\n";

}


int main()
{  static int strans=0,untrans=0;

    books b[max];

     int flag=0;
     int i,ch,n;
     float total_cost=0;
     int id,aval_stock;
     while(1)
     {
       cout<<"MENU :\n1.add\n2.update\n3.search a book\n4.purchase a book\n5.transactions\n6.exit\n";
       cout<<"enter your choice :\t";
       cin>>ch;
       cout<<"\n";

       switch(ch)
       {

           case 1: cout<<"enter how many book entries you want to enter :\t";
                   cin>>n;

                   for(i=0;i<n;i++)
                   {
                    b[i].add();

                       aval_stock++;
                   }
                   break;

           case 2: cout<<"insert the new entry :\n";

                    b[aval_stock].add();
                    aval_stock++;

                    for(i=0;i<aval_stock;i++)
                    {
                        b[i].display();
                    }

                    break;

            case 3: cout<<"enter the book id of a book to be searched :\t";
                    cin>>id;

                    for(i=0;i<aval_stock;i++)
                    {
                        if(id==b[i].book_id)
                        {
                            cout<<"book found at :\t"<<(i+1);
                              flag =1;
                              break;
                        }
                        else
                            flag=-1;

                    }

                    if(flag==-1)
                    {
                        cout<<"book not found \n";
                    }
                    break;

            case 4: cout<<"PURCHASE :\n";


                      cout<<"enter the book id :\t";
                         cin>>id;
                         cout<<"\n";


                       for(i=0;i<aval_stock;i++)
                      {
                         if(id==b[i].book_id)
                         {
                             total_cost=b[i].price;
                             aval_stock--;
                              strans++;
                              flag=1;
                         }
                         else
                            flag=-1;

                      }
                      if(flag==-1)
                      {
                          untrans++;
                      }


                    cout<<"total cost :\t"<<total_cost;
                    cout<<"\n PURCHASE SUCCESSFUL \n";

                    break;

            case 5: cout<<"\n TRANSACTIONS :\n";
                    cout<<"\n total no. of successful transactions :\t"<<strans;
                    cout<<"\n total no. of unsuccessful transactions :\t"<<untrans;
                     break;

            case 6:
            	 cout<<"Enter the book ID that you want to delete\n";
                  cin>>id;
                        for(i=0;i<n;i++)
                        {
                            if(b[i].book_id==id)
                            {
                              cout<<"book found\n";
                              delete b[i].title;
                              delete b[i].author;
                              delete b[i].publ;
                              b[i].aval_stock =-1;
                              flag=1;
                              break;
                            }
                            else
                              flag=0;
                        }
                        
                        if(flag=0)
                        {
                         cout<<"Book not found";
                        }
                    
				break;
			case 7: exit(0);

       }
     }



    return 0;
}


