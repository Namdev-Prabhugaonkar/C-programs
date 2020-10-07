/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <stdlib.h>

bool uniqueCharacters(char str[]){
    if(strlen(str)>256 || strlen(str)==0){
        return false;
    }
    
    bool unique[256]={0};
    
    for(int i=0;i<strlen(str);i++){
        int temp = str[i];
        if(unique[temp]){
            return false;
        }
        unique[temp]=true;
    }
    
    return true;
}

char * reverseString(char arr[], int len){
    char * rev = (char *)malloc(strlen(arr));
    int length = len;
    int mid=length/2;
    for(int i=0,j=length-1;i<mid;i++,j--){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    strcpy(rev,arr);
    return rev;
}

void reverseWords(char * str){
    int j=0;
    int i=0;
  while(j <= strlen(str))
  {
    if( str[j] == ' ' || str[j] == '\0')
    {
      reverseString( str+i, j-i );
      i = j+1;
    }
    j++;
  }
  
  reverseString(str,strlen(str));
  printf("%s\n",str);
}

char * removeDuplicates(char arr1[], char arr2[]){
    char * str = (char * ) malloc(sizeof(char) * strlen(arr2));
    int index=0;
    char letter[26]={0};
    for(int i=0;i<strlen(arr1);i++){
        letter[arr1[i]-'a']++;
    }
    
    for(int i=0;i<strlen(arr2);i++){
        if(!letter[arr2[i]-'a']){
            str[index]=arr2[i];
            index++;
        }
    }
    
    str[index]='\0';
    return str;
}

void countVCDW(char str[]){
    int vowelCount=0;
    int consonantCount=0;
    int digitCount=0;
    int whitespaceCount=0;
    
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || 
           str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' ){
               vowelCount++;
           }
        else if(str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z'){
            consonantCount++;
        }  
        else if((str[i]-'0')>=0 && (str[i]-'0')<=9){
            digitCount++;
        }
        else if(str[i]==' '){
            whitespaceCount++;
        }
    }
    
    printf("Vowels:%d, Consonants:%d, digitCount=%d, Space=%d ",vowelCount,consonantCount,digitCount,whitespaceCount);
    
}

void sumofDigitsinstring(char str[]){
    int sum=0;
    
    for(int i=0;i<strlen(str);i++){
        int temp = str[i]-'0';
        if(temp>=0 && temp<=9){
            sum+=temp;
        }
    }
    printf("Sum of digits:%d",sum);
}

char * lastWord(char *str){
    int length = strlen(str);
    int i=0;
    if(str[length-1-i]==' '){
        i++;
    }
    while(str[length-1-i]!=' '){
        if(str[length-1-i]==' '){
            break;
        }
        i++;
    }
    return  str+length-i;
}

int stoi(char * str){
    int number=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]>='0' && str[i]<='9'){
            int digit = str[i]-'0';
            number = number*10 + digit;
        }
    }
    return number;
}

bool checkifAnagram(char str1[], char str2[]){
    int arrStr1[26]={0};
    int arrStr2[26]={0};
    
    for(int i=0;i<strlen(str1);i++){
        arrStr1[str1[i]-'a']++;
    }
    
    for(int i=0;i<strlen(str2);i++){
        arrStr2[str2[i]-'a']++;
    }
    
    for(int i=0;i<26;i++){
        if(arrStr1[i]!=arrStr2[i]){
            return 0;
        }
    }
    return 1;
}

int isSubstring(char str1[],char str2[]){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i=0;i<=len2-len1;i++){
       int j=0;
        for(j;j<len1;j++){
            if(str1[j]!=str2[j+i]){
                break;
            }
        }
         if(j==len1){
              return i;
            }
    }
    return -1;  
}

int countFrequescyOfwords(char str1[],char str2[]){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int count=0;
 
    for(int i=0;i<=len2-len1;i++){
       int j=0;
        for(j;j<len1;j++){
            if(str1[j]!=str2[j+i]){
                break;
            }
        }
         if(j==len1){
              count++;
            }
    }
    return count;  
}

void swap(char *x, char *y)

{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}


int main(){
    char str[]="dkjwvno!@#$%^&";
    char str2[]="where there is a will there is a way ";
    char str3[]="programming";
    char str4[]="computer";
    char str5[]="233ffv13445hgf123";
    char stoiStr[]="3432123";
    char anagramStr1[]="qwerty";
    char anagramStr2[]="ytrewq";
    char s1 []= "for"; 
    char s2 []= "geeksforgeeksforcdsvsvfor"; 
    char perm[]="ABCD";
    //printf("%d\n",uniqueCharacters(str));
    //printf("%s\n",reverseString(str,strlen(str)));
    //reverseWords(str2);
    //char * removed = removeDuplicates(str3,str4);
    //printf("%s",removed);
    //countVCDW(str);
    //sumofDigitsinstring(str5);
    //char * last=lastWord(str2);
    //printf("String:%s",last);
    //printf("%d ",stoi(stoiStr));
    //printf("%d ",checkifAnagram(anagramStr1,anagramStr2));
    //printf("%d ",countFrequescyOfwords(s1,s2);
    //printf("%d ",isSubstring(s1, s2));
    //permute(perm,0,strlen(perm)-1);
    
    return 0;
}