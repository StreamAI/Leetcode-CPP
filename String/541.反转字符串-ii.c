/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start

void reverseString(char* s, int sSize){
    if(s == NULL || s[0] == '\0' || sSize < 1)
        return;

    for(int left = 0, right = sSize - 1; left < right; left++, right--){
        if(s[left] != s[right]){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
        }
    }
}

char * reverseStr(char * s, int k){
    if(s == NULL || s[0] == '\0' || k <= 1)
        return s;

    int n = 0;
    while(s[n] != '\0')
        n++;

    int begin = 0;
    while (begin < n)
    {
        if(k <= n - begin)
            reverseString(&s[begin], k);
        else
            reverseString(&s[begin], n - begin);
        
        begin += 2*k;
    }
    
    return s;
}


// @lc code=end

