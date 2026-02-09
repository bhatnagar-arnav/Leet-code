void reverseString(char* s, int sSize) {
    char temp; int j=sSize-1,i=0;
    while(i<j){
        temp=s[j];
        s[j]=s[i];
        s[i]=temp;
    
        j--;
        i++;
    }
    
}