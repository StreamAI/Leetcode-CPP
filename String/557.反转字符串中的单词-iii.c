/*
 * @lc app=leetcode.cn id=557 lang=c
 *
 * [557] 反转字符串中的单词 III
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

char * reverseWords(char * s){
    if(s == NULL || s[0] == '\0')
        return s;

    int n = 0;
    while (s[n] != '\0')
        n++;

    int begin = 0;
    for(int i = 0; i <= n; i++){
        if(s[i] == ' ' || s[i] == '\0'){
            reverseString(&s[begin], i - begin);
            begin = i + 1;
        }
    }
    
    return s;
}
// @lc code=end

