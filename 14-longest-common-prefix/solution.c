char* longestCommonPrefix(char** strs, int strsSize) {
    char* result = malloc(201*sizeof(char));
    int i =0;
    while(true){
        char current_char;
        if(strlen(strs[0]) >=i ) current_char = strs[0][i];
        else {
            result[i] = '\0';
            return result;
        }
        for(int j = 0 ; j < strsSize ; j++){
            if(strs[j][i] == '\0' || strs[j][i] != current_char){
                result[i] = '\0';
                return result;
            }
        }
        result[i] = current_char;
        i++;
    }
    return result ;
}