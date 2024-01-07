
#include <stdio.h>
//Bubble sort
void bubble(int a[] , int n){
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
}

//Selection sort
void selection(int a[] ,int n){
    
    for(int i=0;i<n;i++){
        int small = i;
        for(int j=i+1;j<n;j++){
            if(a[small]>a[j]){
                small=j;
            }
        }
        int temp=a[small];
        a[small]=a[i];
        a[i] = temp;
    }
     for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
}

//Insertion sort
void insertion(int a[] , int n){
    
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        
        while(j>=0 && key>a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        
    }
     for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
}
// Merge Sort  - Divide and conquror
void divide(int a[] ,int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    divide(a,si,mid);
    divide(a,mid+1,ei);
    conquror(a,si,mid,ei);
}

void conquror(int a[],int si,int mid , int ei){
    int n=ei-si+1;
    int merge[n];
    int mi=0;
    int idx1=si;
    int idx2=mid+1;
    
    while(idx1<=mid && idx2<=ei){
        if(a[idx1]<=a[idx2]){
            merge[mi++] = a[idx1++];
        }
        else{
            merge[mi++] = a[idx2++];
        }
    }
    
    while(idx1<=mid){
        merge[mi++] = a[idx1++];
    }
    
    while(idx2<=ei){
        merge[mi++] = a[idx2++];
    }
    
    for(int i=0,j=si ;i<n ; i++,j++){
        a[j]=merge[i];
    }
}

//Quick Sort
void quick(int a[],int low,int high){
    
    if(low<high){
        
        int pi = partition(a,low,high);
        
        quick(a,low,pi-1);
        quick(a,pi+1,high);
    }
}

int partition(int a[] , int low , int high){
     int pivot=a[high];
     int i=low-1;
     
     for(int j=low; j<high ;j++){
         
         if(a[j]<pivot){
             i++;
              int temp = a[j];
              a[j]=a[i];
              a[i]= temp;
         }
     }
     i++;
     int temp = a[high];
     a[high] = a[i];
     a[i] = temp;
     return i;
}


int main() {
    
    int a[]={7,8,5,6,4,3,2,1};
    int n = sizeof(a)/4;
     
     quick(a,0,n-1);
     
      for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }

    return 0;
}
