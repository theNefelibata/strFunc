void *memcpy(void* dist, const void* src, size_t n){
    assert(dist != nullptr && src != nullptr);
    char* d = (char*)dist;
    char* s = (char*)src;
    if(d > s && d < s+n){
        d += n-1;
        s += n-1;
        while(n--){
            *d-- = *s--;
        }
    }else{
        while (n--){
            *d++ = *s++;
        }
    }
    return dist;
}

void *memset(void* src, int c, size_t n){
    assert(src != nullptr);
    char* psrc = (char*) src;
    while (n--){
        *psrc++ = char(c);
    }
    return src;
}

char *strcpy(char* dist, const char *src){
    assert(dist != nullptr && src != nullptr);
    char *d;
    d = dist;
    int n = strlen(src);
    if(d > src && d < src + n){
        d += n-1;
        src += n-1;
        *d-- = '\0';
        while(n--) {
            *d-- = *src--;
        }
    }else{
        while (n--){
            *d++ = *src++;
        }
    }
    return dist;
}

char *strcat(char* dist, char* src){
    assert(dist != nullptr && src != nullptr);
    char* pdist = dist;
    while(*pdist != '\0'){
        pdist++;
    }
    while((*pdist++ = *src++) != '\0');
    return dist;
}

int strcmp(const char* s1, const char* s2){
    assert(s1 != nullptr && s2 != nullptr);
    while(*s1 && *s2 && *s1 == *s2){
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int cstrlen(const char* s){
    assert(s != nullptr);
    size_t n = 0;
    while(*s++ != '\0') n++;
    return n;
}

char* cstrncpy(char* dist, char* src, size_t n){
    assert(dist != nullptr && src != nullptr);
    size_t lensrc = strlen(src);

    char * ret = dist;
    n = n > lensrc ? lensrc : n;
    if(dist > src && dist < src + n){
        dist += n;
        *dist = '\0';
        src += n-1;
        while(n--){
            *dist-- = *src--;
        }
    }else{
        while (n--){
            *dist++ = *src++;
        }
        if(*(dist-1) != '\0') *dist = '\0';
    }
    return ret;
}
