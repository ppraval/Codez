#include<stdio.h>
void swap(int *a,int *b)
{
    *a=*a^*b;
    *b=*b^*a;
    *a=*a^*b;
}
int left(int i) {return 2*i+1;}
int right(int i) {return 2*i+2;}
void buildminheap(int arr[],int n,int largest)
{
    int i=largest;
    int l=left(i);int r=right(i);
    if(l<n && arr[l]<=arr[i])
    {
i=l;
    }
    if(r<n && arr[r]<=arr[i])i=r;
    if(i!=largest)
    {
        swap(&arr[i],&arr[largest]);
        buildminheap(arr,n,i);
    }
}
void insert(int arr[],int i)
{
    int parent=i/2;
    while(parent>0 && arr[i]<arr[parent])
    {
        swap(&arr[i],&arr[parent]);
        i=parent;
        parent=i/2;
    }
}
void extractmin(int arr[],int *n)
{
    int mini=arr[0];printf("%d ",mini);
    //now mini stores the root of the heap so the minimum value
    //now just replace arr[0] with arr[last element ] and swap(both of them and reduce heapsize);
    swap(&arr[0],&arr[*n-1]);(*n)--;
    buildminheap(arr,*n-1,0);
}


int main()
{
    int n;scanf("%d",&n);
    int arr[2000];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    for(int i=n/2-1;i>=0;i--)buildminheap(arr,n,i);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    //the minheap is built
    //now lets insert a new element into the heap
    int x;scanf("%d",&x);
    arr[n]=x;
    n++;
    insert(arr,n-1);
    //the last element is inserted into the right position
    //now lets code increase key operation
    //for this you just have to bubble down once
    int index;scanf("%d",&index);
    int increase;scanf("%d",&increase);arr[index]+=increase;
    buildminheap(arr,n,index);
    for(int i=0;i<n;i++){printf("%d ",arr[i]);}
    //now let us write the extract min function
extractmin(arr,&n);for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}