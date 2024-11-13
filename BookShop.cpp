/*******************************Offline 2****************************************/
/* Implement the functions of the class BookShop below as per the instructions  */
/* given inline the class definition. Make sure the output of the code in the   */
/* main function matches the given sample output. You may add/delete codes in   */
/* the main function during your testing. But before submission remove all your */
/* modifications from the main function and submit it as provided initially.    */
/********************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include "Book.cpp"

using namespace std;

class BookShop
{
    char name[100];
    Book* books; //List of books in the shop
    int size;  //maximum number of books the shop can keep
    int count; //tracks currently how many numbers in the shop
public:
    //setter
    void setName(char* name)
    {
        strcpy(this->name,name);
    }
    void setSize(int size)
    {
        this->size=size;
    }
    void setCount(int count)
    {
        this->count=count;
    }
    //getter
    int getSize()
    {
        return size;
    }
    int getCount()
    {
        return count;
    }
    Book getBook(int i)
    {
        return books[i];
    }

    BookShop() //Default constructor
    {
        /*Initialize with size 5 and name to empty string ""*/
        setName("");
        books=new Book[5];
        size=5;
        count=0;
    }

    BookShop(char* name, int size) //Parameterized constructor
    {
        /*Initialize with the given name and size*/
        strcpy(this->name,name);
        books=new Book[size];
        this->size=size;
        count=0;
    }

    BookShop(const BookShop& bs) //Copy constructor
    {
        /*Write necessary code for the copy constructor*/
        strcpy(this->name,bs.name);
        this->books=new Book[bs.size];
        this->books=bs.books;
        this->size=bs.size;
        this->count=bs.count;
    }

    ~BookShop() //Destructor
    {
        delete[] books;
    }

    void addBook(Book b)
    {
        /*Add book b to the end of the list*/
        books[count]=b;
        count++;
    }

    void addBook(Book* ba, int count)
    {
        /*Add the given array of books ba to the end of the list*/
        for(int i=0; i<count; i++,this->count++)
            books[this->count]=ba[i];
    }

    Book getBookInfo(char* title)
    {
        /*Return the **first** book that has the given title. Assume there is atleast one book in the list with the given title*/
        int c=5;
        for(int i=0; i<count; i++)
        {
             c=strcmp(books[i].getTitle(),title);
            if(c==0)
            {
                return books[i];
                break;
            }
        }
        if(c==5)
            cout<<"Book not found"<<endl;
    }

    void updateBookPrice(int isbn, int price)
    {
        /*Update the price of the book with given isbn to the given price*/
        for(int i=0; i<count; i++)
        {
            if(books[i].getISBN()==isbn)
            {
                books[i].setPrice(price);
            }
            break;
        }
    }

    void removeBook(int isbn)
    {
        /*Remove the book with the given isbn from the list. After removing a book all the books below the removed book will be shifted up, i.e, there will be no hole in the list*/
        int r=-1;
        int i;
        for(i=0; i<count; i++)
        {
            if(books[i].getISBN()==isbn)
            {
                r=i;
                break;
            }
        }
        for(i=r+1; i<count; i++)
        {
            books[i-1]=books[i];
        }
        count--;
    }

    int totalPrice()
    {
        /*Return the sum of the prices of all the books in the list*/
        int sum=0;
        for(int i=0; i<count; i++)
            sum+=books[i].getPrice();
        return sum;
    }

    void print()
    {
        /*Print the bookshop's name followed by information of all the books in the bookshop*/
        cout<<"Bookshop Name: "<<name<<endl;
        for (int i=0; i<count; i++)
            books[i].print();
    }

    BookShop mergeShop(BookShop b)
    {
        /* Return a new bookshop object that will contain all the books of this bookshop and the given bookshop b*/ 			/* Use the title **MergedShop** of the new bookshop														*/
        BookShop temp;
        int lim,i;
        lim=this->count + b.getCount();
        temp.setSize(lim);
        for(i=0; i<this->count; i++)
        {
            temp.addBook(this->getBook(i));
        }
        for(i=0;i<b.getCount();i++)
        {
            temp.addBook(b.getBook(i));
        }
        return temp;
    }
};

int main()
{

    BookShop bs1;
    bs1.setName("Boimela");
    Book b1(101,"Teach Yourself C++",100);
    Book b2(102,"Teach Yourself C",200);
    Book b3(103,"Java For Dummies",300);
    bs1.addBook(b1);
    bs1.addBook(b2);
    bs1.addBook(b3);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Edition: 100
					ISBN: 102, Title: Teach Yourself C, Edition: 200
					ISBN: 103, Title: Java For Dummies, Edition: 300
				 */
    cout<<"Total price of books: "<<bs1.totalPrice()<<endl;	/*Output:
															   Total price of books: 600
															*/

    bs1.removeBook(102);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Edition: 100
					ISBN: 103, Title: Java For Dummies, Edition: 300
				 */

    bs1.updateBookPrice(101,500);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Edition: 500
					ISBN: 103, Title: Java For Dummies, Edition: 300
				 */


    Book jfd=bs1.getBookInfo("Java For Dummies");
    jfd.print();  /*Output:
					 ISBN: 103, Title: Java For Dummies, Edition: 300
				 */

    cout<<endl;
    Book ba[3]= {Book(201,"Operating Systems",1000),Book(202,"Compilers",2000),Book(203,"Computer Networks",1500)};
    BookShop bs2("Puthighor",5);
    bs2.addBook(ba,3);
    bs2.print();  /*Output:
					 Bookshop Name: Puthighor
					 ISBN: 201, Title: Operating Systems, Edition: 1000
					 ISBN: 202, Title: Compilers, Edition: 2000
					 ISBN: 203, Title: Computer Networks, Edition: 1500
				 */

    cout<<endl;
    BookShop bs3=bs1.mergeShop(bs2);
    bs3.setName("Mullick Brothers");
    bs3.print(); /*Output: Mullick Brothers
					ISBN: 101, Title: Teach Yourself C++, Edition: 500
					ISBN: 103, Title: Java For Dummies, Edition: 300
					ISBN: 201, Title: Operating Systems, Edition: 1000
					ISBN: 202, Title: Compilers, Edition: 2000
					ISBN: 203, Title: Computer Networks, Edition: 1500
				 */
}
