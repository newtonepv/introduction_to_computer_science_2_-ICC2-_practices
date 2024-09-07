#include <stdio.h>
#include<stdlib.h>
int* merge(int* lista1, int* lista2, int t1,int t2){
    int* lista3 = (int*)malloc(sizeof(int)*(t1+t2));
    int i=0,j=0,k=0;
    while(i<t2 && j<t1){
        int prox=0;

        if(lista1[j]<=lista2[i]){
            lista3[k]=lista1[j];
            j++;
        }else{
            lista3[k]=lista2[i];
            i++;
        }
        k++;
    }
    while(i<t2){
        lista3[k]=lista2[i++];
        k++;
    }
    while(j<t1){
        lista3[k]=lista1[j++];
        k++;
    }
    return lista3;
}
int* mergesort(int v[],int end){
    int middle=(end)/2;
    if(end==0){
        int* single = (int*)malloc(sizeof(int));
        single[0] = v[0];
        return single;
    }else if(end==1){
        int* sorted = (int*)malloc(2 * sizeof(int));
        if (v[0] <= v[1]) {
            sorted[0] = v[0];
            sorted[1] = v[1];
        } else {
            sorted[0] = v[1];
            sorted[1] = v[0];
        }
        return sorted;
    }else{
        int middle=end/2;
        int* l1 = mergesort(v, middle);
        int* l2 = mergesort(v+middle+1, (end-middle)-1);
        int* merged = merge(l1, l2, middle+1,end-middle);
        free(l1); free(l2);
        return merged;
    }
}
int main(){
    /*int lista1[5] = {2,3,4,7,8};
    int lista2[9] = {1,2,2,2,3,3,8,9,9};
    int* tamanho = (int*)malloc(sizeof(int));
    int* lista3 = merge(lista1,lista2,tamanho);
    while(*tamanho>=0){
        printf("%d ",lista3[--(*tamanho)]);
    }
    free(lista3);
    lista3=NULL;
    free(tamanho);*/
    int end = 11;
    int unordered[12] = {5,4,2,4,5,63,6,453,45,35,34,5};
    int* ordered=mergesort(unordered,end);
    for(int i=0;i<=end;i++){
        printf("%d ", ordered[i]);
    }
    free(ordered);
    return 0;   
}
