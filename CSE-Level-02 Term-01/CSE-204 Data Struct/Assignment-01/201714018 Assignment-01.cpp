#include<iostream>
#include<cstdlib>
using namespace std;

int *p;                     // Globally declared ptr p
int occupied;               //Dynamic index of my Array

int initialize(int n)
{
    p=(int*)malloc(n*sizeof(int));
    occupied=0;
}

void append(int val)         //For taking Input and Insert Last
{
    p[occupied++]=val;
}

void appendLast(int val)         //For taking Input and Insert Last
{
    p=(int*)realloc(p,(occupied+1)*sizeof(int));
    p[occupied++]=val;
}

void printArray()
{
    cout<<"The resultant array: ";
    for(int i=0;i<=occupied-1;i++)
    {
        cout<<p[i]<<" ";
    }
}

void insertFirst(int val)
{
    p=(int*)realloc(p,(occupied+1)*sizeof(int));
    for(int i=occupied-1;i>=0;i--)
    {
        p[i+1]=p[i];
    }
    p[0]=val;
    occupied++;
}

void insertMiddle(int pos,int val)
{
    p=(int*)realloc(p,(occupied+1)*sizeof(int));
    for(int i=occupied-1;i>=pos-1;i--)
    {
        p[i+1]=p[i];
    }
    p[pos-1]=val;
    occupied=occupied+1;

}

void deleteFirst()
{
    for(int i=1;i<=occupied-1;i++)
    {
        p[i-1]=p[i];
    }
    occupied--;
}

void deleteLast()
{
    occupied=occupied-1;
}

void deleteMiddle(int pos)
{
    for(int i=pos-1+1;i<=occupied-1;i++)
    {
        p[i-1]=p[i];
    }
    occupied--;
}

void changeMiddle(int pos,int val)
{
    p[pos-1]=val;
}

void freePtr()
{
    free(p);
}

int main()
{
    cout<<"Enter the size of the array: ";

    int x;
    cin>>x;

    initialize(x);        //Dynamically Allocated the Array

    cout<<"Enter the elements of the array: ";    //Taking Input

    for(int i=0;i<x;i++)
    {
        int value;
        cin>>value;
        append(value);
    }

    printArray();    //Printing the resultant Array at the beginning

    //Menu Items
    cout<<"\nChoose one of the option: \n\t1. Insert element at the first position of the array \n\t2. Insert element at the last position of the array \n\t3. Insert element at any middle position of the array \n\t4. Delete an element from the first position of the array \n\t5. Delete an element from the last position of the array \n\t6. Delete an element from any position of the array \n\t7. Update any value of any position of the array \n\t8. Quit ";

    while(1)
    {
        cout<<"\nEnter option: ";
        int choice;
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter value: ";
            int val;
            cin>>val;
            insertFirst(val);

            printArray();
            cout<<"\n";
        }
        else if(choice==2)
        {
            cout<<"Enter value: ";
            int val;
            cin>>val;
            appendLast(val);

            printArray();
            cout<<"\n";
        }
        else if(choice==3)
        {
            cout<<"Enter position: ";
            int pos;
            cin>>pos;
            if(pos<=occupied && pos>=1)
            {
                cout<<"Enter value: ";
                int val;
                cin>>val;

                insertMiddle(pos,val);

                printArray();
                cout<<"\n";
            }
            else
            {
                cout<<"Entered position is not a valid one.\n";
            }

        }
        else if(choice==4)
        {
            deleteFirst();
            printArray();
            cout<<"\n";
        }
        else if(choice==5)
        {
            deleteLast();
            printArray();
            cout<<"\n";
        }
        else if(choice==6)
        {
            cout<<"Enter position: ";
            int pos;
            cin>>pos;
            if(pos<=occupied && pos>=1)
            {
                deleteMiddle(pos);

                printArray();
                cout<<"\n";
            }
            else
            {
                cout<<"Entered position is not a valid one.\n";
            }

        }
        else if(choice==7)
        {
            cout<<"Enter position: ";
            int pos;
            cin>>pos;
            if(pos<=occupied && pos>=1)
            {
                cout<<"Enter value: ";
                int val;
                cin>>val;

                changeMiddle(pos,val);

                printArray();
                cout<<"\n";
            }
            else
            {
                cout<<"Entered position is not a valid one.\n";
            }
        }
        else if(choice==8)
        {
            freePtr();
            break;
        }
    }


    return 0;

}
