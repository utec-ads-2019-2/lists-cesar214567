template<typename T>
void merge(T* m, int inicio, int medio, int final){
        int k=inicio,parte1,parte2;
        parte1=medio-inicio+1;
        parte2=final-medio;
        int *temporal1=new int[parte1];
        int *temporal2=new int[parte2];
        for (int i=0;i<parte1;i++){
            temporal1[i]=m[inicio+i];
        }
        for (int i=0;i<parte2;i++){
            temporal2[i]=m[medio+i+1];
        }

        int i=0,j=0;
        while (i<parte1 &&j< parte2){
            if (temporal1[i]<=temporal2[j]){
                m[k]=temporal1[i];
                i++;
            }
            else{
                m[k]=temporal2[j];
                j++;
            }
            k++;
        }
        while(i<parte1){
            m[k]=temporal1[i];
            i++;
            k++;
        }
        while(j<parte2){
            m[k]=temporal2[j];
            j++;
            k++;
        }
        }

template<typename T>
    void mergesort(T* m,int inicio, int final){
        if (inicio<final){
            int medio=inicio+(final-inicio)/2;
            mergesort(m,inicio,medio);
            mergesort(m,medio+1,final);
            merge(m,inicio,medio, final);
        }

    }