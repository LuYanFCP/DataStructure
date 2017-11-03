//
// Created by luyanfcp on 17-11-1.
// email:lyhxbq@gmail.com
//
#include <stdio.h>

// 求next数组
void getNext(const char *t, int *next, int t_len)
{
    int j; //后缀指针
    int k; //前缀指针
    int z; //next index
    // 初始化next数组
    for (int i = 0; i < t_len; ++i) {
        z = (i+1) % t_len;
        next[z]= 0;
        for (j=1,k=0; j <= i && k<j ; ++j) {
            if (t[k] == t[j]){
                k++;
                next[z]++;
            } else{
                next[z] = 0;
                k = 0;
            }
        }
    }
    next[0]=-1;

}


int kmp(char* s, char* t, int s_len, int t_len, int pos)
{
    int i,j;
    int next[t_len];
    char *str_s ;
    str_s=s;
    char *str_t;
    str_t=t;
    i = pos;
    j = 0;
    getNext(str_t,next,t_len);
    while (i<s_len && j<t_len){
        if(j==-1 || str_s[i] == str_t[j]){
            i++;
            j++;
        } else
            j = next[j];
    }
    return j == t_len ? i - t_len : -1;
}

int main()
{
//    FILE *file =fopen("file test.txt", "r");
//    if (file==NULL) {
//        printf("文件路径错误,不存在文件!\n");
//        return 0;
//    }

    char *x1 = "bbc abcdab abcdabcdabde";
    char *x2 = "abcdabd";
    char *s=x1;
    char *t=x2;

//    *s = x1;
//    *t = x2;

//    getline(s,0,file);
//    getline(t,0,file);
    printf("s:%s\n",t);
    printf("t:%s\n",s);
    printf("%d\n",kmp(x1,x2,23,7,0));
}