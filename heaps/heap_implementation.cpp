#include<bits/stdc++.h>
using namespace std;

template<class T>
class minHeap{
   
int size;
T * array;
int position;
minHeap();
bool heapify(int );
void minheapify(int );

 //public functions---
public:
minHeap(int);
bool insert(T);
void heapify();
void print();
T extract();
T min();


};

template<class T>                                      
minHeap<T>::minHeap(){}                                 //default constructor

template<class T>
 minHeap<T>::minHeap(int size)                          // constructor
{
    this->position=-1;
    this->size=size;
    this->array=(T*)malloc( sizeof(T)*  size);

}
template<class T>
bool minHeap<T>::insert(T data)                         //insert
{
    if( position +1 > size)
    {

        cout<<"Heap is full"<<endl;
        return false;
    }
        position+=1;
    array[(position)]=data;

   // heapify(position);

    return true; 

}



//this function is to do heapify during insertion time 
// it take positio of insertion and heapify the heap 
//TC =o(log n);
template<class T>
bool minHeap<T>::heapify(int pos)                      // heapiy for insert
{
 
    int  parent;

     while( (pos !=0))
     {        
         parent=(pos-1)/2;
        if(array[parent] > array[pos])
        swap(array[parent],array[pos]);

        else break;

        pos=parent;
       
     }
    
   

}

// it is used when our whole array is in minheap condition 
// just one element voilates the rule of minheap 
// so just heapify the heap to again make it minheap
template<class T>
void minHeap<T>:: heapify()                           // search of voilede position
{
   
int i=0;
while(2*i+1<=position )
 {
   

    int left=2*i+1;
    int right=2*i+2;
    if(left<=size)
    {
       if( array[left] < array[i])
        {
            minheapify(i);
        break;
        }
    }
    else if(right <=size)
    {
        if(array[right]< array[i])
        {
            minheapify(i);
        break;
        }
    }
     i++;
 }


}
template<class T>
void minHeap<T>:: minheapify(int pos)                 //heapify on voileted position
{
       int smaller=pos;
       int left=2*pos+1;
       int right=2*pos+2;

       if(left <=position)
       {
        if(array[smaller] >array[left])
        {
            smaller=left;
        }

       }
        if(right <=position)
        {
            if(array[smaller] > array[right])
            smaller=right;
        }

        if(smaller !=pos)
        {
            swap(array[pos],array[smaller]);
            minheapify(smaller);
        }

        return;

}


template<class T>
void minHeap<T>::print()                           //print heap
{
    for(int i=0;i<=position;i++)
    {
        cout<<array[i]<<" ";
    }
    
}

template<class T>
T minHeap<T>::extract()
{
     T data;
    if(position == -1)
    {
        cout<<"Heap is empty"<<endl;
        return data;
    }

     data=array[0];
swap(array[position],array[0]);
position--;
heapify();
return data;
}

template<class T>
T minHeap<T>::min()
{
    T data;
    if(position==-1)
    {
        return data;
    }
    data=array[0];
    return data;


}

int main()
{
    minHeap<int> heap(18);
//     heap.insert(8);
   
//     heap.insert(4);
   
//     heap.insert(9);
   

//      heap.insert(1);
   

//     heap.insert(7);
//     heap.insert(5);
//     heap.insert(1);
//     heap.insert(1);
//     heap.print();
//    cout<<endl;
    // minHeap<string>heap1(8);
    // heap1.insert("a");
    // heap1.insert("zpple");
    // heap1.insert("b");
    // heap1.insert("c");
    // heap1.print();

heap.insert(11);
heap.insert(20);
heap.insert(30);
heap.insert(35);
heap.insert(25);
heap.insert(80);
heap.insert(32);
heap.insert(100);
heap.insert(70);
heap.insert(60);
heap.print();
cout<<endl;
heap.heapify();
heap.print();
cout<<endl;

cout<<" minimu element is"<<heap.extract()<<endl;
cout<<" minimu element is"<<heap.extract()<<endl;
cout<<" minimu element is"<<heap.extract()<<endl;
heap.print();

}