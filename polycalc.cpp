#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;

//function to clear screen

void clrscr()
{
    system("cls");
}

//project introductory page

void start(){
    int i;
    cout<<"\n\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"<<endl<<endl;
    cout<<"\t\t\t\t     POLYNOMIAL CALCULATOR \t\t\t"<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t BY"<<endl<<endl<<endl;
    cout<<"\t\t\t\t 20PW03 - AKSHAYA J"<<endl<<endl;
    cout<<"\t\t\t\t 20PW36 - SWETHA S"<<endl<<endl<<endl;
    cout<<"\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"<<endl<<endl<<endl;

}

//class Polynomial is declared

class Polynomial{

    private:

        //a user defined data type named node is created which has coefficient and exponent

        struct node {
            float coeff;
            int expo;
            node* link;
        }*start,*ptr,*ptr1,*ptr2;


    public:

        //member function declarations

        Polynomial();
        void insert_polynomial(float , int );
        void display_polynomial();
        void add_polynomial(Polynomial& l1, Polynomial& l2);
        void sub_polynomial(Polynomial& l1, Polynomial& l2);
        void scalarmul_polynomial(Polynomial& l1, float );
        void multiply_polynomial(Polynomial& l1, Polynomial& l2);
        void scalardiv_polynomial(Polynomial& l1, float );
        void find_degree(Polynomial& l1 );
};

//default constructor

Polynomial::Polynomial()
{

    start=NULL;

}

//to insert coeff and expo into a node of the polynomial

void Polynomial::insert_polynomial(float co,int ex){
    struct node *N=start;

    //creation of the node if no other node exists

    if(N == NULL) {
        N = new node;
        start = N;
    }

    //creating a node at the end of the linked list

    else {

        while (N->link != NULL)
        {
            N = N->link;
        }

        N->link = new node;
        N = N->link;

    }

    //inserting coefficient and exponent values into the newly created node

    N->coeff = co;
    N->expo = ex;
    N->link = NULL;
}

//to display the polynomial

void Polynomial::display_polynomial()
{
    ptr=start;
    int x= 0;

    //traversing through each node

    while (ptr!=NULL) {
        if (x!=0) {
            if (ptr->coeff > 0)
            cout<<"+";
        }
        if (ptr->expo != 0){
            cout<<ptr->coeff<< "x^"<<ptr->expo;
        }
        else
            cout<<ptr->coeff;
        ptr=ptr->link;

        x=1;
    }

}

//to add the two polynomials

void Polynomial::add_polynomial(Polynomial& l1, Polynomial& l2)
{
    //assigning the start of the two polynomials to ptr1 and ptr2

    ptr1=l1.start;
    ptr2=l2.start;

    //traversing both polynomials
    //ptr is the pointer of the resultant polynomial

    while (ptr1!=NULL && ptr2!=NULL) {
        if(start==NULL) {
            start=new node;
            ptr=start;
        }
        else {
            ptr->link=new node;
            ptr=ptr->link;
        }
        if(ptr1->expo<ptr2->expo)
        {
            ptr->coeff=ptr2->coeff;
            ptr->expo=ptr2->expo;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo>ptr2->expo)
        {
            ptr->coeff=ptr1->coeff;
            ptr->expo=ptr1->expo;
            ptr1=ptr1->link;
        }
        else{
            ptr->coeff=ptr1->coeff + ptr2->coeff;
            ptr->expo=ptr1->expo;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }

    }

    //while there are remaining terms in the two polynomials

    while (ptr1!=NULL || ptr2!=NULL)
    {
        if (start==NULL) {
            start=new node;
            ptr=start;
        }
        else {
            ptr->link=new node;
            ptr=ptr->link;
        }
        if(ptr1!=NULL){
            ptr->coeff=ptr1->coeff;
            ptr->expo=ptr1->expo;
            ptr1=ptr1->link;
        }
        if(ptr2!=NULL)
        {
            ptr->coeff=ptr2->coeff;
            ptr->expo=ptr2->expo;
            ptr2=ptr2->link;
        }
    }
    ptr->link=NULL;

}

