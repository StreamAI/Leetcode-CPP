/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode* prev = malloc(sizeof(struct ListNode));
    prev->next = head;

    struct ListNode* curr = head;
    struct ListNode* post = curr->next;
    while (post != NULL)
    {
        curr->next = post->next;
        post->next = prev->next;
        prev->next = post;
        post = curr->next;
    }

    head = prev->next;
    free(prev);
    
    return head;
}
/*
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    else{
        struct ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
}

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* post;

    while (curr != NULL)
    {
        post = curr->next;
        curr->next = prev;
        prev = curr;
        curr = post;
    }
    
    return prev;
}
*/
// @lc code=end

