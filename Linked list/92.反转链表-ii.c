/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* prev, int k){
    if(prev->next == NULL || prev->next->next == NULL || k < 1)
        return prev;

    struct ListNode* curr = prev->next;
    struct ListNode* post = curr->next;
    while (k-- > 0 && post != NULL)
    {
        curr->next = post->next;
        post->next = prev->next;
        prev->next = post;
        post = curr->next;
    }
    
    return prev;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(head == NULL || head->next == NULL || m < 1 || n <= m)
        return head;

    struct ListNode* H = malloc(sizeof(struct ListNode));
    H->next = head;

    struct ListNode* begin = H;
    int k = n - m;
    while (m-- > 1)
        begin = begin->next;

    reverseList(begin, k);

    head = H->next;
    free(H);

    return head;
}
// @lc code=end