//to subtract the two polynomials

void Polynomial::sub_polynomial(Polynomial& l1, Polynomial& l2)
{
    //assigning the start of the two polynomials to ptr1 and ptr2

    ptr1=l1.start;
    ptr2=l2.start;

    //traversing both polynomials
    //ptr is the pointer of the resultant polynomial

    while (ptr1!=NULL && ptr2!=NULL) {
        if(start==NULL) {
            start=new node;
            ptr=start;
        }
        else {
            ptr->link=new node;
            ptr=ptr->link;
        }
        if(ptr1->expo<ptr2->expo)
        {
            ptr->coeff=-1*(ptr2->coeff);
            ptr->expo=ptr2->expo;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo>ptr2->expo)
        {
            ptr->coeff=ptr1->coeff;
            ptr->expo=ptr1->expo;
            ptr1=ptr1->link;
        }
        else{
            if(ptr1->coeff-ptr2->coeff!=0){
                ptr->expo=ptr1->expo;
                ptr->coeff=ptr1->coeff-ptr2->coeff;
                ptr1=ptr1->link;
                ptr2=ptr2->link;
            }
        }

    }

    //while there are remaining terms in the two polynomials

    while (ptr1!=NULL || ptr2!=NULL)
    {
        if (start==NULL) {
            start=new node;
            ptr=start;
        }
        else {
            ptr->link=new node;
            ptr=ptr->link;
        }
        if(ptr1!=NULL){
            ptr->coeff=ptr1->coeff;
            ptr->expo=ptr1->expo;
            ptr1=ptr1->link;
        }
        if(ptr2!=NULL)
        {
            ptr->coeff=-1*(ptr2->coeff);
            ptr->expo=ptr2->expo;
            ptr2=ptr2->link;
        }

    }
    ptr->link=NULL;

}

//to multiply a polynomial by a scalar

void Polynomial::scalarmul_polynomial(Polynomial& l1, float k)
{
    //assigning the start of the polynomial to ptr1
    ptr1=l1.start;
    while (ptr1!=NULL)
    {
        if (start==NULL) {
            start=new node;
            ptr=start;
        }
        else {
            ptr->link=new node;
            ptr=ptr->link;
        }
        if(ptr1!=NULL){
            ptr->coeff=ptr1->coeff*k;
            ptr->expo=ptr1->expo;
            ptr1 = ptr1->link;
        }
    }
    ptr->link=NULL;

}

//to multiply the two polynommials

void Polynomial::multiply_polynomial(Polynomial& l1, Polynomial& l2)
{
    //assigning the start of the two polynomials to ptr1 and ptr2

    ptr1=l1.start;
    ptr2=l2.start;

    //traversing both polynomials
    //ptr is the pointer of the resultant polynomial

    if (ptr1==NULL && ptr2==NULL)
    {
       cout<<"\nMultiplication of polynomial is not possible!\n"<<endl;
    }

    while (ptr1!=NULL && ptr2!=NULL)
    {
        while(ptr1!=NULL)
        {
            //multiplying each node of ptr1 with each and every node of ptr2

            ptr2=l2.start;
            while(ptr2!=NULL)
            {
                if(start==NULL) {
                    start=new node;
                    ptr=start;
                }
                else {
                    ptr->link=new node;
                    ptr=ptr->link;
                }
                ptr->coeff=ptr1->coeff*ptr2->coeff;
                ptr->expo=ptr1->expo+ptr2->expo;
                ptr2=ptr2->link;
            }
        ptr1=ptr1->link;
        }
    }
    ptr->link=NULL;
}

//to divide a polynomial by a scalar

void Polynomial::scalardiv_polynomial(Polynomial& l1, float k)
{
    ptr1=l1.start;

    //assigning the start of the polynomial to ptr1

    while (ptr1!=NULL)
    {
        if (start==NULL) {
            start=new node;
            ptr=start;
        }
        else {
            ptr->link=new node;
            ptr=ptr->link;
        }
        if(ptr1!=NULL){
            ptr->coeff=ptr1->coeff/k;
            ptr->expo=ptr1->expo;
            ptr1 = ptr1->link;
        }
    }
    ptr->link=NULL;

}

