#include <stdio.h>
#include <stdlib.h>


void merge(int* arr, int l, int m, int r){

    int n1 = m - l + 1; 
    int n2 = r - m; 

    int *left = malloc(n1*sizeof(int));
    int *right = malloc(n2*sizeof(int));
    
    for(int i = 0; i < n1; i++){
        left[i] = arr[l+i];
    }

    for(int i = 0; i < n2; i++){
        right[i] = arr[m + 1 + i];
    }
   
    int i = 0; int j = 0; int k = l;
    
    while( i < n1 && j < n2){
        if(left[i] >= right[j]){
            arr[k++] = right[j++];
        }
        else{
            arr[k++] = left[i++];
        }
    }

    while(j < n2){
        arr[k++] = right[j++];
    }
    
    while(i < n1){
        arr[k++] = left[i++];
    }

    free(left);
    free(right);

}

void mergeSort(int* arr, int l, int r){
    
    if(l < r){
    int mid = l + (r -l)/2;


    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1, r);
    merge(arr, l, mid,r);


    }
}

void MERGE_SORT(int* arr, int n){
    mergeSort(arr,0,n-1);
}


int main(){
    
    int n;

    scanf("%d", &n);    

    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
     }
    


    MERGE_SORT(arr, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;

}
