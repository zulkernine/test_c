#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dis_char(const char* a){
    int m=0,s[26],j;
    for(j=0;j<26;j++){
        s[j]=0;
    }
    for(int i=0;a[i];i++){
        for(char c='a',j=0;c<='z';c++,j++){
            if(a[i]== c && s[j]==0){
                s[j]++;
                break;
            }
        }
    }

    return m;
}
void sv(char* a, char*b);
int lexicographic_sort(const char* a, const char* b);
int lexicographic_sort_reverse(const char* a, const char* b){
      if(lexicographic_sort(a,b)==1){
        return 0;
    }
    else{
        return 1;
    }
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int m=dis_char(a), n=dis_char(b);
    if(m<n){
        return 1;
    }else if(m>n){
        return 0;
    }else{
        return  lexicographic_sort(a,b);
    }
}



int sort_by_length(const char* a, const char* b) {
   
    int m,n;
    m=strlen(a);
    n=strlen(b);
    if(m>n)
    {
        return 0;
    }else if(n>m){
        return 1;
    }else {
        return  lexicographic_sort(a,b);
    }


}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
int i,j;
for(i=0;i<len;i++){
    for(j=i+1;j<=len;j++){
        if( !(*cmp_func)(arr[i],arr[j])){
            sv(arr[i],arr[j]);
        }
    }
}
}
void sv(char* a, char*b){
    int i;
    char s[80];
    for(i=0;a[i];i++){
        s[i]=a[i];
    }
    for(i=0;b[i];i++){
        a[i]=b[i];
    }

    for(i=0;s[i];i++){
            b[i]=s[i];
    }


   
}

int lexicographic_sort(const char* a, const char* b)
{
    
    for(int i=0;a[i]||b[i];i++){
        if(a[i]<b[i]){
            return 1;
            break;
        }else if(a[i]==b[i]){
            if(a[i+1]=='\0'&&b[i+1]!='\0'){
                return 1;
                break;
            }else if(a[i+1]!='\0'&&b[i+1]=='\0'){
                return 0;
                break;
            }else {
                continue;
        }

        }else if(a[i]>b[i])
        {
            return 0;
            break;
        }
    }

}



int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
    return 0;
}