//to find the degree of the polynomial

void Polynomial::find_degree(Polynomial& l1)
{
    ptr1=l1.start;
    int maximum=0,c;
    while (ptr1!=NULL)
    {
        if(ptr1->expo>maximum)
        {
            //to find maximum exponent by traversing and storing its coefficient

            maximum=ptr1->expo;
            c=ptr1->coeff;

        }
        ptr1=ptr1->link;

    }
    cout<<"The degree of the polynomial is:"<<maximum<<endl<<endl;
    cout<<"The term with the highest degree is:"<<endl;
    cout<<c<<"x^"<<maximum<<endl<<endl;


}

int main(){
    start();

    //creating instances for the class

    Polynomial p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
    string consent;
    float c;
    int e;
    int i,choice;
    for(i=0;i<2;i++){
        if(i==0){
            int flag=1;
            cout<<"\n\nENTER FIRST POLYNOMIAL:"<<endl;

            //to enter any no of the terms the user wants to input into the polyomial

            cout<<"\nDo you want to insert into the polynomial?"<<endl;
            cin>>consent;
            while(flag!=0){
                if(consent=="yes" || consent=="Yes"){
                    cout<<"Enter coefficient:";
                    cin>>c;
                    cout<<"Enter exponent:";
                    cin>>e;
                    p1.insert_polynomial(c,e);
                    cout<<"\nDo you want to insert into the polynomial?"<<endl;
                    cin>>consent;
                    if(consent=="yes" || consent=="Yes"){
                        flag=1;
                    }
                    else{
                        flag=0;
                    }
                }
            }
        }

        else{
            clrscr();
            int flag=1;
            cout<<"ENTER SECOND POLYNOMIAL:"<<endl;

            //to enter any no of the terms the user wants to input into the polyomial

            cout<<"\nDo you want to insert into the polynomial?"<<endl;
            cin>>consent;
            while(flag!=0){
                if(consent=="yes" || consent=="Yes"){
                    cout<<"Enter coefficient:";
                    cin>>c;
                    cout<<"Enter exponent:";
                    cin>>e;
                    p2.insert_polynomial(c,e);
                    cout<<"\nDo you want to insert into the polynomial?"<<endl;
                    cin>>consent;
                    if(consent=="yes" || consent=="Yes"){
                        flag=1;
                    }
                    else{
                        flag=0;
                    }
                }
            }
        }

    }

    //to display the two polynomials the user has input

    cout<<"\nTHE FIRST POLYNOMIAL:"<<endl;
    p1.display_polynomial();
    cout<<endl<<endl;
    cout<<"\nTHE SECOND POLYNOMIAL:"<<endl;
    p2.display_polynomial();
    cout<<endl<<endl;

    //menu driven program to perform the desired operations on the polynomial/polynomials

    cout<<" OPERATIONS:"<<endl<<endl;
    cout<<"\t1.To add the two polynomials\n"<<endl;
    cout<<"\t2.To subtract the two polynomials\n"<<endl;
    cout<<"\t3.To multiply a polynomial by a scalar\n"<<endl;
    cout<<"\t4.To multiply the two polynomials\n"<<endl;
    cout<<"\t5.To divide a polynomial by a scalar\n"<<endl;
    cout<<"\t6.To find degree of a polynomial\n"<<endl;
    cout<<endl;
    cout<<"Enter your choice/Enter 0 to exit:"<<endl;
    cin>>choice;

    system("cls");
    while(choice!=0){
        switch(choice){

            //to perform the operations

            case 1:
            {

                //addition
                cout<<"\nTHE FIRST POLYNOMIAL:"<<endl;
                p1.display_polynomial();
                cout<<endl<<endl;
                cout<<"\nTHE SECOND POLYNOMIAL:"<<endl;
                p2.display_polynomial();
                cout<<endl<<endl;
                cout<<"THE ADDITION OF THE TWO POLYNOMIALS = "<<endl<<endl;
                p3.add_polynomial(p1,p2);
                cout<<"Resultant Polynomial:"<<endl<<endl;
                p3.display_polynomial();
                break;

            }

            case 2:
            {

                //subtraction

                cout<<"THE SUBTRACTION OF THE TWO POLYNOMIALS = "<<endl<<endl;
                p4.sub_polynomial(p1,p2);
                cout<<"Subtracting p1 from p2"<<endl;
                cout<<"Resultant Polynomial:"<<endl<<endl;
                p4.display_polynomial();
                break;

            }

            case 3:
            {
                //multiplication by scalar

                int k=0;
                float scalar;
                cout<<"Enter the scalar value:"<<endl;
                cin>>scalar;
                cout<<"THE MULTIPLICATION OF THE POLYNOMIAL BY THE SCALAR = "<<endl<<endl;

                //asks the choice of polynomial to perform the operation on

                while(k!=1 || k!=2){
                    cout<<"Do you want to multiply the scalar with the first polynomial or the second polynomial? Enter 1 for 1st and 2 for 2nd:";
                    cin>>k;
                    if(k==1){
                        p5.scalarmul_polynomial(p1,scalar);
                        cout<<"\nResultant Polynomial:"<<endl<<endl;
                        p5.display_polynomial();
                        break;
                    }
                    else if(k==2){
                        p6.scalarmul_polynomial(p2,scalar);
                        cout<<"\nResultant Polynomial:"<<endl<<endl;
                        p6.display_polynomial();
                        break;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                    }
                }
                break;

            }
            case 4:
            {
                //multiplication

                cout<<"THE MULTIPLICATION OF THE TWO POLYNOMIALS = "<<endl<<endl;
                p7.multiply_polynomial(p1,p2);
                cout<<"Resultant Polynomial:"<<endl<<endl;
                p7.display_polynomial();
                break;

            }

            case 5:
            {
                //division by scalar

                int k=0;
                float scalar;
                cout<<"Enter the scalar value:"<<endl;
                cin>>scalar;
                cout<<"THE DIVISION OF THE POLYNOMIAL BY THE SCALAR = "<<endl<<endl;

                //asks the choice of polynomial to perform the operation on

                while(k!=1 || k!=2){
                    cout<<"Do you want to divide the first or the second polynomial by the scalar? Enter 1 for 1st and 2 for 2nd:";
                    cin>>k;
                    if(k==1){
                        p8.scalardiv_polynomial(p1,scalar);
                        cout<<"\nResultant Polynomial:"<<endl<<endl;
                        p8.display_polynomial();
                        break;
                    }
                    else if(k==2){
                        p9.scalardiv_polynomial(p2,scalar);
                        cout<<"\nResultant Polynomial:"<<endl<<endl;
                        p9.display_polynomial();
                        break;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                    }
                }
                break;
            }
            case 6:
            {
                //finding degree

                int k=0;

                //asks the choice of polynomial to perform the operation on

                while(k!=1 || k!=2){
                    cout<<"Do you want to find degree of the first polynomial or the second polynomial? Enter 1 for 1st and 2 for 2nd:";
                    cin>>k;
                    if(k==1){
                        p10.find_degree(p1);
                        break;
                    }
                    else if(k==2){
                        p11.find_degree(p2);
                        break;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                    }
                }
                break;
            }

        }

        //repeats the menu driven program unless user exits

        cout<<"\n\n OPERATIONS:"<<endl<<endl;
        cout<<"\t1.To add two polynomials\n"<<endl;
        cout<<"\t2.To subtract the two polynomials\n"<<endl;
        cout<<"\t3.To multiply a polynomial by a scalar\n"<<endl;
        cout<<"\t4.To multiply the two polynomials\n"<<endl;
        cout<<"\t5.To divide a polynomial by a scalar\n"<<endl;
        cout<<"\t6.To find degree of a polynomial\n"<<endl;
        cout<<endl;
        cout<<"\nEnter your choice/Enter 0 to exit :";
        cin>>choice;

    }

}
