/*
 * @lc app=leetcode.cn id=344 lang=c
 *
 * [344] 反转字符串
 */

// @lc code=start
void swapChar(char* c1, char* c2){
    if(*c1 != *c2){
        char temp = *c1;
        *c1 = *c2;
        *c2 = temp;
    }
}

void reverseString(char* s, int sSize){
    if(s == NULL || s[0] == '\0' || sSize < 1)
        return;

    for(int left = 0, right = sSize - 1; left < right; left++, right--)
        swapChar(&s[left], &s[right]);
}
// @lc code=end

