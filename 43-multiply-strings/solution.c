char* multiply(char* num1, char* num2){
    int l1= strlen(num1), l2= strlen(num2), len= l1+l2;
    char* result= (char*)malloc(len+1);
    for(int i= 0; i < len; i++) result[i]= '0';
    result[len]= '\0';
    char* subresult= (char*)malloc(l1+2);
    int padding= 0;
    for(int j= l2- 1; j >= 0; j--, padding++){
        int fullLen= l1+1;
        for(int i= 0; i < fullLen; i++) subresult[i]= '0';
        subresult[fullLen]= '\0';
        int carry= 0;
        for(int i= l1- 1; i >= 0; i--){
            int m= (num1[i]- '0') * (num2[j]- '0')+carry;
            subresult[i+1]= m % 10+'0';
            carry= m / 10;
        }
        subresult[0]= carry+'0';
        int offset= len- fullLen- padding;
        carry= 0;
        for(int i= fullLen- 1; i >= 0; i--){
            int s= (result[offset+i]- '0')+(subresult[i]- '0')+carry;
            result[offset+i]= s % 10+'0';
            carry= s / 10;
        }
        int k= offset- 1;
        while(carry && k >= 0){
            int s= (result[k]- '0')+carry;
            result[k]= s % 10+'0';
            carry= s / 10;
            k--;
        }
    }
    int pos= 0;
    while(pos < len- 1 && result[pos]== '0') pos++;
    return result+pos;
}