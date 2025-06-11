int strStr(char* haystack, char* needle) {
    char *found = strstr(haystack,needle);
    if(!found ){
        return -1;
    }
    return found - haystack;
}